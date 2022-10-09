#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

void solve() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    if (a == b) {
        cout << 0 << '\n';
        return;
    }
    int cnt[2][2];
    for (int i = 0; i < 2; ++i) {
        cnt[i][0] = 0, cnt[i][1] = 0;
    }
    for (int i = 0; i < n; ++i) {
        cnt[a[i] - '0'][b[i] - '0']++;
    }
    int ans = n + 228;
    {
        if (cnt[1][0] == cnt[0][1]) {
            ans = min(ans, cnt[1][0] + cnt[0][1]);
        }
    }
    {
        if (cnt[0][0] + 1 == cnt[1][1]) {
            ans = min(ans, cnt[0][0] + cnt[1][1]);
        }
    }
    if (ans == n + 228) {
        cout << -1 << '\n';
    } else {
        cout << ans << '\n';
    }
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