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

    long long x, y, a1, b1, a2, b2;
    long long x1, y1, t;
    cin >> x >> y >> a1 >> a2 >> b1 >> b2;
    cin >> x1 >> y1 >> t;
    vector<pair<long long, long long>> pt;
    const long long inf = 2e16;
    while (x < inf && y < inf) {
        pt.emplace_back(x, y);
        x = x * a1 + b1;
        y = y * a2 + b2;
    }
    int ans = 0;
    for (int i = 0; i < (int) pt.size(); ++i) {
        for (int j = i; j < (int) pt.size(); ++j) {
            {
                long long d1 = abs(x1 - pt[j].first) + abs(y1 - pt[j].second);
                long long d2 = abs(x1 - pt[i].first) + abs(y1 - pt[i].second);
                long long d3 = abs(pt[i].first - pt[j].first) + abs(pt[i].second - pt[j].second);
                if (min(d1, d2) + d3 <= t) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
    }
    cout << ans << '\n';
}