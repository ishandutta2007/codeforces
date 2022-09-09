#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, k, x, y;
        cin >> n >> k >> x >> y;
        vector<int> a(k);
        for (int& ai : a) cin >> ai;
        vector<vector<int>> G(n + 1);
        for (int i = 1, u, v; i < n; i += 1) {
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        function<pair<vector<int>, vector<int>>(int)> BFS = [&](int s) {
            vector<int> p(n + 1), d(n + 1);
            queue<int> q;
            q.push(s);
            while (not q.empty()) {
                int u = q.front();
                q.pop();
                for (int v : G[u])
                    if (v != p[u]) {
                        p[v] = u;
                        d[v] = d[u] + 1;
                        q.push(v);
                    }
            }
            return make_pair(p, d);
        };
        auto [px, dx] = BFS(x);
        auto [py, dy] = BFS(y);
        vector<int> v(n + 1);
        v[x] = 1;
        int ans = 0, ans2 = n;
        for (int ai : a)
            for (int j = ai; not v[j]; j = px[j]) {
                v[j] = 1;
                ans += 1;
            }
        for (int ai : a)
            ans2 = min(ans2, dy[ai] - dx[ai]);
        cout << ans * 2 + ans2 << "\n";
    }
}