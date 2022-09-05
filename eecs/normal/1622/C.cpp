#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int T, n, a[maxn];
long long K;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %lld", &n, &K);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        sort(a + 1, a + n + 1);
        reverse(a + 2, a + n + 1);
        long long s = accumulate(a + 1, a + n + 1, 0LL);
        long long ans = LLONG_MAX, dec = 0;
        for (int i = 1; i <= n; i++) {
            dec += a[i] - a[1], s -= a[i];
            long long l = 0, r = 1e18, p;
            while (l <= r) {
                long long mid = (l + r) / 2;
                if ((__int128)(a[1] - mid) * i + s <= K) r = (p = mid) - 1;
                else l = mid + 1;
            }
            ans = min(ans, p + i - 1);
        }
        printf("%lld\n", ans);
    }
    return 0;
}