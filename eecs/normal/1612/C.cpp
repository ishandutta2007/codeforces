#include <bits/stdc++.h>
using namespace std;

int T, k;
long long x;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %lld", &k, &x);
        auto chk = [&](long long t) {
            long long n = min(1LL * k, t);
            long long sum = n * (n + 1) / 2;
            n = max(0LL, t - k);
            sum += k * n - n * (n + 1) / 2;
            return sum;
        };
        long long l = 1, r = 2 * k - 1, ans = r;
        while (l <= r) {
            long long mid = (l + r) / 2;
            chk(mid) >= x ? r = (ans = mid) - 1 : l = mid + 1;
        }
        printf("%lld\n", ans);
    }
    return 0;
}