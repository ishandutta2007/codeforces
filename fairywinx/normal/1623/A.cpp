#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

void solve() {
    int ans = (int) 1e9 + 228;
    int n, m, a, b, c, d;
    cin >> n >> m >> a >> b >> c >> d;
    if (c >= a) {
        ans = min(ans, c - a);
    } else {
        ans = min(ans, n - a + n - c);
    }
    if (d >= b) {
        ans = min(ans, d - b);
    } else {
        ans = min(ans, m - b + m - d);
    }
    cout << ans << '\n';
}

signed main() {
    #ifdef DEBUG
        freopen("main/in.txt", "r", stdin);
    #endif
    #ifndef LOCAL
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif

    SOLVE
}