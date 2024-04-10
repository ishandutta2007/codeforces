#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int mn = INF, mx = -INF;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        mn = min(mn, x); mx = max(mx, x);
    }

    cout << (mx - mn + 1) - n << '\n';
    return 0;
}