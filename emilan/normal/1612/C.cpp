#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    ll k, x;
    cin >> k >> x;

    if (k * (k + 1) / 2 >= x) {
        ll l = 0, r = k;
        while (l + 1 < r) {
            ll m = (l + r) / 2;
            if (m * (m + 1) / 2 >= x) r = m;
            else l = m;
        }
        cout << r << "\n";
    } else {
        ll l = 0, r = k - 1;
        while (l + 1 < r) {
            ll m = (l + r) / 2;
            if (m * (2 * k - m - 1) / 2 >= x - k * (k + 1) / 2) r = m;
            else l = m;
        }
        cout << r + k << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}