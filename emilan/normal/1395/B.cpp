#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define vt          vector
#define sz(x)       (int)(x).size()
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, m, sx, sy;
    cin >> n >> m >> sx >> sy;

    cout << sx << ' ' << sy << '\n';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!i && (j == sy - 1)) continue;

            cout << (sx + i - 1) % n + 1 << ' ';
            if (i & 1) cout << m - j << '\n';
            else cout << j + 1 << '\n';
        }
    }
}