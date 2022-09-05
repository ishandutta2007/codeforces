#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int T, n, a[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        sort(a + 1, a + n + 1);
        long long ans = a[n], s = 0;
        for (int i = 2; i <= n; i++) {
            s += a[i - 1];
            ans -= 1LL * (i - 1) * a[i] - s;
        }
        printf("%lld\n", ans);
    }
    return 0;
}