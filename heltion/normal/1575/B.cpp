#include <bits/stdc++.h>
using namespace std;
using LL = long long;
struct P{
    int x, y;
    double dis() const{
        return hypot(x, y);
    }
};
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    vector<P> vp(n);
    double L = 0, R = 200000;
    for (auto& [x, y] : vp) {
        cin >> x >> y;
        if (x == 0 and y == 0) {
            k -= 1;
            x = 2 * R;
        }
    }
    double PI = acos(-1);
    for (int step = 0; step < 50; step += 1) {
        double M = (L + R) / 2;
        vector<pair<double, int>> sp;
        for (auto p : vp) {
            double cs = p.dis() / 2 / M;
            if (cs > 1) continue;
            double c = atan2(p.y, p.x);
            double t = acos(cs);
            double x = c - t, y = c + t;
            if (x <= -PI) {
                sp.push_back({x + 2 * PI, 1});
                sp.push_back({PI, -1});
                x = -PI;
            }
            if (y >= PI) {
                sp.push_back({-PI, 1});
                sp.push_back({y - 2 * PI, -1});
                y = PI;
            }
            sp.push_back({x, 1});
            sp.push_back({y, -1});
        }
        sort(sp.begin(), sp.end());
        int p = 0, s = 0;
        for (auto [x, y] : sp) {
            s += y;
            p = max(p, s);
        }
        if (p >= k) R = M;
        else L = M;
    }
    cout << fixed << setprecision(20) << L;
    return 0;
}