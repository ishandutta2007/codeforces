#include <bits/stdc++.h>

using namespace std;

#define MN 200020

int n, q, a[MN];
set<int> occ[MN];

struct node {
    int mini, maxfreq, sum, l, r, lazy;
    node() : mini(0), maxfreq(0), sum(0), l(0), r(0), lazy(0) {}
};

node tree[8*MN];

void push_lazy(int id, int l, int r) {
    if(tree[id].lazy) {
        tree[id].mini += tree[id].lazy;
        if(l != r) {
            tree[id*2  ].lazy += tree[id].lazy;
            tree[id*2+1].lazy += tree[id].lazy;
        }
        tree[id].lazy = 0;
    }
}

node merge(node a, node b) {
    node c;
    if(a.mini == b.mini) {
        c.mini = a.mini;
        c.maxfreq = max(a.maxfreq, b.maxfreq);
        c.sum = a.sum + b.sum - min(a.r, b.l);
        c.l = a.l;
        c.r = b.r;
    } else if(a.mini < b.mini) {
        c.mini = a.mini;
        c.maxfreq = max(a.maxfreq, b.maxfreq);
        c.sum = a.sum - a.r + max(a.r, b.maxfreq);
        c.l = a.l;
        c.r = max(a.r, b.maxfreq);
    } else {
        c.mini = b.mini;
        c.maxfreq = max(a.maxfreq, b.maxfreq);
        c.sum = b.sum - b.l + max(b.l, a.maxfreq);
        c.l = max(b.l, a.maxfreq);
        c.r = b.r;
    }
    return c;
}

void upd_range(int id, int l, int r, int lq, int rq, int delta) {
    push_lazy(id, l, r);
    if(rq < l || r < lq) return;
    if(lq <= l && r <= rq) {
        tree[id].lazy += delta;
        push_lazy(id, l, r);
    } else {
        int m = (l + r) / 2;
        upd_range(id*2  , l,   m, lq, rq, delta);
        upd_range(id*2+1, m+1, r, lq, rq, delta);
        tree[id] = merge(tree[id*2], tree[id*2+1]);
    }
}

void upd_freq(int id, int l, int r, int x, int val) {
    push_lazy(id, l, r);
    if(x < l || r < x) return;
    if(l == r) {
        tree[id].maxfreq = tree[id].sum = tree[id].l = tree[id].r = val;
    } else {
        int m = (l + r) / 2;
        upd_freq(id*2  , l,   m, x, val);
        upd_freq(id*2+1, m+1, r, x, val);
        tree[id] = merge(tree[id*2], tree[id*2+1]);
    }
}

int query() {
    if(tree[1].mini == 0) return tree[1].sum;
    return tree[1].maxfreq;
}

int main() {
    scanf("%d %d", &n, &q);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        occ[a[i]].insert(i);
    }

    for(int i = 0; i < MN; i++) {
        if(occ[i].size() >= 1) {
            upd_range(1, 1, 2*n, 2**occ[i].begin(), 2**occ[i].rbegin(), 1);
            upd_freq(1, 1, 2*n, 2**occ[i].begin(), occ[i].size());
        }
    }

    printf("%d\n", n - query());

    for(int i = 0; i < q; i++) {
        int p, x, y;
        scanf("%d %d", &p, &x);
        y = a[p];


        if(occ[y].size() >= 1) {
            upd_range(1, 1, 2*n, 2**occ[y].begin(), 2**occ[y].rbegin(), -1);
            upd_freq(1, 1, 2*n, 2**occ[y].begin(), 0);
        }
        occ[y].erase(p);
        if(occ[y].size() >= 1) {
            upd_range(1, 1, 2*n, 2**occ[y].begin(), 2**occ[y].rbegin(), 1);
            upd_freq(1, 1, 2*n, 2**occ[y].begin(), occ[y].size());
        }

        /// <<<<<<<<<

        if(occ[x].size() >= 1) {
            upd_range(1, 1, 2*n, 2**occ[x].begin(), 2**occ[x].rbegin(), -1);
            upd_freq(1, 1, 2*n, 2**occ[x].begin(), 0);
        }
        occ[x].insert(p);
        if(occ[x].size() >= 1) {
            upd_range(1, 1, 2*n, 2**occ[x].begin(), 2**occ[x].rbegin(), 1);
            upd_freq(1, 1, 2*n, 2**occ[x].begin(), occ[x].size());
        }

        a[p] = x;
        printf("%d\n", n - query());
    }

    return 0;
}