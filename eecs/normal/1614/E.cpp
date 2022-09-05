#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010, INF = 1e9;
int n, rt, tot;
struct node { int l, r, tag; } t[maxn * 50];

#define mid ((l + r) >> 1)
void add(int &k, int l, int r, int ql, int qr, int v) {
    if (!k) k = ++tot;
    if (l >= ql && r <= qr) { t[k].tag += v; return; }
    if (mid >= ql) add(t[k].l, l, mid, ql, qr, v);
    if (mid < qr) add(t[k].r, mid + 1, r, ql, qr, v);
}

int query(int k, int l, int r, int p, int tag = 0) {
    tag += t[k].tag;
    if (!k || l == r) return p + tag;
    return mid >= p ? query(t[k].l, l, mid, p, tag) : query(t[k].r, mid + 1, r, p, tag);
}

int main() {
    scanf("%d", &n);
    int ans = 0;
    while (n--) {
        int T, k;
        scanf("%d %d", &T, &k);
        int l = 0, r = INF, p1 = -1, p2 = INF + 1;
        while (l <= r) {
            query(1, 0, INF, mid) < T ? l = (p1 = mid) + 1 : r = mid - 1;
        }
        l = 0, r = INF;
        while (l <= r) {
            query(1, 0, INF, mid) > T ? r = (p2 = mid) - 1 : l = mid + 1;
        }
        if (~p1) add(rt, 0, INF, 0, p1, 1);
        if (p2 <= INF) add(rt, 0, INF, p2, INF, -1);
        while (k--) {
            int x;
            scanf("%d", &x), (x += ans) %= INF + 1;
            printf("%d\n", ans = query(1, 0, INF, x));
        }
    }
    return 0;
}