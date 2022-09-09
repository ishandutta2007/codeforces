#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int t;
    for (cin >> t; t; t -= 1) {
        LL W, H, x1, y1, x2, y2, w, h;
        cin >> W >> H >> x1 >> y1 >> x2 >> y2 >> w >> h;
        LL ans = -1;
        if (x2 - x1 + w <= W) {
            LL pans = max(min(x2 + w - W, w - x1), 0LL);
            if (ans == -1 or pans < ans) ans = pans;
        }
        if (y2 - y1 + h <= H) {
            LL pans = max(min(y2 + h - H, h - y1), 0LL);
            if (ans == -1 or pans < ans) ans = pans;
        }
        cout << ans << "\n";
    }
    return 0;
}