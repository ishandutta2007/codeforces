#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MN 1001000


const ll MOD = 998244353;

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

ll n, m, a[MN], b[MN], f[MN];

template<typename T>
struct fenwick_tree {
    vector<T> a;
    fenwick_tree(int n) { a.resize(n + 1); }
    fenwick_tree(vector<T> &vec) : a(vec) {
        for(int i = 1; i+(i&-i) < (int)a.size(); i++) a[i+(i&-i)] += a[i];
    }
    void update(int idx, T delta) {
        for(; idx < (int)a.size(); idx += (idx & -idx)) a[idx] += delta;
    }
    T query(int idx) {
        T ret = 0;
        for(; idx; idx -= (idx & -idx)) ret += a[idx];
        return ret;
    }
};

int main() {
    prep();
    fenwick_tree<ll> bit(200200);

    scanf("%lld %lld", &n, &m);
    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        bit.update(a[i], 1);
        f[a[i]]++;
    }
    for(int i = 0; i < m; i++) {
        scanf("%lld", &b[i]);
    }
    
    ll ans = 0, multi = 1;
    for (int i = 1; i <= 200000; i++)
        multi = multi * invfat[f[i]] % MOD;

    for (ll i = 0; i < min(n, m); i++) {
        ans += fat[n-i-1] * multi % MOD * bit.query(b[i]-1) % MOD;
        if (ans >= MOD) ans -= MOD;

        if (f[b[i]] == 0) break;
        multi = multi * fat[f[b[i]]] % MOD;
        f[b[i]]--;
        multi = multi * invfat[f[b[i]]] % MOD;
        bit.update(b[i], -1);

        if (i + 1 == n && n < m) ans = (ans + 1) % MOD;
    }


    printf("%lld\n", ans);
    return 0;
}