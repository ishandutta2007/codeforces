#include <bits/stdc++.h>
using namespace std;

const int maxn = 55;
int n, m, a[maxn], b[maxn], p[maxn];
double f[maxn][5010];

int main() {
    double st = clock();
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d", &a[i], &b[i], &p[i]);
    }
    auto chk = [&](double lim) {
        for (int i = n + 1; i; i--) {
            if (i > n) {
                for (int j = 0; j <= m; j++) f[i][j] = 0;
            } else {
                for (int j = 0; j <= m; j++) {
                    f[i][j] = 0;
                    if (j >= a[i]) f[i][j] += p[i] / 100.0 * min(lim + a[i], f[i + 1][j - a[i]] + a[i]);
                    else f[i][j] += p[i] / 100.0 * (lim + a[i]);
                    if (j >= b[i]) f[i][j] += (1 - p[i] / 100.0) * min(lim + b[i], f[i + 1][j - b[i]] + b[i]);
                    else f[i][j] += (1 - p[i] / 100.0) * (lim + b[i]);
                }
            }
        }
        return f[1][m] < lim;
    };
    double l = 0, r = 1e9;
    while ((clock() - st) / CLOCKS_PER_SEC < 1) {
        double mid = (l + r) / 2;
        chk(mid) ? r = mid : l = mid;
    }
    printf("%.12f\n", l);
    return 0;
}