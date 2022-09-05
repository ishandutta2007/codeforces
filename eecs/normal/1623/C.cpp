#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int T, n, h[maxn], mx[maxn];
long long a[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &h[i]);
        }
        auto chk = [&](int lim) {
            copy(h + 1, h + n + 1, a + 1);
            for (int i = n; i >= 3; i--) {
                int t = max(0LL, min(1LL * h[i] / 3, (a[i] - lim) / 3));
                a[i - 2] += 2 * t, a[i - 1] += t, a[i] -= 3 * t;
            }
            for (int i = 1; i <= n; i++) {
                if (a[i] < lim) return 0;
            }
            return 1;
        };
        int l = 1, r = 1e9, ans;
        while (l <= r) {
            int mid = (l + r) / 2;
            chk(mid) ? l = (ans = mid) + 1 : r = mid - 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}