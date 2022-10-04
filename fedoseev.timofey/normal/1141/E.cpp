#include <bits/stdc++.h>

#define int long long

using namespace std;

typedef long long ll;
typedef long double ld;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll H, n;
    cin >> H >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    ll cur = H;
    for (int i = 0; i < n; ++i) {
        cur += a[i];
        if (cur <= 0) {
            cout << i + 1 << '\n';
            return 0;
        }
    }
    ll delta = 0;
    for (int i = 0; i < n; ++i) {
        delta += a[i];
    }
    if (delta >= 0) {
        cout << "-1\n";
        return 0;
    }
    ll mx = 0;
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        sum -= a[i];
        mx = max(mx, sum);
    }

    delta *= -1;
    ll ans = ((H - mx) / delta) * n;
    H = mx + ((H - mx) % delta);
    while (true) {
        for (int i = 0; i < n; ++i) {
            ++ans;
            H += a[i];
            if (H <= 0) {
                cout << ans << '\n';
                return 0;
            }
        }
    }
}