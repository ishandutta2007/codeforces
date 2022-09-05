#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 500010;
int n, r;
ll k, a[maxn], b[maxn];

bool chk(ll x) {
    ll s = 0;
    memset(b, 0, sizeof(b));
    for (int i = 1; i <= n; i++) {
        b[max(1, i - r)] += a[i];
        b[min(n, i + r) + 1] -= a[i];
    }
    for (int i = 1; i <= n; i++) {
        b[i] += b[i - 1];
        if (b[i] < x) {
            s += x - b[i];
            b[min(n, i + r + r) + 1] -= x - b[i];
            b[i] += x - b[i];
        }
        if (s > k) return 0;
    }
    return 1;
}

int main() {
    scanf("%d %d %lld", &n, &r, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    ll l = 0, r = 2e18, ans;
    while (l <= r) {
        ll mid = (l + r) >> 1;
        chk(mid) ? l = (ans = mid) + 1 : r = mid - 1;
    }
    printf("%lld\n", ans);
    return 0;
}