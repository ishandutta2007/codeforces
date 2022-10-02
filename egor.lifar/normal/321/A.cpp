#include <iostream>
#include <algorithm>
#include <cstdio>
#include <sstream>
#include <cmath>
#include <map>
#include <string.h>
#include <vector>


using namespace std;


long long a, b;
string s;
long long x[100001], y[100001];


int main() {
    cin >> a >> b >> s;
    x[0] = 0;
    y[0] = 0;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (x[i] == a && y[i] == b) {
            cout << "Yes" << endl;
            return 0;
        }
        x[i + 1] = x[i];
        y[i + 1] = y[i];
        if (s[i] == 'U') {
            y[i + 1]++;
        }
        if (s[i] == 'D') {
            y[i + 1]--;
        }
        if (s[i] == 'L') {
            x[i + 1]--;
        }
        if (s[i] == 'R') {
            x[i + 1]++;
        }
    }
    if (x[n] == a && y[n] == b) {
        cout << "YES" << endl;
        return 0;
    }
    for (int i = 0; i <= n; i++) {
        long long a1 = a - x[i];
        long long b1 = b - y[i];
        if (x[n] == 0 || y[n] == 0) {
            if (x[n] == 0 && a1 != 0) {
                continue;
            } else {
                if (x[n] != 0) {
                    if (a1 % x[n] != 0 || a1 / x[n] < 0) {
                        continue;
                    }
                }
            }
            if (y[n] == 0 && b1 != 0) {
                continue;
            } else {
                if (y[n] != 0) {
                    if (b1 % y[n] != 0 || b1 / y[n] < 0) {
                        continue;
                    }
                }
            }
            cout << "Yes" << endl;
            return 0;
        }
        if (a1 % x[n] == 0 && b1 % y[n] == 0 && a1 / x[n] == b1 / y[n] && a1 / x[n] >= 0) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}