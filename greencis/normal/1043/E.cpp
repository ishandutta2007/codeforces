#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, m, x[300105], y[300105];
ll ans[300105];
pair<int, pll> a[300105];

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i] >> y[i];
        a[i] = {x[i] - y[i], {x[i], y[i]}};
    }
    sort(a + 1, a + n + 1);

    for (int i = 1; i <= n; ++i) {
        a[i].second.first += a[i - 1].second.first;
        a[i].second.second += a[i - 1].second.second;
    }

    for (int i = 1; i <= n; ++i) {
        int idx = lower_bound(a + 1, a + n + 1, make_pair(x[i] - y[i], make_pair(LLONG_MIN, LLONG_MIN))) - (a + 1);
        ans[i] = y[i] * ll(idx) + x[i] * ll(n - idx);
        ans[i] += a[idx].second.first - a[idx].second.second + a[n].second.second;
    }

    while (m--) {
        int a, b;
        cin >> a >> b;
        int mn = min(x[a] + y[b], x[b] + y[a]);
        ans[a] -= mn;
        ans[b] -= mn;
    }

    for (int i = 1; i <= n; ++i)
        cout << ans[i] - x[i] - y[i] << " ";
}