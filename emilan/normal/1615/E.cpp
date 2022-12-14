#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> depth(n);
    vector<int> par(n);
    auto dfs = [&](auto &self, int u, int p) -> void {
        for (int v : adj[u]) if (v != p) {
            depth[v] = depth[u] + 1;
            par[v] = u;
            self(self, v, u);
        }
    };
    par[0] = -1;
    dfs(dfs, 0, -1);

    auto cmp = [&](int u, int v) { return depth[u] > depth[v]; };
    vector<int> seq(n);
    iota(seq.begin(), seq.end(), 0);
    sort(seq.begin(), seq.end(), cmp);

    vector<int> del_cnt(n);
    vector<bool> vis(n);
    for (int u : seq) {
        for (int v = u; v != -1 && !vis[v]; v = par[v]) {
            vis[v] = true;
            del_cnt[u]++;
        }
    }

    i64 ans = LLONG_MIN;
    sort(del_cnt.rbegin(), del_cnt.rend());
    for (int r = 0, del = 0; r <= k; r++) {
        int b = min(n - del, n / 2);
        ans = max(ans, i64(n - r - b) * (r - b));
        if (r < k) del += del_cnt[r];
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}