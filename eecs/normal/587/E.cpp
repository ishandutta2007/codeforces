#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, q, a[maxn], xors[maxn << 2];

struct node {
    int a[31];
    void clear() { memset(a, 0, sizeof(a)); }

    void ins(int x) {
        for (int i = 0; i < 31; i++) if (x >> i & 1) {
            if (!a[i]) { a[i] = x; break; }
            x ^= a[i];
        }
    }
} t[maxn << 2];

node merge(node A, node B) {
    for (int x : B.a) if (x) A.ins(x);
    return A;
}

#define mid (l + r >> 1)
#define ls (k << 1)
#define rs (k << 1 | 1)
void build(int k, int l, int r) {
    if (l == r) { t[k].ins(xors[k] = a[l]); return; }
    build(ls, l, mid), build(rs, mid + 1, r);
    t[k] = merge(t[ls], t[rs]);
    xors[k] = xors[ls] ^ xors[rs];
}

void modify(int k, int l, int r, int p, int v) {
    if (l == r) { t[k].clear(), t[k].ins(xors[k] = (a[l] ^= v)); return; }
    mid >= p ? modify(ls, l, mid, p, v) : modify(rs, mid + 1, r, p, v);
    t[k] = merge(t[ls], t[rs]);
    xors[k] = xors[ls] ^ xors[rs];
}

int sum(int k, int l, int r, int ql, int qr) {
    if (l >= ql && r <= qr) return xors[k];
    int ans = 0;
    if (mid >= ql) ans = sum(ls, l, mid, ql, qr);
    if (mid < qr) ans ^= sum(rs, mid + 1, r, ql, qr);
    return ans;
}

node query(int k, int l, int r, int ql, int qr) {
    if (l >= ql && r <= qr) return t[k];
    if (mid >= qr) return query(ls, l, mid, ql, qr);
    if (mid < ql) return query(rs, mid + 1, r, ql, qr);
    return merge(query(ls, l, mid, ql, qr), query(rs, mid + 1, r, ql, qr));
}

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = n; i; i--) {
        a[i] ^= a[i - 1];
    }
    build(1, 1, n);
    while (q--) {
        int op, l, r, k;
        scanf("%d %d %d", &op, &l, &r);
        if (op == 1) {
            scanf("%d", &k), modify(1, 1, n, l, k);
            if (r < n) modify(1, 1, n, r + 1, k);
        } else {
            int x = sum(1, 1, n, 1, l) ^ a[l];
            modify(1, 1, n, l, x);
            node t = query(1, 1, n, l, r);
            int ans = 0;
            for (int x : t.a) if (x) ans++;
            printf("%d\n", 1 << ans);
            modify(1, 1, n, l, x);
        }
    }
    return 0;
}