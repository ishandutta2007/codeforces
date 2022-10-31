#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#ifdef EBUG
#include "trace.h"
#else
template<typename... Args> void trace(Args... args) {}
template<typename... Args> void recInit(Args... args) {}
template<typename... Args> void recEnd(Args... args) {}
#define trace2(args...) trace(args)
#endif

template<typename T>
struct segtree_beats {
    #define MN 200020
    #define L(id) (id*2)
    #define R(id) (id*2+1)
    const T INF = numeric_limits<T>::max() / 2;

    T tree[4*MN]; /// sum
    T max1[4*MN], max2[4*MN], maxcnt[4*MN];
    T min1[4*MN], min2[4*MN], mincnt[4*MN];
    T lazy_add[4*MN];
    int built;

    segtree_beats() {
        built = 0;
    }

    void init(int id, T a) {
        tree[id] = max1[id] = min1[id] = a;
        max2[id] = -INF;
        min2[id] = INF;
        maxcnt[id] = mincnt[id] = 1;
    }

    void merge_nodes(int id, int l, int r) {
        tree[id] = tree[l] + tree[r]; /// sum

        max1[id] = max(max1[l], max1[r]);
        if(max1[l] == max1[r]) {
            maxcnt[id] = maxcnt[l] + maxcnt[r];
            max2[id] = max(max2[l], max2[r]);
        } else if(max1[l] > max1[r]) {
            maxcnt[id] = maxcnt[l];
            max2[id] = max(max2[l], max1[r]);
        } else {
            maxcnt[id] = maxcnt[r];
            max2[id] = max(max1[l], max2[r]);
        }

        min1[id] = min(min1[l], min1[r]);
        if(min1[l] == min1[r]) {
            mincnt[id] = mincnt[l] + mincnt[r];
            min2[id] = min(min2[l], min2[r]);
        } else if(min1[l] < min1[r]) {
            mincnt[id] = mincnt[l];
            min2[id] = min(min2[l], min1[r]);
        } else {
            mincnt[id] = mincnt[r];
            min2[id] = min(min1[l], min2[r]);
        }

        lazy_add[id] = 0;
    }

    void build(int id, int l, int r, T *a) {
        built = 1;
        if(l == r) {
            init(id, a[l]);
            return;
        }
        int m = (l + r) / 2;
        build(L(id),   l,   m, a);
        build(R(id), m+1, r, a);
        merge_nodes(id, L(id), R(id));
    }

    void do_lazy(int id, int l, int r) {
        if(l != r) {
            if(lazy_add[id]) {
                int m = (l + r) / 2;
                apply_add(L(id), l,   m, lazy_add[id]);
                apply_add(R(id), m+1, r, lazy_add[id]);
                lazy_add[id] = 0;
            }

            if(max1[id] < max1[L(id)]) apply_min(L(id), max1[id]);
            if(min1[id] > min1[L(id)]) apply_max(L(id), min1[id]);

            if(max1[id] < max1[R(id)]) apply_min(R(id), max1[id]);
            if(min1[id] > min1[R(id)]) apply_max(R(id), min1[id]);
        }
    }

    void apply_add(int id, int l, int r, T val) {
        tree[id] += val * (r - l + 1);
        max1[id] += val;
        max2[id] = max(max2[id] + val, -INF);
        min1[id] += val;
        min2[id] = min(min2[id] + val, INF);
        lazy_add[id] += val;
    }

    void apply_min(int id, T val) {
        tree[id] -= maxcnt[id] * (max1[id] - val);
        max1[id] = val;
        if(val < min1[id]) min1[id] = val;
        else if(val < min2[id]) min2[id] = val;
    }

    void apply_max(int id, T val) {
        tree[id] += mincnt[id] * (val - min1[id]);
        min1[id] = val;
        if(val > max1[id]) max1[id] = val;
        else if(val > max2[id]) max2[id] = val;
    }

    T query_sum(int id, int l, int r, int lq, int rq) {
        if(!built) assert(false);
        if(lq > rq || r < lq || rq < l) return 0;
        if(lq <= l && r <= rq) return tree[id];
        int m = (l + r) / 2;
        do_lazy(id, l, r);
        return query_sum(L(id), l,   m, lq, rq)
                + query_sum(R(id), m+1, r, lq, rq);
    }

    pair<T, T> query_min_max(int id, int l, int r, int lq, int rq) {
        if(!built) assert(false);
        if(lq > rq || r < lq || rq < l) return {INF, -INF};
        if(lq <= l && r <= rq) return {min1[id], max1[id]};
        int m = (l + r) / 2;
        do_lazy(id, l, r);
        auto ql = query_min_max(L(id), l,   m, lq, rq);
        auto qr = query_min_max(R(id), m+1, r, lq, rq);
        return {min(ql.first, qr.first), max(ql.second, qr.second)};
    }
};

segtree_beats<ll> st;

ll t = 1, n, q, ans, a[MN], b[MN];
//char s[MN]; string str;

int main() {
    //scanf("%lld", &t);
    st: ans = 0;
    scanf("%lld %lld", &n, &q);

    for(int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &b[i]);
        a[i] = b[i] - a[i];
    }
    for(int i = 2; i <= n; i++) {
        a[i] += a[i-1];
    }
    st.build(1, 1, n, a);

    while(q--) {
        int l, r;
        scanf("%d %d", &l, &r);
        if(a[r] != a[l-1]) puts("-1");
        else {
            auto tmp = st.query_min_max(1, 1, n, l, r);
            ll mini = tmp.first - a[l-1];
            if(mini < 0) puts("-1");
            else printf("%lld\n", tmp.second - a[l-1]);
        }
    }
    if(--t) goto st;
    return 0;
}