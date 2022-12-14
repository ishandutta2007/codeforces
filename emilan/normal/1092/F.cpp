#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ll sum = accumulate(a.begin(), a.end(), 0ll);

    vector<ll> sub_a(a.begin(), a.end());
    vector<ll> dp1(n), dp2(n);

    function<void(int, int)> dfs1 = [&](int u, int p) {
        adj[u].erase(remove(adj[u].begin(), adj[u].end(), p), adj[u].end());

        for (int v : adj[u]) {
            dfs1(v, u);

            sub_a[u] += sub_a[v];
            dp1[u] += dp1[v] + sub_a[v];
        }
    };

    function<void(int)> dfs2 = [&](int u) {
        for (int v : adj[u]) {
            dp2[v] = (dp1[u] - (dp1[v] + sub_a[v]))
                + (dp2[u] + (sum - sub_a[u]));

            dfs2(v);
        }
    };

    dfs1(0, 0);
    dfs2(0);

    ll ans = 0;
    for (int u = 0; u < n; u++) {
        ans = max(ans, dp1[u] + dp2[u] + (sum - sub_a[u]));
    }
    cout << ans << '\n';
}