#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
const int maxk = 262144, P = 998244353;
int n, K, ans, fact[maxk], finv[maxk], A[maxk], B[maxk];
int lim, l, r[maxk], w[maxk];

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
    static ull c[maxk];
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
    scanf("%d %d", &n, &K);
    for (int i = fact[0] = finv[0] = 1; i <= K; i++) {
        fact[i] = 1LL * i * fact[i - 1] % P;
        finv[i] = qp(fact[i], P - 2);
    }
    for (int i = 0; i <= K; i++) {
        A[i] = 1LL * finv[i] * qp(i, K) % P;
        B[i] = 1LL * finv[i] * (i & 1 ? P - 1 : 1) % P;
    }
    for (lim = 1; lim <= K + K; lim <<= 1) l++;
    init(), DFT(A, 1), DFT(B, 1);
    for (int i = 0; i < lim; i++) {
        A[i] = 1LL * A[i] * B[i] % P;
    }
    DFT(A, -1);
    for (int i = 1, j = 1; i <= min(n, K); i++) {
        j = 1LL * j * (n - i + 1) % P * qp(i, P - 2) % P;
        ans = (ans + 1LL * A[i] * fact[i] % P * qp(n + 1, n - i) % P * j) % P;
    }
    printf("%d\n", ans);
    return 0;
}