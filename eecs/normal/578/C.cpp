#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, a[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    double st = clock();
    auto calc = [&](double x) {
        double mn = 0, mx = 0;
        double ans = 0, cur = 0;
        for (int i = 1; i <= n; i++) {
            double b = a[i] - x;
            cur += b;
            ans = max(ans, abs(cur - mn));
            ans = max(ans, abs(cur - mx));
            mn = min(mn, cur), mx = max(mx, cur);
        }
        return ans;
    };
    double l = -10000, r = 10000;
    while ((clock() - st) / CLOCKS_PER_SEC < 1.5) {
        double m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
        if (calc(m1) < calc(m2)) r = m2;
        else l = m1;
    }
    printf("%.7f\n", calc(l));
    return 0;
}