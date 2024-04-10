#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MN 4000100

template<typename T>
struct segtree {
    T tree[4*MN], lazy[4*MN];

    segtree() {
        memset(tree, 0, sizeof tree);
        memset(lazy, 0, sizeof lazy);
    }

    T identity() {
        return 0;
    }

    T merge(T a, T b) {
        return a + b;
    }

    void do_lazy(int id, int l, int r) {
        if(lazy[id]) {
            tree[id] += lazy[id] * (r - l + 1LL);
            if(l != r) {
                lazy[id*2]   += lazy[id];
                lazy[id*2+1] += lazy[id];
            }
            lazy[id] = 0;
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

segtree<ll> rows, cols;
int n, m, w, t;
ll sum;

int main() {
    scanf("%d %d %d", &n, &m, &w);
    while(w--) {
        ll xl, xr, yl, yr, v;
        scanf("%d", &t);
        if(t == 0) {
            scanf("%lld %lld %lld %lld %lld", &xl, &yl, &xr, &yr, &v);
            sum += (xr - xl + 1) * (yr - yl + 1) * v;
            rows.update(1, 1, n, xl, xr, v*(yr-yl+1));
            cols.update(1, 1, m, yl, yr, v*(xr-xl+1));
        } else if(t == 1) {
            scanf("%lld %lld %lld %lld", &xl, &yl, &xr, &yr);
            printf("%lld\n", rows.query(1, 1, n, xl, xr) + cols.query(1, 1, m, yl, yr) - sum);
        } else assert(false);
    }
    return 0;
}