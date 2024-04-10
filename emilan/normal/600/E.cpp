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
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> sub(n, 1);
    auto dfs_scout = [&](auto &self, int u, int p) -> void {
        if (p != -1) adj[u].erase(find(begin(adj[u]), end(adj[u]), p));
        for (int &v : adj[u]) {
            self(self, v, u);
            sub[u] += sub[v];
            if (int &w = adj[u][0]; sub[w] < sub[v]) swap(w, v);
        }
    };
    dfs_scout(dfs_scout, 0, -1);

    vector<int> cnt(n + 1);
    vector<ll> sum(n + 1);
    int mex = 1;
    auto add = [&](int u) {
        sum[ ++cnt[a[u]] ] += a[u];
        if (sum[mex] > 0) mex++;
    };
    auto rm = [&](int u) {
        sum[ cnt[a[u]]-- ] -= a[u];
        if (sum[mex - 1] == 0) mex--;
    };

    vector<ll> ans(n);
    vector<vector<int>> sub_nodes(n);
    auto dfs = [&](auto &self, int u, bool keep) -> void {
        for (int i = SZ(adj[u]) - 1; i >= 0; i--) {
            int v = adj[u][i];
            self(self, v, i == 0);
            if (i == 0) sub_nodes[u].swap(sub_nodes[v]);
        }
        sub_nodes[u].push_back(u);
        add(u);
        for (int i = 1; i < SZ(adj[u]); i++) {
            int v = adj[u][i];
            for (int w : sub_nodes[v]) {
                sub_nodes[u].push_back(w);
                add(w);
            }
            sub_nodes[v].clear();
        }

        ans[u] = sum[mex - 1];

        if (!keep) for (int w : sub_nodes[u]) rm(w);
    };
    dfs(dfs, 0, false);

    for (int u = 0; u < n; u++) {
        cout << ans[u] << " \n"[u == n - 1];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}