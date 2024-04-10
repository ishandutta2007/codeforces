#include <bits/stdc++.h>

// Contest: Codeforces Round #591 (Div. 1, based on Technocup 2020 Elimination Round 1) (https://codeforces.com/contest/1240)
// Problem: C: Paint the Tree (https://codeforces.com/contest/1240/problem/C)

using namespace std;

using ll = int64_t;
using u64 = uint64_t;
using u32 = uint32_t;

int k;
vector<vector<pair<int, int>>> adj;

pair<ll, ll> dp(int v, int par) {
    ll child_sum = 0;
    vector<ll> edge_benefits;
    for (auto [nei, w] : adj[v]) {
        if (nei == par)
            continue;
        auto [with_edge, without_edge] = dp(nei, v);
        child_sum += without_edge;
        if (w + with_edge > without_edge)
            edge_benefits.push_back(w + with_edge - without_edge);
    }

    sort(begin(edge_benefits), end(edge_benefits), greater<>{});
    for (int i = 0; i < min(k - 1, (int)edge_benefits.size()); ++i)
        child_sum += edge_benefits[i];
    if (k <= edge_benefits.size())
        return {child_sum, child_sum + edge_benefits[k - 1]};
    return {child_sum, child_sum};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q; cin >> q;
    while (q--) {
        int n; cin >> n >> k;
        adj.resize(n);
        for (auto& r : adj)
            r.clear();
        for (int i = 0; i < n - 1; ++i) {
            int a, b, w; cin >> a >> b >> w; --a, --b;
            adj[a].emplace_back(b, w);
            adj[b].emplace_back(a, w);
        }

        auto [with, without] = dp(0, n);
        cout << without << '\n';
    }

    return 0;
}