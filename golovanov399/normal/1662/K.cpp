#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
 
#include <bits/stdc++.h>
using namespace std;
 
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
 
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using uint = unsigned int;
using ull = unsigned long long;
 
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
default_random_engine generator;
 
void solve();
 
int task;
 
int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);  
#endif 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(12) << fixed;
    cerr << setprecision(12) << fixed;  
 
    int tests = 1;
    // cin >> tests;
 
    for (int test = 1; test <= tests; ++test) {
        // cout << "Case #" << test << ": ";
        solve();
    }
 
#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}
 
// ----------------------------------------------------------------- 

const ld PI = acos(-1);

struct Point {
    ld x, y;
};

Point operator+(const Point &a, const Point &b) {
    return {a.x + b.x, a.y + b.y};
}

Point operator-(const Point &a, const Point &b) {
    return {a.x - b.x, a.y - b.y};
}

Point operator*(const Point &a, ld c) {
    return {a.x * c, a.y * c};
}

ld dot(const Point &a, const Point &b) {
    return a.x * b.x + a.y * b.y;
}

ld cross(const Point &a, const Point &b) {
    return a.x * b.y - a.y * b.x;
}

ld dist(const Point &a) {
    return hypotl(a.x, a.y);
}

ld sum_dist(const array<Point, 3> &p) {  
    array<ld, 3> alpha;
    for (int i = 0; i < 3; ++i) {
        int j = (i + 1) % 3;
        int k = (i + 2) % 3;
        alpha[i] = abs(atan2(cross(p[j] - p[i], p[k] - p[i]), dot(p[j] - p[i], p[k] - p[i])));
        if (alpha[i] >= 2 * PI / 3) {
            return dist(p[i] - p[j]) + dist(p[i] - p[k]);
        }
    }

    array<ld, 3> c = {
        dist(p[1] - p[2]) / sin(alpha[0] + PI / 3),
        dist(p[0] - p[2]) / sin(alpha[1] + PI / 3),
        dist(p[0] - p[1]) / sin(alpha[2] + PI / 3),
    };

    Point cen = (p[0] * c[0] + p[1] * c[1] + p[2] * c[2]) * (1 / (c[0] + c[1] + c[2]));
    ld res = 0;
    for (int i = 0; i < 3; ++i) {
        res += dist(cen - p[i]);
    }

    return res;
}

void solve() {
    array<Point, 3> p;
    for (auto& [x, y] : p) {
        cin >> x >> y;
    }



    auto f = [&](ld x) -> ld {
        ld lf = -1e4, rg = 1e4;

        ld res = 1e9;
        for (int op = 0; op < 200; ++op) {
            ld y1 = (2 * lf + rg) / 3;
            ld y2 = (lf + 2 * rg) / 3;

            Point p1{x, y1};
            Point p2{x, y2};

            ld res1 = 0, res2 = 0;
            for (int i = 0; i < 3; ++i) {
                res1 = max(res1, sum_dist({p[i], p[(i + 1) % 3], p1}));
                res2 = max(res2, sum_dist({p[i], p[(i + 1) % 3], p2}));
            }

            res = min({res, res1, res2});

            if (res1 < res2) {
                rg = y2;
            } else {
                lf = y1;
            }
        }
        // cerr << x << " " << lf << endl;
        return res;
    };

    ld lf = -1e4, rg = 1e4;
    for (int op = 0; op < 200; ++op) {
        ld x1 = (2 * lf + rg) / 3;
        ld x2 = (lf + 2 * rg) / 3;
        if (f(x1) < f(x2)) {
            rg = x2;
        } else {
            lf = x1;
        }
    }

    cout << f(lf) << endl;
}