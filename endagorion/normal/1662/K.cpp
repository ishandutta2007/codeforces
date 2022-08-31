#include <bits/stdc++.h>

#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef pair<i64, i64> pi64;
typedef long double ld;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

struct Point {
    ld x, y;

    Point operator-(const Point &p) const {
        return {x - p.x, y - p.y};
    }

    ld operator%(const Point &p) const {
        return x * p.y - y * p.x;
    }

    ld operator*(const Point &p) const {
        return x * p.x + y * p.y;
    }

    ld operator~() const {
        return hypotl(x, y);
    }

    void read() {
        cin >> x >> y;
    }
};

Point A, B, C;

ld INF = 2e4;
ld alpha = 0.4;
const int ITS = 100;

ld f(const vector<Point> &p, Point q) {
    ld sum = 0.0;
    for (auto &r: p) sum += ~(r - q);
    return sum;
}

ld eval(const vector<Point> &p, optional<ld> x) {
    if (x.has_value()) {
        ld L = -INF, R = INF;
        forn(its, ITS) {
            ld M1 = L + alpha * (R - L), M2 = R - alpha * (R - L);
            ld f1 = f(p, {*x, M1}), f2 = f(p, {*x, M2});
            if (f1 < f2) R = M2;
            else L = M1;
        }
        return f(p, {*x, 0.5 * (L + R)});
    } else {
        forn(i, 3) {
            Point a = p[i], b = p[(i + 1) % 3], c = p[(i + 2) % 3];
            ld X = ~(b - a), Y = ~(c - a);
            if ((c - b) * (c - b) > X * X + X * Y + Y * Y) return X + Y;
        }
        Point a = p[0], b = p[1], c = p[2];
        ld S = fabs((b - a) % (c - a));
        return sqrtl(0.5 * ((b - a) * (b - a) + (c - a) * (c - a) + (c - b) * (c - b)) + sqrtl(3) * S);
    }
}

ld max3(Point p) {
    auto ans = max({eval({p, A, B}, nullopt), eval({p, B, C}, nullopt), eval({p, C, A}, nullopt)});
//    cerr << p.x << ' ' << p.y << ' ' << ans << '\n';
    return ans;
}

ld eval2(optional<ld> x) {
    if (x.has_value()) {
        ld L = -INF, R = INF;
        forn(its, ITS) {
            ld M1 = L + alpha * (R - L), M2 = R - alpha * (R - L);
            ld f1 = max3({*x, M1}), f2 = max3({*x, M2});
            if (f1 < f2) R = M2;
            else L = M1;
        }
        return max3({*x, 0.5 * (L + R)});
    } else {
        ld L = -INF, R = INF;
        forn(its, ITS) {
            ld M1 = L + alpha * (R - L), M2 = R - alpha * (R - L);
            ld f1 = eval2(M1), f2 = eval2(M2);
            if (f1 < f2) R = M2;
            else L = M1;
        }
        return eval2(0.5 * (L + R));
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    A.read(); B.read(); C.read();
    cout << eval2(nullopt) << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}