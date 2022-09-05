#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int T, n, cnt[maxn];

int main() {
    scanf("%d", &T);
    auto calc = [&](int x) {
        if (!x) return 1;
        if (x == 1) return 1;
        return 1 << (__lg(x - 1) + 1);
    };
    while (T--) {
        scanf("%d", &n);
        fill(cnt, cnt + n + 1, 0);
        for (int i = 1, x; i <= n; i++) {
            scanf("%d", &x), cnt[x]++;
        }
        for (int i = 1; i <= n; i++) {
            cnt[i] += cnt[i - 1];
        }
        int ans = INT_MAX;
        for (int i = 0; i <= n; i++) {
            int mn = calc(0) + calc(cnt[i]);
            for (int j = 1; j <= cnt[i]; j <<= 1) {
                int k = upper_bound(cnt, cnt + n + 1, j) - cnt - 1;
                mn = min(mn, calc(cnt[k]) + calc(cnt[i] - cnt[k]));
            }
            ans = min(ans, mn + calc(cnt[n] - cnt[i]));
        }
        printf("%d\n", ans - n);
    }
    return 0;
}