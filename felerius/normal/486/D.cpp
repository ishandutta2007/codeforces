#include <bits/stdc++.h>

// Contest: 21 - Codeforces Rating >= 2200 (https://a2oj.com/ladder?ID=21)
// Problem: (26) Valid Sets (Difficulty: 5) (http://codeforces.com/problemset/problem/486/D)

using namespace std;

using ll = int64_t;
using u64 = uint64_t;
using u32 = uint32_t;

ll M = 1e9 + 7;

int d, n;
vector<int> a;
vector<vector<int>> adj;

ll dfs(int v, int par, int vmax) {
    ll r = 1;
    for (auto nei : adj[v]) {
        if (nei == par || pair(a[nei], nei) > pair(a[vmax], vmax) || a[nei] + d < a[vmax])
            continue;
        r *= (dfs(nei, v, vmax) + 1);
        r %= M;
    }

    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> d >> n;
    a.resize(n);
    for (auto& ai : a) cin >> ai;

    adj.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v; cin >> u >> v; --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ll r = 0;
    for (int i = 0; i < n; ++i) {
        r += dfs(i, n, i);
        r %= M;
    }

    cout << r << '\n';
    return 0;
}