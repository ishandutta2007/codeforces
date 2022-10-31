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

#define MN 200020

struct node {
    ll sum, lp, rp, L, R, sz;
} tree[4*MN], np;

node merge(node l, node r) {
    node id;
    id.sz = l.sz + r.sz;
    id.L = l.L;
    id.R = r.R;
    
    if(l.lp == l.sz) {
        id.lp = l.sz + (l.R <= r.L) * r.lp;
    } else {
        id.lp = l.lp;
    }
    if(r.rp == r.sz) {
        id.rp = r.sz + (l.R <= r.L) * l.rp;
    } else {
        id.rp = r.rp;
    }

    id.sum = l.sum + r.sum;
    if(l.R <= r.L) {
        id.sum += l.rp * r.lp;    
    }
    return id;
}

void build(int id, int l, int r, ll* a) {
    if(l == r) {
        tree[id] = node({1, 1, 1, a[l], a[l], 1});
        return;
    }
    int m = (l + r) / 2;
    build(id*2,   l,   m, a);
    build(id*2+1, m+1, r, a);
    tree[id] = merge(tree[id*2], tree[id*2+1]);
}

void update(int id, int l, int r, int x, ll y) {
    if(r < x || x < l) return;
    if(l == r) {
        tree[id] = node({1, 1, 1, y, y, 1});
        return;
    }
    int m = (l + r) / 2;
    update(id*2,   l,   m, x, y);
    update(id*2+1, m+1, r, x, y);
    tree[id] = merge(tree[id*2], tree[id*2+1]);
}

node query(int id, int l,int r, int lq, int rq) {
    if(lq > rq || r < lq || rq < l) return np;
    if(lq <= l && r <= rq) return tree[id];
    int m = (l + r) / 2;
    return merge(query(id*2,   l,   m, lq, rq),
                query(id*2+1, m+1, r, lq, rq));
}

ll t = 1, n, q, ans, a[MN];

int main() {
    np = node({0, 0, 0, -10000000000LL, 10000000000LL, 0});
    //scanf("%lld", &t);
    st: ans = 0;
    scanf("%lld %lld", &n, &q);

    for(int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    build(1, 1, n, a);

    while(q--) {
        ll t, x, y;
        scanf("%lld %lld %lld", &t, &x, &y);
        if(t == 1) {
            a[x] = y;
            update(1, 1, n, x, y);
        } else if(t == 2) {
            printf("%lld\n", query(1, 1, n, x, y).sum);
        } else assert(false);
    }

    if(--t) goto st;
    return 0;
}