#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

template<typename T>
struct segtree {
    T tree[4*MN], lazy[4*MN];

    segtree() {
        memset(tree, 0, sizeof tree);
        memset(lazy, -1, sizeof lazy);
    }

    T identity() {
        return 0;
    }

    T merge(T a, T b) {
        return a + b;
    }

    void build(int id, int l, int r, ll* a) {
        lazy[id] = -1;
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
        if(lazy[id] != -1) {
            tree[id] = lazy[id] * (r - l + 1LL); /// sum
            if(l != r) {
                lazy[id*2]   = lazy[id];
                lazy[id*2+1] = lazy[id];
            }
            lazy[id] = -1;
        }
    }

    T query(int id, int l, int r, int lq, int rq) {
        do_lazy(id, l, r);
        if(r < lq || rq < l) return identity();
        if(lq <= l && r <= rq) return tree[id];
        int m = (l + r) / 2;
        return merge(query(id*2,   l,   m, lq, rq),
                     query(id*2+1, m+1, r, lq, rq));
    }

    void update(int id, int l, int r, int lq, int rq, T val) {
        do_lazy(id, l, r);
        if(r < lq || rq < l) return;
        if(lq <= l && r <= rq) {
            lazy[id] = val;
            do_lazy(id, l, r);
            return;
        }
        int m = (l + r) / 2;
        update(id*2,   l,   m, lq, rq, val);
        update(id*2+1, m+1, r, lq, rq, val);
        tree[id] = merge(tree[id*2], tree[id*2+1]);
    }
};

ll t, q, n, ans, a[MN], b[MN], l[MN], r[MN];
segtree<int> st;

int main() {
    scanf("%lld", &t);
    st:
    scanf("%lld %lld", &n, &q);

    for(int i = 1; i <= n; i++) {
        scanf("%1lld", &a[i]);
    }
    for(int i = 1; i <= n; i++) {
        scanf("%1lld", &b[i]);
    }

    st.build(1, 1, n, b);
    int flag = 1;
    for(int i = 1; i <= q; i++) {
        scanf("%lld %lld", &l[i], &r[i]);
    }
    for(int i = q; flag && i >= 1; i--) {
        int qq = st.query(1, 1, n, l[i], r[i]);
        if(2 * qq == r[i] - l[i] + 1) flag = 0;
        else {
            if(2*qq < r[i] - l[i] + 1) st.update(1, 1, n, l[i], r[i], 0);
            else st.update(1, 1, n, l[i], r[i], 1);
        }
    }
    for(int i = 1; flag && i <= n; i++) {
        if(st.query(1, 1, n, i, i) != a[i])
            flag = 0;
    }

    puts(flag ? "YES" : "NO");
    if(--t) goto st;
    return 0;
}