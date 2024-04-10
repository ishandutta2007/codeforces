#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> in(n + 1), out(n + 1), dp(n + 1, 1);
    vector<vector<int>> G(n + 1);
    for (int i = 0, u, v; i < m; i += 1) {
        cin >> u >> v;
        G[u].push_back(v);
        in[v] += 1;
        out[u] += 1;
    }
    auto d = in;
    queue<int> q;
    for (int i = 1; i <= n; i += 1)
        if (not d[i]) q.push(i);
    while (not q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : G[u]) {
            if (in[v] > 1 and out[u] > 1)
                dp[v] = max(dp[v], dp[u] + 1);
            if (not (d[v] -= 1))
                q.push(v);
        }
    }
    cout << ranges::max(dp);
}