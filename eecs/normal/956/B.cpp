#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, U, a[maxn];
double ans = -1e18;

int main() {
    scanf("%d %d", &n, &U);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i + 2 <= n; i++) {
        int j = upper_bound(a + 1, a + n + 1, a[i] + U) - a - 1;
        if (j > i + 1) ans = max(ans, 1.0 * (a[j] - a[i + 1]) / (a[j] - a[i]));
    }
    if (ans < 0) puts("-1");
    else printf("%.12f\n", ans);
    return 0;
}