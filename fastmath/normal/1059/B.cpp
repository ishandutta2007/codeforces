#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1007;

int n, m;
char a[MAXN][MAXN];

void read() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
}

char b[MAXN][MAXN];
void solve() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            b[i][j] = '.';
        }
    }

    for (int i = 0; i + 2 < n; ++i) {
        for (int j = 0; j + 2 < m; ++j) {
            if (a[i][j] == '#' && a[i][j + 1] == '#' && a[i][j + 2] == '#' && a[i + 1][j] == '#' && a[i + 1][j + 2] == '#' && a[i + 2][j] == '#' && a[i + 2][j + 1] == '#' && a[i + 2][j + 2] == '#') {
                b[i][j] = b[i][j + 1] = b[i][j + 2] = b[i + 1][j] = b[i + 1][j + 2] = b[i + 2][j] = b[i + 2][j + 1] = b[i + 2][j + 2] = '#';                
            }
        }
    }   
}

void print() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] != b[i][j]) {
                cout << "NO\n";
                exit(0);
            }
        }
    }
    cout << "YES\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    read();
    solve();
    print();

    return 0;
}