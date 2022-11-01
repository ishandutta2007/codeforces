#include <bits/stdc++.h>

#define MN 1001000
#define MOD 1000000007

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


ll t, n, k, ans, a[MN];
//char s[MN]; string str;

int main() {
    prep();
    scanf("%lld", &t);
    st:
    scanf("%lld %lld", &n, &k);

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    sort(a, a + n);

    ll last = a[n-k], l = 0, r = 0;
    for(int i = n-k; i < n && a[i] == last; i++, r++);
    for(int i = n-k-1; i >= 0 && a[i] == last; i--, l++);

    printf("%lld\n", nCr(l+r, r));
    if(--t) goto st;
    return 0;
}