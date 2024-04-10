#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 200 + 2;
char s[maxn], t[3];
int dp[maxn][maxn][maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k >> (s + 1) >> t;
    for(int i = 0; i <= n; i += 1)
        for(int j = 0; j <= i; j += 1)
            for(int x = 0; x <= k; x += 1)
                dp[i][j][x] = -100000;
    dp[0][0][0] = 0;
    for(int i = 1; i <= n; i += 1)
        for(int j = 0; j < i; j += 1)
            for(int x = 0; x <= k; x += 1){
                dp[i][j][x] = max(dp[i][j][x], dp[i - 1][j][x]);
                if(t[0] == t[1]){
                    if(s[i] == t[0]) dp[i][j + 1][x] = max(dp[i - 1][j][x] + j, dp[i][j + 1][x]);
                    if(x < k) dp[i][j + 1][x + 1] = max(dp[i - 1][j][x] + j, dp[i][j + 1][x + 1]);
                }
                else{
                    if(s[i] == t[0]) dp[i][j + 1][x] = max(dp[i - 1][j][x], dp[i][j + 1][x]);
                    if(s[i] == t[1]) dp[i][j][x] = max(dp[i - 1][j][x] + j, dp[i][j][x]);
                    if(x < k){
                        dp[i][j + 1][x + 1] = max(dp[i - 1][j][x], dp[i][j + 1][x + 1]);
                        dp[i][j][x + 1] = max(dp[i - 1][j][x] + j, dp[i][j][x + 1]);
                    }
                }
            }
    int ans = 0;
    for(int i = 0; i <= n; i += 1)
        for(int j = 0; j <= k; j += 1)
            ans = max(dp[n][i][j], ans);
    cout << ans;
    return 0;
}