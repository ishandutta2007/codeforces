#include <bits/stdc++.h>

// Contest: Codeforces Round #586 (Div. 1 + Div. 2) (https://codeforces.com/contest/1220)
// Problem: E: Tourism (https://codeforces.com/contest/1220/problem/E)

using namespace std;

using ll = int64_t;
using u64 = uint64_t;
using u32 = uint32_t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<ll> w(n);
    for (auto& wi : w) cin >> wi;
    ll wsum = accumulate(begin(w), end(w), (ll)0);

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b; --a; --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int s; cin >> s; --s;
    vector<int> deg(n);
    for (int i = 0; i < n; ++i)
        deg[i] = adj[i].size();

    vector<ll> best_tree(n);
    vector<int> z;
    for (int i = 0; i < n; ++i)
        if (i != s && deg[i] == 1)
            z.push_back(i);

    while (!z.empty()) {
        auto v = z.back(); z.pop_back();
        for (auto v2 : adj[v]) {
            if (deg[v2] == 0)
                continue;
            best_tree[v2] = max(best_tree[v2], best_tree[v] + w[v]);
            wsum -= w[v];
            deg[v2]--;
            deg[v] = 0;
            if (v2 != s && deg[v2] == 1)
                z.push_back(v2);
        }
    }

    cout << (wsum + *max_element(begin(best_tree), end(best_tree))) << '\n';

    return 0;
}