#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> poly;
const int maxn = 65536, P = 1000000007;
const long double PI = acos((long double)-1);
ll n;
int K, lim, ans, l, r[maxn], pw[maxn], fact[maxn], finv[maxn];

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

struct complex_t {
    long double x, y;
    complex_t(long double _x = 0, long double _y = 0) : x(_x), y(_y) {}

    complex_t operator + (const complex_t &o) { return complex_t(x + o.x, y + o.y); }
    complex_t operator - (const complex_t &o) { return complex_t(x - o.x, y - o.y); }
    complex_t operator * (const complex_t &o) { return complex_t(x * o.x - y * o.y
        , x * o.y + y * o.x); }
    complex_t operator / (const long double &o) { return complex_t(x / o, y / o); }
};

void DFT(complex_t *c, int type) {
    for (int i = 0; i < lim; i++) {
        if (i < r[i]) swap(c[i], c[r[i]]);
    }
    for (int i = 1; i < lim; i <<= 1) {
        complex_t x(cos(PI / i), type * sin(PI / i));
        for (int j = 0; j < lim; j += i << 1) {
            complex_t y(1, 0);
            for (int k = 0; k < i; k++, y = y * x) {
                complex_t p = c[j + k], q = y * c[i + j + k];
                c[j + k] = p + q, c[i + j + k] = p - q;
            }
        }
    }
    if (!~type) {
        for (int i = 0; i < lim; i++) c[i] = c[i] / lim;
    }
}

void convolution(int *A, int n, int *B, int m, int *C) {
    static complex_t E[maxn], F[maxn], G[maxn], H[maxn];
    for (lim = 1, l = 0; lim < n + m; lim <<= 1) l++;
    for (int i = 0; i < lim; i++) {
        r[i] = (r[i >> 1] >> 1) | ((i & 1) << (l - 1));
        if (i < n) E[i] = A[i] >> 15, F[i] = A[i] & 32767;
        else E[i] = F[i] = 0;
        if (i < m) G[i] = B[i] >> 15, H[i] = B[i] & 32767;
        else G[i] = H[i] = 0;
    }
    DFT(E, 1), DFT(F, 1), DFT(G, 1), DFT(H, 1);
    for (int i = 0; i < lim; i++) {
        complex_t x = E[i] * G[i], y = E[i] * H[i] + F[i] * G[i], z = F[i] * H[i];
        E[i] = x, F[i] = y, G[i] = z;
    }
    DFT(E, -1), DFT(F, -1), DFT(G, -1);
    for (int i = 0; i < n + m - 1; i++) {
        long long x = (long long)round(E[i].x) % P, y = (long long)round(F[i].x)
            % P, z = (long long)round(G[i].x) % P;
        C[i] = ((1 << 30) * x + (1 << 15) * y + z) % P;
    }
}

poly mul(int len, poly A, poly B) {
    poly C(K << 1 | 1);
    for (int i = 0, t = 1; i <= K; i++) {
        A[i] = 1LL * A[i] * t % P;
        t = 1LL * t * pw[len] % P;
    }
    convolution(A.data(), K + 1, B.data(), K + 1, C.data());
    C.resize(K + 1); return C;
}

int main() {
    scanf("%lld %d", &n, &K);
    if (n > K) puts("0"), exit(0);
    for (int i = pw[0] = fact[0] = finv[0] = 1; i <= max((int)n, K); i++) {
        pw[i] = (pw[i - 1] << 1) % P;
        fact[i] = 1LL * i * fact[i - 1] % P;
        finv[i] = qp(fact[i], P - 2);
    }
    for (lim = 1; lim <= K << 1; lim <<= 1) l++;
    for (int i = 0; i < lim; i++) {
        r[i] = (r[i >> 1] >> 1) | ((i & 1) << (l - 1));
    }
    vector<int> A(K + 1), B(K + 1);
    for (int i = 1; i <= K; i++) A[i] = finv[i];
    B[0] = 1;
    for (int len = 1; n; n >>= 1, A = mul(len, A, A), len <<= 1) {
        if (n & 1) B = mul(len, B, A);
    }
    for (int i = 1; i <= K; i++) {
        ans = (ans + 1LL * B[i] * fact[K] % P * finv[K - i]) % P;
    }
    printf("%d\n", ans);
    return 0;
}