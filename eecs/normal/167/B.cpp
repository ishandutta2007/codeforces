#include <bits/stdc++.h>
using namespace std;

const int maxn = 210;
int n, l, k, a[maxn];
double ans, p[maxn], f[maxn][maxn][2 * maxn];

int main() {
    scanf("%d %d %d", &n, &l, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%lf", &p[i]), p[i] /= 100;
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    f[0][0][n + min(k, n)] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            for (int k = 0; k <= 2 * n; k++) {
                if (!~a[i]) {
                    if (k) f[i][j + 1][k - 1] += f[i - 1][j][k] * p[i];
                } else {
                    f[i][j + 1][min(2 * n, k + a[i])] += f[i - 1][j][k] * p[i];
                }
                f[i][j][k] += f[i - 1][j][k] * (1 - p[i]);
            }
        }
    }
    for (int i = l; i <= n; i++) {
        for (int j = n; j <= 2 * n; j++) {
            ans += f[n][i][j];
        }
    }
    printf("%.9f\n", ans);
    return 0;
}