#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (int& ai : a) cin >> ai;
        vector<pair<LL, int>> tp(m);
        vector<vector<int>> p(n);
        for (int i = 0, e; i < m; i += 1) {
            cin >> e >> tp[i].first >> tp[i].second;
            p[e - 1].push_back(i);
        }
        LL cur = 0, ok = 1;
        vector<int> ans;
        for (int i = 0; i < n and ok; i += 1) {
            int m = p[i].size();
            vector dp(m + 1, vector<LL>(100 + 1, -1));
            vector f(m + 1, vector<int>(100 + 1));
            dp[0][0] = 0;
            for (int j = 0; j < m; j += 1) {
                for (int k = 0; k <= 100; k += 1) if (~dp[j][k]) {
                    dp[j + 1][k] = dp[j][k];
                    f[j + 1][k] = k;
                }
                for (int k = 0; k <= 100; k += 1) if (~dp[j][k]) {
                    int nk = min(k + tp[p[i][j]].second, 100);
                    LL w = dp[j][k] + tp[p[i][j]].first;
                    if (dp[j + 1][nk] == -1 or dp[j + 1][nk] > w) {
                        dp[j + 1][nk] = w;
                        f[j + 1][nk] = k;
                    }
                }
            }
            if (dp[m][100] == -1 or cur + dp[m][100] > a[i]) ok = 0;
            else {
                cur += dp[m][100];
                int k = 100;
                for (int j = m; j; j -= 1) {
                    if (f[j][k] == k) continue;
                    else {
                        ans.push_back(p[i][j - 1]);
                        k = f[j][k];
                    }
                }
            }
        }
        if (ok) {
            cout << ans.size() << "\n";
            for (int x : ans) cout << x + 1 << " "; cout << "\n";
        }
        else cout << "-1\n";
    }
    return 0;
}