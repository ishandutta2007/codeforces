#include <bits/stdc++.h>
 
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();
 
using namespace std;

void solve() {
    vector<vector<int>> cnt1(4, vector<int> (4));
    vector<vector<int>> cnt2(4, vector<int> (4));
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            char c;
            cin >> c;
            if (c == '.' || c == 'K') {
                cnt1[i % 4][j % 4] += 1;
            }
            if (c == 'K') {
                cnt2[i % 4][j % 4] += 1;
            }
        }
    }
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (cnt2[i][j] == 2 && cnt1[i][j]) {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
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

    SOLVE;
}