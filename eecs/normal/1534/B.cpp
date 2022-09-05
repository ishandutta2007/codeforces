#include <bits/stdc++.h>
using namespace std;

const int maxn = 400010;
int T, n, a[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        a[n + 1] = 0;
        for (int i = 1; i <= n; i++) {
            ans += max(0, a[i] - a[i - 1]);
            ans += max(0, a[i] - a[i + 1]);
            ans -= max(0, min(a[i] - a[i - 1], a[i] - a[i + 1]));
        }
        printf("%lld\n", ans);
    }
    return 0;
}