#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    long long sum = 0;
    for (auto i : a)
        sum += i;
    sort(all(a));
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        long long x, y;
        cin >> x >> y;
        int ind = upper_bound(all(a), sum - y) - a.begin();
        long long ans1 = 1e18 + 228;
        if (ind < n)
            ans1 = max(0ll, x - a[ind]) + max(0ll, y - (sum - a[ind]));
        --ind;
        if (ind >= 0)
            ans1 = min(ans1, max(0ll, x - a[ind]) + max(0ll, y - (sum - a[ind])));
        cout << ans1 << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // int t;
    // cin >> t;
    // while (t--)
        solve();
}