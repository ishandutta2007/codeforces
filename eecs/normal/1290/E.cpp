#include <bits/stdc++.h>
using namespace std;

const int maxn = 150010;
int n, a[maxn], b[maxn];
long long all, ans[maxn];

namespace BIT {
int c[maxn];
void init() { memset(c, 0, sizeof(c)); }

void add(int p, int v) {
    for (; p <= n; p += p & -p) c[p] += v;
}

int sum(int p) {
    int s = 0;
    for (; p; p -= p & -p) s += c[p];
    return s;
}
}  // namespace BIT

namespace SEG {
#define mid (l + r >> 1)
#define ls (k << 1)
#define rs (k << 1 | 1)
struct node { int mx, cnt, tag, sec; } t[maxn << 2];

void maintain(int k) {
    t[k].mx = max(t[ls].mx, t[rs].mx);
    t[k].cnt = (t[ls].mx == t[k].mx) * t[ls].cnt + (t[rs].mx == t[k].mx) * t[rs].cnt;
    if (t[ls].mx == t[rs].mx) t[k].sec = max(t[ls].sec, t[rs].sec);
    else if (t[ls].mx > t[rs].mx) t[k].sec = max(t[ls].sec, t[rs].mx);
    else t[k].sec = max(t[ls].mx, t[rs].sec);
}

void pushdown(int k) {
    bool L = t[ls].mx >= t[rs].mx, R = t[rs].mx >= t[ls].mx;
    if (L) t[ls].mx += t[k].tag, t[ls].tag += t[k].tag;
    if (R) t[rs].mx += t[k].tag, t[rs].tag += t[k].tag;
    t[k].tag = 0;
}

void build(int k, int l, int r) {
    t[k].mx = t[k].sec = INT_MIN, t[k].cnt = t[k].tag = 0;
    if (l < r) build(ls, l, mid), build(rs, mid + 1, r);
}

void modify(int k, int l, int r, int p, int v) {
    if (l == r) { t[k].mx = v, t[k].cnt = 1; return; }
    if (t[k].tag) pushdown(k);
    mid >= p ? modify(ls, l, mid, p, v) : modify(rs, mid + 1, r, p, v);
    maintain(k);
}

void upd(int k, int l, int r, int ql, int qr, int v) {
    if (t[k].mx <= v) return;
    if (l >= ql && r <= qr && t[k].sec < v) {
        all += 1LL * t[k].cnt * (BIT::sum(v) - BIT::sum(t[k].mx));
        t[k].tag += v - t[k].mx, t[k].mx = v; return;
    }
    if (t[k].tag) pushdown(k);
    if (mid >= ql) upd(ls, l, mid, ql, qr, v);
    if (mid < qr) upd(rs, mid + 1, r, ql, qr, v);
    maintain(k);
}
}  // namespace SEG

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]), b[a[i]] = i;
    }
    for (int $ = 0; $ < 2; $++) {
        all = 0, BIT::init(), SEG::build(1, 1, n);
        for (int i = 1; i <= n; i++) {
            if (b[i] > 1) SEG::upd(1, 1, n, 1, b[i] - 1, b[i] - 1);
            ans[i] += (all += i - BIT::sum(b[i]));
            SEG::modify(1, 1, n, b[i], n), BIT::add(b[i], 1);
            b[i] = n - b[i] + 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%lld\n", ans[i] - i);
    }
    return 0;
}