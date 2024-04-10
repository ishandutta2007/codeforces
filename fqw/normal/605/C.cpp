#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// {{{
// clang-format off
#define all(a) (a).begin(), (a).end()
#define sz(a) static_cast<int>((a).size())
#define fillchar(a, x) memset(a, x, sizeof(a))
#define rep(i, a, b) for (int i = int(a); i <= int(b); ++i)
#define irep(i, a, b) for (int i = int(a); i >= int(b); --i)
#define replr(i, a, b) rep(i, a, (b)-1)
#define reprl(i, a, b) irep(i, (b)-1, a)
#define repn(i, n) rep(i, 0, (n)-1)
#define irepn(i, n) irep(i, (n)-1, 0)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define popcount __builtin_popcount
typedef long long LL;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<double, double> PDD;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<double> VD;
typedef vector<bool> VB;
typedef vector<string> VS;
typedef vector<PII> VPI;
typedef vector<PLL> VPL;
typedef vector<PDD> VPD;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VD> VVD;
typedef vector<VB> VVB;
typedef vector<VS> VVS;
typedef vector<VPI> VVPI;
typedef vector<VPL> VVPL;
template <class T, class S> ostream& operator<<(ostream& os, const pair<T, S>& v) { return os << "(" << v.first << ", " << v.second << ")"; }
template <class T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; repn(i, sz(v)) { if(i) os << ", "; os << v[i]; } return os << "]"; }
template <class T> bool setmax(T& _a, T _b) { if(_a < _b) { _a = _b; return true; } return false; }
template <class T> bool setmin(T& _a, T _b) { if(_b < _a) { _a = _b; return true; } return false; }
template <class T> T gcd(T _a, T _b) { return _b == 0 ? _a : gcd(_b, _a % _b); }
VI read_vi(int n = -1) { if (n < 0) scanf("%d", &n); VI a(n); repn(i, n) scanf("%d", &a[i]); return a; }
VL read_vl(int n = -1) { if (n < 0) scanf("%d", &n); VL a(n); repn(i, n) scanf("%lld", &a[i]); return a; }
VD read_vd(int n = -1) { if (n < 0) scanf("%d", &n); VD a(n); repn(i, n) scanf("%lf", &a[i]); return a; }
VPI read_vpi(int n = -1) { if (n < 0) scanf("%d", &n); VPI a(n); repn(i, n) scanf("%d%d", &a[i].fi,&a[i].se); return a; }
VPL read_vpl(int n = -1) { if (n < 0) scanf("%d", &n); VPL a(n); repn(i, n) scanf("%lld%lld", &a[i].fi,&a[i].se); return a; }
VPD read_vpd(int n = -1) { if (n < 0) scanf("%d", &n); VPD a(n); repn(i, n) scanf("%lf%lf", &a[i].fi,&a[i].se); return a; }
inline LL powmod(LL a, LL b, LL m) { LL r = 1; for(; b > 0; b >>= 1, a = a * a % m) { if(b & 1) r = r * a % m; } return r; }
// clang-format on
// }}}

const double EPS = 1e-10;
int sgn(double x) { return x < -EPS ? -1 : x > EPS; }
struct Point {
    double x, y;
    Point() {}
    Point(double _x, double _y) : x(_x), y(_y) {}
    Point operator+(const Point& p) const { return Point(x + p.x, y + p.y); }
    Point operator-(const Point& p) const { return Point(x - p.x, y - p.y); }
    Point operator*(double b) const { return Point(x * b, y * b); }
    Point operator/(double b) const { return Point(x / b, y / b); }
    void rotate90() {
        swap(x, y);
        x = -x;
    }
    double len() const { return sqrt(x * x + y * y); }
    void normalize() { *this = *this / len(); }
    friend double mult(Point p1, Point p2) { return p1.x * p2.y - p1.y * p2.x; }
    friend double dot(Point p1, Point p2) { return p1.x * p2.x + p1.y * p2.y; }
    friend double mult(Point p0, Point p1, Point p2) {
        return mult(p1 - p0, p2 - p0);
    }
    friend double dot(Point p0, Point p1, Point p2) {
        return dot(p1 - p0, p2 - p0);
    }
    friend double dist(Point p1, Point p2) { return (p1 - p2).len(); }
    double lambda(Point s, Point t) const {  // return c: p=s+(t-s)*c
        return dot(s, t, *this) / dot(s, t, t);
    }
};
struct Line {
    double a, b, c;
    Line() {}
    Line(double _a, double _b, double _c) : a(_a), b(_b), c(_c) {}
    Line(Point p1, Point p2) {
        a = p2.y - p1.y, b = p1.x - p2.x;
        c = -(p1.x * a + p1.y * b);
    }
    Point cross(const Line& l) const {
        double t = a * l.b - b * l.a;
        double x = b * l.c - c * l.b;
        double y = c * l.a - a * l.c;
        return Point(x / t, y / t);
    }
};

vector<Point> convex(vector<Point> a) {
    sort(all(a), [](const Point& p, const Point& q) {
        int s = sgn(p.y - q.y);
        if(s == 0) s = sgn(p.x - q.x);
        return s < 0;
    });
    vector<Point> b;
    for(const auto& p : a) {
        while(sz(b) >= 2 && sgn(mult(b[sz(b) - 2], b.back(), p)) <= 0) {
            b.pop_back();
        }
        b.pb(p);
    }
    int ind = sz(b);
    reverse(all(a));
    for(const auto& p : a) {
        while(sz(b) > ind && sgn(mult(b[sz(b) - 2], b.back(), p)) <= 0) {
            b.pop_back();
        }
        b.pb(p);
    }
    b.pop_back();
    return b;
}

int main() {
    int n, vp, vq;
    scanf("%d%d%d", &n, &vp, &vq);
    Point dx(vp, vq), dy = dx;
    dy.rotate90();
    double len = dx.len();

    double ans = 1e50;
    vector<Point> a;
    repn(i, n) {
        Point p;
        scanf("%lf%lf", &p.x, &p.y);
        double x = dot(p, dx) / len;
        double y = dot(p, dy) / len;
        a.pb(Point(x, y));
        setmin(ans, max(vp / p.x, vq / p.y));
    }
    a = convex(a);
    repn(i, sz(a)) {
        Point p = a[i], q = a[(i + 1) % sz(a)];
        if(sgn(p.y) != 0) {
            if(sgn(p.y) * sgn(q.y) <= 0) {
                double val = (p.y * q.x - p.x * q.y) / (p.y - q.y);
                if(sgn(val) > 0) {
                    setmin(ans, len / val);
                }
            }
        }
    }
    printf("%.15lf\n", ans);
    return 0;
}