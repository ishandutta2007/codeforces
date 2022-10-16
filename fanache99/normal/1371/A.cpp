#include <fstream>
#include <iostream>
using namespace std;

int main(){
    //ifstream cin("input.txt");
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n;
        cin >> n;
        cout << (n - 1) / 2 + 1 << "\n";
    }
    return 0;
}