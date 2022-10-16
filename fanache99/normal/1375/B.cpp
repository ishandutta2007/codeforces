#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAXN = 300;

int a[1 + MAXN][1 + MAXN];

int neighbours(int i, int j, int n, int m) {
    return (i > 1) + (i < n) + (j > 1) + (j < m);
}

int main(){
    //ifstream cin("input.txt");
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n, m;
        cin >> n >> m;
        bool bad = false;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int x;
                cin >> x;
                if (x > neighbours(i, j, n, m)) {
                    bad = true;
                }
            }
        }
        if (bad) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    cout << neighbours(i, j, n, m) << " ";
                }
                cout << "\n";
            }
        }
    }
    return 0;
}