#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 1'000'000'007;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        vector<int> a(n + 1), b(n + 1), c(n + 1), d(n + 1), vis(n + 1);
        for (int i = 1; i <= n; i += 1) cin >> a[i];
        for (int i = 1; i <= n; i += 1) cin >> b[i];
        for (int i = 1; i <= n; i += 1) cin >> c[i];
        vector<vector<int>> G(n + 1);
        for (int i = 1; i <= n; i += 1)
            if (c[i]) {
                G[c[i]].push_back(c[i]);
                d[c[i]] += 2;
            }
            else {
                G[a[i]].push_back(b[i]);
                G[b[i]].push_back(a[i]);
                d[a[i]] += 1;
                d[b[i]] += 1;
            }
        LL ans = 1;
        for (int i = 1; i <= n; i += 1) if (not vis[i]) {
            int x = 0, y = 0, z = 2;
            queue<int> q;
            q.push(i);
            while (not q.empty()) {
                int u = q.front();
                q.pop();
                vis[u] = 1;
                x += 1;
                y += d[u];
                for (int v : G[u]) {
                    if (v == u) z = 1;
                    if (not vis[v])
                        q.push(v);
                }
            }
            if (x * 2 != y) ans = 0;
            else ans = ans * z % mod;
        }
        cout << ans << "\n";
    }
}