#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
const int maxn = 200010, P = 998244353;
int n, fact[maxn], finv[maxn], f[maxn], g[maxn];
int lim, l, r[maxn], w[maxn], A[maxn], B[maxn];

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
    for (int i = (lim >> 1) + 1; i < lim; i++) w[i] = 1LL * w[i - 1] * t % P;
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
    for (int i = fact[0] = finv[0] = 1; i < maxn; i++) {
        fact[i] = 1LL * i * fact[i - 1] % P;
        finv[i] = qp(fact[i], P - 2);
    }
    auto binom = [&](int n, int m) {
        if (n < m || m < 0) return 0LL;
        return 1LL * fact[n] * finv[m] % P * finv[n - m] % P;
    };
    int cur = f[1] = 1, ans = 0;
    while (n--) {
        int a, b; scanf("%d %d", &a, &b);
        for (lim = 1, l = 0; lim <= cur * 2 + a - b; lim <<= 1) l++;
        fill(g, g + lim, 0), init();
        fill(A, A + lim, 0), fill(B, B + lim, 0);
        copy(f, f + cur + 1, A);
        for (int i = -cur; i <= cur + a - b; i++) B[i + cur] = binom(a + b, b + i);
        DFT(A, 1), DFT(B, 1);
        for (int i = 0; i < lim; i++) A[i] = 1LL * A[i] * B[i] % P;
        DFT(A, -1);
        for (int i = 1; i <= cur + a - b; i++) f[i] = A[i + cur];
        cur += a - b;
    }
    for (int i = 1; i <= cur; i++) {
        (ans += f[i]) %= P;
    }
    printf("%d\n", ans);
    return 0;
}