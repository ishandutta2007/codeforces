#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, a, d, t[maxn];
double ans[maxn];

int main() {
    scanf("%d %d %d", &n, &a, &d);
    for (int i = 1, v; i <= n; i++) {
        scanf("%d %d", &t[i], &v);
        // v0 * t + a * t^2 / 2
        double l = 0, r = 1e9;
        for (int i = 1; i <= 100; i++) {
            double mid = (l + r) / 2;
            double t = min(mid, 1.0 * v / a);
            if (a * t * t / 2 + v * (mid - t) > d) r = mid;
            else l = mid;
        }
        ans[i] = max(ans[i - 1], t[i] + r);
        printf("%.9f\n", ans[i]);
    }
    return 0;
}