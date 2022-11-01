#include <bits/stdc++.h>

#define MN 1001000
#define MOD 1000000007
#define F first
#define S second

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

ll ans, a[MN], b[MN], n, m;
pair<ll, ll> dp[MN];

ll sum(ll a, ll b) {
    return (a + b) % MOD;
}

ll sub(ll a, ll b) {
    return (((a - b) % MOD) + MOD) % MOD;
}

ll mul(ll a, ll b) {
    return ((a % MOD) * (b % MOD)) % MOD;
}

ll expo(ll a, ll b) {
    if(!b) return 1;
    a %= MOD;
    if(b % 2) return mul(a, expo(a * a, b >> 1));
    return expo(a * a, b >> 1);
}

ll inv(ll a) {
    return expo(a, MOD - 2);
}

ll divi(ll a, ll b) {
    return mul(a, inv(b));
}

pll sum(pll a, pll b) {
    ll dn = (a.S * b.S) % MOD;
    ll nm = (a.F * b.S + b.F * a.S) % MOD;
    return {nm, dn};
}

pll sub(pll a, pll b) {
    ll dn = (a.S * b.S) % MOD;
    ll nm = ((a.F * b.S - b.F * a.S) % MOD + MOD) % MOD;
    return {nm, dn};
}

pll mul(pll a, pll b) {
    ll dn = (a.S * b.S) % MOD;
    ll nm = (a.F * b.F) % MOD;
    return {nm, dn};
}

int main() {
    scanf("%lld %lld", &n, &m);

    for(int i=0; i<n; i++) {
        scanf("%lld", &a[i]);
    }

    for(int i=0; i<n; i++) {
        scanf("%lld", &b[i]);
    }

    dp[n] = {0, 1};
    for(int i = n-1; i >= 0; i--) {
        if(a[i] && b[i]) {
            if(a[i] > b[i]) dp[i] = {1, 1};
            else if(a[i] < b[i]) dp[i] = {0, 1};
            else dp[i] = dp[i + 1];
        }

        else if(a[i]) {
            dp[i] = sum({a[i]-1, m}, mul({1, m}, dp[i+1]));
        }

        else if(b[i]) {
            dp[i] = sum({m-b[i], m}, mul({1, m}, dp[i+1]));
        }

        else {
            ll M = mul(m, m);
            ll W = divi(sub(M, m), 2);
            dp[i] = sum({W, M}, mul({m, M}, dp[i+1]));
        }
    }

    printf("%lld\n", divi(dp[0].F, dp[0].S));
    return 0;
}