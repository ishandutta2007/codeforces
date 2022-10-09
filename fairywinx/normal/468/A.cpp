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

    int n;
    cin >> n;
    if (n < 4) {
        cout << "NO\n";
        return 0;
    } else if (n % 2 == 0) {
        cout << "YES\n";
        cout << "1 * 2 = 2\n";
        cout << "2 * 3 = 6\n";
        cout << "6 * 4 = 24\n";
        for (int i = 5; i + 1 <= n; i += 2) {
            cout << i + 1 << " - " << i << " = 1\n";
            cout << "1 * 24 = 24\n";
        }
    } else {
        cout << "YES\n";
        cout << "5 - 3 = 2\n";
        cout << "2 + 1 = 3\n";
        cout << "2 * 3 = 6\n";
        cout << "6 * 4 = 24\n";
        for (int i = 6; i + 1 <= n; i += 2) {
            cout << i + 1 << " - " << i << " = 1\n";
            cout << "1 * 24 = 24\n";
        }
    }
}