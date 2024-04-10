#include <bits/stdc++.h>

using namespace std;

#define MN 100010

template<typename T>
struct segtree {
    T tree[4*MN], lazy[4*MN];
    int maxi;

    segtree(int f) {
        memset(tree, 0, sizeof tree);
        memset(lazy, 0, sizeof lazy);
        maxi = f;
    }

    T identity() { return (maxi ? -MN : MN); }

    T merge(T a, T b) {
        return (maxi ? max(a, b) : min(a, b));
    }

    void build(int id, int l, int r) {
        lazy[id] = identity();
        if(l == r) {
            tree[id] = identity();
            return;
        }
        int m = (l + r) / 2;
        build(id*2,   l,   m);
        build(id*2+1, m+1, r);
        tree[id] = merge(tree[id*2], tree[id*2+1]);
    }

    void do_lazy(int id, int l, int r) {
        if(lazy[id] != identity()) {
            tree[id] = merge(tree[id], lazy[id]); /// max
            if(l != r) {
                lazy[id*2]   = merge(lazy[id*2],   lazy[id]);
                lazy[id*2+1] = merge(lazy[id*2+1], lazy[id]);
            }
            lazy[id] = identity();
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
        if(r < lq || rq < l || lq > rq) return;
        if(lq <= l && r <= rq) {
            lazy[id] = merge(lazy[id], val);
            do_lazy(id, l, r);
            return;
        }
        int m = (l + r) / 2;
        update(id*2,   l,   m, lq, rq, val);
        update(id*2+1, m+1, r, lq, rq, val);
        tree[id] = merge(tree[id*2], tree[id*2+1]);
    }
};

segtree<int> smax(1), smin(0);

int n, a[MN], b[MN], ia[MN], ib[MN];

int main() {
    scanf("%d", &n);
    smax.build(1, 1, n);
    smin.build(1, 1, n);

    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        ia[a[i]] = i;
    }
    for(int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
        ib[b[i]] = i;
    }
    for(int i = 1; i <= n; i++) {
        if(ib[i] < ia[i]) {
            smax.update(1, 1, n, 1, ib[i], 1-(ia[i]-ib[i]));
            smin.update(1, 1, n, ib[i]+1, ib[i]+1+n-ia[i], ib[i]+1+n-ia[i]);
            smax.update(1, 1, n, ib[i]+1+n-ia[i]+1, n, ib[i]+1+n-ia[i]);
        } else { /// ib[i] == ia[i]
            smin.update(1, 1, n, 1, ib[i]-ia[i]+1, ib[i]-ia[i]+1);
            smax.update(1, 1, n, ib[i]-ia[i]+2, ib[i], ib[i]-ia[i]+1);
            smin.update(1, 1, n, ib[i]+1, n, n + ib[i]-ia[i]+1);
        }
    }

    for(int i = 1; i <= n; i++) {
        int l = smax.query(1, 1, n, i, i);
        int r = smin.query(1, 1, n, i, i);
        //printf("|> %d %d %d\n", l, i, r);
        assert(l <= i && r >= i);
        printf("%d\n", min(i - l, r - i));
    }
}