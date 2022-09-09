#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        vector<vector<int>> G(n + 1);
        for (int i = 1, u, v; i < n; i += 1) {
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        vector<int> p(n + 1), size(n + 1), dp(n + 1);
        function<void(int)> DFS = [&](int u) {
            size[u] = 1;
            vector<int> s;
            for (int v : G[u]) if (v != p[u]) {
                p[v] = u;
                DFS(v);
                s.push_back(v);
                size[u] += size[v];
            }
            if (s.size() == 1) dp[u] = size[s[0]] - 1;
            if (s.size() == 2) dp[u] = max(dp[s[0]] + size[s[1]] - 1, dp[s[1]] + size[s[0]] - 1);
        };
        DFS(1);
        cout << dp[1] << "\n";
    }
    return 0;
}