#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

void solve() {
    string s;
    cin >> s;
    vector<int> cnt(27);
    for (int i = 0; i < (int) s.size(); ++i) {
        ++cnt[s[i] - 'a'];
    }
    for (int i = 0; i < (int) s.size(); ++i) {
        if (cnt[s[i] - 'a'] == 1) {
            cout << s.substr(i) << '\n';
            return;
        }
        --cnt[s[i] - 'a'];
    }
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