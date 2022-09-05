#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, rt, tot, a[maxn], c[maxn], id[maxn];
struct node { int l, r, cnt; } t[maxn << 5];

#define mid (l + r >> 1)
void ins(int &k, int l, int r, int p) {
    if (!k) k = ++tot; t[k].cnt++;
    if (l == r) return;
    mid >= p ? ins(t[k].l, l, mid, p) : ins(t[k].r, mid + 1, r, p);
}

int query(int k, int l, int r, int p) {
    if (t[k].cnt == r - l + 1) return 0;
    if (!k) return max(l, p);
    int v = 0;
    if (mid >= p) v = query(t[k].l, l, mid, p);
    return v ? v : query(t[k].r, mid + 1, r, p);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &c[i]);
    }
    iota(id + 1, id + n + 1, 1);
    sort(id + 1, id + n + 1, [&](int x, int y) { return c[x] > c[y]; });
    long long ans = 0;
    for (int $ = 1; $ <= n; $++) {
        int i = id[$], v = query(rt, 1, (int)1e9 + maxn, a[i]);
        ans += 1LL * c[i] * (v - a[i]), ins(rt, 1, int(1e9) + maxn, v);
    }
    printf("%lld\n", ans);
    return 0;
}