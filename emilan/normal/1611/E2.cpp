#include <bits/stdc++.h>

using namespace std;

#define REP(i, n)   for (int i = 0; (i) < (n); (i)++)
#define REP1(i, n)  for (int i = 1; (i) <= (n); (i)++)
#define SZ(a)       int(size(a))
#define ALL(a)      begin(a), end(a)
#define RALL(a)     rbegin(a), rend(a)

using uint = unsigned;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128_t;
using u128 = __uint128_t;
using ld = long double;
using pii = pair<int, int>;

const int kK = 20;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (auto &x : a) cin >> x, x--;
    vector<vector<int>> adj(n);
    REP(i, n - 1) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    array<vector<int>, kK> par;
    par.fill(vector<int>(n));
    vector<int> depth(n);
    auto dfs0 = [&](auto &self, int u) -> void {
        for (int v : adj[u]) if (v != par[0][u]) {
            par[0][v] = u;
            depth[v] = depth[u] + 1;
            self(self, v);
        }
    };
    dfs0(dfs0, 0);

    REP(k, kK - 1) REP(u, n) par[k + 1][u] = par[k][par[k][u]];

    vector<bool> die(n);
    for (int u : a) {
        int up = depth[u] / 2;
        for (int k = kK - 1; k >= 0; k--) if (up >> k & 1) {
            u = par[k][u];
        }
        die[u] = true;
    }

    int ans = 0;
    auto dfs = [&](auto &self, int u) -> void {
        if (die[u]) return ans++, void();
        if (u != 0 && SZ(adj[u]) == 1) return ans = m + 1, void();

        for (int v : adj[u]) if (v != par[0][u]) {
            self(self, v);
        }
    };
    dfs(dfs, 0);

    if (ans > m) cout << -1;
    else cout << ans;
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}