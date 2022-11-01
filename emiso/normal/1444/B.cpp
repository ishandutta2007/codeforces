#include <bits/stdc++.h>

#define MN 1001000
#define MOD 998244353

using namespace std;
typedef long long ll;

ll expo(ll a, ll b) {
    if(!b) return 1;
    a %= MOD;
    if(b & 1) return a * expo(a * a, b >> 1) % MOD;
    return expo(a * a, b >> 1);
}

ll inv_mod(ll a) {
    return expo(a, MOD - 2);
}


ll t, n, ans, a[MN];

ll fat[MN], invfat[MN];


void prep() {
    fat[0] = 1;
    for(ll i = 1; i < MN; i++)
        fat[i] = (fat[i-1] * i) % MOD;

    invfat[MN-1] = inv_mod(fat[MN-1]);
    for(ll i = MN-1; i > 0; i--)
        invfat[i-1] = (i * invfat[i]) % MOD;
}

ll nCr(ll n, ll k) {
    if(k < 0 || k > n) return 0;
    return fat[n] * invfat[k] % MOD * invfat[n - k] % MOD;
}

ll ls, hs;

int main() {
    prep();
    scanf("%lld", &n);

    for(int i = 0; i < 2*n; i++) {
        scanf("%lld", &a[i]);
    }
    sort(a, a + 2*n);
    for(int i = 0; i < n; i++) {
        ls += a[i];
        if(ls >= MOD) ls -= MOD;
    }
    for(int i = n; i < 2*n; i++) {
        hs += a[i];
        if(hs >= MOD) hs -= MOD;
    }
    hs -= ls;
    if(hs < 0) hs += MOD;

    printf("%lld\n", 1LL * hs * nCr(2*n, n) % MOD);
    return 0;
}