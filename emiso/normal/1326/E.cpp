#include <bits/stdc++.h>

using namespace std;
#define MN 300100

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
        return max(a, b);
    }

    void build(int id, int l, int r, T* a) {
        if(l == r) {
            tree[id] = a[l];
            lazy[id] = 0;
            return;
        }
        int m = (l + r) / 2;
        build(id*2,   l,   m, a);
        build(id*2+1, m+1, l, a);
        tree[id] = merge(tree[id*2], tree[id*2+1]);
    }

    void do_lazy(int id, int l, int r) {
        if(lazy[id]) {
            tree[id] += lazy[id]; /// max
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

int n, p[MN], q[MN], where[MN];

int main() {
    segtree<int> tree;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
        where[p[i]] = i;
    }
    for(int i = 1; i <= n; i++) {
        scanf("%d", &q[i]);
    }

    int last = n;
    tree.update(1, 1, n, 1, where[last], 1);

    for(int i = 1; i <= n; i++) {
        printf("%d ", last);

        tree.update(1, 1, n, 1, q[i], -1);
        while(last > 1 && tree.query(1, 1, n, 1, n) <= 0) {
            last--;
            tree.update(1, 1, n, 1, where[last], 1);
        }
    }

    return 0;
}