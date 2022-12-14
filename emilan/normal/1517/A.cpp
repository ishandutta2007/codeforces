#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    ll n;
    cin >> n;
    if (n % 2050) return cout << -1, void();

    n /= 2050;
    int ans = 0;
    while (n) {
        ans += n % 10;
        n /= 10;
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    while (tcs--) {
        solve();
        cout << '\n';
    }
}