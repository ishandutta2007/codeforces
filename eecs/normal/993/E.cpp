#include <bits/stdc++.h>
using namespace std;

const int maxn = 524288;
const long double PI = acos((long double)-1);
int n, x, tot, pos[maxn], a[maxn], A[maxn], B[maxn];
int lim, l, r[maxn];
long long ans[maxn];

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

void convolution(int *A, int n, int *B, int m, long long *C) {
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
        long long x = round(E[i].x), y = round(F[i].x), z = round(G[i].x);
        C[i] = (1 << 30) * x + (1 << 15) * y + z;
    }
}

int main() {
    scanf("%d %d", &n, &x);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if (a[i] < x) pos[++tot] = i;
    }
    for (int i = 1; i <= tot; i++) {
        A[tot - i] = pos[i] - pos[i - 1];
    }
    for (int i = 1; i <= tot; i++) {
        B[i] = (i == tot ? n + 1 : pos[i + 1]) - pos[i];
    }
    convolution(A, tot, B, tot + 1, ans);
    long long all = 1LL * n * (n + 1) / 2;
    for (int i = 1; i <= n; i++) {
        all -= ans[tot + i - 1];
    }
    for (int i = 0; i <= n; i++) {
        printf("%lld ", !i ? all : ans[tot + i - 1]);
    }
    return 0;
}