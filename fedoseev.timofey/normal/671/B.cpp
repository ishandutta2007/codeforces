#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, k;
    cin >> n >> k;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    ll sum = 0;
    for (int i = 0; i < n; ++i) sum += a[i];
    int l = a[0], r = 1e9;
    while (r - l > 1) {
        int m = (l + r) >> 1;
        ll cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] < m) cnt += m - a[i];
        }
        if (cnt <= k) l = m;
        else r = m;
    }
    int mn = l;
    l = -1, r = a[n - 1];
    while (r - l > 1) {
        int m = (l + r) >> 1;
        ll cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] > m) cnt += a[i] - m;
        }
        if (cnt <= k) r = m;
        else l = m;
    }
    int mx = r;
    int ans = max(0, mx - mn);
    if (sum % n) ans = max(ans, 1);
    cout << ans << '\n';
}