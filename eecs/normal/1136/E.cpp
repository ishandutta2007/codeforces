#include <bits/stdc++.h>
#define mid (l + r >> 1)
#define ls (k << 1)
#define rs (k << 1 | 1)
using namespace std;

typedef long long ll;
const int maxn = 100010;
int n, m; ll a[maxn], k[maxn], s[maxn];
struct node { ll s, tag = 1e18; } t[maxn << 2];

void pushdown(int k, int l, int r) {
    t[ls].s = (mid - l + 1) * (t[ls].tag = t[k].tag);
    t[rs].s = (r - mid) * (t[rs].tag = t[k].tag), t[k].tag = 1e18;
}

void build(int k, int l, int r) {
    if (l == r) { t[k].s = a[l]; return; }
    build(ls, l, mid), build(rs, mid + 1, r);
    t[k].s = t[ls].s + t[rs].s;
}

void upd(int k, int l, int r, int ql, int qr, ll x) {
    if (l >= ql && r <= qr) { t[k].s = (r - l + 1) * (t[k].tag = x); return; }
    if (t[k].tag < 1e18) pushdown(k, l, r);
    if (mid >= ql) upd(ls, l, mid, ql, qr, x);
    if (mid < qr) upd(rs, mid + 1, r, ql, qr, x);
    t[k].s = t[ls].s + t[rs].s;
}

ll sum(int k, int l, int r, int ql, int qr) {
    if (l >= ql && r <= qr) return t[k].s;
    if (t[k].tag < 1e18) pushdown(k, l, r); ll ans = 0;
    if (mid >= ql) ans += sum(ls, l, mid, ql, qr);
    if (mid < qr) ans += sum(rs, mid + 1, r, ql, qr);
    return ans;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 1; i < n; i++) {
        scanf("%lld", &k[i]);
        a[i + 1] -= (k[i] += k[i - 1]);
        s[i + 1] = s[i] + k[i];
    }
    scanf("%d", &m), build(1, 1, n);
    for (int i = 1, l, r; i <= m; i++) {
        char op[2]; scanf("%s %d %d", op, &l, &r);
        if (op[0] == 's') {
            printf("%lld\n", sum(1, 1, n, l, r) + s[r] - s[l - 1]);
        } else {
            int lb = l, rb = n, ans;
            ll tmp = sum(1, 1, n, l, l);
            while (lb <= rb) {
                int p = (lb + rb) >> 1;
                if (sum(1, 1, n, p, p) <= tmp + r) lb = (ans = p) + 1;
                else rb = p - 1;
            }
            upd(1, 1, n, l, ans, tmp + r);
        }
    }
    return 0;
}