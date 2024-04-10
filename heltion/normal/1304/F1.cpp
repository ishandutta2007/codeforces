#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 50;
constexpr int maxm = 20000;
int c[maxn + 2][maxm + 1];
int s[maxn + 2][maxm + 1];
int dp[maxn + 2][maxm + 1];
int pre[maxm], suf[maxm];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i += 1)
        for(int j = 1; j <= m; j += 1)
            cin >> c[i][j];
    for(int i = 1; i <= n; i += 1)
        for(int j = 1; j <= m; j += 1)
            s[i][j] = s[i][j - 1] + c[i][j];
    int ans = 0;
    for(int i = 1; i <= n; i += 1){
        for(int j = 1; j <= m - k + 1; j += 1) pre[j] = max(pre[j - 1], dp[i - 1][j]);
        for(int j = m - k + 1; j >= 1; j -= 1) suf[j] = max(suf[j + 1], dp[i - 1][j]);
        for(int j = 1; j <= m - k + 1; j += 1){
            for(int x = max(j - k + 1, 1); x <= min(m - k + 1, j + k - 1); x += 1)
                dp[i][j] = max(dp[i][j], dp[i - 1][x] + s[i][j + k - 1] - s[i][j - 1] + s[i + 1][j + k - 1] - s[i + 1][j - 1]
                - s[i][min(x + k - 1, j + k - 1)] + s[i][max(x, j) - 1]);
            int p = 0;
            if(j > k) p = max(p, pre[j - k]);
            if(j + 2 * k - 1 <= m) p = max(p, suf[j + k]);
            dp[i][j] = max(dp[i][j], s[i][j + k - 1] - s[i][j - 1] + s[i + 1][j + k - 1] - s[i + 1][j - 1] + p);
            ans = max(dp[i][j], ans);
            //cout << i << " " << j << " " << dp[i][j] << endl;
        }
    }
    cout << ans;
    return 0;
}