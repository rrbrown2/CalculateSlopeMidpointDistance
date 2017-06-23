/*
   Accepts two sets of ordered pairs and calculates slope, midpoint,
   and distance of those points.
 */
#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
#include <cstdlib>
using namespace std;

//function protype
void program6_1();
ifstream infile;
ofstream outputfile;
int main()
{
    program6_1(); // call program 6_1
    return 0;
}

// Calculate slope, distance, and midpoint
void program6_1()
{

    //creates or opens read and write files
    infile.open("read.txt");
    outputfile.open("write.txt");

    //check to make sure there is a file open. if no file is open program fails
    if (!infile.is_open())
    {
        exit(EXIT_FAILURE);
    }

    // local variables declared
    double y2, y1, x2, x1, slope, distance, midpoint1, midpoint2;
    bool undefined = false;

    // makes the loop run as long as it doesn't reach the end of file.


    // this code reads data from file and stores them in x1 y1 x2 y2
    while (infile >> x1 >> y1 >> x2 >> y2)
    {
        cout << x1 << y1 << x2 << y2;

        //check if slope is 0

        if (x2 - x1 != 0)
            slope = (y2 - y1) / (x2 - x1);

        else
            undefined = true; //cout << "Slope is undefined";

        //calculate distance using distance formula
        distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

        //calculate midpoint using midpoint formula
        midpoint1 = ((x1 + x2) / 2);
        midpoint2 = ((y1 + y2) / 2);

        // begins outputting results
        outputfile << "\nReport\n\n";
        outputfile << setprecision(2) << fixed << showpoint;
        outputfile << "Slope\t\tDistance\t\tMidpoint\n";

        if (undefined)
            outputfile << "undefined" << " \t " << distance << "\t\t\t" << "(" << midpoint1 << ", " << midpoint2 << ")" << "\n\n";

        else
            outputfile << slope << "\t\t" << distance << "\t\t\t" << "(" << midpoint1 << ", " << midpoint2 << ")" << "\n\n";

        outputfile << "End of report\n\n\n";

    } // end while
    outputfile.close();
    infile.close();

} // end of program 1


