#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int T, n, x, a, y, b, p[maxn], c[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &p[i]), p[i] /= 100;
        }
        sort(p + 1, p + n + 1, greater<>());
        scanf("%d %d %d %d", &x, &a, &y, &b);
        long long k;
        scanf("%lld", &k);
        auto chk = [&](int m) {
            fill(c + 1, c + m + 1, 0);
            for (int i = a; i <= m; i += a) c[i] += x;
            for (int i = b; i <= m; i += b) c[i] += y;
            sort(c + 1, c + m + 1, greater<>());
            long long sum = 0;
            for (int i = 1; i <= m; i++) sum += 1LL * c[i] * p[i];
            return sum;
        };
        int l = 1, r = n, ans = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            chk(mid) >= k ? r = (ans = mid) - 1 : l = mid + 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}