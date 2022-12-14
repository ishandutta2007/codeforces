#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, h;
    cin >> n >> h;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    sort(a.rbegin(), a.rend());

    int ans = h / (a[0] + a[1]) * 2;
    h -= ans / 2 * (a[0] + a[1]);
    if (h > 0) ans++;
    if (h > a[0]) ans++;

    cout << ans << '\n';
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