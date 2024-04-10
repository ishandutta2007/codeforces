#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main(){
    //ifstream cin("input.txt");
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n, k;
        cin >> n >> k;
        vector<vector<int> > a(n, vector<int>(n, 0));
        for (int step = 1, i = 0, j = 0; step <= k; step++) {
            a[i][j] = 1;
            i = (i + 1) % n;
            j = (j + 1) % n;
            if (step % n == 0) {
                j = (j + 1) % n;
            }
        }
        if (k % n == 0) {
            cout << "0\n";
        } else {
            cout << "2\n";
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << a[i][j];
            }
            cout << "\n";
        }
    }
    return 0;
}