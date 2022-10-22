#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
constexpr int INF = 0x3f3f3f3f;
constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr double EPS = 1e-8;
constexpr int MOD = 1000000007;
// constexpr int MOD = 998244353;
constexpr int DY[]{1, 0, -1, 0}, DX[]{0, -1, 0, 1};
constexpr int DY8[]{1, 1, 0, -1, -1, -1, 0, 1}, DX8[]{0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

namespace geometry {
using Real = long double;
constexpr long double PI = 3.14159265358979323846;

int sgn(Real x) {
  static constexpr Real EPS = 1e-8;
  return x > EPS ? 1 : x < -EPS ? -1 : 0;
}

Real degree_to_radian(Real d) { return d * PI / 180; }
Real radian_to_degree(Real r) { return r * 180 / PI; }

struct Point {
  Real x, y;
  Point(Real x = 0, Real y = 0) : x(x), y(y) {}
  Real abs() const { return std::sqrt(norm()); }
  Real arg() const { Real res = std::atan2(y, x); return res < 0 ? res + PI * 2 : res; }
  Real norm() const { return x * x + y * y; }
  Point rotate(Real angle) const { Real cs = std::cos(angle), sn = std::sin(angle); return Point(x * cs - y * sn, x * sn + y * cs); }
  Point unit_vector() const { Real a = abs(); return Point(x / a, y / a); }
  std::pair<Point, Point> normal_unit_vector() const { Point p = unit_vector(); return {Point(-p.y, p.x), Point(p.y, -p.x)}; }
  Point &operator+=(const Point &p) { x += p.x; y += p.y; return *this; }
  Point &operator-=(const Point &p) { x -= p.x; y -= p.y; return *this; }
  Point &operator*=(Real k) { x *= k; y *= k; return *this; }
  Point &operator/=(Real k) { x /= k; y /= k; return *this; }
  bool operator<(const Point &p) const { int x_sgn = sgn(p.x - x); return x_sgn != 0 ? x_sgn == 1 : sgn(p.y - y) == 1; }
  bool operator<=(const Point &p) const { return !(p < *this); }
  bool operator>(const Point &p) const { return p < *this; }
  bool operator>=(const Point &p) const { return !(*this < p); }
  Point operator+() const { return *this; }
  Point operator-() const { return Point(-x, -y); }
  Point operator+(const Point &p) const { return Point(*this) += p; }
  Point operator-(const Point &p) const { return Point(*this) -= p; }
  Point operator*(Real k) const { return Point(*this) *= k; }
  Point operator/(Real k) const { return Point(*this) /= k; }
  friend std::ostream &operator<<(std::ostream &os, const Point &p) { return os << '(' << p.x << ", " << p.y << ')'; }
  friend std::istream &operator>>(std::istream &is, Point &p) { Real x, y; is >> x >> y; p = Point(x, y); return is; }
};

struct Segment {
  Point s, t;
  Segment(const Point &s = {0, 0}, const Point &t = {0, 0}) : s(s), t(t) {}
};
struct Line : Segment {
  using Segment::Segment;
  Line(Real a, Real b, Real c) {
    if (sgn(a) == 0) {
      s = Point(0, -c / b); t = Point(1, s.y);
    } else if (sgn(b) == 0) {
      s = Point(-c / a, 0); t = Point(s.x, 1);
    } else if (sgn(c) == 0) {
      s = Point(0, 0); t = Point(1, -a / b);
    } else {
      s = Point(0, -c / b); t = Point(-c / a, 0);
    }
  }
};

struct Circle {
  Point p; Real r;
  Circle(const Point &p = {0, 0}, Real r = 0) : p(p), r(r) {}
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

Real get_angle(const Point &a, const Point &b, const Point &c) {
  Real ba_arg = (a - b).arg(), bc_arg = (c - b).arg();
  if (ba_arg > bc_arg) std::swap(ba_arg, bc_arg);
  return std::min(bc_arg - ba_arg, static_cast<Real>(PI * 2 - (bc_arg - ba_arg)));
}

Real closest_pair(std::vector<Point> ps) {
  int n = ps.size();
  assert(n > 1);
  std::sort(ps.begin(), ps.end());
  std::function<Real(int, int)> rec = [&ps, &rec](int left, int right) -> Real {
    int mid = (left + right) >> 1;
    Real x_mid = ps[mid].x, d = std::numeric_limits<Real>::max();
    if (left + 1 < mid) {
      Real tmp = rec(left, mid);
      if (tmp < d) d = tmp;
    }
    if (mid + 1 < right) {
      Real tmp = rec(mid, right);
      if (tmp < d) d = tmp;
    }
    std::inplace_merge(ps.begin() + left, ps.begin() + mid, ps.begin() + right, [&](const Point &a, const Point &b) -> bool { return sgn(b.y - a.y) == 1; });
    std::vector<Point> tmp;
    for (int i = left; i < right; ++i) {
      if (sgn(std::abs(ps[i].x - x_mid) - d) == 1) continue;
      for (int j = static_cast<int>(tmp.size()) - 1; j >= 0; --j) {
        Point now = ps[i] - tmp[j];
        if (sgn(now.y - d) == 1) break;
        Real tmp = now.abs();
        if (tmp < d) d = tmp;
      }
      tmp.emplace_back(ps[i]);
    }
    return d;
  };
  return rec(0, n);
}

Point projection(const Segment &a, const Point &b) { return a.s + (a.t - a.s) * dot(a.t - a.s, b - a.s) / (a.t - a.s).norm(); }
Point reflection(const Segment &a, const Point &b) { return projection(a, b) * 2 - b; }

bool is_parallel(const Segment &a, const Segment &b) { return sgn(cross(a.t - a.s, b.t - b.s)) == 0; }
bool is_orthogonal(const Segment &a, const Segment &b) { return sgn(dot(a.t - a.s, b.t - b.s)) == 0; }

Real distance(const Point&, const Point&);
Real distance(const Segment&, const Point&);
Real distance(const Line&, const Point&);
int sizeof_common_tangent(const Circle&, const Circle&);
bool has_intersected(const Segment &a, const Point &b) { return ccw(a.s, a.t, b) == 0; }
bool has_intersected(const Segment &a, const Segment &b) { return ccw(a.s, a.t, b.s) * ccw(a.s, a.t, b.t) <= 0 && ccw(b.s, b.t, a.s) * ccw(b.s, b.t, a.t) <= 0; }
bool has_intersected(const Line &a, const Point &b) { int c = ccw(a.s, a.t, b); return c != 1 && c != -1; }
bool has_intersected(const Line &a, const Segment &b) { return ccw(a.s, a.t, b.s) * ccw(a.s, a.t, b.t) != 1; }
bool has_intersected(const Line &a, const Line &b) { return sgn(cross(a.t - a.s, b.t - b.s)) != 0 || sgn(cross(a.t - a.s, b.s - a.s)) == 0; }
bool has_intersected(const Circle &a, const Point &b) { return sgn(distance(a.p, b) - a.r) == 0; }
bool has_intersected(const Circle &a, const Segment &b) { return sgn(a.r - distance(b, a.p)) != -1 && sgn(std::max(distance(a.p, b.s), distance(a.p, b.t)) - a.r) != -1; }
bool has_intersected(const Circle &a, const Line &b) { return sgn(a.r - distance(b, a.p)) != -1; }
bool has_intersected(const Circle &a, const Circle &b) { return sizeof_common_tangent(a, b) > 0; }

Point intersection(const Line &a, const Line &b) {
  assert(has_intersected(a, b) && !is_parallel(a, b));
  return a.s + (a.t - a.s) * cross(b.t - b.s, b.s - a.s) / cross(b.t - b.s, a.t - a.s);
}
Point intersection(const Segment &a, const Segment &b) {
  assert(has_intersected(a, b));
  if (is_parallel(a, b)) {
    if (sgn(distance(a.s, b.s)) == 0) {
      assert(sgn(dot(a.t - a.s, b.t - a.s)) == -1);
      return a.s;
    } else if (sgn(distance(a.s, b.t)) == 0) {
      assert(sgn(dot(a.t - a.s, b.s - a.s)) == -1);
      return a.s;
    } else if (sgn(distance(a.t, b.s)) == 0) {
      assert(sgn(dot(a.s - a.t, b.t - a.t)) == -1);
      return a.t;
    } else if (sgn(distance(a.t, b.t)) == 0) {
      assert(sgn(dot(a.s - a.t, b.s - a.t)) == -1);
      return a.t;
    } else {
      assert(false);
    }
  } else {
    return intersection(Line(a.s, a.t), Line(b.s, b.t));
  }
}
Point intersection(const Line &a, const Segment &b) {
  assert(has_intersected(a, b));
  return intersection(a, Line(b.s, b.t));
}
std::vector<Point> intersection(const Circle &a, const Line &b) {
  Point pro = projection(b, a.p);
  Real nor = (a.p - pro).norm();
  int sign = sgn(a.r - std::sqrt(nor));
  if (sign == -1) return {};
  if (sign == 0) return {pro};
  Point v = (b.t - b.s).unit_vector() * std::sqrt(a.r * a.r - nor);
  return {pro + v, pro - v};
}
std::vector<Point> intersection(const Circle &a, const Segment &b) {
  if (!has_intersected(a, b)) return {};
  std::vector<Point> res = intersection(a, Line(b.s, b.t));
  if (sgn(distance(a.p, b.s) - a.r) != -1 && sgn(distance(a.p, b.t) - a.r) != -1) return res;
  return {sgn(dot(res[0] - b.s, res[0] - b.t)) == 1 ? res[1] : res[0]};
}
std::vector<Point> intersection(const Circle &a, const Circle &b) {
  int sz = sizeof_common_tangent(a, b);
  if (sz == 0 || sz == 4) return {};
  Real alpha = (b.p - a.p).arg();
  if (sz == 1 || sz == 3) return {Point(a.p.x + a.r * std::cos(alpha), a.p.y + a.r * std::sin(alpha))};
  Real dist = (b.p - a.p).norm(), beta = std::acos((dist + a.r * a.r - b.r * b.r) / (2 * std::sqrt(dist) * a.r));
  return {a.p + Point(a.r * std::cos(alpha + beta), a.r * std::sin(alpha + beta)), a.p + Point(a.r * std::cos(alpha - beta), a.r * std::sin(alpha - beta))};
}

Real distance(const Point &a, const Point &b) { return (b - a).abs(); }
Real distance(const Segment &a, const Point &b) {
  Point foot = projection(a, b);
  return has_intersected(a, foot) ? distance(foot, b) : std::min(distance(a.s, b), distance(a.t, b));
}
Real distance(const Segment &a, const Segment &b) { return has_intersected(a, b) ? 0 : std::min({distance(a, b.s), distance(a, b.t), distance(b, a.s), distance(b, a.t)}); }
Real distance(const Line &a, const Point &b) { return distance(projection(a, b), b); }
Real distance(const Line &a, const Segment &b) { return has_intersected(a, b) ? 0 : std::min(distance(a, b.s), distance(a, b.t)); }
Real distance(const Line &a, const Line &b) { return has_intersected(a, b) ? 0 : distance(a, b.s); }

std::vector<Point> tangency(const Circle &a, const Point &b) {
  Real dist = distance(a.p, b);
  int sign = sgn(dist - a.r);
  if (sign == -1) return {};
  if (sign == 0) return {b};
  Real alpha = (b - a.p).arg(), beta = std::acos(a.r / dist);
  return {a.p + Point(a.r * std::cos(alpha + beta), a.r * std::sin(alpha + beta)), a.p + Point(a.r * std::cos(alpha - beta), a.r * std::sin(alpha - beta))};
}
int sizeof_common_tangent(const Circle &a, const Circle &b) {
  Real dist = distance(a.p, b.p);
  int sign = sgn(a.r + b.r - dist);
  if (sign == -1) return 4;
  if (sign == 0) return 3;
  sign = sgn((sgn(a.r - b.r) == -1 ? b.r - a.r : a.r - b.r) - dist);
  if (sign == -1) return 2;
  if (sign == 0) return 1;
  return 0;
}
std::vector<Line> common_tangent(const Circle &a, const Circle &b) {
  std::vector<Line> tangents;
  Real dist = distance(a.p, b.p), argument = (b.p - a.p).arg();
  int sign = sgn(a.r + b.r - dist);
  if (sign == -1) {
    Real ac = std::acos((a.r + b.r) / dist), alpha = argument + ac, cs = std::cos(alpha), sn = std::sin(alpha);
    tangents.emplace_back(a.p + Point(a.r * cs, a.r * sn), b.p + Point(-b.r * cs, -b.r * sn));
    alpha = argument - ac; cs = std::cos(alpha); sn = std::sin(alpha);
    tangents.emplace_back(a.p + Point(a.r * cs, a.r * sn), b.p + Point(-b.r * cs, -b.r * sn));
  } else if (sign == 0) {
    Point s = a.p + Point(a.r * std::cos(argument), a.r * std::sin(argument));
    tangents.emplace_back(s, s + (b.p - a.p).normal_unit_vector().first);
  }
  if (sgn(b.r - a.r) == -1) {
    sign = sgn(a.r - b.r - dist);
    if (sign == -1) {
      Real at = std::acos((a.r - b.r) / dist), alpha = argument + at, cs = std::cos(alpha), sn = std::sin(alpha);
      tangents.emplace_back(a.p + Point(a.r * cs, a.r * sn), b.p + Point(b.r * cs, b.r * sn));
      alpha = argument - at; cs = std::cos(alpha); sn = std::sin(alpha);
      tangents.emplace_back(a.p + Point(a.r * cs, a.r * sn), b.p + Point(b.r * cs, b.r * sn));
    } else if (sign == 0) {
      Point s = a.p + Point(a.r * std::cos(argument), a.r * std::sin(argument));
      tangents.emplace_back(s, s + (b.p - a.p).normal_unit_vector().first);
    }
  } else {
    sign = sgn(b.r - a.r - dist);
    if (sign == -1) {
      Real at = std::acos((b.r - a.r) / dist), alpha = argument - at, cs = std::cos(alpha), sn = std::sin(alpha);
      tangents.emplace_back(a.p + Point(-a.r * cs, -a.r * sn), b.p + Point(-b.r * cs, -b.r * sn));
      alpha = argument + at; cs = std::cos(alpha); sn = std::sin(alpha);
      tangents.emplace_back(a.p + Point(-a.r * cs, -a.r * sn), b.p + Point(-b.r * cs, -b.r * sn));
    } else if (sign == 0) {
      Point s = b.p + Point(-b.r * std::cos(argument), -b.r * std::sin(argument));
      tangents.emplace_back(s, s + (a.p - b.p).normal_unit_vector().first);
    }
  }
  return tangents;
}

Real intersection_area(const Circle &a, const Circle &b) {
  Real nor = (b.p - a.p).norm(), dist = std::sqrt(nor);
  if (sgn(a.r + b.r - dist) != 1) return 0;
  if (sgn(std::abs(a.r - b.r) - dist) != -1) return std::min(a.r, b.r) * std::min(a.r, b.r) * PI;
  Real alpha = std::acos((nor + a.r * a.r - b.r * b.r) / (2 * dist * a.r)), beta = std::acos((nor + b.r * b.r - a.r * a.r) / (2 * dist * b.r));
  return (alpha - std::sin(alpha + alpha) * 0.5) * a.r * a.r + (beta - std::sin(beta + beta) * 0.5) * b.r * b.r;
}

using Polygon = std::vector<Point>;

Real area(const Polygon &a) {
  int n = a.size();
  Real res = 0;
  for (int i = 0; i < n; ++i) res += cross(a[i], a[(i + 1) % n]);
  return res * 0.5;
}

Point centroid(const Polygon &a) {
  Point res(0, 0);
  int n = a.size();
  Real den = 0;
  for (int i = 0; i < n; ++i) {
    Real cro = cross(a[i], a[(i + 1) % n]);
    res += (a[i] + a[(i + 1) % n]) / 3 * cro;
    den += cro;
  }
  return res / den;
}

int is_contained(const Polygon &a, const Point &b) {
  int n = a.size();
  bool is_in = false;
  for (int i = 0; i < n; ++i) {
    Point p = a[i] - b, q = a[(i + 1) % n] - b;
    if (sgn(q.y - p.y) == -1) std::swap(p, q);
    int sign = sgn(cross(p, q));
    if (sign == 1 && sgn(p.y) != 1 && sgn(q.y) == 1) is_in = !is_in;
    if (sign == 0 && sgn(dot(p, q)) != 1) return 1;
  }
  return is_in ? 2 : 0;
}

bool is_convex(const Polygon &a) {
  int n = a.size();
  for (int i = 0; i < n; ++i) {
    if (ccw(a[(i - 1 + n) % n], a[i], a[(i + 1) % n]) == -1) return false;
  }
  return true;
}

Polygon monotone_chain(std::vector<Point> ps, bool tight = true) {
  std::sort(ps.begin(), ps.end());
  int n = ps.size(), idx = 0;
  Polygon convex_hull(n << 1);
  for (int i = 0; i < n; convex_hull[idx++] = ps[i++]) {
    while (idx >= 2 && sgn(cross(convex_hull[idx - 1] - convex_hull[idx - 2], ps[i] - convex_hull[idx - 1])) < tight) --idx;
  }
  for (int i = n - 2, border = idx + 1; i >= 0; convex_hull[idx++] = ps[i--]) {
    while (idx >= border && sgn(cross(convex_hull[idx - 1] - convex_hull[idx - 2], ps[i] - convex_hull[idx - 1])) < tight) --idx;
  }
  convex_hull.resize(idx - 1);
  return convex_hull;
}

Polygon cut_convex(const Polygon &a, const Line &b) {
  int n = a.size();
  Polygon res;
  for (int i = 0; i < n; ++i) {
    int c = ccw(b.s, b.t, a[i]);
    if (c != -1) res.emplace_back(a[i]);
    if (c * ccw(b.s, b.t, a[(i + 1) % n]) == -1) res.emplace_back(intersection(Line(a[i], a[(i + 1) % n]), b));
  }
  if (res.size() < 3) res.clear();
  return res;
}

std::pair<Point, Point> rotating_calipers(const Polygon &a) {
  int n = a.size(), high = 0, low = 0;
  if (n <= 2) {
    assert(n == 2);
    return {a[0], a[1]};
  }
  for (int i = 1; i < n; ++i) {
    if (a[i].y > a[high].y) high = i;
    if (a[i].y < a[low].y) low = i;
  }
  Real max_norm = (a[high] - a[low]).norm();
  int i = high, j = low, max_i = i, max_j = j;
  do {
    ((sgn(cross(a[(i + 1) % n] - a[i], a[(j + 1) % n] - a[j])) != -1 ? j : i) += 1) %= n;
    Real tmp = (a[j] - a[i]).norm();
    if (sgn(tmp - max_norm) == 1) {
      max_norm = tmp;
      max_i = i; max_j = j;
    }
  } while (i != high || j != low);
  return {a[max_i], a[max_j]};
}
}  // geometry

int main() {
  using Real = long double;
  int n, r; cin >> n >> r;
  vector<int> x(n), y(n); REP(i, n) cin >> x[i] >> y[i];
  const auto dist = [&](int i, int j) -> ll {
    return 1LL * (x[i] - x[j]) * (x[i] - x[j]) + 1LL * (y[i] - y[j]) * (y[i] - y[j]);
  };
  vector holds(n, vector(n, 1));
  REP(i, n) {
    vector<pair<Real, Real>> angle{{-M_PI, M_PI}};
    REP(j, n) {
      const ll d = dist(i, j);
      if (d <= 1LL * r * r) continue;
      const Real a = atan2l(y[j] - y[i], x[j] - x[i]), b = asinl(r / sqrtl(d));
      vector<pair<Real, Real>> tmp;
      if (a - b < -M_PI) {
        tmp = {{-M_PI, a + b}, {a - b + M_PI * 2.l, M_PI}};
      } else if (a + b > M_PI) {
        tmp = {{-M_PI, a + b - M_PI * 2.l}, {a - b, M_PI}};
      } else {
        tmp = {{a - b, a + b}};
      }
      vector<pair<Real, Real>> nx;
      for (const auto [a, b] : angle) {
        for (const auto [c, d] : tmp) {
          if (max(a, c) <= min(b, d)) nx.emplace_back(max(a, c), min(b, d));
        }
      }
      angle.swap(nx);
    }
    REP(j, n) {
      if (j == i) continue;
      const Real ata = atan2l(y[j] - y[i], x[j] - x[i]);
      holds[i][j] = false;
      for (const auto [a, b] : angle) {
        holds[i][j] |= a - EPS < ata && ata < b + EPS;
      }
    }
  }
  int ans = 0;
  REP(i, n) FOR(j, i + 1, n) ans += holds[i][j] && holds[j][i];
  cout << ans << '\n';
  return 0;
}