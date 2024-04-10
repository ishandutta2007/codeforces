#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const ll MOD = 1e9 + 7;

struct mint {
    ll x;

    mint(ll s = 0) {
        x = s % MOD;
        if (x < 0) x += MOD;
    }

    friend mint operator+(mint s, mint t) { return mint(s.x + t.x); }
    friend mint operator-(mint s, mint t) { return mint(s.x - t.x); }
    friend mint operator*(mint s, mint t) { return mint(s.x * t.x); }
};

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

    vector<mint> sub_size(n, 1);
    vector<mint> dp1(n), dp2(n);

    function<void(int, int)> dfs1 = [&](int u, int p) {
        adj[u].erase(remove(adj[u].begin(), adj[u].end(), p), adj[u].end());

        for (int v : adj[u]) {
            dfs1(v, u);

            sub_size[u] = sub_size[u] + sub_size[v];
            dp1[u] = dp1[u] - dp1[v];
        }

        dp1[u] = dp1[u] + sub_size[u] * a[u];
    };

    function<void(int, int)> dfs2 = [&](int u, int p) {
        for (int v : adj[u]) {
            dp2[v] = (dp1[u] - sub_size[u] * a[u] + dp1[v])
                - dp2[u] + (n - sub_size[v]) * a[u];

            dfs2(v, u);
        }
    };

    dfs1(0, 0);
    dfs2(0, 0);

    mint sum = 0;
    for (int u = 0; u < n; u++) {
        sum = sum + dp1[u] - dp2[u] + (n - sub_size[u]) * a[u];
    }

    cout << sum.x << '\n';
}