#include <bits/stdc++.h>
using namespace std;

int _T, n;
double C, T, f[110][110][1010], pw[110];
pair<int, int> p[110];

int main() {
    for (int i = pw[0] = 1; i <= 100; i++) {
        pw[i] = pw[i - 1] / 0.9;
    }
    scanf("%d", &_T);
    while (_T--) {
        scanf("%d %lf %lf", &n, &C, &T);
        for (int i = 1; i <= n; i++) {
            scanf("%d %d", &p[i].first, &p[i].second);
        }
        sort(p + 1, p + n + 1, greater<pair<int, int>>());
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                for (int k = 0; k <= n * 10; k++) f[i][j][k] = 1e18;
            }
        }
        f[0][0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                for (int k = 0; k <= n * 10; k++) if (f[i - 1][j][k] < 1e18) {
                    f[i][j][k] = min(f[i][j][k], f[i - 1][j][k]);
                    f[i][j + 1][k + p[i].second] = min(f[i][j + 1][k + p[i].second],
                        f[i - 1][j][k] + p[i].first * pw[j + 1]);
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= n * 10; j++) if (f[n][i][j] < 1e18) {
                auto calc = [&](double t) {
                    return t + f[n][i][j] / (1 + C * t);
                };
                double l = 0, r = T;
                for (int $ = 1; $ <= 50; $++) {
                    double m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
                    calc(m1) > calc(m2) ? l = m1 : r = m2;
                }
                if (calc(l) + 10 * i <= T) ans = max(ans, j);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}