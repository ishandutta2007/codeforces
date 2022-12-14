#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    int best = INT_MAX, ans;
    for (int i = 0; i + k < n; i++) {
        int d = a[i + k] - a[i];
        if (d < best) {
            best = d;
            ans = (a[i + k] + a[i]) / 2;
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