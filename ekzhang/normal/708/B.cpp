#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
LL XX, XY, YX, YY;

#define BAD { cout << "Impossible" << endl; return 0; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    
    cin >> XX >> XY >> YX >> YY;
    
    LL X = 1;
    LL Y = 1;
    while (X * (X - 1) / 2 < XX) {
        X++;
    }
    if (X * (X - 1) / 2 != XX) {
        BAD;
    }
    while (Y * (Y - 1) / 2 < YY) {
        Y++;
    }
    if (Y * (Y - 1) / 2 != YY) {
        BAD;
    }

    if (!XX) {
        if (!(XY || YX)) {
            for (int i = 0; i < Y; i++) {
                cout << 1;
            }
            cout << endl; return 0;
        }
    }
    if (!YY) {
        if (!(XY || YX)) {
            for (int i = 0; i < X; i++) {
                cout << 0;
            }
            cout << endl; return 0;
        }
    }

    if (XY + YX != X * Y) {
        BAD;
    }

    LL d = XY / Y;
    LL m = XY % Y;

    for (int i = 0; i < d; i++) {
        cout << 0;
    }
    for (int i = 0; i < Y - m; i++) {
        cout << 1;
    }
    if (m) cout << 0;
    for (int i = 0; i < m; i++) {
        cout << 1;
    }
    for (int i = 0; i < X - d - ((bool) m); i++) {
        cout << 0;
    }
    
    cout << endl;
    return 0;
}