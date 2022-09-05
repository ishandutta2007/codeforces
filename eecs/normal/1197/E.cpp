#include <bits/stdc++.h>
#define x first
#define y second
#define mid (l + r >> 1)
using namespace std;

const int maxn = 200010, P = 1000000007;
int n, tot, rt;
pair<int, int> p[maxn], ans[maxn];
struct node { int l, r; pair<int, int> p; } t[maxn * 50];

pair<int, int> merge(pair<int, int> p1, pair<int, int> p2) {
    if (p1.x ^ p2.x) return min(p1, p2);
    (p1.y += p2.y) %= P; return p1;
}

void ins(int &k, int l, int r, int p, pair<int, int> v) {
    if (!k) k = ++tot; t[k].p = merge(t[k].p, v);
    if (l == r) return;
    if (mid >= p) ins(t[k].l, l, mid, p, v);
    else ins(t[k].r, mid + 1, r, p, v);
}

pair<int, int> query(int k, int l, int r, int ql, int qr) {
    if (!k || l >= ql && r <= qr) return t[k].p;
    pair<int, int> p = {0, 0};
    if (mid >= ql) p = merge(p, query(t[k].l, l, mid, ql, qr));
    if (mid < qr) p = merge(p, query(t[k].r, mid + 1, r, ql, qr));
    return p;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &p[i].x, &p[i].y), swap(p[i].x, p[i].y);
    }
    sort(p + 1, p + n + 1);
    for (int i = 1; i <= n; i++) {
        pair<int, int> t = query(rt, 1, 1e9, 1, p[i].x);
        t = merge(t, {0, 1}), t.x += p[i].x - p[i].y;
        ins(rt, 1, 1e9, p[i].y, t);
        ans[i] = t, ans[i].x += p[i].y;
        if (p[i].y <= p[n].x) ans[i].x = INT_MAX;
    }
    sort(ans + 1, ans + n + 1);
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        if (ans[i].x == ans[1].x && ans[1].x != INT_MAX) {
            (sum += ans[i].y) %= P;
        }
    }
    printf("%d\n", sum);
    return 0;
}