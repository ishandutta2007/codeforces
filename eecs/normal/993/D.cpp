#include <bits/stdc++.h>
using namespace std;

int n;
double f[55][55], g[55], w[55];
pair<int, int> p[55];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i].first);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i].second);
    }
    double st = clock();
    sort(p + 1, p + n + 1);
    auto chk = [&](double x) {
        for (int i = 0; i <= n; i++) {
            w[i] = p[i].first - x * p[i].second;
            for (int j = 0; j <= n; j++) f[i][j] = 1e18;
        }
        f[0][0] = 0;
        for (int i = 1, _i; i <= n; i = _i) {
            for (_i = i; _i <= n && p[i].first == p[_i].first; _i++);
            fill(g, g + _i - i + 1, 1e18), g[0] = 0;
            for (int j = i; j < _i; j++) {
                for (int k = _i - i; k; k--) g[k] = min(g[k], g[k - 1] + w[j]);
            }
            for (int j = 0; j < i; j++) {
                for (int k = 0; k <= j; k++) {
                    for (int l = 1; l <= _i - i; l++) {
                        int nk = max(0, k + i - j - 1 - l) + _i - i - l;
                        f[_i - 1][nk] = min(f[_i - 1][nk], f[j][k] + g[l]);
                    }
                }
            }
        }
        return f[n][0] <= 0;
    };
    double l = 0, r = 1e8;
    while ((clock() - st) / CLOCKS_PER_SEC < 0.7) {
        double mid = (l + r) / 2;
        chk(mid) ? r = mid : l = mid;
    }
    printf("%.0f\n", ceil(r * 1000 - 1e-6));
    return 0;
}