#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, m;
        cin >> n >> m;
        int mr = 0, mw = 0;
        for (int i = 0, r, w; i < m; i += 1) {
            cin >> r >> w;
            mr = max(mr, r);
            mw = max(mw, w);
        }
        if (mr + mw > n) cout << "IMPOSSIBLE\n";
        else cout << string(mr, 'R') << string(n - mr, 'W') << "\n";
    }
}