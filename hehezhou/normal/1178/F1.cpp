#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n, a[510], m;
int dp[510][510];
int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m + 1; i++) dp[i][i - 1] = 1;
    for(int i = 1; i <= m; i++) dp[i][i] = 1, scanf("%d", a + i);
    a[0] = 1e9;
    for(int i = n; i > 0; i--)
        for(int j = i + 1; j <= n; j++) {
            int p = 0;
            for(int k = i; k <= j; k++) if(a[k] < a[p]) p = k;
            long long l = 0, r = 0;
            for(int k = i; k <= p; k++) l = (l + 1ll * dp[i][k - 1] * dp[k][p - 1]) % mod;
            for(int k = p; k <= j; k++) r = (r + 1ll * dp[p + 1][k] * dp[k + 1][j]) % mod;
            dp[i][j] = l * r % mod;
        }
    return cout << dp[1][n] << endl, 0;
}