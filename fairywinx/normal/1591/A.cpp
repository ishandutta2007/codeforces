#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

void solve() {
    int n;
    cin >> n;
    int ans = 1;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    if (a[0] == 1)
        ++ans;
    for (int i = 1; i < n; ++i) {
        if (a[i] && a[i - 1]) {
            ans += 5;
        } else if (a[i]) {
            ++ans;
        } else if (!a[i] && !a[i - 1]) {
            ans = -1;
            break;
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