#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

#define rep(i, n)   for (int i = 0; i < (n); i++)
#define sz(x)       (int)(x).size()
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

vector<pii> adj{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

struct State {
    int x, y, color, d;
};

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, m, t;
    cin >> n >> m >> t;
    vector<string> v(n);
    for (auto& i : v) cin >> i;

    vector<vector<pii>> a(n, vector<pii>(m, {-1, -1}));
    queue<State> q;
    function<void(int, int)> dfs = [&] (int x, int y) {
        for (auto& d : adj) {
            int i = x + d.fi, j = y + d.se;
            if (i == -1 || j == -1 || i == n || j == m) continue;
            if (a[i][j].se != -1) continue;

            if (v[i][j] == v[x][y]) {
                if (a[x][y].fi == -1) {
                    a[x][y].fi = 0;
                    q.push({x, y, a[x][y].se, 0});
                }
                a[i][j] = a[x][y];
                q.push({i, j, a[i][j].se, 0});
                dfs(i, j);
            }
        }
    };
    rep(i, n) rep(j, m) {
        if (a[i][j].se == -1) {
            a[i][j].se = v[i][j] == '1';
            dfs(i, j);
        }
    }

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        for (auto& d : adj) {
            int i = cur.x + d.fi, j = cur.y + d.se;
            if (i == -1 || j == -1 || i == n || j == m) continue;
            if (a[i][j] != pii{-1, cur.color ^ 1}) continue;

            a[i][j] = {cur.d + 1, a[cur.x][cur.y].se};
            q.push({i, j, cur.color ^ 1, cur.d + 1});
        }
    }

    while (t--) {
        ll x, y, p;
        cin >> x >> y >> p;
        x--, y--;

        if (a[x][y].fi != -1 && p >= a[x][y].fi)
            cout << (a[x][y].se ^ (p & 1));
        else cout << (v[x][y] == '1');
        cout << '\n';
    }
}