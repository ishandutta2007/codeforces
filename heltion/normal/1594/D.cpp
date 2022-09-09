#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr  LL mod = 1'000'000'007;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, m;
        cin >> n >> m;
        vector<vector<pair<int, int>>> G(n);
        for (int i = 0; i < m; i += 1) {
            int u, v, c;
            string sc;
            cin >> u >> v >> sc;
            u -= 1;
            v -= 1;
            c = sc[0] == 'i';
            G[u].push_back({v, c});
            G[v].push_back({u, c});
        }
        vector<int> vis(n, -1);
        int ok = 1, ans = 0;
        function<vector<int>(int, int)> dfs = [&](int u, int c) {
            vector<int> p(2);
            vis[u] = c;
            p[c] += 1;
            for (auto [v, w] : G[u]) {
                if (vis[v] == -1){
                    auto q = dfs(v, c ^ w);
                    for (int i : {0, 1}) p[i] += q[i];
                }
                else if((c ^ w) != vis[v]) ok = 0;
            }
            return p;
        };
        for (int i = 0; i < n and ok; i += 1)
            if (vis[i] == -1) {
                auto v = dfs(i, 0);
                ans += max(v[0], v[1]);
            }
        cout << (ok ? ans : -1) << "\n";
    }
    return 0;
}