#include <bits/stdc++.h>

#define MN 100010
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

ll n, k, ans, other, ways[100010];
map<ll, ll> lucky;

bool isit(ll x) {
    while(x) {
        if(x % 10 != 4 && x % 10 != 7)
            return false;
        x /= 10;
    }
    return true;
}

int main() {
    prep();
    scanf("%lld %lld", &n, &k);

    for(int i = 0; i < n; i++) {
        ll x;
        scanf("%lld", &x);
        if(isit(x)) lucky[x]++;
        else other++;
    }

    ways[0] = 1;
    for(auto p : lucky) {
        for(int i = k; i > 0; i--) {
            ways[i] += p.second * ways[i-1] % MOD;
            if(ways[i] >= MOD) ways[i] -= MOD;
        }
    }

    for(int i = 0; i <= k; i++) {
        ans += ways[i] * nCr(other, k-i) % MOD;
        if(ans >= MOD) ans -= MOD;
    }

    printf("%lld\n", ans);
    return 0;
}