#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 540;
constexpr LL mod = 1000000007;
char s[maxn][maxn];
LL dp[2][maxn][maxn];
void no(){
    printf("0");
    exit(0);
}
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i += 1) scanf("%s", s[i] + 1);
    if(s[1][1] != s[n][m]) no();
    dp[0][1][n] = 1;
    for(int i = 1, u = 1; i < (n + m) / 2; i += 1, u ^= 1){
        memset(dp[u], 0, sizeof dp[u]);
        for(int a1 = 1; a1 <= n; a1 += 1)
            for(int a2 = 1; a2 <= n; a2 += 1){
                int b1 = i + 2 - a1, b2 = m + n - i - a2;
                if(b1 < 1 or b1 > m or b2 < 1 or b2 > m) continue;
                if(s[a1][b1] != s[a2][b2]) continue;
                dp[u][a1][a2] = (dp[u ^ 1][a1][a2] + dp[u ^ 1][a1 - 1][a2 + 1]
                    + dp[u ^ 1][a1][a2 + 1] + dp[u ^ 1][a1 - 1][a2]) % mod;
                //printf("%d %d %d %d %lld\n", a1, b1, a2, b2, dp[u][a1][a2]);
            }
    }
    LL ans = 0;
    int u = ((n + m) / 2 - 1) & 1;
    if((n + m) & 1) for(int a1 = 1; a1 <= n; a1 += 1)
        ans = (ans + dp[u][a1][a1] + dp[u][a1][a1 + 1]) % mod;
    else for(int a1 = 1; a1 <= n; a1 += 1)
        ans = (ans + dp[u][a1][a1]) % mod;
    printf("%lld", ans);
}