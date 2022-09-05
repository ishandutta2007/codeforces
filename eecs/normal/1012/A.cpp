#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, a[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= 2 * n; i++) {
        scanf("%d", &a[i]);
    }
    if (n == 1) puts("0"), exit(0);
    sort(a + 1, a + 2 * n + 1);
    long long ans = 1LL * (a[n] - a[1]) * (a[2 * n] - a[n + 1]);
    for (int i = 2; i + n - 1 < 2 * n; i++) {
        ans = min(ans, 1LL * (a[i + n - 1] - a[i]) * (a[2 * n] - a[1]));
    }
    printf("%lld\n", ans);
    return 0;
}