#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    string ans;
    for (int i = 0; i < m - 1; ++i)
        ans += "L";
    for (int i = 0; i < n - 1; ++i)
        ans += "D";
    for (int i = 0; i < n;) {
        for (int j = 0; j < m - 1; ++j)
            ans += "R";
        ans += "U";
        ++i;
        if (i == n)
            break;
        for (int j = 0; j < m - 1; ++j)
            ans += "L";
        ans += "U";
        ++i;
    }
    cout << ans.size() << '\n';
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