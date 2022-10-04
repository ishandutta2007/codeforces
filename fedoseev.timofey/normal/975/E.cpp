#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <ctime>
#include <random>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <list>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const ld PI = 3.141592653589793;

struct point {
    ld x, y;
    point() : x(0), y(0) {}
    point(ld x, ld y) : x(x), y(y){}
    ld operator*(const point &p) const {
        return x * p.x + y * p.y;
    }
    ld operator%(const point &p) const {
        return x * p.y - y * p.x;
    }
    point operator-(const point &p) const {
        return point(x - p.x, y - p.y);
    }
    point operator+(const point &p) const {
        return point(x + p.x, y + p.y);
    }
    point operator/(ld k) const {
        return point(x / k, y / k);
    }
    point operator*(ld k) const {
        return point(x * k, y * k);
    }
    point rotate(ld ang) const {
        point res;
        res.x = x * cos(ang) - y * sin(ang);
        res.y = x * sin(ang) + y * cos(ang);
        return res;
    }
    ld len() const {
        return sqrt(x * x + y * y);
    }
    point normalize(ld k = 1) const {
        ld l = (*this).len();
        return (*this) * (k / l);
    }
};

istream& operator>>(istream &in, point &p) {
    in >> p.x >> p.y;
    return in;
}
ostream& operator<<(ostream &out, point &p) {
    out << p.x << ' ' << p.y << '\n';
    return out;
}

vector <point> pts;
vector <point> vects;

ld angle = 0;

ld getAng(const point &u, const point &v) {
    return atan2(u % v, u * v);
}

point get(point centroid, int i) {
    return centroid + vects[i].rotate(angle);
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0), cout.setf(ios::fixed), cout.precision(20);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, q;
    cin >> n >> q;
    pts.resize(n), vects.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> pts[i];
    }
    ld area = 0;
    point C;
    for (int i = 1; i + 1 < n; ++i) {
        point t = (pts[0] + pts[i] + pts[i + 1]) / 3.0;
        ld s = abs((pts[i] - pts[0]) % (pts[i + 1] - pts[0])) / 2.0;
        C.x += t.x * s;
        C.y += t.y * s;
        area += s;
    }
    C = C / area;
    for (int i = 0; i < n; ++i) {
        vects[i] = pts[i] - C;
    }
    int a = 0, b = 1;
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int f, t;
            cin >> f >> t;
            --f, --t;
            if (f != a) swap(a, b);
            point cur = get(C, b);
            point NewC = point(cur.x, cur.y - vects[b].len());
            angle += getAng(C - cur, NewC - cur);
            if (angle < 0) angle += 2 * PI;
            if (angle > 2 * PI) angle -= 2 * PI;
            C = NewC;
            a = t;
        }
        else {
            int v;
            cin >> v;
            --v;
            point res = get(C, v);
            cout << res;
        }
    }
}