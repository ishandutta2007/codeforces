#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    vector<int> ans(n);
    if (~n & 1) {
        for (int i = 0; i < n; i += 2) {
            ans[i] = -a[i + 1];
            ans[i + 1] = a[i];
        }
    } else {
        for (int i = 0; i < n - 3; i += 2) {
            ans[i] = -a[i + 1];
            ans[i + 1] = a[i];
        }

        if ((a[n - 2] > 0) == (a[n - 1] > 0)) {
            ans[n - 3] = -(a[n - 2] + a[n - 1]);
            ans[n - 2] = a[n - 3];
            ans[n - 1] = a[n - 3];
        } else {
            ans[n - 3] = -(a[n - 2] - a[n - 1]);
            ans[n - 2] = a[n - 3];
            ans[n - 1] = -a[n - 3];
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
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