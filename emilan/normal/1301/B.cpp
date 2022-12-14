#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        int mn = 1 << 30, mx = -1, d = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == -1) {
                if (i && a[i - 1] != -1) {
                    mn = min(mn, a[i - 1]);
                    mx = max(mx, a[i - 1]);
                }

                if (i != n - 1 && a[i + 1] != -1) {
                    mn = min(mn, a[i + 1]);
                    mx = max(mx, a[i + 1]);
                }
            } else {
                if (i && a[i - 1] != -1) {
                    d = max(abs(a[i] - a[i - 1]), d);
                }
            }
        }
        int x = (mx - mn + 1) / 2;

        cout << max(d, x) << ' ' << mn + x << '\n';
    }

    return 0;
}