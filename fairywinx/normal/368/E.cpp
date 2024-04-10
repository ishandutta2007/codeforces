#include <bits/stdc++.h>
 
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();
 
using namespace std;

signed main() {
    #ifdef DEBUG
        freopen( "main/in.txt", "r", stdin);
    #endif
    #ifndef LOCAL
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif

    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i] >> a[i];
    }
    sort(rall(a));
    for (int i = m; i >= 0; --i) {
        long long c = 1ll * i * (i - 1) / 2;
        if (i % 2 == 0) {
            c += i / 2 - 1;
        }
        if (c <= n - 1) {
            long long ans = 0;
            for (int j = 0; j < i; ++j) {
                ans += a[j];
            }
            cout << ans << '\n';
            return 0;
        }
    }
}