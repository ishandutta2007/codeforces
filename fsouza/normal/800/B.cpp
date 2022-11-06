#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;
typedef complex<double> point_t;

const double E = 1e-10, pi = acos(-1.0);

const double max_coord_abs = 1e9;

double dot(const point_t &a, const point_t &b) {
  return a.real() * b.real() + a.imag() * b.imag();
}
double cross(const point_t &a, const point_t &b) {
  return a.real() * b.imag() - a.imag() * b.real();
}

double cross(const point_t &a, const point_t &b, const point_t &c) {
  return cross(b - a, c - a);
}

double dist(const point_t &a, const point_t &b) { return abs(a - b); }

point_t unit(const point_t &a) { return a / abs(a); }

point_t rotate_ccw(const point_t &a, double angle) {
  return a * point_t(cos(angle), sin(angle));
}

point_t proj(const point_t &u, const point_t &v) {
  return v * dot(u, v) / dot(v, v);
}

point_t line_intersection(const point_t &p1, const point_t &v1,
                          const point_t &p2, const point_t &v2) {
  double t = cross(p2 - p1, v2) / cross(v1, v2);
  return p1 + t * v1;
}

double signed_dist_to_line(const point_t &p, const point_t &line_p,
                           const point_t &line_v) {
  return cross(line_v, p - line_p) / abs(line_v);
}

bool circles_coline(const point_t &a, const point_t &b, const point_t &c,
                    double radius) {
  if (dist(a, b) <= 2 * radius + E ||
      dist(a, c) <= 2 * radius + E ||
      dist(b, c) <= 2 * radius + E) {
    return true;
  }
  double half_dist = dist(a, b) / 2;
  point_t m = (a + b) / 2.0;
  double x = asin(radius / half_dist);
  point_t up = unit(rotate_ccw(b - m, pi / 2));
  point_t m_pa_dir = rotate_ccw(up, pi / 2 - x);
  point_t m_pb_dir = rotate_ccw(up, -(pi / 2 - x));
  point_t top_a = a + up * radius;
  point_t top_b = b + up * radius;
  point_t pa = line_intersection(m, m_pa_dir, top_a, top_b - top_a);
  point_t pb = line_intersection(m, m_pb_dir, top_a, top_b - top_a);
  if (signed_dist_to_line(c, pa, pb - pa) > radius + E &&
      signed_dist_to_line(c, pa, m - pa) > radius + E &&
      signed_dist_to_line(c, m, pb - m) > radius + E) {
    return false;
  }
  point_t right = unit(b - m);
  point_t c_x = proj(c - m, right);
  point_t c_y = proj(c - m, up);
  point_t mirror_c = m + c_x - c_y;
  if (signed_dist_to_line(mirror_c, pa, pb - pa) > radius + E &&
      signed_dist_to_line(mirror_c, pa, m - pa) > radius + E &&
      signed_dist_to_line(mirror_c, m, pb - m) > radius + E) {
    return false;
  }
  return true;
}

double solve(const point_t &a, const point_t &b, const point_t &c) {
  double l = 0, r = 4.0 * max_coord_abs;
  for (int rep = 0; rep < 75; ++rep) {
    double m = (l + r) / 2;
    if (circles_coline(a, b, c, m)) r = m;
    else l = m;
  }
  return l;
}

int main() {
  int n;
  scanf("%d", &n);
  vector<point_t> points(n);
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    points[i] = point_t(x, y);
  }
  double result = numeric_limits<double>::infinity();
  for (int i = 0; i < n; ++i) {
    result =
        min(result, solve(points[i], points[(i + 1) % n], points[(i + 2) % n]));
  }
  printf("%.10f\n", result);
  return 0;
}