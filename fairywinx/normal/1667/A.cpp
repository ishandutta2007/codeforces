#include <bits/stdc++.h>
 
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();
 
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    long long ans = 1e18;
    for (int i = 0; i < n; ++i) {
        long long tmp = 0;
        {
            long long lst = 1;
            for (int j = i - 1; j >= 0; --j) {
                tmp += (lst + a[j] - 1) / a[j];
                lst = 1ll * ((lst + a[j] - 1) / a[j]) * a[j] + 1;
            }
            // cout << tmp << ' ';
        }
        {
            long long lst = 1;
            for (int j = i + 1; j < n; ++j) {
                tmp += (lst + a[j] - 1) / a[j];
                lst = 1ll * ((lst + a[j] - 1) / a[j]) * a[j] + 1;
            }
        }
        // cout << i << ':' << tmp << '\n';
        ans = min(ans, tmp);
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

    // SOLVE;
    solve();
}