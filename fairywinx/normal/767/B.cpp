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

    long long s, f, k;
    cin >> s >> f >> k;
    int n;
    cin >> n;
    if (n == 0) {
        cout << s << '\n';
        return 0;
    }
    vector<long long> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    if (a[0] > s) {
        cout << s << '\n';
        return 0;
    }
    a.push_back(f);
    for (int i = 1; i <= n; ++i) {
        if (s + i * k < a[i] && s + i * k <= f - k) {
            cout << s + i * k << '\n';
            return 0;
        }
    }
    pair<long long, long long> ans = {1e18, -1};
    for (int i = 0; i < n; ++i) {
        if (s + i * k <= f - k)
            ans = min(ans, {s + i * k - (a[i] - 1), a[i] - 1});
    }
    cout << ans.second << '\n';
}