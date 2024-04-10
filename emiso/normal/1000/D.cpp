#include <bits/stdc++.h>

#define MOD 998244353

using namespace std;
typedef long long ll;

ll n, ans, a[1010], dp[1010], nCr[1010][1010];

int main() {
    scanf("%lld", &n);

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    for(int i = 0; i <= 1001; i++) {
        for(int j = 0; j <= i; j++) {
            if(j == 0) nCr[i][j] = 1;
            else nCr[i][j] = (nCr[i-1][j-1] + nCr[i-1][j]) % MOD;
        }
    }


    dp[n] = 1;
    for(ll i = n-1; i >= 0; i--) {
        if(a[i] <= 0 || a[i] > n) continue;
        for(ll j = i+a[i]+1; j <= n; j++) {
            dp[i] += (nCr[j - i - 1][a[i]] * dp[j])%MOD;
            dp[i] %= MOD;
        }
    }

    for(int i = 0; i < n; i++) {
        ans = (ans + dp[i]) % MOD;
    }

    printf("%lld\n", ans);
    return 0;
}