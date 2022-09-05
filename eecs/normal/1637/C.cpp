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
        if (*max_element(a + 2, a + n) == 1 || n == 3 && a[2] % 2) {
            puts("-1"); continue;
        }
        long long ans = 0;
        for (int i = 2; i < n; i++) {
            ans += a[i] / 2;
            if (a[i] % 2) ans++;
        }
        printf("%lld\n", ans);
    }
    return 0;
}