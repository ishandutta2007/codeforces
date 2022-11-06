#include <bits/stdc++.h>

// Contest: Codeforces Round #588 (Div. 1) (https://codeforces.com/contest/1229)
// Problem: B: Kamil and Making a Stream (https://codeforces.com/contest/1229/problem/B)

using namespace std;

using ll = int64_t;
using u64 = uint64_t;
using u32 = uint32_t;

ll M = 1e9 + 7;

vector<vector<int>> adj;
vector<ll> vals;

ll dfs(int v, int par, map<ll, ll> gcd) {
    ll res = 0;
    for (auto [a, b] : gcd)
        res = (res + a * b % M) % M;
    for (auto v2 : adj[v]) {
        if (v2 == par)
            continue;
        map<ll, ll> gcd2;
        gcd2.emplace(vals[v2], 1);
        for (auto [a, b] : gcd)
            gcd2[::gcd(a, vals[v2])] += b;
        res = (res + dfs(v2, v, gcd2)) % M;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    adj.resize(n); vals.resize(n);
    for (auto& vi : vals) cin >> vi;
    for (int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b; --a, --b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }

    map<ll, ll> m; m[vals[0]] = 1;
    cout << dfs(0, n, m) << '\n';

    return 0;
}