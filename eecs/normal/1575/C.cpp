#include <bits/stdc++.h>
using namespace std;

typedef complex<double> complex_t;
const int maxn = 524288, P = 1000000007;
const double PI = acos(-1);
int n, m, K, ans, a[maxn], pre[maxn], suf[maxn];
int c[maxn], cl[maxn], cr[maxn], cur[maxn];
int lim, l, r[maxn];
complex_t A[maxn], B[maxn];

void DFT(complex_t *c, int type) {
    for (int i = 0; i < lim; i++) {
        if (i < r[i]) swap(c[i], c[r[i]]);
    }
    for (int i = 1; i < lim; i <<= 1) {
        complex_t x(cos(PI / i), type * sin(PI/ i));
        for (int j = 0; j < lim; j += i << 1) {
            complex_t y(1, 0);
            for (int k = 0; k < i; k++, y *= x) {
                complex_t p = c[j + k], q = y * c[i + j + k];
                c[j + k] = p + q, c[i + j + k] = p - q;
            }
        }
    }
    if (type == -1) {
        for (int i = 0; i < lim; i++) c[i] /= lim;
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &K);
    int all = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]), (all += a[i]) %= K;
        pre[i] = (pre[i - 1] + a[i]) % K;
        if (i < n) cl[pre[i]]++, A[pre[i]] += 1;
    }
    for (int i = n; i; i--) {
        suf[i] = (suf[i + 1] + a[i]) % K;
        if (i > 1) cr[suf[i]]++, B[suf[i]] += 1;
    }
    for (lim = 1; lim < K << 1; lim <<= 1) l++;
    for (int i = 0; i < lim; i++) {
        r[i] = (r[i >> 1] >> 1) | ((i & 1) << (l - 1));
    }
    DFT(A, 1), DFT(B, 1);
    for (int i = 0; i < lim; i++) {
        A[i] *= B[i];
    }
    DFT(A, -1);
    for (int i = 0; i < K + K; i++) {
        c[i % K] = (c[i % K] + (long long)round(A[i].real())) % P;
    }
    int all_m = 1LL * m * all % K;
    auto solve = [&](int r, int type) {
        memset(cur, 0, sizeof(cur));
        int num = 0;
        for (int i = 0; i <= n; i++) {
            (num += cur[(pre[i] - r + K) % K]) %= P;
            cur[pre[i]]++;
        }
        if (all == r) (num += P - 1) %= P;
        ans = (ans + 1LL * m * num) % P;
        for (int i = 0; i <= m; i++) {
            int tar = (r - 1LL * i * all % K + K) % K;
            if (i < m) ans = (ans + 1LL * c[tar] * (m - i - 1)) % P;
            if (i) {
                if (!tar) (ans += m - i + 1) %= P;
                ans = (ans + 1LL * (cl[tar] + cr[tar]) * (m - i)) % P;
            }
        }
        if (type) {
            for (int i = 0; i < m; i++) {
                int tar = (r - 1LL * i * all % K + K) % K;
                if (i && !tar) (ans += P - 1) %= P, (ans += P - 1) %= P;
                ans = (ans - cl[tar] + P) % P;
                ans = (ans - cr[tar] + P) % P;
            }
            if (all_m == r) (ans += P - 1) %= P;
        }
    };
    solve(0, 0), solve(all_m, 1);
    printf("%d\n", ans);
    return 0;
}