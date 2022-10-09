#include <bits/stdc++.h>
 
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();
 
using namespace std;

void solve() {
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < (int) s.size(); ) {
        int cnt = 0;
        char c = s[i];
        while (i < (int) s.size() && s[i] == c) {
            ++i;
            ++cnt;
        }
        if (cnt == 1) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    return;
}

signed main() {
    #ifdef DEBUG
        freopen( "main/in.txt", "r", stdin);
    #endif
    #ifndef LOCAL
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif

    SOLVE
}