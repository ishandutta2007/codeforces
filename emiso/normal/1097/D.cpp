#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MOD 1000000007

ll expo(ll a, ll b) {
    if(!b) return 1;
    a %= MOD;
    if(b & 1) return a * expo(a * a, b >> 1) % MOD;
    return expo(a * a, b >> 1);
}

ll inv_mod(ll x) { return expo(x, MOD - 2);}

ll n, dp[60][10010], im[60];
vector<pair<ll, int>> divs;
int k;

int main() {
    scanf("%lld %d", &n, &k);

    for(int i = 0; i < 60; i++)
        im[i] = inv_mod(i);

    ll tmp = n;
    for(ll i = 2; i * i <= tmp; i++) {
        if(tmp % i == 0) {
            int q = 0;
            while(tmp % i == 0) {
                q++;
                tmp /= i;
            }
            divs.emplace_back(i, q);
        }
    }
    if(tmp > 1) divs.emplace_back(tmp, 1);

    ll ans = 1;
    for(auto d : divs) {
        memset(dp, 0, sizeof dp);
        dp[d.second][k] = 1;

        for(int K = k; K > 0; K--)
            for(int i = 0; i <= d.second; i++)
                for(int j = 0; j <= i; j++)
                    dp[j][K-1] = (dp[j][K-1] + dp[i][K] * im[i+1]) % MOD;

        ll tot = 0, mult = 1;
        for(int i = 0; i <= d.second; i++) {
            tot += dp[i][0] * mult % MOD;
            mult = mult * d.first % MOD;
        }
        ans = (tot % MOD * ans) % MOD;
    }

    printf("%lld\n", ans);
    return 0;
}