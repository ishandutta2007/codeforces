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

    int n, k;
    cin >> n >> k;
    int len = 0;
    for (int i = 0; i < k; ++i) {
        int m;
        cin >> m;
        int st = 0;
        for (int j = 0; j < m; ++j) {
            int c;
            cin >> c;
            if (j == 0) {
                st = c;
            }
            if (st == 1 && c == j + 1) {
                ++len;
            }
        }
    }
    cout << 2 * n - 2 * len - k + 1 << '\n';
}