#include <bits/stdc++.h>
using namespace std;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, m;
        cin >> n >> m;
        vector a(n, vector<int>(m));
        unordered_map<int, int> x, y;
        for (int i = 0; i < n; i += 1)
            for (int j = 0; j < m; j += 1) {
                cin >> a[i][j];
                x[i - j] += a[i][j];
                y[i + j] += a[i][j];
            }
        int ans = 0;
        for (int i = 0; i < n; i += 1)
            for (int j = 0; j < m; j += 1)
                ans = max(ans, x[i - j] + y[i + j] - a[i][j]);
        cout << ans << "\n";
    }
}