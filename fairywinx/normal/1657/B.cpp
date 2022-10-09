#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

void solve() {
    int n, mx, x, y;
    cin >> n >> mx >> x >> y;
    long long ans = 0;
    int now = 0;
    for (int i = 1; i <= n; ++i) {
        if (now + x <= mx)
            now += x;
        else
            now -= y;
        ans += now;
    }
    cout << ans << '\n';
}

signed main() {
    #ifndef LOCAL
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif
    #ifdef DEBUG
        freopen("main/in.txt", "r", stdin);
    #endif

    SOLVE
}