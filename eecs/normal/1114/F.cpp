#include <bits/stdc++.h>
#define mid (l + r >> 1)
#define ls (k << 1)
#define rs (k << 1 | 1)
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> T;
const int maxn = 400010, P = 1000000007;
int n, q, tot, a[maxn], p[310];
ll add[310], inv[310]; bool chk[310]; char op[10];
struct node { ll mul = 1, mask, t1 = 1, t2; } t[maxn << 2];

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

void maintain(int k) {
    t[k].mul = t[ls].mul * t[rs].mul % P;
    t[k].mask = t[ls].mask | t[rs].mask;
}

void pushdown(int k, int l, int r) {
    (t[ls].mul *= qp(t[k].t1, mid - l + 1)) %= P;
    (t[rs].mul *= qp(t[k].t1, r - mid)) %= P;
    (t[ls].t1 *= t[k].t1) %= P, (t[rs].t1 *= t[k].t1) %= P;
    t[ls].mask |= t[k].t2, t[ls].t2 |= t[k].t2;
    t[rs].mask |= t[k].t2, t[rs].t2 |= t[k].t2;
    t[k].t1 = 1, t[k].t2 = 0;
}

void build(int k, int l, int r) {
    if (l == r) { t[k].mul = a[l], t[k].mask = add[a[l]]; return; }
    build(ls, l, mid), build(rs, mid + 1, r), maintain(k);
}

void modify(int k, int l, int r, int ql, int qr, int x) {
    if (l >= ql && r <= qr) {
        (t[k].mul *= qp(x, r - l + 1)) %= P, (t[k].t1 *= x) %= P;
        t[k].mask |= add[x], t[k].t2 |= add[x]; return;
    }
    pushdown(k, l, r);
    if (mid >= ql) modify(ls, l, mid, ql, qr, x);
    if (mid < qr) modify(rs, mid + 1, r, ql, qr, x);
    maintain(k);
}

T query(int k, int l, int r, int ql, int qr) {
    if (l >= ql && r <= qr) return T(t[k].mul, t[k].mask);
    pushdown(k, l, r); T ans(1, 0), t1(1, 0), t2(1, 0);
    if (mid >= ql) t1 = query(ls, l, mid, ql, qr);
    if (mid < qr) t2 = query(rs, mid + 1, r, ql, qr);
    return T(ans.x * t1.x % P * t2.x % P, ans.y | t1.y | t2.y);
}

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 2; i <= 300; i++) {
        if (!chk[i]) p[++tot] = i, inv[i] = qp(i, P - 2);
        for (int j = i + i; j <= 300; j += i) chk[j] = 1;
        for (int j = 1; j <= tot; j++) {
            if (!(i % p[j])) add[i] |= (1LL << j);
        }
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    build(1, 1, n);
    for (int i = 1, l, r, x; i <= q; i++) {
        scanf("%s %d %d", op, &l, &r);
        if (op[0] == 'M') {
            scanf("%d", &x), modify(1, 1, n, l, r, x);
        } else {
            T t = query(1, 1, n, l, r);
            for (int j = 1; j <= tot; j++) {
                if (t.y >> j & 1) t.x = t.x * (p[j] - 1) % P * inv[p[j]] % P;
            }
            printf("%lld\n", t.x);
        }
    }
    return 0;
}