#include <bits/stdc++.h>
using namespace std;
struct P{
    int x, y;
};
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> G(n), H(n);
        for (int i = 0, u, v; i < m; i += 1) {
            cin >> u >> v;
            u -= 1;
            v -= 1;
            G[u].push_back(v);
            H[v].push_back(u);
        }
        vector<int> order, id(n);
        function<void(int)> dfs1 = [&](int u){
            id[u] = -1;
            for (int v : H[u])
                if (not id[v])
                    dfs1(v);
            order.push_back(u);
        };
        for (int i = 0; i < n; i += 1) if (not id[i]) dfs1(i);
        reverse(order.begin(), order.end());
        int count = 0;
        function<void(int)> dfs2 = [&](int u){
            id[u] = count;
            for (int v : G[u])
                if (not ~id[v])
                    dfs2(v);
        };
        for (int i : order) if (not ~id[i]) {
            dfs2(i);
            count += 1;
        }
        vector<vector<int>> g(count);
        for (int i = 0; i < n; i += 1)
            for (int j : G[i]) {
                g[id[i]].push_back(id[j]);
                assert(id[i] >= id[j]);
            }
        vector<int> dp(count);
        for (int i = id[0]; i >= 0; i -= 1) {
            if (i == id[0]) dp[i] = 1;
            if (dp[i]) {
                for (int j : g[i]) if (j == i) dp[i] = -1;
            }
            for (int j : g[i]) {
                if (dp[i] == -1) dp[j] = -1;
                if (dp[i] == 2 and dp[j] != -1) dp[j] = 2;
                if (dp[i] == 1 and dp[j] != -1 and dp[j] <= 1) dp[j] += 1;
            } 
        }
        for (int i = 0; i < n; i += 1) cout << dp[id[i]] << " ";
        cout << "\n";
    }
    return 0;
}