#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<string> s(n - 2);
    for (int i = 0; i < n - 2; ++i) {
        cin >> s[i];
    }
    string ans = s[0];
    bool find = false;
    for (int i = 1; i < n - 2; ++i) {
        if (s[i][0] != s[i - 1][1]) {
            find = true;
            ans += s[i];
        } else {
            ans += s[i].back();
        }
    }
    if (!find)
        ans += 'a';
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