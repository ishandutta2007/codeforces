#include <bits/stdc++.h>

#define MN 300030

using namespace std;

template<typename T>
struct segtree {
    pair<int, int> tree[4*MN];
    int lazy[4*MN];

    segtree() {
    }

    void build(int id, int l, int r, T* a) {
        lazy[id] = 0;
        if(l == r) {
            tree[id] = {l - a[l], l};
            return;
        }
        int m = (l + r) / 2;
        build(id*2,   l,   m, a);
        build(id*2+1, m+1, r, a);
        tree[id] = merge(tree[id*2], tree[id*2+1]);
    }

    pair<int, int> identity() {
        return {10000000, -1};
    }

    pair<int, int> merge(pair<int, int> a, pair<int, int> b) {
        if(a.first < b.first) return a;
        return b;
    }

    void do_lazy(int id, int l, int r) {
        if(lazy[id]) {
            tree[id].first += lazy[id];
            if(l != r) {
                lazy[id*2]   += lazy[id];
                lazy[id*2+1] += lazy[id];
            }
            lazy[id] = 0;
        }
    }

    pair<int, int> query(int id, int l, int r, int lq, int rq) {
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

int n, q, a[MN], ans[MN];
vector<pair<int, int>> ev[MN];
segtree<int> st;
fenwick_tree<int> bit(MN);

int main() {
    scanf("%d %d", &n, &q);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    st.build(1, 1, n, a);

    for(int i = 1; i <= q; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        ev[x+1].emplace_back(n-y, i);
    }

    for(int l = n; l >= 1; l--) {
        while(1) {
            pair<int, int> mini = st.query(1, 1, n, l, n);
            if(mini.first < 0) {
                st.update(1, 1, n, mini.second, mini.second, 3*n);
            } else if(mini.first == 0) {
                bit.update(mini.second, 1);
                st.update(1, 1, n, mini.second, n, -1);
            } else break;
        }

        for(auto tt : ev[l]) {
            ans[tt.second] = bit.query(tt.first);
        }
    }


    for(int i = 1; i <= q; i++)
        printf("%d\n", ans[i]);

    return 0;
}