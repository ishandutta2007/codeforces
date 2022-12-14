#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    using P = pair<int, int>;
    vector<vector<P>> adj(n);
    while (m--) {
        int u, v;
        string ident;
        cin >> u >> v >> ident;
        u--, v--;
        adj[u].emplace_back(v, ident == "imposter");
        adj[v].emplace_back(u, ident == "imposter");
    }

    int ans = 0;
    bool bad = false;
    vector<int> color(n, -1);
    for (int s = 0; s < n; s++) if (color[s] == -1) {
        int cnt[2] = {};
        auto dfs = [&](auto &self, int u) -> void {
            cnt[ color[u] ]++;
            for (auto [v, w] : adj[u]) {
                int nc = color[u] ^ w;
                if (color[v] == -1) {
                    color[v] = nc;
                    self(self, v);
                } else if (color[v] != nc) {
                    bad = true;
                }
            }
        };
        color[s] = 0;
        dfs(dfs, s);
        ans += max(cnt[0], cnt[1]);
    }
    if (bad) cout << -1;
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