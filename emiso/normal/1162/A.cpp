#include <bits/stdc++.h>

using namespace std;

int n, m, h, tree[400020];

void update(int id, int l, int r, int lq, int rq, int val) {
    if(rq < l || r < lq) return;
    if(lq <= l && r <= rq) tree[id] = min(tree[id], val);
    else {
        int m = (l + r) / 2;
        update(id*2, l, m, lq, rq, val);
        update(id*2+1, m+1, r, lq, rq, val);
    }
}

int query(int id, int l, int r, int pos) {
    if(l == r) return tree[id];
    else {
        int m = (l + r) / 2, ret = tree[id];
        if(pos <= m) ret = min(ret, query(id*2, l, m, pos));
        else ret = min(ret, query(id*2+1, m+1, r, pos));
        return ret;
    }
}

int main() {
    scanf("%d %d %d", &n, &h, &m);
    fill(tree, tree + 400020, h);

    for(int i = 0; i < m; i++) {
        int l, r, x;
        scanf("%d %d %d", &l, &r, &x);
        update(1, 1, n, l, r, x);
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        int x = query(1, 1, n, i);
        ans += x * x;
    }
    printf("%d\n", ans);
    return 0;
}