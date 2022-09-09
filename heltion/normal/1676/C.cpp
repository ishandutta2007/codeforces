#include <bits/stdc++.h>
using namespace std;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, m;
        cin >> n >> m;
        vector<string> s(n);
        for (auto& si : s) cin >> si;
        int ans = INT_MAX;
        for (int i = 0; i < n; i += 1)
            for (int j = i + 1; j < n; j += 1) {
                int pans = 0;
                for (int k = 0; k < m; k += 1)
                    pans += abs(s[i][k] - s[j][k]);
                ans = min(ans, pans);
            }
        cout << ans << "\n";
    }
}