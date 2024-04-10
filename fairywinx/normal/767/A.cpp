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
    vector<int> cnt(n + 1);
    int it = n;
    for (int i = 1; i <= n; i += 1) {
        int a;
        cin >> a;
        ++cnt[a];
        while (cnt[it]) {
            cout << it << ' ';
            --it;
        }
        cout << '\n';
    }
}