#include <bits/stdc++.h>

#define MN 1001000
#define MOD 1000000007

using namespace std;
typedef long long ll;

ll n, k, q, a[MN], dp[5050][5050], ans, quant[5050];

int main() {
    scanf("%lld %lld %lld", &n, &k, &q);
    k++;

    for(int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        dp[i][0] = dp[i][1] = 1;
    }

    for(int l = 1; l <= k; l++) {
        dp[1][l] = dp[2][l-1];
        dp[n][l] = dp[n-1][l-1];
        for(int i = 2; i + 1 <= n; i++) {
            dp[i][l] = dp[i-1][l-1] + dp[i+1][l-1];
            if(dp[i][l] >= MOD) dp[i][l] -= MOD;
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int l = 0; l < k; l++) {
            quant[i] += 1LL * dp[i][l] * dp[i][k-l-1] % MOD;
            if(quant[i] >= MOD) quant[i] -= MOD;
        }
        ans += a[i] * quant[i] % MOD;
        if(ans >= MOD) ans -= MOD;
    }

    while(q--) {
        ll x, y;
        scanf("%lld %lld", &x, &y);
        ans = (ans - a[x] * quant[x] % MOD + MOD) % MOD;
        a[x] = y;
        ans = (ans + a[x] * quant[x] % MOD + MOD) % MOD;
        printf("%lld\n", ans);
    }

    return 0;
}