#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <random>
#include <time.h>
#include <bitset>

using namespace std;

const int INF = 1e9 + 7;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
        
    int n, m, c1, c2, v;
    cin >> n >> m >> c1 >> c2 >> v;

    vector <int> a(c1);
    for (int i = 0; i < c1; ++i) cin >> a[i];

    vector <int> b(c2);
    for (int i = 0; i < c2; ++i) cin >> b[i];

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        if (x1 == x2) {
            cout << abs(y1 - y2) << '\n';
            continue;
        }

        int ans = INF;
        
        int l, r;

        l = -1;
        r = c1;
        while (l < r - 1) {
            int m = (l + r) / 2;
            if (a[m] < y1) {
                l = m;
            }
            else {
                r = m;
            }
        }
        if (l != -1) ans = min(ans, abs(y1 - a[l]) + abs(x1 - x2) + abs(y2 - a[l]));
        if (r != c1) ans = min(ans, abs(y1 - a[r]) + abs(x1 - x2) + abs(y2 - a[r]));


        l = -1;
        r = c2;
        while (l < r - 1) {
            int m = (l + r) / 2;
            if (b[m] < y1) {
                l = m;
            }
            else {
                r = m;
            }
        }
        int add = (abs(x1 - x2) - 1) / v + 1;
        if (l != -1) ans = min(ans, abs(y1 - b[l]) + add + abs(y2 - b[l]));
        if (r != c2) ans = min(ans, abs(y1 - b[r]) + add + abs(y2 - b[r]));

        cout << ans << '\n';
    }

    return 0;
}