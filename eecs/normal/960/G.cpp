#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef vector<int> poly;
const int maxn = 262144, P = 998244353;
int n, A, B, ans, f[maxn], g[maxn], fact[maxn], finv[maxn], inv[maxn];
int lim, L, r[maxn], w[maxn];

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

void init() {
    for (int i = 0; i < lim; i++) r[i] = (r[i >> 1] >> 1) | ((i & 1) << (L - 1));
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

poly operator * (poly A, poly B) {
    int len = A.size() + B.size() - 1;
    for (lim = 1, L = 0; lim < len; lim <<= 1) L++;
    A.resize(lim), B.resize(lim);
    init(), DFT(A.data(), 1), DFT(B.data(), 1);
    for (int i = 0; i < lim; i++) A[i] = 1LL * A[i] * B[i] % P;
    DFT(A.data(), -1), A.resize(len); return A;
}

poly qp(poly A, int k, int n) {
    poly B = A;
    for (k--; k; k >>= 1) {
        if (k & 1) B = B * A, B.resize(n + 1);
        A = A * A, A.resize(n + 1);
    }
    return B;
}

int main() {
    scanf("%d %d %d", &n, &A, &B);
    if (!A || !B) puts("0"), exit(0);
    for (int i = fact[0] = finv[0] = inv[0] = 1; i <= n; i++) {
        fact[i] = 1LL * i * fact[i - 1] % P;
        finv[i] = qp(fact[i], P - 2);
        inv[i] = qp(i, P - 2);
    }
    auto binom = [&](int x, int y) {
        return 1LL * fact[x] * finv[y] % P * finv[x - y] % P;
    };
    auto solve = [&](int n, int m) {
        if (m > n) return 0;
        if (!n) return 1;
        function<poly(int, int)> solve = [&](int l, int r) {
            if (l == r) return poly{l - 1, 1};
            int mid = (l + r) >> 1;
            return solve(l, mid) * solve(mid + 1, r);
        };
        return solve(1, n)[m];
    };
    printf("%lld\n", 1LL * solve(n - 1, A + B - 2) * binom(A + B - 2, A - 1) % P);
    return 0;
}