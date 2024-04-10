#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> G(n + 1), H(n + 1);
    for (int i = 0, u, v, w; i < m; i += 1) {
        cin >> u >> v >> w;
        G[u].emplace_back(v, w);
        H[v].emplace_back(u, w);
    }
    vector<LL> d(n + 1, -1);
    d[1] = 0;
    auto relax = [&](vector<vector<pair<int, int>>>& G) {
        priority_queue<pair<LL, int>> pq;
        for (int i = 1; i <= n; i += 1)
            if (d[i] != -1) pq.emplace(-d[i], i);
        while (not pq.empty()) {
            auto [du, u] = pq.top();
            pq.pop();
            if (d[u] < -du) continue;
            for (auto [v, w] : G[u])
                if (d[v] == -1 or d[v] > d[u] + w)
                    pq.emplace(-(d[v] = d[u] + w), v);
        }
    };
    relax(G);
    relax(H);
    for (int i = 2; i <= n; i += 1) cout << d[i] << " ";
}