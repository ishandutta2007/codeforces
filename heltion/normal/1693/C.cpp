#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n + 1);
    vector<int> d(n + 1, m), cnt(n + 1), done(n + 1);
    for (int i = 0, u, v; i < m; i += 1) {
        cin >> u >> v;
        G[v].push_back(u);
        cnt[u] += 1;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.emplace(d[n] = 0, n);
    while (not q.empty()) {
        int u = q.top().second;
        q.pop();
        if (done[u]) continue;
        done[u] = 1;
        for (int v : G[u]) {
            if (d[v] > d[u] + cnt[v])
                q.emplace(d[v] = d[u] + cnt[v], v);
            cnt[v] -= 1;
        }
    }
    cout << d[1];
}