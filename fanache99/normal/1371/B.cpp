#include <fstream>
#include <iostream>
using namespace std;

int main(){
    //ifstream cin("input.txt");
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        long long n, r;
        cin >> n >> r;
        if (n - 1 < r) {
            cout << (n - 1) * n / 2 + 1 << "\n";
        } else {
            cout << (r + 1) * r / 2 << "\n";
        }
    }
    return 0;
}