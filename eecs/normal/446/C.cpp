#include <bits/stdc++.h>
using namespace std;

const int maxn = 300010, P = 1000000009;
int n, m, fib[maxn], pre[maxn], a[maxn];
int tag1[maxn << 2], tag2[maxn << 2], sum[maxn << 2];

#define mid ((l + r) >> 1)
#define ls (k << 1)
#define rs (k << 1 | 1)
void apply(int k, int l, int r, int a, int b) {
    sum[k] = (sum[k] + 1LL * a * pre[r - l + 1] + 1LL * b * (pre[r - l + 2] + P - 1)) % P;
    (tag1[k] += a) %= P, (tag2[k] += b) %= P;
}

void pushdown(int k, int l, int r) {
    apply(ls, l, mid, tag1[k], tag2[k]);
    apply(rs, mid + 1, r, (1LL * tag1[k] * fib[mid - l] + 1LL * tag2[k] * fib[mid - l + 1]) % P,
        (1LL * tag1[k] * fib[mid - l + 1] + 1LL * tag2[k] * fib[mid - l + 2]) % P);
    tag1[k] = tag2[k] = 0;
}

void build(int k, int l, int r) {
    if (l == r) { sum[k] = a[l]; return; }
    build(ls, l, mid), build(rs, mid + 1, r);
    sum[k] = (sum[ls] + sum[rs]) % P;
}

void add(int k, int l, int r, int ql, int qr) {
    if (l >= ql && r <= qr) { apply(k, l, r, l > ql ? fib[l - ql - 1] : 1, fib[l - ql]); return; }
    if (tag1[k] || tag2[k]) pushdown(k, l, r);
    if (mid >= ql) add(ls, l, mid, ql, qr);
    if (mid < qr) add(rs, mid + 1, r, ql, qr);
    sum[k] = (sum[ls] + sum[rs]) % P;
}

int query(int k, int l, int r, int ql, int qr) {
    if (l >= ql && r <= qr) return sum[k];
    if (tag1[k] || tag2[k]) pushdown(k, l, r);
    int s = 0;
    if (mid >= ql) s = query(ls, l, mid, ql, qr);
    if (mid < qr) (s += query(rs, mid + 1, r, ql, qr)) %= P;
    return s;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    build(1, 1, n);
    fib[1] = fib[2] = 1;
    for (int i = 3; i <= n + 1; i++) {
        fib[i] = (fib[i - 1] + fib[i - 2]) % P;
    }
    for (int i = 1; i <= n + 1; i++) {
        pre[i] = (pre[i - 1] + fib[i]) % P;
    }
    while (m--) {
        int op, l, r;
        scanf("%d %d %d", &op, &l, &r);
        if (op == 1) add(1, 1, n, l, r);
        else printf("%d\n", query(1, 1, n, l, r));
    }
    return 0;
}