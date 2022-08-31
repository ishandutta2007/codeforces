#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100010], b[100010];
ll sum;
int n;
#define calc(a, b) ((a) - 1 - 3ll * (b) * (b) - 3ll * (b))
inline void check(ll mid) {
    for (int i = 1; i <= n; i++) {
        if (a[i] - 1 < mid) b[i] = 0;
        else if (calc(a[i], a[i]) >= mid) b[i] = a[i];
        else {
            ll A = 3, B = 3, C = mid + 1 - a[i];
            ll r = (-B + sqrt(B * B - 4. * A * C)) / (2 * A);
            while (calc(a[i], r) >= mid) r++;
            while (calc(a[i], r - 1) < mid) r--;
            b[i] = r;
        }
    }
    sum = 0;
    for (int i = 1; i <= n; i++) sum += b[i];
}
ll k;
int main() {
    scanf("%d%lld", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    ll L = -4e18, R = 1e9, ans;
    while (L <= R) {
        ll mid = (L + R) >> 1;
        check(mid);
        if (sum >= k) ans = mid, L = mid + 1;
        else R = mid - 1;
    }
    check(ans);
    for (int i = 1; i <= n; i++) {
        if (sum == k) break;
        if (b[i] && calc(a[i], b[i] - 1) == ans) sum--, b[i]--;
    }
    for (int i = 1; i <= n; i++) printf("%d%c", b[i], " \n"[i == n]);
}