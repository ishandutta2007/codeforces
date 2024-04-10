#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, m, a[MN], id[MN], l[MN], r[MN];
vector<pair<int, int>> ev[MN];
int ans, pai[MN];

template<typename T>
struct segtree {
    T tree[4*MN], lazy[4*MN];

    segtree() {
        memset(tree, 0, sizeof tree);
        memset(lazy, 0, sizeof lazy);
    }

    T identity() {
        return {INT_MAX, 1};
    }

    T merge(T a, T b) {
        return min(a, b);
    }

    void build(int id, int l, int r, T a) {
        lazy[id] = {INT_MAX, 1};
        if(l == r) {
            tree[id] = a;
            return;
        }
        int m = (l + r) / 2;
        build(id*2,   l,   m, a);
        build(id*2+1, m+1, r, a);
        tree[id] = merge(tree[id*2], tree[id*2+1]);
    }

    void do_lazy(int id, int l, int r) {
        if(lazy[id] != pair<int, int>{INT_MAX, 1}) {
            tree[id] = min(tree[id], lazy[id]);
            if(l != r) {
                lazy[id*2]   = min(lazy[id], lazy[id*2]);
                lazy[id*2+1] = min(lazy[id], lazy[id*2+1]);
            }
            lazy[id] = {INT_MAX, 1};
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

segtree<pair<int, int>> st;

int main() {
    st: ans = INT_MAX;
    scanf("%lld %lld", &n, &m);

    vector<ll> ys;
    for(int i = 0; i < m; i++) {
        scanf("%lld %lld %lld", &id[i], &l[i], &r[i]);
        ys.push_back(l[i]);
        ys.push_back(r[i]);
    }
    sort(ys.begin(), ys.end());
    ys.resize(unique(ys.begin(), ys.end()) - ys.begin());
    for(int i = 0; i < m; i++) {
        l[i] = lower_bound(ys.begin(), ys.end(), l[i]) - ys.begin() + 1LL;
        r[i] = lower_bound(ys.begin(), ys.end(), r[i]) - ys.begin() + 1LL;
        ev[id[i]].push_back({l[i], r[i]});
    }
    int N = ys.size() + 1;
    ev[0].push_back({1, N});

    st.build(1, 1, N, {n + 1, n + 1});
    for(int i = n; i >= 0; i--) {
        pair<int, int> res = {INT_MAX, 1};
        for(auto tt : ev[i]) {
            int l = tt.first, r = tt.second;
            auto tmp = st.query(1, 1, N, l, r);
            tmp.first -= (i + 1);
            res = min(res, tmp);
        }
        pai[i] = res.second;
        if(i == 0) ans = min(ans, res.first);
        for(auto tt : ev[i]) {
            int l = tt.first, r = tt.second;
            st.update(1, 1, N, l, r, {res.first + i, i});
        }
    }

    printf("%d\n", ans);
    for(int i = 1, tmp = pai[0]; i <= n; i++) {
        if(i == tmp) {
            tmp = pai[tmp];
            continue;
        }
        printf("%d ", i);
    }
    return 0;
}