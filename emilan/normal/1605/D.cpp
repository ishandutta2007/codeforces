#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << "1\n";
        return;
    }

    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> par(n + 1);
    vector<int> odd, even;
    function<void(int, int)> dfs = [&](int u, int p) {
        if (par[u] == 1) odd.push_back(u);
        else even.push_back(u);

        for (int v : adj[u]) if (v != p) {
            par[v] = par[u] ^ 1;
            dfs(v, u);
        }
    };
    dfs(1, 1);

    if (odd.size() > even.size()) swap(odd, even);
    int m = odd.size();
    vector<int> ans_odd, ans_even;
    for (int k = 0; k <= __lg(m); k++) {
        vector<int> g(1 << k);
        iota(g.begin(), g.end(), 1 << k);
        if (m >> k & 1) {
            ans_odd.insert(ans_odd.end(), g.begin(), g.end());
        } else {
            ans_even.insert(ans_even.end(), g.begin(), g.end());
        }
    }
    {
        vector<int> g(n - (2 << __lg(m)) + 1);
        iota(g.begin(), g.end(), 2 << __lg(m));
        ans_even.insert(ans_even.end(), g.begin(), g.end());
    }

    vector<int> ans(n + 1);
    for (int i = 0; i < m; i++) {
        ans[ odd[i] ] = ans_odd[i];
    }
    for (int i = 0; i < n - m; i++) {
        ans[ even[i] ] = ans_even[i];
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
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