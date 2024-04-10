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

    int n, q;
    cin >> n >> q;
    vector<vector<int>> used(2, vector<int> (n + 2));
    int cnt = 0;
    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        for (int i = -1; i <= 1; ++i) {
            if (used[a][b] && used[a ^ 1][b + i]) {
                cnt -= 1;
            } else if (!used[a][b] && used[a ^ 1][b + i]) {
                cnt += 1;
            }
        }
        if (!cnt) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
        used[a][b] = used[a][b] ^ 1;
    }
}