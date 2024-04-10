#include <bits/stdc++.h>

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

#define MOD 998244353

#define MN 1001000

ll expo(ll a, ll b) {
    if(!b) return 1;
    a %= MOD;
    if(b & 1) return a * expo(a * a, b >> 1) % MOD;
    return expo(a * a, b >> 1);
}

ll inv_mod(ll a) { return expo(a, MOD - 2); }

ll fat[MN], invfat[MN];

void prep() {
    fat[0] = 1;
    for(ll i = 1; i < MN; i++) fat[i] = fat[i-1] * i % MOD;
    invfat[MN-1] = inv_mod(fat[MN-1]);
    for(ll i = MN-1; i > 0; i--) invfat[i-1] = i * invfat[i] % MOD;
}

ll nCr(ll n, ll k) {
    if(k < 0 || k > n) return 0;
    return fat[n] * invfat[k] % MOD * invfat[n - k] % MOD;
}

ll t = 1, n, ans, a[MN];
//char s[MN]; string str;

int main() {
    prep();
    scanf("%lld", &t);
    st: ans = 0;
    scanf("%lld", &n);

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    sort(a, a + n);
    if(a[n-1] == a[n-2]) ans = fat[n];
    else if(a[n-1] - 1 > a[n-2]) ans = 0;
    else {
        int m1 = 1;
        for(int i = n-3; i >= 0 && a[i] == a[n-2]; i--, m1++);
        ans = (fat[n] - fat[n] * invfat[m1+1] % MOD * fat[m1] % MOD + MOD) % MOD;
    }

    printf("%lld\n", ans);
    if(--t) goto st;
    return 0;
}