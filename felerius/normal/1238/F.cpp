#include <bits/stdc++.h>

// Contest: Educational Codeforces Round 74 (Rated for Div. 2) (https://codeforces.com/contest/1238)
// Problem: F: The Maximum Subtree (https://codeforces.com/contest/1238/problem/F)

using namespace std;

using ll = int64_t;
using u64 = uint64_t;
using u32 = uint32_t;

pair<ll, ll> dfs(int v, int par, vector<vector<int>>& adj) {
    array<ll, 2> best_subs = {0, 0};
    ll best_sub_self = 0;
    for (auto nei : adj[v]) {
        if (nei == par)
            continue;
        auto [sub, sub_self] = dfs(nei, v, adj);
        best_sub_self = max(best_sub_self, sub_self);
        if (sub > best_subs[0])
            best_subs = {sub, best_subs[0]};
        else if (sub > best_subs[1])
            best_subs[1] = sub;
    }

    ll child_count = adj[v].size() - (par == adj.size() ? 0 : 1);
    ll best_self = best_subs[0] + best_subs[1] + 1 + max((int)adj[v].size() - 2, 0);
    ll best_path = child_count == 0 ? 1 : best_subs[0] + child_count;
    return {best_path, max(best_self, best_sub_self)};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q; cin >> q;
    while (q--) {
        int n; cin >> n;
        vector<vector<int>> adj(n);
        for (int i = 0; i < n - 1; ++i) {
            int u, v; cin >> u >> v; --u, --v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        auto [_, res] = dfs(0, n, adj);
        cout << res << '\n';
    }

    return 0;
}