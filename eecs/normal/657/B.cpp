#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 210000;
int n, K;
ll a[maxn], b[maxn];

int main() {
    scanf("%d %d", &n, &K);
    for (int i = 0; i <= n; i++) {
        scanf("%lld", &a[i]), b[i] = a[i];
    }
    ll ans = 0, cur = 0;
    int m;
    for (int i = 0; ; i++) {
        if (i > n + 200 && !b[i]) { m = i; break; }
        if (b[i] > 1) {
            b[i + 1] += b[i] / 2;
            b[i] %= 2;
        } else if (b[i] < -1) {
            b[i + 1] -= -b[i] / 2;
            b[i] += -b[i] / 2 * 2;
        }
    }
    for (int i = 0; i <= n; i++) if (b[i] || i == n) {
        ll num = 0;
        bool flag = 1;
        for (int j = m; j >= i; j--) {
            num = num * 2 + b[j];
            if (abs(num) > (ll)1e18) { flag = 0; break; }
        }
        if (flag) {
            ll o = num;
            for (int j = i; j >= 0; j--) {
                if (abs(a[j] - num) > (ll)1e18) break;
                if (i == n && a[j] == num) ans--;
                if (abs(a[j] - num) <= K) ans++;
                num <<= 1;
            }
            num = o;
            for (int j = i + 1; j <= n; j++) {
                if (num & 1) break;
                num >>= 1;
                if (abs(a[j] - num) <= K) {
                    ans++;
                    if (i == n && a[j] == num) ans--;
                }
            }
        }
        break;
    }
    printf("%lld\n", ans);
    return 0;
}