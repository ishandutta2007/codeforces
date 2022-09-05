#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, M, q, a[maxn], b[maxn], c[12][maxn];
vector<int> V;
struct node { int sum, tag, mul, tag2; } t[maxn << 2];

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % M) {
        if (y & 1) z = 1LL * z * x % M;
    }
    return z;
}

void add(int *c, int p, int v) {
    for (; p <= n; p += p & -p) c[p] += v;
}

int sum(int *c, int p) {
    int s = 0;
    for (; p; p -= p & -p) s += c[p];
    return s;
}

#define mid (l + r >> 1)
#define ls (k << 1)
#define rs (k << 1 | 1)
void maintain(int k) {
    t[k].sum = (t[ls].sum + t[rs].sum) % M;
}

void pushdown(int k, int l, int r) {
    if (t[k].tag ^ 1) {
        t[ls].sum = 1LL * t[ls].sum * t[k].tag % M;
        t[rs].sum = 1LL * t[rs].sum * t[k].tag % M;
        t[ls].tag = 1LL * t[ls].tag * t[k].tag % M;
        t[rs].tag = 1LL * t[rs].tag * t[k].tag % M, t[k].tag = 1;
    }
    if (t[k].tag2 ^ 1) {
        t[ls].mul = 1LL * t[ls].mul * t[k].tag2 % M;
        t[rs].mul = 1LL * t[rs].mul * t[k].tag2 % M;
        t[ls].tag2 = 1LL * t[ls].tag2 * t[k].tag2 % M;
        t[rs].tag2 = 1LL * t[rs].tag2 * t[k].tag2 % M, t[k].tag2 = 1;
    }
}

void build(int k, int l, int r) {
    if (l == r) { t[k].mul = a[l], t[k].sum = b[l]; return; }
    build(ls, l, mid), build(rs, mid + 1, r);
    t[k].tag = t[k].tag2 = 1, maintain(k);
}

void mul(int k, int l, int r, int ql, int qr, int v1, int v2) {
    if (l >= ql && r <= qr) {
        t[k].sum = 1LL * t[k].sum * v1 % M;
        t[k].tag = 1LL * t[k].tag * v1 % M;
        t[k].mul = 1LL * t[k].mul * v2 % M;
        t[k].tag2 = 1LL * t[k].tag2 * v2 % M; return;
    }
    pushdown(k, l, r);
    if (mid >= ql) mul(ls, l, mid, ql, qr, v1, v2);
    if (mid < qr) mul(rs, mid + 1, r, ql, qr, v1, v2);
    maintain(k);
}

void modify(int k, int l, int r, int p, int v, int v2) {
    if (l == r) { t[k].sum = v, t[k].mul = 1LL * t[k].mul * v2 % M; return; }
    pushdown(k, l, r);
    mid >= p ? modify(ls, l, mid, p, v, v2) : modify(rs, mid + 1, r, p, v, v2);
    maintain(k);
}

int query(int k, int l, int r, int ql, int qr) {
    if (l >= ql && r <= qr) return t[k].sum % M;
    pushdown(k, l, r);
    int s = 0;
    if (mid >= ql) s = query(ls, l, mid, ql, qr);
    if (mid < qr) (s += query(rs, mid + 1, r, ql, qr)) %= M;
    return s;
}

int get(int k, int l, int r, int p) {
    if (l == r) return t[k].mul;
    pushdown(k, l, r);
    return mid >= p ? get(ls, l, mid, p) : get(rs, mid + 1, r, p);
}

int main() {
    scanf("%d %d", &n, &M);
    int m = M, phi = M;
    for (int i = 2; i * i <= m; i++) if (!(m % i)) {
        V.push_back(i), phi = phi / i * (i - 1);
        while (!(m % i)) m /= i;
    }
    if (m > 1) V.push_back(m), phi = phi / m * (m - 1);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]), b[i] = a[i];
        for (int j = 0; j < V.size(); j++) if (!(a[i] % V[j])) {
            int x = 0;
            while (!(a[i] % V[j])) a[i] /= V[j], x++;
            add(c[j], i, x), add(c[j], i + 1, -x);
        }
    }
    scanf("%d", &q), build(1, 1, n);
    while (q--) {
        int op, l, r, p, x;
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d %d %d", &l, &r, &x);
            int o = x;
            for (int i = 0; i < V.size(); i++) if (!(x % V[i])) {
                int y = 0;
                while (!(x % V[i])) x /= V[i], y++;
                add(c[i], l, y), add(c[i], r + 1, -y);
            }
            mul(1, 1, n, l, r, o, x);
        } else if (op == 2) {
            scanf("%d %d", &p, &x);
            for (int i = 0; i < V.size(); i++) if (!(x % V[i])) {
                int y = 0;
                while (!(x % V[i])) x /= V[i], y++;
                add(c[i], p, -y), add(c[i], p + 1, y);
            }
            int v = 1LL * get(1, 1, n, p) * qp(x, phi - 1) % M;
            for (int i = 0; i < V.size(); i++) {
                v = 1LL * v * qp(V[i], sum(c[i], p)) % M;
            }
            modify(1, 1, n, p, v, qp(x, phi - 1));
        } else {
            scanf("%d %d", &l, &r);
            printf("%d\n", query(1, 1, n, l, r));
        }
    }
    return 0;
}