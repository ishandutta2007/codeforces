#include <bits/stdc++.h>
using namespace std;

const int maxn = 35010;
int n, K, a[maxn], f[maxn], g[maxn], lst[maxn];
struct node { int tag, mn; } t[maxn << 2];

#define mid (l + r >> 1)
#define ls (k << 1)
#define rs (k << 1 | 1)
void maintain(int k) {
    t[k].mn = min(t[ls].mn, t[rs].mn);
}

void pushdown(int k) {
    t[ls].tag += t[k].tag, t[ls].mn += t[k].tag;
    t[rs].tag += t[k].tag, t[rs].mn += t[k].tag, t[k].tag = 0;
}

void build(int k, int l, int r) {
    t[k].tag = 0;
    if (l == r) { t[k].mn = f[l]; return; }
    build(ls, l, mid), build(rs, mid + 1, r), maintain(k);
}

void add(int k, int l, int r, int ql, int qr, int v) {
    if (l >= ql && r <= qr) { t[k].mn += v, t[k].tag += v; return; }
    if (t[k].tag) pushdown(k);
    if (mid >= ql) add(ls, l, mid, ql, qr, v);
    if (mid < qr) add(rs, mid + 1, r, ql, qr, v);
    maintain(k);
}

int query(int k, int l, int r, int ql, int qr) {
    if (l >= ql && r <= qr) return t[k].mn;
    if (t[k].tag) pushdown(k);
    int ans = INT_MAX;
    if (mid >= ql) ans = query(ls, l, mid, ql, qr);
    if (mid < qr) ans = min(ans, query(rs, mid + 1, r, ql, qr));
    return ans;
}

int main() {
    scanf("%d %d", &n, &K);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    memset(f, 0x3f, sizeof(f)), f[0] = 0;
    for (int $ = 1; $ <= K; $++, swap(f, g)) {
        build(1, 0, n), memset(lst, 0, sizeof(lst));
        for (int i = $; i <= n; i++) {
            if (lst[a[i]]) add(1, 0, n, 0, lst[a[i]] - 1, i - lst[a[i]]);
            g[i] = query(1, 0, n, 0, i - 1), lst[a[i]] = i;
        }
    }
    printf("%d\n", f[n]);
    return 0;
}