#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1000000007;
// const int MOD = 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
const int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
  }
} iosetup;

const long double EPS = 1e-8;
using Real = long double;
int sgn(Real x) { return x > EPS ? 1 : x < -EPS ? -1 : 0; }
struct Point {
  Real x, y;
  Point(Real x = 0, Real y = 0) : x(x), y(y) {}
  Real abs() const { return sqrtl(norm()); }
  Real norm() const { return x * x + y * y; }
  Point &operator-=(const Point &p) { x -= p.x; y -= p.y; return *this; }
  Point operator-(const Point &p) const { return Point(*this) -= p; }
  friend ostream &operator<<(ostream &os, const Point &p) { return os << '(' << p.x << ", " << p.y << ')'; }
};
struct Segment {
  Point s, t;
  Segment(const Point &s = {0, 0}, const Point &t = {0, 0}) : s(s), t(t) {}
  Real get_y(Real x) const { return s.y + (t.y - s.y) * (x - s.x) / (t.x - s.x); }
  inline bool operator<(const Segment &b) const {
    Real x = max(s.x, b.s.x), a_y = get_y(x), b_y = b.get_y(x);
    if (abs(a_y - b_y) < EPS) {
      return abs(s.x - b.s.x) > EPS ? s.x < b.s.x : t.y < b.t.y;
    } else {
      return a_y < b_y;
    }
  }
};
Real cross(const Point &a, const Point &b) { return a.x * b.y - a.y * b.x; }
Real dot(const Point &a, const Point &b) { return a.x * b.x + a.y * b.y; }
int ccw(const Point &a, const Point &b, const Point &c) {
  Point ab = b - a, ac = c - a;
  int sign = sgn(cross(ab, ac));
  if (sign == 0) {
    if (sgn(dot(ab, ac)) == -1) return 2;
    if (sgn(ac.norm() - ab.norm()) == 1) return -2;
  }
  return sign;
}
bool has_intersected(const Segment &a, const Segment &b) { return ccw(a.s, a.t, b.s) * ccw(a.s, a.t, b.t) <= 0 && ccw(b.s, b.t, a.s) * ccw(b.s, b.t, a.t) <= 0; }
Real distance(const Point &a, const Point &b) { return (b - a).abs(); }

int main() {
  int n; cin >> n;
  vector<int> x(n), y(n);
  vector<long double> vx(n), vy(n);
  REP(i, n) {
    int dx, dy, s; cin >> x[i] >> y[i] >> dx >> dy >> s;
    long double d = sqrtl(dx * dx + dy * dy);
    // cout << dx << ' ' << dy << ' ' << d << endl;
    vx[i] = dx / d * s;
    vy[i] = dy / d * s;
    // cout << vx[i] << ' ' << vy[i] << endl;
  }
  function<bool(long double)> solve = [&](long double t) {
    vector<long double> sx(n), sy(n), gx(n), gy(n);
    REP(i, n) {
      sx[i] = x[i];
      sy[i] = y[i];
      gx[i] = x[i] + t * vx[i];
      gy[i] = y[i] + t * vy[i];
      if (sx[i] > gx[i]) {
        swap(sx[i], gx[i]);
        swap(sy[i], gy[i]);
      }
      // cout << sx[i] << ' ' << sy[i] << ' ' << gx[i] << ' ' << gy[i] << '\n';
    }
    vector<int> p(n * 2);
    iota(ALL(p), 0);
    stable_sort(ALL(p), [&](int l, int r) {
      double a = l < n ? sx[l] : gx[l - n];
      double b = r < n ? sx[r] : gx[r - n];
      return a < b;
    });
    set<Segment> st;
    REP(i, n * 2) {
      int pi = p[i], idx = pi < n ? pi : pi - n;
      Segment seg(Point(sx[idx], sy[idx]), Point(gx[idx], gy[idx]));
      if (pi < n) {
        auto [it, flag] = st.emplace(seg);
        // if (!flag) {
        //   cout << "Assertion failed\n";
        //   Real x = max(seg.s.x, it->s.x);
        //   cout << seg.get_y(x) << ' ' << (*it).get_y(x) << endl;
        //   cout << "seg: " << seg.s << ' ' << seg.t << endl;
        //   cout << "it: " << it->s << ' ' << it->t << endl;
        // }
        assert(flag);
        if (it != st.begin()) {
          if (has_intersected(seg, *prev(it))) return true;
        }
        if (next(it) != st.end()) {
          if (has_intersected(seg, *next(it))) return true;
        }
      } else {
        auto it = st.lower_bound(seg);
        if (distance(seg.s, it->s) > EPS) {
          assert(it != st.begin());
          it = prev(it);
        }
        if (it != st.begin() && next(it) != st.end()) {
          if (has_intersected(*prev(it), *next(it))) return true;
        }
        st.erase(it);
      }
      // cout << i << ": " << pi << ' ' << idx << endl;
      // for (Segment e : st) cout << e.s << ' ' << e.t << '\n';
    }
    return false;
  };
  long double lb = 0, ub = 1e13;
  REP(_, 200) {
    long double t = (lb + ub) / 2;
    // cout << t << ' ' << solve(t) << '\n';
    (solve(t) ? ub : lb) = t;
  }
  if (1e13 - ub < EPS) {
    cout << "No show :(\n";
  } else {
    cout << ub << '\n';
  }
  return 0;
}