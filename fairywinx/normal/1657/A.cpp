#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

void solve() {
    int x, y;
    cin >> x >> y;
    if (x == 0 && y == 0) {
        cout << 0 << '\n';
        return;
    }
    for (int i = 0; i < 100; ++i) {
        if (i * i == x * x + y * y) {
            cout << 1 << '\n';
            return;
        }
    }
    cout << 2 << '\n';
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