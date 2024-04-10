#include <bits/stdc++.h>

#define MOD 998244353
#define MN 1000100

using namespace std;
typedef long long ll;

ll expo(ll b, ll e) {
    if(!e) return 1;
    b %= MOD;
    if(e & 1) return (b * expo(b * b, e >> 1)) % MOD;
    return expo(b * b, e >> 1);
}

ll inv_mod(ll x) {
    return expo(x, MOD - 2);
}

ll fat[MN], invfat[MN], n, p3[MN];

ll nCr(ll n, ll k) {
    ll ret = (fat[n] * invfat[k]) % MOD;
    return (ret * invfat[n-k]) % MOD;
}

int main() {
    scanf("%lld", &n);

    fat[0] = p3[0] = 1;
    for(ll i = 1; i < MN; i++) {
        fat[i] = (fat[i-1] * i) % MOD;
        p3[i] = (p3[i-1] * 3) % MOD;
    }

    invfat[MN-1] = inv_mod(fat[MN-1]);
    for(ll i = MN-1; i > 0; i--) {
        invfat[i-1] = (i * invfat[i]) % MOD;
    }

    ll ans = 0;
    for(ll i = 1; i <= n; i++) {
        ll add = (2LL * p3[i] * nCr(n, i)) % MOD;
        add = (add * expo(3, n*(n-i))) % MOD;

        add = add * ((i % 2) ? 1 : -1);
        if(add < 0) add += MOD;

        ans += add;
    }
    ans %= MOD;

    for(ll i = 1; i <= n; i++) {
        ll add = nCr(n, i) * ((i % 2) ? -1 : 1);
        if(add < 0) add += MOD;

        ll p3i = expo(3, n - i);

        ll summ = (expo(p3i - 1, n) - expo(p3i, n));
        if(summ < 0) summ += MOD;

        add = ((-3 * add * summ) % MOD);
        if(add < 0) add += MOD;

        ans = (ans + add);
    }
    ans %= MOD;


    printf("%lld\n", ans);
    return 0;
}