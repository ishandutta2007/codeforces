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

#define die return cout << -1, void()

vt<pii> adj{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void solve(int tc) {
    int n, m;
    cin >> n >> m;
    vt<string> v(n);
    for (auto &i : v) cin >> i;

    bool emptyRow = false, emptyColumn = false;
    for (int i = 0; i < n; i++) {
        int has = v[i][0] == '#';
        for (int j = 1; j < m; j++) {
            if (v[i][j - 1] == '.' && v[i][j] == '#') {
                if (has) die;
                has = true;
            }
        }
        if (!has) emptyRow = true;
    }
    for (int i = 0; i < m; i++) {
        int has = v[0][i] == '#';
        for (int j = 1; j < n; j++) {
            if (v[j - 1][i] == '.' && v[j][i] == '#') {
                if (has) die;
                has = true;
            }
        }
        if (!has) emptyColumn = true;
    }

    if (emptyRow != emptyColumn) die;

    int cnt = 0;
    function<void(int, int)> dfs = [&](int x, int y) {
        for (pii &i : adj) {
            int _x = x + i.fi, _y = y + i.se;
            if (_x == -1 || _y == -1 || _x == n || _y == m) continue;
            if (v[_x][_y] == '.') continue;
            v[_x][_y] = '.';
            dfs(_x, _y);
        }
    };
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        if (v[i][j] == '#') {
            v[i][j] = '.';
            dfs(i, j);
            cnt++;
        }
    }

    cout << cnt;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) solve(tc);
}