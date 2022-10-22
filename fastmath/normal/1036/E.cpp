#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double

const double PI = acos(-1);
const double EPS = 1e-9;
const int INF = 1e9 + 7;

struct Point {
    double x, y;
    Point(double x_, double y_) {
        x = x_; y = y_;
    }
    Point(){}
    bool const operator <(const Point p) const {
        return x + EPS < p.x || (abs(x - p.x) < EPS && y + EPS < p.y);
    }
    Point operator +(Point p) {
        return Point(x + p.x, y + p.y);
    }
    Point operator -(Point p) {
        return Point(x - p.x, y - p.y);
    }
    double operator *(Point p) {
        return x * p.y - y * p.x;
    }
    double operator %(Point p) {
        return x * p.x + y * p.y;
    }
    Point operator *(double t) {
        return Point(x * t, y * t);
    }   
    Point rt(double alp) {
        alp = alp / 180 * PI;
        return Point(cos(alp) * x - sin(alp) * y, sin(alp) * x + cos(alp) * y);
    }
    Point rt90() {
        return Point(-y, x);
    }
};

struct Line {
    Point p, v;

    bool check(Line l) {
        double d = v % l.v.rt90();
        if (!d) return 0;
        double t = ((l.p - p) % l.v.rt90()) / (v % l.v.rt90());

        Point np = p + v * t;
        int lx = max(min(p.x, p.x + v.x), min(l.p.x, l.p.x + l.v.x));
        int rx = min(max(p.x, p.x + v.x), max(l.p.x, l.p.x + l.v.x));
        int ly = max(min(p.y, p.y + v.y), min(l.p.y, l.p.y + l.v.y));
        int ry = min(max(p.y, p.y + v.y), max(l.p.y, l.p.y + l.v.y));
        
        return (lx < np.x + EPS && np.x - EPS < rx && ly < np.y + EPS && np.y - EPS < ry);
    }

    Point operator *(Line l) {
        /*
        x = p + v * t
        (x - l.0) % l.v.rt(90) = 0
        (p + v * t - l.0) % l.v.rt(90) = 0
        (v * t) % l.v.rt(90) = (l.0 - p) % l.v.rt(90)
        t = ((l.0 - p) % l.v.rt(90)) / (v % l.v.rt(90))
        */
        double t = ((l.p - p) % l.v.rt90()) / (v % l.v.rt90());
        return p + v * t;
    }

    int get() {
        return __gcd(abs((int)v.x), abs((int)v.y)) + 1;
    }
};

const int MAXN = 1007;

int n;
Line a[MAXN];

void read() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        Point p1, p2;
        cin >> p1.x >> p1.y >> p2.x >> p2.y;
        a[i].p = p1;
        a[i].v = p2 - p1;
    }
}

int ans = 0;
void solve() {
    for (int i = 0; i < n; ++i) {
        ans += a[i].get();
        set <pair <int, int> > ms;
        for (int j = 0; j < i; ++j) {
            if (a[i].check(a[j])) {
                auto np = a[i] * a[j];
                if (abs(np.x - round(np.x)) < EPS && abs(np.y - round(np.y)) < EPS) {
                    ms.insert({round(np.x), round(np.y)});
                }
            }
        }
        ans -= ms.size();
    }
}

void print() {
    cout << ans << '\n';
}

signed main() {
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    read();
    solve();
    print();

    return 0;
}