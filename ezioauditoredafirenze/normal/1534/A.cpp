#include <bits/stdc++.h>

using namespace std;

#define debug(...) fprintf(stderr, __VA_ARGS__)
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define SZ(x)(int((x).size()))
#define ALL(x)(x).begin(), (x).end()

template <typename T> inline bool chkmin(T & a,
    const T & b) {
    return b < a ? a = b, 1 : 0;
}
template <typename T> inline bool chkmax(T & a,
    const T & b) {
    return a < b ? a = b, 1 : 0;
}

typedef long long LL;

const LL infinity = 0x3f3f3f3f3f3f3f3f;
const LL mod = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    char g[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }
    char mat[n][m][2];
    for (int k = 0; k < 2; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                mat[i][j][k] = (k == 0 ? (i + j) % 2 == 0 ? 'R' : 'W' : (i + j) % 2 == 0 ? 'W' : 'R');
            }
        }
    }
    for (int k = 0; k < 2; k++) {
        bool clear = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (g[i][j] != '.') {
                    clear &= g[i][j] == mat[i][j][k];
                }
            }
        }
        if (clear) {
            cout << "YES\n";
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    cout << mat[i][j][k] << (j == m - 1 ? "\n" : "");
                }
            }
            return;
        }
    }
    cout << "NO\n";
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}