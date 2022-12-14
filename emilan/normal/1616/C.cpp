#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    int ans = n - 1;
    for (int l = 0; l < n; l++) {
        for (int r = l + 1; r < n; r++) {
            int cur = 0;
            for (int i = 0; i < n; i++) {
                int num = (i - l) * (a[r] - a[l]);
                int den = r - l;
                if (num % den != 0 || a[l] + num / den != a[i]) cur++;
            }
            ans = min(ans, cur);
        }
    }
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