#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    while (m--) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> vis(n + 1);
    vector<vector<int>> depth(n);
    auto dfs = [&](int u, int d, auto &f) -> bool {
        vis[u] = true;
        depth[d].push_back(u);

        if (d + 1 >= (n + 1) / 2) {
            cout << "PATH\n";
            cout << d + 1 << '\n';
            cout << u << ' ';

            return true;
        }

        for (int v : adj[u]) if (!vis[v]) {
            if (f(v, d + 1, f)) {
                cout << u << ' ';

                return true;
            }
        }

        return false;
    };

    if (dfs(1, 0, dfs)) {
        cout << '\n';
        return;
    }

    vector<pii> ans;
    for (auto &v : depth) {
        for (int i = 0; i + 1 < v.size(); i += 2) {
            ans.emplace_back(v[i], v[i + 1]);
        }
    }

    cout << "PAIRING\n";
    cout << ans.size() << '\n';
    for (pii &p : ans) cout << p.first << ' ' << p.second << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}