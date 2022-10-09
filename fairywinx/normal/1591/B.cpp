#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

void solve() {
    int n;
    cin >> n;
    int ans = -1;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int mx = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] > mx) {
            ++ans;
            mx = a[i];
        }
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

    SOLVE;
}