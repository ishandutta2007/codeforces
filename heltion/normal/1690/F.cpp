#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        string s;
        cin >> n >> s;
        s = ' ' + s;
        vector<int> p(n + 1), vis(n + 1);
        for (int i = 1; i <= n; i += 1) cin >> p[i];
        LL ans = 1;
        for (int i = 1; i <= n; i += 1) if (not vis[i]) {
            string t;
            for (int j = i; not vis[j]; j = p[j]) {
                vis[j] = 1;
                t.push_back(s[j]);
            }
            int m = t.size();
            for (int i = 1; i <= m; i += 1) if (m % i == 0) {
                int ok = 1;
                for (int j = 0; j < m and ok; j += 1)
                    ok = t[j] == t[(j + i) % m];
                if (ok) {
                    ans = lcm(ans, i);
                    break;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;   
}