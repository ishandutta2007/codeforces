#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int long long

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, m, ta, tb, k;
    cin >> n >> m >> ta >> tb >> k;
    vector <int> a(n), b(m);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];
    if (k >= n) {
        cout << "-1\n";
        return 0;
    }
    int ans = 0;
    for (int c = 0; c <= min(k, n - 1); ++c) {
        int have = k - c;
        int x = a[c] + ta;
        auto it = lower_bound(b.begin(), b.end(), x);
        int cnt = b.end() - it;
        if (cnt <= have) {
            cout << "-1\n";
            return 0;
        }
        ans = max(ans, tb + *(it + have));
    }
    cout << ans << '\n';
}