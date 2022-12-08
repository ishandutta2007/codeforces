#include <algorithm>
#include <cassert>
#include <cmath>
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
typedef vector<string> VS;
typedef vector<PII> VPI;
typedef vector<PLL> VPL;
template <class T, class S> ostream& operator<<(ostream& os, const pair<T, S>& v) { return os << "(" << v.first << ", " << v.second << ")"; }
template <class T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; repn(i, sz(v)) { if(i) os << ", "; os << v[i]; } return os << "]"; }
template <class T> bool setmax(T& _a, T _b) { if(_a < _b) { _a = _b; return true; } return false; }
template <class T> bool setmin(T& _a, T _b) { if(_b < _a) { _a = _b; return true; } return false; }
template <class T> T gcd(T _a, T _b) { return _b == 0 ? _a : gcd(_b, _a % _b); }
// clang-format on
// }}}

const double EPS = 1e-10;
double sgn(double x) { return x < -EPS ? -1 : x > EPS; }
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

int main() {
    int n;
    scanf("%d", &n);
    vector<Point> ps(n);
    for(auto& p : ps) scanf("%lf%lf", &p.x, &p.y);
    double ans = 1e50;
    repn(i, n) {
        Point p1 = ps[i], p2 = ps[(i + 1) % n], p3 = ps[(i + 2) % n];
        Point dir = (p1 - p3);
        dir.rotate90();
        dir.normalize();
        setmin(ans, abs(dot(dir, p2 - p1)) / 2);
    }
    printf("%.9lf\n", ans);
    return 0;
}