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
    int n, q;
    cin >> n >> q;
    vector<vector<int>> chi(n);
    for (int u = 1; u < n; u++) {
        int p;
        cin >> p;
        chi[p - 1].push_back(u);
    }
    string s;
    cin >> s;

    vector<vector<pii>> tasks(n);
    for (int i = 0; i < q; i++) {
        int u, d;
        cin >> u >> d;
        tasks[u - 1].emplace_back(d - 1, i);
    }

    vector<int> sub(n, 1), depth(n);
    auto dfs_scout = [&](auto &self, int u) -> void {
        for (int &v : chi[u]) {
            depth[v] = depth[u] + 1;
            self(self, v);
            sub[u] += sub[v];
            if (int &w = chi[u][0]; sub[w] < sub[v]) swap(w, v);
        }
    };
    dfs_scout(dfs_scout, 0);

    vector<bitset<26>> depth_parity(n);
    vector<bool> ans(q);
    auto update = [&](int u) {
        depth_parity[ depth[u] ].flip(s[u] - 'a');
    };

    vector<vector<int>> sub_nodes(n);
    auto dfs = [&](auto &self, int u, bool keep) -> void {
        for (int i = SZ(chi[u]) - 1; i >= 0; i--) {
            int v = chi[u][i];
            self(self, v, i == 0);
            if (i == 0) sub_nodes[u].swap(sub_nodes[v]);
        }
        sub_nodes[u].push_back(u);
        update(u);
        for (int i = 1; i < SZ(chi[u]); i++) {
            int v = chi[u][i];
            for (int w : sub_nodes[v]) {
                sub_nodes[u].push_back(w);
                update(w);
            }
            sub_nodes[v].clear();
        }

        for (auto [d, i] : tasks[u]) {
            ans[i] = depth_parity[d].count() <= 1;
        }

        if (!keep) for (int w : sub_nodes[u]) update(w);
    };
    dfs(dfs, 0, false);

    for (bool x : ans) cout << (x ? "Yes" : "No") << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}