#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 100010;
int n, A;
ll cf, cm, m, ans[maxn], pre[maxn];
pair<ll, int> a[maxn];

int main() {
    scanf("%d %d %lld %lld %lld", &n, &A, &cf, &cm, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i].first), a[i].second = i;
        ans[i] = a[i].first;
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + a[i].first;
    }
    ll sum = 0, mx = 0, num = 0;
    int pos = n + 1;
    for (int i = n + 1; i; i--) {
        if (i <= n) sum += A - a[i].first;
        if (sum > m) break;
        ll l = 0, r = A, foo;
        while (l <= r) {
            ll mid = (l + r) >> 1;
            int bar = lower_bound(a + 1, a + i, make_pair(mid, 0)) - a - 1;
            if (m - sum >= bar * mid - pre[bar]) l = (foo = mid) + 1;
            else r = mid - 1;
        }
        ll bar = (n - i + 1) * cf + foo * cm;
        if (bar > mx) mx = bar, pos = i, num = foo;
    }
    printf("%lld\n", mx);
    for (int i = pos; i <= n; i++) {
        ans[a[i].second] = A;
    }
    for (int i = 1; i <= n; i++) {
        ans[a[i].second] = max(ans[a[i].second], num);
    }
    for (int i = 1; i <= n; i++) {
        printf("%lld ", ans[i]);
    }
    return 0;
}