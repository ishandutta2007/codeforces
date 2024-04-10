#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();
#define int long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    long long ans = 0;
    for (int i = 0; i < n - 1; i += 2) {
        int bal = 0, mn = -1;
        for (int j = i + 1; j < n; j += 2) {
            int A = min(a[j] - bal, a[i]) + mn + 1;
            A = max(A, 0ll);
            // cout << i << ' ' << j << ' ' << bal << ' ' << mn << ' ' << A << '\n';
            ans += A;
            bal -= a[j];
            mn = min(bal, mn);
            if (j + 1 < n)
                bal += a[j + 1];
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
    // SOLVE
}