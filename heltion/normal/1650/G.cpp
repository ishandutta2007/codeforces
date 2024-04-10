#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 1'000'000'007;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> G(n + 1);
        int s, t;
        cin >> s >> t;
        for (int i = 0, u, v; i < m; i += 1) {
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        auto DF = [&](int s) {
            vector<pair<int, LL>> df(n + 1, {-1, 0});
            queue<int> q;
            q.push(s);
            df[s] = {0, 1};
            while (not q.empty()) {
                int u = q.front();
                q.pop();
                for (int v : G[u]) {
                    if (df[v].first == -1) {
                        df[v].first = df[u].first + 1;
                        q.push(v);
                    }
                    if (df[v].first == df[u].first + 1)
                        df[v].second = (df[v].second + df[u].second) % mod;
                }
            }
            return df;
        };
        auto dfs = DF(s), dft = DF(t);
        LL ans = dfs[t].second;
        for (int u = 1; u <= n; u += 1)
            if (dfs[u].first + dft[u].first == dfs[t].first)
                for (int v : G[u])
                    if (dft[u].first == dft[v].first)
                        ans = (ans + dfs[u].second * dft[v].second) % mod;
        cout << ans << "\n";
    }
    return 0;
}