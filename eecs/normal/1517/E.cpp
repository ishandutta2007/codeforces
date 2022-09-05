#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 200010, P = 998244353;
int T, n, a[maxn];
ll pre[maxn], pre2[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        ll lim = 0, ans = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]), lim += a[i];
            pre[i] = pre[i - 1] + a[i], pre2[i] = a[i];
            if (i >= 3) pre2[i] += pre2[i - 2];
        }
        if (n == 1) { puts("1"); continue; }
        lim = (lim - 1) >> 1;
        // s1 = 0:
        // sub: s2 = 0
        for (int i = 2; i <= n; i++) {
            if (pre[n] - pre[i] <= lim) ans++;
        }
        // sub: s2 = 1
        for (int i = 2; i <= n; i++) if (pre[i] - pre[1] <= lim) {
            if (i == n) { ans++; continue; }
            ll lim2 = lim - (pre[i] - pre[1]);
            int l = 0, r = (n - i - 1) / 2, pos;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (pre2[i + mid * 2] - pre2[i] <= lim2) l = (pos = mid) + 1;
                else r = mid - 1;
            }
            ans += pos + 1;
            if (i < n - 1 && lim2 >= a[n]) {
                lim2 -= a[n];
                l = 0, r = (n - i - 2) / 2, pos;
                while (l <= r) {
                    int mid = (l + r) >> 1;
                    if (pre2[i + mid * 2] - pre2[i] <= lim2) l = (pos = mid) + 1;
                    else r = mid - 1;
                }
                ans += pos + 1;
            }
        }
        // s1 = 1:
        for (int i = 1; i <= n; i++) if (pre[i] <= lim) {
            if (i == n) { ans++; continue; }
            ll lim2 = lim - pre[i];
            int l = 0, r = (n - i - 1) / 2, pos;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (pre2[i + mid * 2] - pre2[i] <= lim2) l = (pos = mid) + 1;
                else r = mid - 1;
            }
            ans += pos + 1;
            if (lim2 >= a[n] && i < n - 1) {
                lim2 -= a[n];
                l = 0, r = (n - i - 2) / 2, pos;
                while (l <= r) {
                    int mid = (l + r) >> 1;
                    if (pre2[i + mid * 2] - pre2[i] <= lim2) l = (pos = mid) + 1;
                    else r = mid - 1;
                }
                ans += pos + 1;
            }
        }
        printf("%lld\n", ans % P);
    }
    return 0;
}