#include <bits/stdc++.h>

#define MOD 998244353

using namespace std;
typedef long long ll;

ll expo(ll a, ll b) {
    if(!b) return 1;
    a %= MOD;
    if(b & 1) return a * expo(a * a, b >> 1) % MOD;
    return expo(a * a, b >> 1);
}

int inv_mod(int x) { return expo(x, MOD - 2); }

ll n, dp[200020];

int main() {
    ll n;
    scanf("%lld", &n);

    ll i1 = inv_mod(2), i2 = inv_mod(4);
    dp[0] = 1;
    for(int i = 1; i <= n; i++) {
        dp[i] = dp[i-1] * i1 % MOD;
        if(i >= 3) {
            dp[i] += dp[i-2] * i2 % MOD;
            if(dp[i] >= MOD) dp[i] -= MOD;
        }
    }

    printf("%lld\n", dp[n]);
    return 0;
}