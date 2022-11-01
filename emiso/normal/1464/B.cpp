#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, x, y, ans, a[MN], cur, qmark;
const ll INF = 11234567890123;

template<typename T>
struct segtree {
    T tree[4*MN];
    ll lazy[4*MN];

    segtree() {
        memset(lazy, 0, sizeof lazy);
    }

    T identity() {
        return {-INF, -INF};
    }

    T merge(T a, T b) {
        return (a > b) ? a : b;
    }

    void do_lazy(int id, int l, int r) {
        if(lazy[id]) {
            tree[id].first += lazy[id]; /// max
            if(l != r) {
                lazy[id*2]   += lazy[id];
                lazy[id*2+1] += lazy[id];
            }
            lazy[id] = 0;
        }
    }

    void build(int id, int l, int r) {
        lazy[id] = 0;
        if(l == r) {
            tree[id] = {- ((l-1LL)*x + (n-l)*y), l};
            return;
        }
        int m = (l + r) / 2;
        build(id*2,   l,   m);
        build(id*2+1, m+1, r);
        tree[id] = merge(tree[id*2], tree[id*2+1]);
    }

    T query(int id, int l, int r, int lq, int rq) {
        do_lazy(id, l, r);
        if(r < lq || rq < l) return identity();
        if(lq <= l && r <= rq) return tree[id];
        int m = (l + r) / 2;
        return merge(query(id*2,   l,   m, lq, rq),
                     query(id*2+1, m+1, r, lq, rq));
    }

    void update(int id, int l, int r, int lq, int rq, ll val) {
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

segtree<pair<ll, ll>> st;

char s[1000100];

void change(int idx) {
    pair<ll, ll> pos = st.query(1, 1, n, idx, idx);
    cur -= pos.first;
    st.update(1, 1, n, 1, idx-1, x + y);
    st.update(1, 1, n, idx + 1, n, x + y);
    st.update(1, 1, n, idx, idx, -INF);
}

int main() {
    scanf("%s %lld %lld", s, &x, &y);
    n = strlen(s);

    st.build(1, 1, n);
    for(int i = 1; i <= n; i++) {
        if(s[i-1] == '0') st.update(1, 1, n, i, i, -INF);
        else if(s[i-1] == '1') change(i);
        else qmark++;
    }
    ans = cur;

    while(qmark--) {
        pair<ll, ll> nxt = st.query(1, 1, n, 1, n);
        change(nxt.second);
        // cur -= nxt.first;
        if(cur < ans) ans = cur;
    }

    printf("%lld\n", ans);
    return 0;
}