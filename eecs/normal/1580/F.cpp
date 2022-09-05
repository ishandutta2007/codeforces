#include <bits/stdc++.h>
using namespace std;

typedef vector<int> poly;
typedef unsigned long long ull;
const int maxn = 131072, P = 998244353;
int n, m, inv[maxn];
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
 
poly poly_inv(poly A) {
    if (A.size() == 1) return {qp(A[0], P - 2)};
    int m = (A.size() + 1) / 2;
    poly B = poly_inv({A.begin(), A.begin() + m}), C = A * B;
    C.resize(A.size()), fill(C.begin(), C.begin() + m, 0);
    poly ans = B;
    ans.resize(A.size()), C = C * B;
    for (int i = m; i < A.size(); i++) ans[i] = (P - C[i]) % P;
    return ans;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = inv[0] = 1; i <= n; i++) {
        inv[i] = qp(i, P - 2);
    } 
    if (!(n % 2)) {
        poly F(n / 2 + 1), G(n / 2 + 1);
        F[0] = 1;
        for (int i = 1; i <= n / 2; i++) {
            // f_i = -binom(m + i, 2i), g_i = i * f_i
            F[i] = 1LL * F[i - 1] * (m - i + 1) % P * (m + i) % P * inv[2 * i
                - 1] % P * inv[2 * i] % P;
            G[i] = 1LL * (P - i) * F[i] % P;
        }
        F = G * poly_inv(F);
        printf("%lld\n", 1LL * F[n / 2] * (n / 2 % 2 ? P - 1 : 1) % P);
    } else {
        poly F(n / 2 + 1);
        for (int i = 1; i <= n / 2; i++) {
            F[i] = 1LL * (i > 1 ? F[i - 1] : P - 1) * (m / 2 - i + 1) % P *
                (m / 2 + i) % P * inv[2 * i - 1] % P * inv[2 * i] % P;
        }

        poly fir(n / 2 + 2);
        fir[1] = (P - m / 2) % P;
        for (int i = 2; i <= n / 2 + 1; i++) {
            fir[i] = 1LL * fir[i - 1] * (m / 2 - i + 1) % P * (m / 2 + i - 1)
                % P * inv[2 * i - 2] % P * inv[2 * i - 1] % P;
        }

        F[0] = 1;
        for (int i = 1; i <= n / 2; i++) {
            F[i] = (P - F[i]) % P;
        }
        poly odd = fir * poly_inv(F);
        if (m % 2) odd[1] = P - m / 2 - 1;

        F = poly(n + 1);
        for (int i = 1; i <= n && i / 2 + 1 < odd.size(); i += 2) {
            F[i] = odd[i / 2 + 1];
            if (!(i / 2 % 2)) F[i] = (P - F[i]) % P;
        }

        poly G = F;
        for (int i = 1; i <= n; i++) {
            G[i] = 1LL * i * G[i] % P;
        }
        F[0] = 1;
        for (int i = 1; i <= n; i++) {
            F[i] = (P - F[i]) % P;
        }
        F = G * poly_inv(F);
        printf("%d\n", F[n]);
    }
    return 0;
}