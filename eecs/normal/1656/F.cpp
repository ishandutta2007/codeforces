#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int T, n, a[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        sort(a + 1, a + n + 1);
        auto solve = [&](long long t) {
            long long ans = 0;
            ans += 1LL * (a[1] + t) * (a[n] + t);
            for (int i = 2; i < n; i++) {
                ans += min(1LL * (a[1] + t) * (a[i] + t), 1LL * (a[i] + t) * (a[n] + t));
            }
            return ans - t * t * (n - 1);
        };
        long long sum = accumulate(a + 1, a + n + 1, 0LL);
        if (sum + 1LL * a[1] * (n - 2) <= 0 && sum + 1LL * a[n] * (n - 2) >= 0) {
            long long l = -1e6, r = 1e6, ans = LLONG_MIN;
            while (l < r) {
                long long mid = (l + r) >> 1;
                long long v1 = solve(mid), v2 = solve(mid + 1);
                ans = max({ans, v1, v2});
                if (v1 < v2) l = mid + 1;
                else r = mid;
            }
            printf("%lld\n", ans);
        } else {
            puts("INF");
        }
    }
    return 0;
}