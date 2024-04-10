#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 300010;
int n, m, k;
ll a[maxn], r[maxn], s[maxn];

int main() {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    fill(r, r + maxn, 1e18), r[0] = 0;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + a[i];
        for (int j = 0; j < m; j++) {
            ll tmp = s[i] - 1LL * i / m * k - r[j];
            if (i % m > j) tmp -= k;
            ans = max(ans, tmp);
        }
        r[i % m] = min(r[i % m], s[i] - 1LL * i / m * k);
    }
    printf("%lld\n", ans);
    return 0;
}
// 7 -2k
// 5 -k