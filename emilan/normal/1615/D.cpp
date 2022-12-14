#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pii>> adj0(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj0[u].emplace_back(v, w);
        adj0[v].emplace_back(u, w);
    }

    vector<vector<pii>> adj(n);
    for (int u = 0; u < n; u++) {
        for (auto &[v, w] : adj0[u]) if (w != -1) {
            adj[u].emplace_back(v, __builtin_parity(w));
        }
    }

    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    vector<int> color(n, -1);
    bool ok = true;
    auto dfs = [&](auto &self, int u) -> void {
        for (auto [v, w] : adj[u]) {
            if (color[v] == -1) {
                color[v] = color[u] ^ w;
                self(self, v);
            } else if (color[v] != (color[u] ^ w)) {
                ok = false;
            }
        }
    };
    for (int s = 0; s < n; s++) if (color[s] == -1) {
        color[s] = 0;
        dfs(dfs, s);
    }

    if (ok) {
        map<pii, int> ans;
        auto dfs0 = [&](auto &self, int u, int p) -> void {
            for (auto [v, w] : adj0[u]) if (v != p) {
                pii key = {min(u, v), max(u, v)};
                if (!ans.count(key)) {
                    if (w != -1) ans[key] = w;
                    else ans[key] = color[u] ^ color[v];
                }
                self(self, v, u);
            }
        };
        dfs0(dfs0, 0, -1);

        cout << "yEs\n";
        for (auto [key, w] : ans) {
            auto [u, v] = key;
            cout << u + 1 << ' ' << v + 1 << ' ' << w << '\n';
        }
    } else {
        cout << "nO\n";
    }
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