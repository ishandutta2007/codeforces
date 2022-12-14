#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#define MN 300000
#define uint unsigned int
using namespace std;
int n, N = 1, fa[MN + 5];
int big[MN + 5], mx[MN + 5], dfn[MN + 5], bottom[MN + 5], cc, top[MN + 5], dd[MN + 5], tree[MN + 5], contribute[MN + 5];
int num[MN + 5][19], mex1[MN + 5], mex2[MN + 5];
uint bits[MN + 5]; int bitof[(1 << 19) + 5];
bool lblock[MN + 5];
vector<int> v[MN + 5];

struct info{
    int rmex, out0, out1, sum0, sum1;
    bool lblock;
    info operator + (const info &r) {
        info res;
        res.lblock = lblock;
        res.rmex = r.rmex;
        // printf("combining %d %d %d %d %d\n", r.lblock, r.out0, r.out1, out0, out1);
        if (!r.lblock && r.out0 == rmex) {
            res.out0 = out1;
            res.sum0 = r.sum0 + sum1;
        } else {
            res.out0 = out0;
            res.sum0 = r.sum0 + sum0;
        }
        if (!r.lblock && r.out1 == rmex) {
            res.out1 = out1;
            res.sum1 = r.sum1 + sum1;
        } else {
            res.out1 = out0;
            res.sum1 = r.sum1 + sum0;
        }
        return res;
    }
};

struct Tree {
    int l, r;
    info x;
}T[MN * 4 + 5];

inline void merge(int x) {
    int l = x << 1, r = l | 1;
    T[x].x = T[l].x + T[r].x;
}

inline int lowbit(uint u) {
    return bitof[~u & (-(~u))];
}

void propagate(int t) {
    // printf("propagate %d\n", t);
    while(t >>= 1) merge(t);
}

inline void update(int x) {
    // printf("update %d <= %d\n", x, N);
    if (x <= N) {
        uint s = bits[x];
        mex1[x] = lowbit(s);
        s ^= (1 << mex1[x]);
        mex2[x] = lowbit(s);
        T[tree[dfn[x]]].x = (info) {
            mex1[x], mex1[x], mex2[x], mex1[x], mex2[x], 
            lblock[x]
        };
        // printf("update results %u %d %d %d to %d\n", bits[x], mex1[x], mex2[x], lblock[x], tree[dfn[x]]);
    } else {
        T[tree[dfn[x]]].x = (info) {
            20, 20, 20, 0, 0
        };
        // printf("update failed to %d\n", tree[dfn[x]]);
    }
}

void change(int x, int w, int W) {
    // printf("change %d %d %d\n", x, w, W);
    if (w == W) return;
    bool updated = false;
    if (!num[x][W]++) {
        bits[x] |= 1 << W;
        if (W == mex1[x] || W == mex2[x]) {
            update(x);
            updated = true;
        }
    }
    if (w >= 0 && !--num[x][w]) {
        bits[x] ^= 1 << w;
        if (w < mex2[x]) {
            update(x);
            updated = true;
        }
    }
    if (updated) {
        propagate(tree[dfn[x]]);
    }
}

void dfs(int x) {
    big[x] = 1;
    for (int i = 0; i < v[x].size(); ++i) {
        int to = v[x][i];
        fa[to] = x; dfs(to);
        big[x] += big[to];
        if (big[to] > big[mx[x]]) {
            mx[x] = to;
        }
    }
}

void dfs2(int x, int tp) {
    top[x] = tp; dfn[x] = ++cc; bottom[tp] = cc; dd[cc] = x;
    if (tp == x) contribute[x] = -1;
    if (mx[x]) dfs2(mx[x], tp);
    for (int i = 0; i < v[x].size(); ++i) {
        int to = v[x][i];
        if (to != mx[x]) {
            lblock[to] = true;
            dfs2(to, to);
        }
    }
}

void build(int x, int l, int r) {
    if ((T[x].l = l) == (T[x].r = r)) {
        tree[l] = x; update(dd[l]);
        return;
    }
    int mid = l + r >> 1;
    build(x << 1, l, mid);
    build(x << 1 | 1, mid + 1, r);
    merge(x);
}

info Query(int x, int l, int r) {
    // printf("query %d %d %d\n", x, l, r);
    if (T[x].l == l && T[x].r == r) {
        return T[x].x;
    }
    int mid = T[x].l + T[x].r >> 1;
    if (r <= mid) return Query(x << 1, l, r);
    if (l > mid) return Query(x << 1 | 1, l, r);
    return Query(x << 1, l, mid) + Query(x << 1 | 1, mid + 1, r);
}

int main() {
    scanf("%d", &n); ++n;
    for (int i = 0; i < 20; ++i) bitof[1 << i] = i;
    for (int i = 2, x; i <= n; ++i) {
        scanf("%d", &x);
        v[x].push_back(i);
    }
    dfs(1); dfs2(1, 1); build(1, 1, n);
    while (++N <= n) {
        update(N); propagate(tree[dfn[N]]);
        for (int t = N; top[t] > 1; t = fa[top[t]]) {
            info res = Query(1, dfn[top[t]], bottom[top[t]]);
            // printf("query res %d %d %d %d %d\n", res.out0, res.out1, res.sum0, res.sum1, res.rmex);
            int nc = res.out0;
            change(fa[top[t]], contribute[top[t]], nc);
            contribute[top[t]] = nc;
        }
        printf("%d\n", T[1].x.sum0);
    }
    return 0;
}