#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1);
const int maxn = 1048576, P = 490019;
int n, m, c, ans, A[maxn], B[maxn], C[maxn], pw[P];
int lim, l, r[maxn];

struct complex_t {
    double x, y;
    complex_t(double _x = 0, double _y = 0) : x(_x), y(_y) {}

    complex_t operator + (const complex_t &o) { return complex_t(x + o.x, y + o.y); }
    complex_t operator - (const complex_t &o) { return complex_t(x - o.x, y - o.y); }
    complex_t operator * (const complex_t &o) { return complex_t(x * o.x - y * o.y
        , x * o.y + y * o.x); }
    complex_t operator / (const double &o) { return complex_t(x / o, y / o); }
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

void convolution(int n, int *A, int m, int *B, int *C) {
    static complex_t E[maxn], F[maxn], G[maxn], H[maxn];
    for (lim = 1, l = 0; lim < P << 1; lim <<= 1) l++;
    for (int i = 0; i < lim; i++) {
        r[i] = (r[i >> 1] >> 1) | ((i & 1) << (l - 1));
        if (i < n) E[i] = A[i] >> 10, F[i] = A[i] & 1023;
        else E[i] = F[i] = 0;
        if (i < m) G[i] = B[i] >> 10, H[i] = B[i] & 1023;
        else G[i] = H[i] = 0;
    }
    DFT(E, 1), DFT(F, 1), DFT(G, 1), DFT(H, 1);
    for (int i = 0; i < lim; i++) {
        complex_t x = E[i] * G[i], y = E[i] * H[i] + F[i] * G[i], z = F[i] * H[i];
        E[i] = x, F[i] = y, G[i] = z;
    }
    DFT(E, -1), DFT(F, -1), DFT(G, -1);
    for (int i = 0; i < lim; i++) {
        long long x = (long long)round(E[i].x) % P, y = (long long)round(F[i].x)
            % P, z = (long long)round(G[i].x) % P;
        C[i] = ((1 << 20) * x + (1 << 10) * y + z) % P;
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &c);
    for (int i = 0, x; i < n; i++) {
        scanf("%d", &x);
        (A[1LL * i * i % (P - 1)] += x) %= P;
    }
    for (int i = 0, x; i < m; i++) {
        scanf("%d", &x);
        (B[1LL * i * i * i % (P - 1)] += x) %= P;
    }
    for (int i = pw[0] = 1; i < P; i++) {
        pw[i] = 1LL * c * pw[i - 1] % P;
    }
    auto binom = [&](int x) {
        return 1LL * x * (x - 1) / 2 % (P - 1);
    };
    for (int i = 0; i < P - 1; i++) {
        B[i] = 1LL * B[i] * pw[P - 1 - binom(i)] % P;
    }
    reverse(B, B + P - 1);
    for (int i = 0; i < (P - 1) << 1; i++) {
        C[i] = pw[binom(i)];
    }
    convolution(P - 1, B, (P - 1) << 1, C, B);
    for (int i = 0; i < P - 1; i++) {
        ans = (ans + 1LL * A[i] * B[P - 2 + i] % P * pw[P - 1 - binom(i)]) % P;
    }
    printf("%d\n", ans);
    return 0;
}