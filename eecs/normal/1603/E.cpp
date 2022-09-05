#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef __uint128_t L;
struct Barrett {
    ull b, m;
    Barrett(ull b = 2) : b(b), m(ull((L(1) << 64) / b)) {}
    ull red(ull a) {
        ull q = (ull)((L(m) * a) >> 64);
        ull r = a - q * b; // can be proven that 0 <= r < 2b
        return r >= b ? r - b : r;
    }
} F;

const int maxn = 210;
int n, P, ans, fact[maxn], finv[maxn], f[maxn][maxn][maxn];

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = F.red(1uLL * x * x)) {
        if (y & 1) z = F.red(1uLL * z * x);
    }
    return z;
}

int main() {
    scanf("%d %d", &n, &P), F = Barrett(P);
    for (int i = fact[0] = finv[0] = 1; i <= n; i++) {
        fact[i] = F.red(1uLL * i * fact[i - 1]);
        finv[i] = qp(fact[i], P - 2);
    }
    for (int mn = 1; mn <= n + 1; mn++) {
        for (int i = mn; i <= n + 2; i++) {
            for (int j = 0; j <= n; j++) {
                fill(f[i][j], f[i][j] + mn + 1, 0);
            }
        }
        f[mn][0][0] = 1;
        for (int i = mn; i <= n + 1; i++) {
            for (int j = 0; j <= n; j++) {
                for (int k = 0; k <= mn; k++) if (f[i][j][k]) {
                    if (j * mn + k + (n - j) * i > mn * (n + 1)) continue;
                    for (int _j = i == mn; _j <= n - j; _j++) {
                        int _k = k + (i - mn) * _j;
                        if (_k > mn || mn * (i - j) - k < i * _j) break;
                        f[i + 1][j + _j][_k] = F.red(f[i + 1][j + _j][_k] + 1uLL * f[i][j][k] * finv[_j]);
                    }
                }
            }
        }
        for (int i = 0; i <= mn; i++) {
            (ans += f[n + 2][n][i]) %= P;
        }
    }
    printf("%llu\n", F.red(1uLL * ans * fact[n]));
    return 0;
}