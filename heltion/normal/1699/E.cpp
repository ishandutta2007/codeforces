#include <bits/stdc++.h>
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
        vector<int> f(m + 1, INT_MAX), p(m + 1), v(m + 1);
        vector<int> g(m + 2);
        for (int i = 1, a; i <= n; i += 1) {
            cin >> a;
            v[a] = 1;
            g[a] = max(g[a], a);
            g[a + 1] = max(g[a + 1], INT_MAX);
        }
        for (int i = 1; i <= m; i += 1)
            f[i] = i;
        //for (int i = 1; i <= m; i += 1) cout << g[i] << " "; cout << "\n";
        for (int i = m; i >= 1; i -= 1) {
            if ((LL)i * i <= m) {
                for (int j = i * i; j <= m; j += i) {
                    if (f[j / i] < f[j]) {
                        if (v[j]) g[i + 1] = max(g[i + 1], f[j]);
                        f[j] = f[j / i];
                    }
                }
                //for (int i = 1; i <= m; i += 1) cout << g[i] << " "; cout << "\n";
            }
        }
        int ans = INT_MAX;
        for (int i = 1; i <= m; i += 1)
            if (v[i]) g[1] = max(g[1], f[i]);
        for (int i = 1; i <= m; i += 1) {
            g[i] = max(g[i], g[i - 1]);
            ans = min(ans, g[i] - i);
        }
        cout << ans << "\n";
    }
    return 0;
}