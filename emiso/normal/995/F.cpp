#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;
typedef long long ll;

ll n, d, a, dpLTE[3003][3003], dpDif[3003], fat[3030], invfat[3030];
vector<int> adj[3030];

ll solveLTE(int node, int k) {
    if(k == 1) return 1;
    if(adj[node].size() == 0) return k;
    if(dpLTE[node][k] != -1) return dpLTE[node][k];

    ll x = solveLTE(node, k - 1);
    ll mult = 1;
    for(int v : adj[node])
        mult = (mult * solveLTE(v, k)) % MOD;

    x = (x + mult); if(x > MOD) x -= MOD;

    return dpLTE[node][k] = x;
}

ll expo(ll b, ll e) {
    if(!e) return 1;
    b %= MOD;
    if(e & 1) return (b * expo(b * b, e / 2)) % MOD;
    return expo(b * b, e / 2);
}

ll inv_mod(ll x) {
    return expo(x, MOD - 2);
}

ll nCr(ll n, ll k) {
    ll ret = 1;
    if(n < 3030) {
        ret = (fat[n] * invfat[k]) % MOD;
        ret = (ret * invfat[n-k]) % MOD;
    } else {
        for(ll i = n; i > n - k; i--)
            ret = (ret * i) % MOD;

        ret = (ret * invfat[k]) % MOD;
    }
    return ret;
}

int main() {
    scanf("%lld %lld", &n, &d);

    for(int i = 2; i <= n; i++) {
        scanf("%lld", &a);
        adj[a].push_back(i);
    }

    fat[0] = invfat[0] = 1;
    for(ll i = 1; i < 3030; i++) {
        fat[i] = (fat[i-1] * i) % MOD;
        invfat[i] = inv_mod(fat[i]);
    }

    memset(dpLTE, -1, sizeof dpLTE);
    solveLTE(1, n);

    if(d > n) {
        for(int i = 1; i <= n; i++) {
            dpDif[i] = solveLTE(1, i);
            for(int j = 1; j < i; j++) {
                ll sub = (dpDif[j] * nCr(i, j)) % MOD;
                dpDif[i] = (dpDif[i] - sub);
                if(dpDif[i] < 0) dpDif[i] += MOD;
            }
        }

        ll ret = 0;
        for(int i = 1; i <= n; i++) {
            ret = (ret + dpDif[i]*nCr(d, i)) % MOD;
        }
        printf("%lld\n", ret);
    } else {
        printf("%lld\n", solveLTE(1, d));
    }


    return 0;
}