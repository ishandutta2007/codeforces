#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    LL k;
    cin >> n >> m >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i += 1) cin >> a[i];
    vector<vector<int>> G(n + 1);
    for (int i = 0, u, v; i < m; i += 1) {
        cin >> u >> v;
        G[u].push_back(v);
    }
    auto s = a;
    ranges::sort(s);
    int L = 1, R = n + 1;
    while (L < R) {
        int M = (L + R) / 2, c = 0;
        vector<int> d(n + 1), dp(n + 1, 1), q;
        for (int i = 1; i <= n; i += 1)
            if (a[i] <= s[M]) {
                c += 1;
                for (int j : G[i])
                    if (a[j] <= s[M])
                        d[j] += 1;
            }
        for (int i = 1; i <= n; i += 1)
            if (a[i] <= s[M] and d[i] == 0)
                q.push_back(i);
        for (int i = 0; i < q.size(); i += 1) {
            int u = q[i];
            for (int v : G[u])
                if (a[v] <= s[M]) {
                    dp[v] = max(dp[v], dp[u] + 1);
                    if (not (d[v] -= 1))
                        q.push_back(v);
                }
        }
        if (q.size() < c or ranges::max(dp) >= k)
            R = M;
        else L = M + 1;
    }
    if (L > n) cout << "-1";
    else cout << s[L];
}