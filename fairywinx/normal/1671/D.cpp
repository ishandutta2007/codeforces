#include <bits/stdc++.h>
 
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();
 
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    long long ans = 0;
    for (int i = 0; i < n - 1; ++i) {
        ans += abs(a[i + 1] - a[i]);
    }
    const int inf = 1e9 + 228;
    int l = inf, r = -inf;
    int mn = *min_element(all(a));
    int mx = *max_element(all(a));
    if (mn > 1) {
        l = 1;
    }
    if (mx < x) {
        r = x;
    }
    int val1 = 0, val2 = 0;
    if (r > mx) {
        val1 = min((r - mx) * 2, r - max(a.back(), a[0]));
    }
    if (l < mn) {
        val2 = min((mn - l) * 2, min(a.back(), a[0]) - l);
    }
    cout << ans + val1 + val2 << '\n';
}

signed main() {
    #ifdef DEBUG
        freopen( "main/in.txt", "r", stdin);
    #endif
    #ifndef LOCAL
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif

    SOLVE
}