#include <bits/stdc++.h>

// Contest: 20 - 2100 <= Codeforces Rating <= 2199 (https://a2oj.com/ladder?ID=20)
// Problem: (52) Jzzhu and Cities (Difficulty: 5) (http://codeforces.com/problemset/problem/449/B)

using namespace std;

using ll = int64_t;
using u64 = uint64_t;
using u32 = uint32_t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k; cin >> n >> m >> k;
    vector<vector<pair<int,int>>> adj(n);
    vector<pair<int,int>> trains(k);
    for (int i = 0; i < m; ++i) {
        int a, b, l; cin >> a >> b >> l; --a; --b;
        adj[a].emplace_back(b, l);
        adj[b].emplace_back(a, l);
    }
    for (int i = 0; i < k; ++i) {
        int a, l; cin >> a >> l; --a;
        trains[i] = {a, l};
        adj[0].emplace_back(a, l);
        adj[a].emplace_back(0, l);
    }

    vector<ll> dist(n, (ll)1e18 + 1);
    dist[0] = 0;
    priority_queue<pair<ll, int>> q;
    q.emplace(0, 0);
    while (!q.empty()) {
        auto [d, v] = q.top(); q.pop();
        d = -d;
        if (dist[v] < d)
            continue;
        for (auto [v2, l] : adj[v]) {
            if (d + l < dist[v2]) {
                dist[v2] = d + l;
                q.emplace(-d - l, v2);
            }
        }
    }

    int res = 0;
    vector<int> in_deg(n);
    for (int i = 0; i < n; ++i)
        for (auto [v, l] : adj[i])
            in_deg[i] += dist[v] + l == dist[i];

    for (auto [v, l] : trains) {
        if (l > dist[v]) {
            ++res; continue;
        }

        if (in_deg[v] > 1) {
            ++res;
            --in_deg[v];
        }
    }

    cout << res << '\n';

    return 0;
}