#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010, P = 1000000007, inv2 = (P + 1) / 2;
int L, n, m, f[maxn * 2], s[maxn * 2], si[2][maxn * 2];

struct seg {
    int l, r, op;
    bool operator < (const seg &o) const {
        return r < o.r || r == o.r && l > o.l;
    }
} a[maxn], b[maxn], c[maxn * 2];

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> L >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i].l >> a[i].r;
        a[i].l--, a[i].op = 0;
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i].l >> b[i].r;
        b[i].l--, b[i].op = 1;
    }
    sort(a, a + n), sort(b, b + m);
    for (int i = 1; i < n; i++) {
        a[i].l = max(a[i].l, a[i - 1].l);
    }
    for (int i = 1; i < m; i++) {
        b[i].l = max(b[i].l, b[i - 1].l);
    }
    merge(a, a + n, b, b + m, c);
    int ans = 1;
    for (int i = 0; i < n + m; i++) {
        int p = upper_bound(c, c + n + m, c[i].l, [&](int x, seg t) { return x < t.r; }) - c;
        int t1 = P - qp(inv2, c[i].r - c[i].l), t2 = P - qp(inv2, c[i].r);
        f[i] = (1LL * (s[p] + 1) * t1 + 1LL * (P + si[c[i].op][i] - si[c[i].op][p]) * t2) % P;
        s[i + 1] = (s[i] + f[i]) % P;
        si[c[i].op][i + 1] = (si[c[i].op][i] + 1LL * f[i] * qp(2, c[i].r)) % P;
        si[!c[i].op][i + 1] = si[!c[i].op][i];
        (ans += f[i]) %= P;
    }
    cout << 1LL * ans * qp(2, L) % P << "\n";
    return 0;
}