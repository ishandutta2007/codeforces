#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 7;

int n;
int a[MAXN][2], b[MAXN][2];

int t[MAXN][2];
void check(int f1, int f2) {
    t[0][0] = f1;
    t[0][1] = f2;
    for (int i = 0; i < n - 1; ++i) {
        for (int p = 0; p < 2; ++p) {
            int sum = -1;
            if (a[i][p] == 0 && b[i][p] == 0) {
                sum = 0;     
            }
            else if (a[i][p] == 1 && b[i][p] == 1) {
                sum = 2;
            }   
            else if (a[i][p] == 1 && b[i][p] == 0) {
                sum = 1;
            }
            if (sum < t[i][p]) return;
            else {
                t[i + 1][p] = sum - t[i][p];
            }
        }
    }
    for (int i = 0; i < n - 1; ++i) {
        int ax = a[i][0] + 2 * a[i][1];
        int bx = b[i][0] + 2 * b[i][1];
        int tx1 = t[i][0] + 2 * t[i][1];
        int tx2 = t[i + 1][0] + 2 * t[i + 1][1];
        if ((tx1 | tx2) != ax || (tx1 & tx2) != bx) {
            return;
        }   
    }
    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        int tx = t[i][0] + 2 * t[i][1];
        cout << tx << ' ';
    }
    cout << '\n';
    exit(0);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int t;
        cin >> t;
        a[i][0] = (t & 1);
        a[i][1] = (t >> 1) & 1;
    }
    for (int i = 0; i < n - 1; ++i) {
        int t;
        cin >> t;
        b[i][0] = (t & 1);
        b[i][1] = (t >> 1) & 1;
    }

    for (int i = 0; i < n - 1; ++i) {
        int ax = a[i][0] + 2 * a[i][1];
        int bx = b[i][0] + 2 * b[i][1];
        if (ax < bx) {
            cout << "NO\n";
            exit(0);
        }   
    }
    
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            check(i, j);
        }
    }   
    
    cout << "NO\n";
    return 0;
}