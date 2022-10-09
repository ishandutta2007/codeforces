#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

void solve() {
    int n;
    cin >> n;
    if (n % 2 == 0) {
        cout << (n - 2) / 2 << ' ' << (n - 2) / 2 + 1 << ' ' << 1 << '\n';
    } else if (n % 4 != 3) {
        cout << (n - 3) / 2 << ' ' << (n - 3) / 2 + 2 << ' ' << 1 << '\n';
    } else {
        cout << (n - 5) / 2 << ' ' << (n - 5) / 2 + 4 << ' ' << 1 << '\n';
    }
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