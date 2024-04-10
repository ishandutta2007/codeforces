#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

const int maxn = 510;
int n, m, _K, w1[maxn][maxn], w2[maxn][maxn], f[15][maxn][maxn];

inline void chk(int &x, int y) {
    if (x > y) x = y;
}

int main() {
    scanf("%d %d %d", &n, &m, &_K);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < m; j++) scanf("%d", &w1[i][j]);
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= m; j++) scanf("%d", &w2[i][j]);
    }
    int K = (_K + 1) / 2;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            f[0][i][j] = 0;
            for (int t = 1; t <= K; t++) {
                for (int k = max(1, i - t); k <= min(n, i + t); k++) {
                    int d1 = t - abs(i - k);
                    for (int l = max(1, j - d1); l <= min(m, j + d1); l++) {
                        f[t][k][l] = 1e9;
                    }
                }
                for (int k = max(1, i - (t - 1)); k <= min(n, i + t - 1); k++) {
                    int d1 = t - 1 - abs(i - k);
                    for (int l = max(1, j - d1); l <= min(m, j + d1); l++) {
                        chk(f[t][k][l + 1], f[t - 1][k][l] + w1[k][l]);
                        chk(f[t][k][l - 1], f[t - 1][k][l] + w1[k][l - 1]);
                        chk(f[t][k + 1][l], f[t - 1][k][l] + w2[k][l]);
                        chk(f[t][k - 1][l], f[t - 1][k][l] + w2[k - 1][l]);
                    }
                }
            }
            int ans = 1e9;
            for (int k = max(1, i - K); k <= min(n, i + K); k++) {
                int d1 = K - abs(i - k);
                for (int l = max(1, j - d1); l <= min(m, j + d1); l++) {
                    if (abs(i - k) + abs(j - l) > _K - K) continue;
                    chk(ans, f[K][k][l] + f[_K - K][k][l]);
                }
            }
            printf("%d%c", ans >= (int)1e9 ? -1 : ans, " \n"[j == m]);
        }
    }
    return 0;
}