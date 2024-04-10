#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200;

char a[MAXN][MAXN];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) cin >> a[i][j];
    }

    int l1 = MAXN, r1 = -1, l2 = MAXN, r2 = -1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == 'B') {
                l1 = min(l1, i);
                l2 = min(l2, j);
                r1 = max(r1, i);
                r2 = max(r2, j);
            }
        }
    }
    
    cout << (l1 + r1) / 2 + 1 << ' ' << (l2 + r2) / 2 + 1 << '\n';
    return 0;
}