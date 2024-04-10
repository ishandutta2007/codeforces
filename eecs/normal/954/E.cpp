#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n; double T;
pair<double, double> a[maxn];

bool chk(double x) {
    double ans1 = 0, ans2 = 0;
    double y = x, z = x;
    for (int i = 1; i <= n; i++) {
        ans1 += a[i].first * min(a[i].second, x);
        x -= min(a[i].second, x);
    }
    for (int i = n; i; i--) {
        ans2 += a[i].first * min(a[i].second, z);
        z -= min(a[i].second, z);
    }
    return ans1 <= T * y && ans2 >= T * y;
}

int main() {
    scanf("%d %lf", &n, &T);
    double l = 0, r = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%lf", &a[i].second), r += a[i].second;
    }
    for (int i = 1; i <= n; i++) {
        scanf("%lf", &a[i].first);
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= 100; i++) {
        double mid = (l + r) / 2;
        chk(mid) ? l = mid : r = mid;
    }
    printf("%.15f\n", l);
    return 0;
}