#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

int n, x[2005], y[2005], ai;
pii a[4001005];
ll ans;

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            a[ai++] = make_pair(x[i] - x[j], y[i] - y[j]);
        }
    }

    sort(a, a + ai);
    a[ai] = make_pair(INT_MAX, INT_MAX);

    int idx = 0;
    while (idx < ai) {
        int oi = idx;
        while (a[oi] == a[idx]) ++idx;
        ans += ll(idx - oi) * ll(idx - oi - 1) / 2LL;
    }
    cout << ans / 4LL;

    return 0;
}