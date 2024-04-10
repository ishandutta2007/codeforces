#include <bits/stdc++.h>

using namespace std;

template <typename T, typename U>
vector<T> rerooting_no_ew(
        const vector<U> &a,
        vector<vector<int>> adj,
        function<T(const T &, const T &)> aggr,
        function<T(const T &, const U &)> comb,
        const T &dp_id = T()) {
    int n = int(size(a));

    vector<int> par(n);
    vector<T> dp1(n, dp_id);
    auto dfs1 = [&](auto &self, int u) -> void {
        if (u != 0) {
            adj[u].erase(find(begin(adj[u]), end(adj[u]), par[u]));
        }
        for (int v : adj[u]) {
            par[v] = u;
            self(self, v);
            dp1[u] = aggr(dp1[u], comb(dp1[v], a[v]));
        }
    };
    dfs1(dfs1, 0);

    vector<T> dp2(n, dp_id);
    auto dfs2 = [&](auto &self, int u) -> void {
        int m = int(size(adj[u]));
        vector<T> dp_chi(m, dp_id);
        for (int i = 0; i < m; i++) {
            int v = adj[u][i];
            dp_chi[i] = comb(dp1[v], a[v]);
        }

        vector<T> pre(m + 1, dp_id), suf(m + 1, dp_id);
        pre[0] = dp2[u];
        for (int i = 0; i < m - 1; i++) {
            pre[i + 1] = aggr(pre[i], dp_chi[i]);
        }
        for (int i = m - 1; i > 0; i--) {
            suf[i] = aggr(suf[i + 1], dp_chi[i]);
        }

        for (int i = 0; i < m; i++) {
            int v = adj[u][i];
            dp2[v] = comb(aggr(pre[i], suf[i + 1]), a[u]);
            self(self, v);
        }
    };
    dfs2(dfs2, 0);

    vector<T> ans(n, dp_id);
    for (int u = 0; u < n; u++) {
        ans[u] = aggr(dp1[u], dp2[u]);
    }
    return ans;
}

using ll = long long;
using pii = pair<int, int>;

using pil = pair<int, ll>;

pil dp_aggr(const pil &p, const pil &q) {
    return {p.first + q.first, p.second + q.second};
}

pil dp_comb(const pil &p, int) {
    return {p.first + 1, p.second + p.first + 1};
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    auto res = rerooting_no_ew<pil, int>(
            vector<int>(n), adj, dp_aggr, dp_comb);
    ll ans = 0;
    for (auto &x : res) {
        ans = max(ans, x.second);
    }
    cout << ans + n << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}