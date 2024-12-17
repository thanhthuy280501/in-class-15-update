#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function to calculate average score
int averageScore(const string& fileName) {
    ifstream f(fileName);
    int num, sum = 0, count = 0;

    while (f >> num) {
        sum += num;
        count++;
    }
    f.close();
    return count > 0 ? (sum / count) : 0;
}

int main(int argc, char* argv[]) {
    string fileName;

    try {
        if (argc == 1) {  // No arguments
            cout << "No arguments provided. Defaulting to 'scores.txt'." << endl;
            fileName = "scores.txt";
        } else if (argc > 2) {  // Too many arguments
            cout << "Warning: Too many arguments provided. Using '" << argv[1] << "' as file name." << endl;
            fileName = argv[1];
        } else {
            fileName = argv[1];
        }
    } catch (...) {
        cerr << "An unexpected error occurred." << endl;
        return 1;
    }

    int avg = averageScore(fileName);
    cout << "Average score: " << avg << endl;

    return 0;
}
