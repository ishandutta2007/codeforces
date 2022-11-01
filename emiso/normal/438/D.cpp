#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MN 1000100

template<typename T>
struct segtree { /// 1-INDEXED
    T tree[4*MN], lazy[4*MN];
    T maxi[4*MN], mini[4*MN];

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

    void build(int id, int l, int r, T* a) {
        lazy[id] = -1;
        if(l == r) {
            tree[id] = maxi[id] = mini[id] = a[l];
            return;
        }
        int m = (l + r) / 2;
        build(id*2,   l,   m, a);
        build(id*2+1, m+1, r, a);
        tree[id] = merge(tree[id*2], tree[id*2+1]);
        maxi[id] = max(maxi[id*2], maxi[id*2+1]);
        mini[id] = min(mini[id*2], mini[id*2+1]);
    }

    void do_lazy(int id, int l, int r) {
        if(lazy[id] != -1) {
            tree[id] = lazy[id] * (r - l + 1LL); /// sum
            maxi[id] = mini[id] = lazy[id];
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

    void update_eq(int id, int l, int r, int lq, int rq, T val) {
        do_lazy(id, l, r);
        if(r < lq || rq < l) return;
        if(lq <= l && r <= rq) {
            lazy[id] = val;
            do_lazy(id, l, r);
            return;
        }
        int m = (l + r) / 2;
        update_eq(id*2,   l,   m, lq, rq, val);
        update_eq(id*2+1, m+1, r, lq, rq, val);

        tree[id] = merge(tree[id*2], tree[id*2+1]);
        maxi[id] = max(maxi[id*2], maxi[id*2+1]);
        mini[id] = min(mini[id*2], mini[id*2+1]);
    }

    void update_mod(int id, int l, int r, int lq, int rq, T val) {
        do_lazy(id, l, r);
        if(r < lq || rq < l || maxi[id] < val) return;
        if(lq <= l && r <= rq && maxi[id] == mini[id]) {
            lazy[id] = maxi[id] % val;
            do_lazy(id, l, r);
            return;
        }
        int m = (l + r) / 2;
        update_mod(id*2,   l,   m, lq, rq, val);
        update_mod(id*2+1, m+1, r, lq, rq, val);

        tree[id] = merge(tree[id*2], tree[id*2+1]);
        maxi[id] = max(maxi[id*2], maxi[id*2+1]);
        mini[id] = min(mini[id*2], mini[id*2+1]);
    }
};

segtree<ll> st;
int n, m;
ll a[100010];

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    st.build(1, 1, n, a);
    while(m--) {
        ll t, l, r, k, x;
        scanf("%lld", &t);
        if(t == 1) {
            scanf("%lld %lld", &l, &r);
            printf("%lld\n", st.query(1, 1, n, l, r));
        } else if(t == 2) {
            scanf("%lld %lld %lld", &l, &r, &x);
            st.update_mod(1, 1, n, l, r, x);
        } else if(t == 3) {
            scanf("%lld %lld", &k, &x);
            st.update_eq(1, 1, n, k, k, x);
        } else assert(false);
    }
    return 0;
}