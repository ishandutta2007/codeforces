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

#define die return cout << "INVALID", 0

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;
    vt<vt<pii>> dest(n, vt<pii>(n));
    for (auto &i : dest) for (pii &j : i) {
        cin >> j.fi >> j.se;
        if (j.fi != -1) j.fi--, j.se--;
    }

    vt<vt<bool>> vis(n, vt<bool>(n));
    vt<vt<char>> ans(n, vt<char>(n));
    function<void(int, int, int, int)> dfs = 
    [&](int x, int y, int sx, int sy) {
        vis[x][y] = true;

        const auto visit = [&](int x, int y, char c) {
            if (x < 0 || y < 0 || x >= n || y >= n ||
                    vis[x][y]) return;
            pii d = dest[x][y];
            if (d.fi != sx || d.se != sy) return;

            ans[x][y] = c;
            dfs(x, y, sx, sy);
        };

        visit(x + 1, y, 'U');
        visit(x - 1, y, 'D');
        visit(x, y + 1, 'L');
        visit(x, y - 1, 'R');
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (vis[i][j] || dest[i][j].fi != -1) continue;

            bool d = i != n - 1 && dest[i + 1][j].fi == -1,
                 r = j != n - 1 && dest[i][j + 1].fi == -1;
            if (d || r) {
                if (d) ans[i][j] = 'D';
                else ans[i][j] = 'R';

                dfs(i, j, -1, -1);
            } else die;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            pii d = dest[i][j];
            if (d.fi != i || d.se != j) continue;

            ans[i][j] = 'X';
            dfs(i, j, i, j);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!ans[i][j]) die;
        }
    }

    cout << "VALID\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j];
        }
        cout << '\n';
    }
}