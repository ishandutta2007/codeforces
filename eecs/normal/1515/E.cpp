#include <bits/stdc++.h>
using namespace std;

const int maxn = 410;
int n, P, ans, f[maxn][maxn], fact[maxn], finv[maxn], prob[maxn], g[2][maxn][maxn];

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

int main() {
    scanf("%d %d", &n, &P);
    for (int i = fact[0] = finv[0] = 1; i <= n; i++) {
        fact[i] = 1LL * i * fact[i - 1] % P;
        finv[i] = qp(fact[i], P - 2);
    }
    int cur = 0, nxt = 1;
    g[0][1][2] = g[0][2][1] = 1;
    for (int i = 3; i <= n; i++, swap(cur, nxt)) {
        memset(g[nxt], 0, sizeof(g[nxt]));
        for (int k = 1; k < i; k++) {
            int s1 = 0, s2 = 0;
            for (int j = 1; j < i; j++) if (g[cur][j][k]) {
                if (j < k) (s1 += g[cur][j][k]) %= P;
                else (s2 += g[cur][j][k]) %= P;
            }
            for (int j = k + 1; j <= i; j++) {
                (g[nxt][k][j] += s1) %= P;
            }
            for (int j = 1; j <= i; j++) {
                if (j <= k) (g[nxt][k + 1][j] += s2) %= P;
                else (g[nxt][k][j] += s2) %= P;
            }
        }
        for (int j = 1; j <= i; j++) {
            for (int k = 1; k <= i; k++) {
                (prob[i] += g[nxt][j][k]) %= P;
            }
        }
        prob[i] = 1LL * prob[i] * finv[i] % P;
    }
    f[1][1] = prob[1] = prob[2] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= i; j++) {
            for (int k = 1; k <= i; k++) if (i - k + 1 <= j) {
                if (k == 2) continue;
                if (k == 1) (f[i][j] += prob[j]) %= P;
                else f[i][j] = (f[i][j] + 1LL * f[k - 2][j - (i - k + 1)] * prob[i - k + 1]) % P;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        ans = (ans + 1LL * fact[i] * f[n][i]) % P;
    }
    printf("%d\n", ans);
    return 0;
}