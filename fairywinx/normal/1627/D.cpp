#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

signed main() {
    #ifdef DEBUG
        freopen("main/in.txt", "r", stdin);
    #endif
    #ifndef LOCAL
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif

    int n;
    cin >> n;
    unordered_set<int> s(2 * n);
    int mx = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        mx = max(mx, a);
        s.insert(a);
    }
    int ans = 0;
    for (int j = mx - 1; j >= 1; --j) {
        int d = 0;
        for (int i = j; i <= mx; i += j) {
            if (s.count(i))
                d = gcd(d, i / j);
        }
        if (d == 1 && !s.count(j)) {
            ans++;
            s.insert(j);
        }
    }
    cout << ans << '\n';
}