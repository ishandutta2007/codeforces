#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 1000000007, MN = 200020;
ll n, k, sum, fac, x, fat[MN], invfat[MN];

ll pow_mod(ll a, ll e) {
    if(!e) return 1;
    a %= MOD;
    if(e & 1) return (a * pow_mod(a * a, e / 2)) % MOD;
    return pow_mod(a * a, e / 2);
}

ll nCr(ll n, ll k) {
    ll ret = (fat[n] * invfat[k])%MOD;
    return (ret * invfat[n-k])%MOD;
}

// stirling numbers of the second kind
ll stirling(ll n, ll k) {
    ll prod = invfat[k], sum = 0;

    for(ll j = 0; j <= k; j++) {
        ll p = 1;
        if((k - j) % 2) p = -1;
        sum = (sum + (p*nCr(k, j)*pow_mod(j, n))%MOD + MOD)%MOD;
    }
    return (sum * prod) % MOD;
}

ll calc(ll n, ll k) {
    return (stirling(n, k) + ((n-1)*stirling(n-1, k))%MOD)%MOD;
}

int main() {
    scanf("%lld %lld", &n, &k);

    fat[0] = invfat[0] = 1;
    for(ll i = 1; i < MN; i++) {
        fat[i] = (fat[i-1] * i) % MOD;
        invfat[i] = pow_mod(fat[i], MOD - 2);
    }

    for(int i = 0; i < n; i++) {
        scanf("%lld", &x);
        sum = (sum + x) % MOD;
    }
    fac = calc(n, k);
    printf("%lld\n", (sum * fac)%MOD);
    return 0;
}