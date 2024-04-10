#include <bits/stdc++.h>

using namespace std;

#define SZ(a)   int(size(a))
#define ALL(a)  begin(a), end(a)
#define RALL(a) rbegin(a), rend(a)

using ll = long long;
using i128 = __int128_t;
using ld = long double;
using pii = pair<int, int>;

void solve() {
    int n, t;
    cin >> n >> t;
    t--;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> depth(n);
    auto dfs0 = [&](auto &self, int u, int p) -> void {
        for (int v : adj[u]) if (v != p) {
            depth[v] = depth[u] + 1;
            self(self, v, u);
        }
    };
    dfs0(dfs0, 0, -1);

    int ans = 0;
    auto dfs = [&](auto &self, int u, int p, int d) -> void {
        ans = max(ans, 2 * depth[u]);
        if (d < depth[u]) {
            for (int v : adj[u]) if (v != p) {
                self(self, v, u, d + 1);
            }
        }
    };
    dfs(dfs, t, -1, 0);

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}