#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, delta, a[MN];

template<typename T>
struct fenwick_tree {
    vector<T> a;
    fenwick_tree(int n) {
        a.resize(n + 1);
    }
    void update(int idx, T delta) {
        for(; idx < a.size(); idx += (idx & -idx)) a[idx] += delta;
    }
    T query(int idx) {
        T ret = 0;
        for(; idx; idx -= (idx & -idx)) ret += a[idx];
        return ret;
    }
};

ll solve(ll delta, ll L, ll R) {
    ll ret = LLONG_MAX;
    for(ll aa : {(L - delta) / 2}){//, (L - delta + 1) / 2}){
        ret = min(ret, max({aa, L - aa, aa + delta, R - aa - delta}));
    }
    return ret;
}

int main() {
    scanf("%lld", &n);
    fenwick_tree<ll> bit(n);

    for(int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        bit.update(i, a[i]);
        bit.update(i + 1, -a[i]);
        if(i > 1 && a[i] > a[i-1]) delta += a[i] - a[i-1];
    }

    printf("%lld\n", solve(delta, bit.query(1), bit.query(n)));

    scanf("%lld", &t);
    while(t--) {
        ll l, r, x;
        scanf("%lld %lld %lld", &l, &r, &x);

        if(l > 1 && bit.query(l) > bit.query(l-1)) delta -= bit.query(l) - bit.query(l-1);
        if(r < n && bit.query(r+1) > bit.query(r)) delta -= bit.query(r+1) - bit.query(r);

        bit.update(l, x);
        bit.update(r+1, -x);

        if(l > 1 && bit.query(l) > bit.query(l-1)) delta += bit.query(l) - bit.query(l-1);
        if(r < n && bit.query(r+1) > bit.query(r)) delta += bit.query(r+1) - bit.query(r);

        printf("%lld\n", solve(delta, bit.query(1), bit.query(n)));
    }
    return 0;
}