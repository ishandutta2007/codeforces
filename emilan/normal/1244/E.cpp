#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    int n;
    ll k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    sort(a.begin(), a.end());

    int ans = a[n - 1] - a[0];
    int l = 0, r = n - 1;
    while (k > 0 && l <= r) {
        int diff;
        ll cost;
        // mv l
        diff = a[l + 1] - a[l];
        cost = diff * ll(l + 1);
        if (k < cost) {
            ans -= int(k / (l + 1));
            k = 0;
        } else {
            ans -= diff;
            a[l] = a[l + 1];
            k -= cost;
        }
        l++;

        if (k <= 0 || l > r) break;
        // mv r
        diff = -(a[r - 1] - a[r]);
        cost = diff * ll(n - r);
        if (k < cost) {
            ans -= int(k / (n - r));
            k = 0;
        } else {
            ans -= diff;
            a[r] = a[r - 1];
            k -= cost;
        }
        r--;
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}