#include <bits/stdc++.h>
 
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();
 
using namespace std;
 
signed main() {
    #ifdef DEBUG
        freopen("main/in.txt", "r", stdin);
    #endif
    #ifndef LOCAL
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif

    int n, m;
    cin >> n >> m;
    for (int i = 1; ; ++i) {
        if (n == 0) {
            cout << i - 1 << '\n';
            return 0;
        }
        --n;
        if (i % m == 0)
            ++n;
    }
}