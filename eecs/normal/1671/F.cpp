#include <bits/stdc++.h>
using namespace std;

const int P = 998244353;
int T, n, k, x, f[25][12][12][13], g[12][12][25], inv[25];

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

void red(int &x) {
    x += x >> 31 & P;
}

int main() {
    scanf("%d", &T);
    f[0][0][0][0] = 1;
    for (int i = 0; i < 24; i++) {
        inv[i] = qp(i, P - 2);
        for (int j = 0; j < 12; j++) for (int k = 0; k < 12; k++) {
            for (int l = 0; l < 12; l++) if (f[i][j][k][l]) {
                for (int p = 0; p <= i && k + p < 12; p++) {
                    red(f[i + 1][p][k + p][l + (p > j)] += f[i][j][k][l] - P);
                }
            }
        }
    }
    for (int i = 1; i <= 24; i++) {
        for (int j = 0; j < 12; j++) for (int k = 0; k < 12; k++) {
            for (int l = 0; l < 12; l++) {
                red(g[j][k][i] += f[i][l][j][k] - P);
            }
        }
    }
    while (T--) {
        scanf("%d %d %d", &n, &k, &x);
        if (n < 11) { printf("%d\n", g[k][x][n]); continue; }
        int ans = 0;
        for (int i = 12; i <= 24; i++) {
            int prod = 1;
            for (int j = 12; j <= 24; j++) if (i ^ j) {
                prod = 1LL * prod * (n - j + P) % P * (i > j ? inv[i - j] : P - inv[j - i]) % P;
            }
            ans = (ans + 1LL * prod * g[k][x][i]) % P;
        }
        printf("%d\n", ans);
    }
    return 0;
}