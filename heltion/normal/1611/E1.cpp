#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    for (cin >> t; t; t -= 1) {
        int n, k;
        cin >> n >> k;
        vector<int> d(n + 1, n + 1);
        vector<vector<int>> G(n + 1);
        queue<int> q;
        for (int i = 0, x; i < k; i += 1) {
            cin >> x;
            d[x] = 0;
            q.push(x);
        }
        for (int i = 1, u, v; i < n; i += 1) {
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        while (not q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : G[u]) if (d[v] > d[u] + 1) {
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
        int ok = 0;
        function<void(int, int, int)> dfs = [&](int u, int p, int dp) {
            if (dp >= d[u]) return;
            if (u != 1 and G[u].size() == 1) ok = 1;
            for (int v : G[u]) if (v != p)
                dfs(v, u, dp + 1);
        };
        dfs(1, 0, 0);
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}