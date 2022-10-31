#include <bits/stdc++.h>

#define MN 1001000

#define MOD 998244353

using namespace std;
typedef long long ll;

#ifdef EBUG
#include "trace.h"
#else
template<typename... Args> void trace(Args... args) {}
template<typename... Args> void recInit(Args... args) {}
template<typename... Args> void recEnd(Args... args) {}
#define trace2(args...) trace(args)
#endif

ll n, m, ans, d[50050][21], f[22];

ll expo(ll a, ll b) {
    if(!b) return 1;
    a %= MOD;
    if(b & 1) return a * expo(a * a, b >> 1) % MOD;
    return expo(a * a, b >> 1);
}

ll inv_mod(ll a) {
    return expo(a, MOD - 2);
}

ll fat[MN], invfat[MN];

void prep() {
    fat[0] = 1;
    for(ll i = 1; i < MN; i++)
        fat[i] = (fat[i-1] * i) % MOD;

    invfat[MN-1] = inv_mod(fat[MN-1]);
    for(ll i = MN-1; i > 0; i--)
        invfat[i-1] = (i * invfat[i]) % MOD;
}

int main() {
    prep();
    scanf("%lld %lld", &n, &m);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%lld", &d[j][i]);
        }
    }

    for(int j = 0; j < m; j++) {
        memset(f, 0, sizeof f);
        for(int i = 0; i < n; i++) f[d[j][i]]++;

        ll tmp = fat[n], tot = 1;
        for(int i = n+1; i > 1; i--) {
            tot = tot * f[i] % MOD;
            f[i-1] += f[i] - 1;
        }

        ans += tmp;
        if(ans >= MOD) ans -= MOD;
        ans -= tot;
        if(ans < 0) ans += MOD;
        trace2(j, tot, tmp, ans);
    }

    printf("%lld\n", ans * invfat[n] % MOD);
    return 0;
}