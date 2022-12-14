#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, l, r, k;
    cin >> n >> l >> r >> k;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    sort(a.begin(), a.end());

    int ans = 0;
    for (int x : a) {
        if (l <= x && x <= r && k - x >= 0) {
            k -= x;
            ans++;
        }
    }
    cout << ans << "\n";
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