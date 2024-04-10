#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        ll k;
        cin >> n >> k;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        ll sum = 0;
        for (ll x : a) {
            sum += x;
        }
        if (sum <= k) {
            cout << 0 << "\n";
            continue;
        }
        ll diff = sum - k;
        ll ans = diff;
        ll cur_diff = 0;
        for (int i = n - 1, cnt = 1; i >= 1; --i, ++cnt) {
            cur_diff += a[i] - a[0];
            ans = min(ans, cnt + max(0ll, (diff - cur_diff + cnt) / (cnt + 1)));
        }
        cout << ans << '\n';
    }
    return 0;
}