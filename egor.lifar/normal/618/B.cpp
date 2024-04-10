#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;


int n;
int a[51][51];
bool b[51];
int c[51];


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        int s = 1;
        for (int j = 0; j < n; j++) {
            if (j != i) {
                if (b[j]) {
                    if (a[i][j] == c[j]) {
                        s = max(s, a[i][j] + 1);
                    }
                } else {
                    s = max(s, a[i][j]);
                }
            }
        }
        bool bb = 1;
        for (int j = 0; j < n; j++) {
            if (j != i) {
                if (b[j]) {
                    if (a[i][j] != c[j]) {
                        b[j] = 1;
                        c[i] = a[i][j];
                        bb = 0;
                        break;
                    }
                }
            }
        }
        if (bb) {
            b[i] = 1;
            c[i] = s;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << c[i] << ' ';
    }
    cout << endl;
    return 0;   
}