#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (ll &x : a) cin >> x;

        ll ans = a[0] * n + a[1] * n;

        ll x_min = a[0], x_sum = a[0];
        ll y_min = a[1], y_sum = a[1];
        for (int i = 2; i < n; i++) {
            if (~i & 1) {
                x_min = min(a[i], x_min);
                x_sum += a[i];
            } else {
                y_min = min(a[i], y_min);
                y_sum += a[i];
            }

            int x_cnt = n - (i + 2) / 2;
            int y_cnt = n - (i + 1) / 2;
            ans = min(
                x_sum + y_sum + x_min * x_cnt + y_min * y_cnt,
                ans
            );
        }

        cout << ans << '\n';
    }
}