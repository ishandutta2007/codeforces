#include <bits/stdc++.h>

#define MN 110
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

ll dp[2][55][55], inv2 = inv_mod(2);

ll solve(int can, int sz, int m) {
    if(m < 0) return 0;
    if(sz == 0) return (m == 0);
    if(sz == 1) return (m == 0 && can == 0);
    ll &x = dp[can][sz][m];
    if(x != -1) return x;
    x = 0;

    /// 1 edge
    if(can) {
        x = (x + solve(0, sz - 1, m - 1) * nCr(sz - 1, sz - 2)) % MOD;
    } else {
        x = (x + solve(1, sz - 1, m) * nCr(sz - 1, sz - 2)) % MOD;
    }

    /// 2 edges
    if(can) {
        for(int l = 1; l + 2 <= sz; l++) {
            int r = sz - 1 - l;
            ll comb = nCr(sz-1, l) * l * r % MOD * inv2 % MOD;
            for(int ml = 0; ml < m; ml++) {
                int mr = m - ml - 1;
                x = (x + solve(0, l, ml) * solve(0, r, mr) % MOD * comb) % MOD;
                x = (x + solve(1, l, ml) * solve(0, r, mr) % MOD * comb) % MOD;
                x = (x + solve(0, l, ml) * solve(1, r, mr) % MOD * comb) % MOD;
            }
        }
    } else {
        for(int l = 1; l + 2 <= sz; l++) {
            int r = sz - 1 - l;
            ll comb = nCr(sz-1, l) * l * r % MOD * inv2 % MOD;
            for(int ml = 0; ml <= m; ml++) {
                int mr = m - ml;
                x = (x + solve(1, l, ml) * solve(1, r, mr) % MOD * comb) % MOD;
            }
        }
    }
    return x;
}

ll n, k;

int main() {
    prep();
    scanf("%lld %lld", &n, &k);
    memset(dp, -1, sizeof dp);
    printf("%lld\n", (solve(1, n, k) + solve(0, n, k)) % MOD);
    return 0;
}