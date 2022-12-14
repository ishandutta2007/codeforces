#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 1ll << 61;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<ll> a(n);
    for (ll &x : a) cin >> x;
    sort(a.begin(), a.end());
    ll sum = accumulate(a.begin(), a.end(), 0ll);

    int m;
    cin >> m;
    while (m--) {
        ll atk, def;
        cin >> def >> atk;

        ll ans = INF;
        int i = lower_bound(a.begin(), a.end(), def) - a.begin();

        // no buff atk
        if (i != n) {
            ans = min(
                ans,
                max(atk - (sum - a[i]), 0ll)
            );
        }

        // buff atk
        if (i != 0) {
            ans = min(
                ans,
                max(atk - (sum - a[i - 1]), 0ll) + def - a[i - 1]
            );
        }

        cout << ans << '\n';
    }
}