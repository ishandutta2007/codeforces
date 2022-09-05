#include <bits/stdc++.h>
using namespace std;

const int maxn = 35010;
int n, K, a[maxn], f[maxn], g[maxn], lst[maxn];
struct node { int mx, tag; } t[maxn << 2];

#define mid (l + r >> 1)
#define ls (k << 1)
#define rs (k << 1 | 1)
void pushdown(int k) {
    t[ls].mx += t[k].tag, t[ls].tag += t[k].tag;
    t[rs].mx += t[k].tag, t[rs].tag += t[k].tag, t[k].tag = 0;
}

void build(int k, int l, int r) {
    t[k].tag = 0;
    if (l == r) { t[k].mx = f[l]; return; }
    build(ls, l, mid), build(rs, mid + 1, r);
    t[k].mx = max(t[ls].mx, t[rs].mx);
}

void modify(int k, int l, int r, int ql, int qr, int v) {
    if (l >= ql && r <= qr) { t[k].mx += v, t[k].tag += v; return; }
    if (t[k].tag) pushdown(k);
    if (mid >= ql) modify(ls, l, mid, ql, qr, v);
    if (mid < qr) modify(rs, mid + 1, r, ql, qr, v);
    t[k].mx = max(t[ls].mx, t[rs].mx);
}

int query(int k, int l, int r, int ql, int qr) {
    if (l >= ql && r <= qr) return t[k].mx;
    if (t[k].tag) pushdown(k);
    int s = INT_MIN;
    if (mid >= ql) s = query(ls, l, mid, ql, qr);
    if (mid < qr) s = max(s, query(rs, mid + 1, r, ql, qr));
    return s;
}

int main() {
    scanf("%d %d", &n, &K);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    memset(f, -0x3f, sizeof(f)), f[0] = 0;
    for (int i = 1; i <= K; i++, swap(f, g)) {
        memset(g, -0x3f, sizeof(g)), build(1, 0, n);
        memset(lst, 0, sizeof(lst));
        for (int j = 1; j <= n; j++) {
            if (lst[a[j]]) modify(1, 0, n, 0, lst[a[j]] - 1, -1);
            modify(1, 0, n, 0, j - 1, 1), lst[a[j]] = j;
            g[j] = query(1, 0, n, 0, j - 1);
        }
    }
    printf("%d\n", f[n]);
    return 0;
}