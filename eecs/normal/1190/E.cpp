#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, m, x[maxn], y[maxn], f[maxn], g[maxn], h[maxn];
double dist[maxn], ang[maxn];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &x[i], &y[i]);
        dist[i] = sqrt(1LL * x[i] * x[i] + 1LL * y[i] * y[i]);
        ang[i] = atan2(y[i], x[i]);
    }
    if (m >= n) {
        printf("%.9f\n", *min_element(dist + 1, dist + n + 1)), exit(0);
    }
    auto chk = [&](double lim) {
        vector<array<double, 2>> V;
        for (int i = 1; i <= n; i++) {
            double t = acos(lim / dist[i]);
            double l = ang[i] - t, r = ang[i] + t;
            if (r > 2 * M_PI) l -= 2 * M_PI, r -= 2 * M_PI;
            V.push_back({r, l}), V.push_back({r + 2 * M_PI, l + 2 * M_PI});
        }
        sort(V.begin(), V.end());
        for (int i = 0, j = 0; i < n; i++) {
            for (; j < V.size() && V[j][1] < V[i][0]; j++);
            f[i] = j, g[i] = i;
        }
        for (int o = m; o; o >>= 1) {
            if (o & 1) {
                for (int j = 0; j < n; j++) {
                    h[j] = g[f[j] % n] + f[j] - f[j] % n;
                    if (h[j] >= n + j) return 1;
                }
                memcpy(g, h, sizeof(g));
            }
            for (int j = 0; j < n; j++) {
                h[j] = f[f[j] % n] + f[j] - f[j] % n;
            }
            memcpy(f, h, sizeof(f));
        }
        return 0;
    };
    double l = 0, r = *min_element(dist + 1, dist + n + 1);
    while (r - l > 1e-7) {
        double mid = (l + r) / 2;
        chk(mid) ? l = mid : r = mid;
    }
    printf("%.9f\n", l);
    return 0;
}