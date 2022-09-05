#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef vector<int> poly;
const int maxn = 131072, P = 998244353;
int n, m, ans, a[maxn], b[maxn], fact[maxn], finv[maxn];
int lim, l, r[maxn], w[maxn];
vector<int> V;
poly f[maxn << 2][2][2];

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

void init() {
    for (int i = 0; i < lim; i++) r[i] = (r[i >> 1] >> 1) | ((i & 1) << (l - 1));
    w[lim >> 1] = 1;
    int t = qp(3, (P - 1) / lim);
    for (int i = (lim >> 1) + 1; i < lim; i++) w[i] = 1LL * t * w[i - 1] % P;
    for (int i = (lim >> 1) - 1; i > 0; i--) w[i] = w[i << 1];
}

void DFT(int *a, int type) {
    static ull c[maxn];
    copy(a, a + lim, c);
    for (int i = 0; i < lim; i++) if (i < r[i]) swap(c[i], c[r[i]]);
    for (int i = 1; i < lim; i <<= 1) {
        for (int j = 0; j < lim; j += i << 1) {
            for (int k = 0; k < i; k++) {
                ull t = c[i + j + k] * w[i + k] % P;
                c[i + j + k] = c[j + k] + P - t, c[j + k] += t;
            }
        }
    }
    if (!~type) {
        reverse(c + 1, c + lim);
        for (int i = 0, t = qp(lim, P - 2); i < lim; i++) c[i] = c[i] % P * t % P;
    }
    for (int i = 0; i < lim; i++) a[i] = c[i] % P;
}

int main() {
    scanf("%d", &n);
    for (int i = fact[0] = finv[0] = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        fact[i] = 1LL * i * fact[i - 1] % P;
        finv[i] = qp(fact[i], P - 2);
    }
    for (int i = 1; i <= n; i += a[i]) {
        b[++m] = a[i];
        for (int j = i; j < i + a[i]; j++) {
            if (a[i] ^ a[j]) puts("0"), exit(0);
        }
    }
    function<void(int, int, int)> solve = [&](int k, int l, int r) {
        if (l == r) {
            f[k][0][0] = {0, b[l] == 1 ? (P + 1) / 2 : 1};
            f[k][0][1] = f[k][1][0] = f[k][1][1] = {0, 1}; return;
        }
        int mid = (l + r) / 2, ls = k << 1, rs = k << 1 | 1;
        solve(ls, l, mid), solve(rs, mid + 1, r);
        for (lim = 1, ::l = 0; lim <= r - l + 1; lim <<= 1) ::l++;
        init();
        for (int p : {0, 1}) for (int q : {0, 1}) {
            f[k][p][q].resize(lim);
            if (q) f[ls][p][q].erase(f[ls][p][q].begin());
            f[ls][p][q].resize(lim), f[rs][p][q].resize(lim);
            DFT(f[ls][p][q].data(), 1), DFT(f[rs][p][q].data(), 1);
        }
        for (int a : {0, 1}) for (int b : {0, 1}) for (int c : {0, 1}) {
            for (int i = 0; i < lim; i++) {
                f[k][a][c][i] = (f[k][a][c][i] + 1LL * f[ls][a][b][i] * f[rs][b][c][i]) % P;
            }
        }
        for (int p : {0, 1}) for (int q : {0, 1}) {
            DFT(f[k][p][q].data(), -1), f[k][p][q].resize(r - l + 2);
        }
    };
    solve(1, 1, m);
    for (int i = 1; i <= m; i++) {
        ans = (ans + 1LL * fact[i] * f[1][0][0][i] % P * qp(2, i) % P * ((m - i) & 1 ? P - 1 : 1)) % P;
    }
    printf("%d\n", ans);
    return 0;
}