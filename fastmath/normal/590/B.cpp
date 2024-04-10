#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
const int INF = 1e9 + 7;
const int T = 100;
int v, t;
int vx1, vy1, vx2, vy2;
int wx, wy;
pair <double, double> getd(double m) {
    if (m < t) {
        return {vx1 * m, vy1 * m};
    }
    else {
        return {vx1 * t + vx2 * (m - t), vy1 * t + vy2 * (m - t)};
    }   
}   
bool check(pair <double, double> d, double t) {
    pair <double, double> w = {wx - d.first, wy - d.second};
    return w.first * w.first + w.second * w.second <= t * v * t * v;
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0); cout.precision(20);
    #endif
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    wx = x2 - x1, wy = y2 - y1;
    cin >> v >> t;
    cin >> vx1 >> vy1 >> vx2 >> vy2;
    double l = 0, r = INF;
    for (int i = 0; i < T; ++i) {
        double m = (l + r) / 2;
        pair <double, double> d = getd(m);
        if (check(d, m)) {
            r = m;
        }
        else {
            l = m;
        }   
    }   
    cout << r << '\n';
}