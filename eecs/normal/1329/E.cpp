#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 400010;
int T, m;
ll n, K, a[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%lld %d %lld", &n, &m, &K);
        for (int i = 1; i <= m; i++) {
            scanf("%lld", &a[i]);
        }
        a[++m] = n;
        for (int i = m; i; i--) {
            a[i] -= a[i - 1];
        }
        ll l = 1, r = *min_element(a + 1, a + m + 1), lmax, rmin;
        while (l <= r) {
            ll mid = (l + r) >> 1, sum = 0;
            for (int i = 1; i <= m; i++) {
                sum += a[i] / mid - 1;
            }
            sum >= K ? l = (lmax = mid) + 1 : r = mid - 1;
        }
        l = 1, r = *max_element(a + 1, a + m + 1);
        while (l <= r) {
            ll mid = (l + r) >> 1, sum = 0;
            for (int i = 1; i <= m; i++) {
                sum += (a[i] + mid - 1) / mid - 1;
            }
            sum <= K ? r = (rmin = mid) - 1 : l = mid + 1;
        }
        if (lmax >= rmin) { printf("0\n"); continue; }
        vector<pair<ll, ll>> V = {{lmax, rmin}};
        for (int i = 1; i <= m; i++) {
            ll foo = a[i] / lmax, bar = (a[i] + rmin - 1) / rmin;
            if (foo >= bar) continue;
            V.emplace_back(a[i] / (foo + 1), (a[i] - 1) / (bar - 1) + 1);
        }
        sort(V.begin(), V.end());
        ll ans = LLONG_MAX, cur = rmin;
        for (int i = 0; i < V.size(); i++) {
            ans = min(ans, cur - V[i].first);
            cur = max(cur, V[i].second);
        }
        printf("%lld\n", ans);
    }
    return 0;
}