#include <bits/stdc++.h>

#define MN 1001000

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

template<typename T>
struct segtree {
    ll tree[4*MN];
    T lazy[4*MN];

    segtree() {
        memset(lazy, 0, sizeof lazy);
    }

    ll identity() {
        return 0;
    }

    ll merge(ll a, ll b) {
        return a + b;
    }

    void do_lazy(int id, int l, int r) {
        if(lazy[id]) {
            tree[id]++;
            lazy[id] = 0;
        }
    }

    ll query(int id, int l, int r, int lq, int rq) {
        do_lazy(id, l, r);
        if(lq > rq || r < lq || rq < l) return identity();
        if(lq <= l && r <= rq) return tree[id];
        int m = (l + r) / 2;
        return merge(query(id*2,   l,   m, lq, rq),
                     query(id*2+1, m+1, r, lq, rq));
    }

    void update(int id, int l, int r, int lq, int rq, T val) {
        do_lazy(id, l, r);
        if(lq > rq || r < lq || rq < l) return;
        if(lq <= l && r <= rq) {
            lazy[id] += val;
            do_lazy(id, l, r);
            return;
        }
        int m = (l + r) / 2;
        update(id*2,   l,   m, lq, rq, val);
        update(id*2+1, m+1, r, lq, rq, val);
        tree[id] = merge(tree[id*2], tree[id*2+1]);
    }
};

template<typename T>
struct segtree2 {
    ll tree[4*MN];
    T lazy[4*MN];

    segtree2() {
        memset(lazy, 0, sizeof lazy);
    }

    ll identity() {
        return 0;
    }

    ll merge(ll a, ll b) {
        return a + b;
    }

    void do_lazy(int id, int l, int r) {
        if(lazy[id]) {
            tree[id] += lazy[id];
            lazy[id] = 0;
        }
    }

    ll query(int id, int l, int r, int lq, int rq) {
        do_lazy(id, l, r);
        if(lq > rq || r < lq || rq < l) return identity();
        if(lq <= l && r <= rq) return tree[id];
        int m = (l + r) / 2;
        return merge(query(id*2,   l,   m, lq, rq),
                     query(id*2+1, m+1, r, lq, rq));
    }

    void update(int id, int l, int r, int lq, int rq, T val) {
        do_lazy(id, l, r);
        if(lq > rq || r < lq || rq < l) return;
        if(lq <= l && r <= rq) {
            lazy[id] += val;
            do_lazy(id, l, r);
            return;
        }
        int m = (l + r) / 2;
        update(id*2,   l,   m, lq, rq, val);
        update(id*2+1, m+1, r, lq, rq, val);
        tree[id] = merge(tree[id*2], tree[id*2+1]);
    }
};


segtree<ll> st;
segtree2<ll> st2;

ll n, ans[MN], a[MN], sum;

int main() {
    scanf("%lld", &n);

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);

        ans[i] += sum;
        for(ll j = a[i], mult = 1; j <= 300000; j += a[i], mult++) {
            ll l = j, r = min(j + a[i]-1, 300000LL);
            auto tt = st.query(1, 1, 300000, l, r);
            ans[i] -= tt * mult * a[i];
        }

        ll tmp = a[i] * i;
        tmp -= st2.query(1, 1, 300000, 1, a[i]);
        ans[i] += tmp;

        if(i) ans[i] += ans[i-1];
        printf("%lld ", ans[i]);

        st.update(1, 1, 300000, a[i], a[i], 1);
        for(ll j = a[i], mult = 1; j <= 300000; j += a[i], mult++) {
            ll l = j, r = min(j + a[i]-1, 300000LL);
            st2.update(1, 1, 300000, l, l, a[i]);
        }
        sum += a[i];
    }
    return 0;
}