#include <bits/stdc++.h>

using namespace std;

#define MN 500100

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
            tree[id] += lazy[id];
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

int n, l[MN], r[MN], t[MN], dp[MN];
vector<int> ys;

segtree<int> st[2];
vector<pair<int, int>> evs[MN];

int main() {
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d %d %d", &l[i], &r[i], &t[i]);
        ys.push_back(l[i]);
        ys.push_back(r[i]);
    }

    sort(ys.begin(), ys.end());
    ys.resize(unique(ys.begin(), ys.end()) - ys.begin());

    for(int i = 0; i < n; i++) {
        l[i] = lower_bound(ys.begin(), ys.end(), l[i]) - ys.begin() + 1;
        r[i] = lower_bound(ys.begin(), ys.end(), r[i]) - ys.begin() + 1;
        evs[l[i]].emplace_back(r[i], t[i] - 1);
    }

    int ans = 0, N = 2*n+5;
    for(int l = N-1; l >= 1; l--) {
        for(auto tt : evs[l]) {
            int r = tt.first, t = tt.second;
            st[t].update(1, 1, N, r + 1, N, 1);
        }
        int tmp = max(st[0].query(1, 1, N, l + 1, N),
                      st[1].query(1, 1, N, l + 1, N));
        st[0].update(1, 1, N, l, l, tmp);
        st[1].update(1, 1, N, l, l, tmp);
        ans = max(ans, tmp);
    }

    printf("%d\n", ans);
    return 0;
}