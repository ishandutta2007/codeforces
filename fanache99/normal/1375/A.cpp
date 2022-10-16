#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    //ifstream cin("input.txt");
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            if (i % 2 == 1) {
                cout << abs(x) << " ";
            } else {
                cout << -abs(x) << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}