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
    T tree[4*MN], lazy[4*MN];

    segtree() {
        memset(tree, 0, sizeof tree);
        memset(lazy, 0, sizeof lazy);
    }

    T identity() {
        return LLONG_MAX/2;
    }

    T merge(T a, T b) {
        return min(a, b);
    }

    void build(int id, int l, int r, T* a) {
        lazy[id] = 0;
        if(l == r) {
            tree[id] = a[l];
            return;
        }
        int m = (l + r) / 2;
        build(id*2,   l,   m, a);
        build(id*2+1, m+1, r, a);
        tree[id] = merge(tree[id*2], tree[id*2+1]);
    }

    void do_lazy(int id, int l, int r) {
        if(lazy[id]) {
            tree[id] += lazy[id]; /// max
            /// tree[id] += lazy[id] * (r - l + 1LL); /// sum
            if(l != r) {
                lazy[id*2]   += lazy[id];
                lazy[id*2+1] += lazy[id];
            }
            lazy[id] = 0;
        }
    }

    T query(int id, int l, int r, int lq, int rq) {
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

ll t, n, ans, p[MN], a[MN], cost[MN], rev[MN];
//char s[MN]; string str;

int main() {
    scanf("%lld", &n);

    for(int i = 1; i <= n; i++) {
        scanf("%lld", &p[i]);
        rev[p[i]] = i;
    }
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    ans = min(a[1], a[n]);

    cost[0] = a[rev[1]];
    for(int i = 1; i < n; i++) {
        cost[i] = cost[i-1];
        if(p[i] == 1) cost[i] -= a[i];
        else cost[i] += a[i];
    }

    st.build(1, 1, n-1, cost);
    ans = min(ans, st.query(1, 1, n-1, 1, n-1));

    for(int i = 2; i < n; i++) {
        st.update(1, 1, n-1, 1, rev[i]-1, +a[rev[i]]);
        st.update(1, 1, n-1, rev[i], n-1, -a[rev[i]]);
        ans = min(ans, st.query(1, 1, n-1, 1, n-1));
    }

    printf("%lld\n", ans);
    return 0;
}