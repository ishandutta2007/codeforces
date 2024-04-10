#include <bits/stdc++.h>
using namespace std;
using LL = long long;
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
        if (n <= 2) {
            cout << n - 1 << "\n";
            continue;
        }
        function<int(int, int)> DFS = [&](int u, int p) {
            int res = 0, cnt = 0;
            for (int v : G[u]) if (v != p) {
                int x = DFS(v, u);
                res += x;
                cnt += not x;
            }
            return res + max(cnt - 1, 0);
        };
        int r = 1;
        for (int i = 1; i <= n; i += 1)
            if (G[i].size() > G[r].size()) r = i;
        cout << DFS(r, 0) << "\n";
    }
}