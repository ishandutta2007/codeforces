#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    array<int, 3> ans;
    if (~n & 1) ans = {n / 2 - 1, n / 2, 1};
    else {
        for (int i = 2; i < n; i++) {
            int j = n - i - 1;
            if (gcd(i, j) == 1) {
                ans = {i, j, 1};
                break;
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        cout << ans[i] << " \n"[i == 2];
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