#include <bits/stdc++.h>

using namespace std;

#define MN 200100

template<typename T>
struct segtree {
    T tree[4*MN], lazy[4*MN], mini[4*MN];

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

    void build(int id, int l, int r, T* a) {
        lazy[id] = 0;
        if(l == r) {
            tree[id] = mini[id] = a[l];
            return;
        }
        int m = (l + r) / 2;
        build(id*2,   l,   m, a);
        build(id*2+1, m+1, r, a);
        tree[id] = merge(tree[id*2], tree[id*2+1]);
        mini[id] = min(mini[id*2], mini[id*2+1]);
    }

    void do_lazy(int id, int l, int r) {
        if(lazy[id]) {
            tree[id] = lazy[id] * (r - l + 1LL);
            mini[id] = lazy[id];
            if(l != r) {
                lazy[id*2]   = lazy[id];
                lazy[id*2+1] = lazy[id];
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

segtree<long long> st;

int traverse(int id, int l, int r, int x, int& y) {
    st.do_lazy(id, l, r);
    if(r < x || st.mini[id] > y) return 0;
    if(x <= l && y >= st.tree[id]) {
        y -= st.tree[id];
        return (r - l + 1);
    }
    if(l == r) return 0;

    int m = (l + r) / 2;
    int ret = traverse(id*2, l, m, x, y);
    ret += traverse(id*2+1, m+1, r, x, y);
    return ret;
}

int n, q, t, x, y;
long long a[200020];

int main() {
    scanf("%d %d", &n, &q);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    st.build(1, 1, n, a);

    vector<int> ids(n+1);
    iota(ids.begin(), ids.end(), 1);

    for(int i = 0; i < q; i++) {
        scanf("%d %d %d", &t, &x, &y);
        if(t == 1) {
            int pos = lower_bound(ids.begin(), ids.begin() + x, y, [&](int l, int r){
                return st.query(1, 1, n, l, l) >= r;
            }) - ids.begin() + 1;
            if(pos <= x) st.update(1, 1, n, pos, x, y);
        } else if(t == 2) {
            printf("%d\n", traverse(1, 1, n, x, y));
        } else assert(false);
    }
    return 0;
}