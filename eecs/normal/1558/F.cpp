#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int T, n, a[maxn], b[maxn], tag[maxn << 2], mx[maxn << 2];

#define mid ((l + r) >> 1)
#define ls (k << 1)
#define rs (k << 1 | 1)
void apply(int k, int v) {
    tag[k] += v, mx[k] += v;
}

void pushdown(int k) {
    apply(ls, tag[k]), apply(rs, tag[k]), tag[k] = 0;
}

void build(int k, int l, int r) {
    tag[k] = 0, mx[k] = r - 2;
    if (l < r) build(ls, l, mid), build(rs, mid + 1, r);
}

void add(int k, int l, int r, int ql, int qr, int v) {
    if (l >= ql && r <= qr) { apply(k, v); return; }
    if (tag[k]) pushdown(k);
    if (mid >= ql) add(ls, l, mid, ql, qr, v);
    if (mid < qr) add(rs, mid + 1, r, ql, qr, v);
    mx[k] = max(mx[ls], mx[rs]);
}

int query(int k, int l, int r, int ql, int qr) {
    if (l >= ql && r <= qr) return mx[k];
    if (tag[k]) pushdown(k);
    int s = INT_MIN;
    if (mid >= ql) s = query(ls, l, mid, ql, qr);
    if (mid < qr) s = max(s, query(rs, mid + 1, r, ql, qr));
    return s;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        bool flag = is_sorted(a + 1, a + n + 1);
        for (int i = 1; i < n; i += 2) {
            if (a[i] > a[i + 1]) swap(a[i], a[i + 1]);
        }
        for (int i = 1; i <= n; i++) {
            b[a[i]] = i;
        }
        build(1, 1, n);
        int ans = 0;
        for (int i = 1, rb = 0; i < n; i++) {
            add(1, 1, n, b[i], n, -2), rb = max(rb, b[i]);
            add(1, 1, n, b[i], b[i], -1e9);
            ans = max(ans, i + 1 + query(1, 1, n, 1, rb));
        }
        printf("%d\n", flag ? 0 : (ans + 1));
    }
    return 0;
}