#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<pii>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v, i);
        adj[v].emplace_back(u, i);
    }

    vector<int> level(n + 1);
    vector<int> bri(n + 1);
    vector<pii> ans(m);
    
    auto dfs = [&](int u, auto &f) -> void {
        for (auto &[v, i] : adj[u]) {
            if (ans[i].first == 0) ans[i] = {u, v};

            if (level[v] == 0) {
                level[v] = level[u] + 1;

                f(v, f);

                bri[u] += bri[v];
                bri[v]--;
            } else if (level[v] < level[u]) {
                bri[u]++;
                bri[v]--;
            }
        }
    };

    level[1] = 1;
    dfs(1, dfs);

    if (count(bri.begin() + 2, bri.end(), 0)) cout << 0;
    else for (pii &p : ans) cout << p.first << ' ' << p.second << '\n';
}