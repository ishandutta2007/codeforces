#include <bits/stdc++.h>
using namespace std;

typedef vector<int> poly;
typedef unsigned long long ull;
const int maxn = 524288, P = 998244353;
int n, K, f[maxn], fact[maxn], finv[maxn];
int lim, L, r[maxn], w[maxn];

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

void init(int n) {
    for (lim = 1, L = 0; lim < n; lim <<= 1) L++;
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
    init(len), A.resize(lim), B.resize(lim);
    DFT(A.data(), 1), DFT(B.data(), 1);
    for (int i = 0; i < lim; i++) A[i] = 1LL * A[i] * B[i] % P;
    DFT(A.data(), -1), A.resize(len); return A;
}

int main() {
    scanf("%d %d", &n, &K);
    if (K == 1) puts("1"), exit(0);
    for (int i = fact[0] = finv[0] = 1; i <= n; i++) {
        fact[i] = 1LL * i * fact[i - 1] % P;
        finv[i] = qp(fact[i], P - 2);
    }
    auto calc = [&](int x) {
        poly A(x + 1), B(x + 1);
        for (int i = 0; i <= x; i++) {
            A[i] = 1LL * qp(i, x) * finv[i] % P;
            B[i] = 1LL * (i & 1 ? P - 1 : 1) * finv[i] % P;
        }
        return A * B;
    };
    for (int i = n; i; i--) {
        int x = (n + i - 1) / i;
        poly A = calc(x);
        for (int j = 1; j <= min(x, K); j++) (f[i] += A[j]) %= P;
        for (int j = i + i; j <= n + i - 1; j += i) f[i] = (f[i] - f[min(j, n)] + P) % P;
    }
    printf("%d\n", f[1]);
    return 0;
}