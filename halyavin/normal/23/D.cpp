#ifdef __GNUC__
#pragma GCC target("sse4,avx")
#endif

#include <immintrin.h>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>

struct point {
  int x, y;

  point() : x(0), y(0) { }

  point(int x, int y) : x(x), y(y) { }
};

struct dpoint {
  double x, y;

  dpoint() : x(0), y(0) { }

  dpoint(double x, double y) : x(x), y(y) { }
};

int area(point p1, point p2, point p3) {
  return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
}

double darea(dpoint p1, dpoint p2, dpoint p3) {
  return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
}

// ax + by = c
struct line {
  int a, b, c;

  line(int a, int b, int c) : a(a), b(b), c(c) { }
};

line middleLine(point p1, point p2) {
  int a = 2 * (p2.x - p1.x);
  int b = 2 * (p2.y - p1.y);
  int c = ((p1.x * a + p1.y * b) + (p2.x * a + p2.y * b)) / 2;
  return line(a, b, c);
}

dpoint intersect(line eq1, line eq2) {
  double det = eq1.a * eq2.b - eq1.b * eq2.a;
  return dpoint((eq1.c * eq2.b - eq1.b * eq2.c) / det, (eq1.a * eq2.c - eq1.c * eq2.a) / det);
}

point intersect(line eq1, line eq2, int& det) {
  det = eq1.a * eq2.b - eq1.b * eq2.a;
  return point(eq1.c * eq2.b - eq1.b * eq2.c, eq1.a * eq2.c - eq1.c * eq2.a);
}

bool isGood(point p1, point p2, point p3, dpoint& dp1, dpoint& dp2, dpoint& dp3, dpoint& dp4) {
  if ((p1.x == p2.x && p1.y == p2.y) ||
      (p1.x == p3.x && p1.y == p3.y) ||
      (p2.x == p3.x && p2.y == p3.y)) {
    return false;
  }
  if (area(p1, p2, p3) == 0) {
    return false;
  }
  line m1 = middleLine(p1, p2);
  line m2 = middleLine(p2, p3);
  line m2T = line(-m2.a, -m2.b, m2.c - m2.a * 2 * p2.x - m2.b * 2 * p2.y);
  dp2 = intersect(m1, m2T);
  dp1 = dpoint(2 * p1.x - dp2.x, 2 * p1.y - dp2.y);
  dp3 = dpoint(2 * p2.x - dp2.x, 2 * p2.y - dp2.y);
  dp4 = dpoint(2 * p3.x - dp3.x, 2 * p3.y - dp3.y);
  double area1 = darea(dp1, dp2, dp3);
  double area2 = darea(dp2, dp3, dp4);
  double area3 = darea(dp3, dp4, dp1);
  double area4 = darea(dp4, dp1, dp2);
  if (area1 < 0) {
    area2 = -area2;
    area3 = -area3;
    area4 = -area4;
  }
  if (abs(area1) < 1e-6 || area2 < 1e-6 || area3 < 1e-6 || area4 < 1e-6) {
    return false;
  } else {
    return true;

  }
}

bool isGood2(point p1, point p2, point p3, dpoint& dp1, dpoint& dp2, dpoint& dp3, dpoint& dp4) {
  if ((p1.x == p2.x && p1.y == p2.y) ||
      (p1.x == p3.x && p1.y == p3.y) ||
      (p2.x == p3.x && p2.y == p3.y)) {
    return false;
  }
  if (area(p1, p2, p3) == 0) {
    return false;
  }
  line m1 = middleLine(p1, p2);
  line m2 = middleLine(p2, p3);
  line m2T = line(-m2.a, -m2.b, m2.c - m2.a * 2 * p2.x - m2.b * 2 * p2.y);
  int det;
  point ip2 = intersect(m1, m2T, det);
  point ip1 = point(2 * p1.x * det - ip2.x, 2 * p1.y * det - ip2.y);
  point ip3 = point(2 * p2.x * det - ip2.x, 2 * p2.y * det - ip2.y);
  point ip4 = point(2 * p3.x * det - ip3.x, 2 * p3.y * det - ip3.y);
  int area1 = area(ip1, ip2, ip3);
  int area2 = area(ip2, ip3, ip4);
  int area3 = area(ip3, ip4, ip1);
  int area4 = area(ip4, ip1, ip2);
  if (area1 < 0) {
    area2 = -area2;
    area3 = -area3;
    area4 = -area4;
  }
  if (area1 == 0 || area2 <= 0 || area3 <= 0 || area4 <= 0) {
    return false;
  } else {
    double c = 1.0 / det;
    dp1.x = ip1.x * c;
    dp1.y = ip1.y * c;
    dp2.x = ip2.x * c;
    dp2.y = ip2.y * c;
    dp3.x = ip3.x * c;
    dp3.y = ip3.y * c;
    dp4.x = ip4.x * c;
    dp4.y = ip4.y * c;
    return true;
  }
}

void run(std::istream& in, std::ostream& out) {
  int t;
  in >> t;
  out.precision(12);
  for (int test = 0; test < t; test++) {
    point p1, p2, p3;
    in >> p1.x >> p1.y;
    in >> p2.x >> p2.y;
    in >> p3.x >> p3.y;
    dpoint dp1, dp2, dp3, dp4;
    if (isGood2(p1, p2, p3, dp1, dp2, dp3, dp4)) {
//      out << "YES" << "\n";
      printf("YES\n %.12lf %.12lf %.12lf %.12lf %.12lf %.12lf %.12lf %.12lf\n", dp1.x, dp1.y, dp2.x, dp2.y, dp3.x, dp3.y, dp4.x, dp4.y);
//      out << dp1.x << " " << dp1.y << " " << dp2.x << " " << dp2.y << " " << dp3.x << " " << dp3.y << " " << dp4.x <<
//      " " << dp4.y << "\n";
      continue;
    }

    if (isGood2(p1, p3, p2, dp1, dp2, dp3, dp4)) {
      printf("YES\n %.12lf %.12lf %.12lf %.12lf %.12lf %.12lf %.12lf %.12lf\n", dp1.x, dp1.y, dp2.x, dp2.y, dp3.x, dp3.y, dp4.x, dp4.y);
//      out << "YES" << "\n";
//      out << dp1.x << " " << dp1.y << " " << dp2.x << " " << dp2.y << " " << dp3.x << " " << dp3.y << " " << dp4.x <<
//      " " << dp4.y << "\n";
      continue;
    }

    if (isGood2(p2, p1, p3, dp1, dp2, dp3, dp4)) {
      printf("YES\n %.12lf %.12lf %.12lf %.12lf %.12lf %.12lf %.12lf %.12lf\n", dp1.x, dp1.y, dp2.x, dp2.y, dp3.x, dp3.y, dp4.x, dp4.y);
//      out << "YES" << "\n";
//      out << dp1.x << " " << dp1.y << " " << dp2.x << " " << dp2.y << " " << dp3.x << " " << dp3.y << " " << dp4.x <<
//      " " << dp4.y << "\n";
      continue;
    }
    printf("NO\n\n");
//    out << "NO" << std::endl << std::endl;
  }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}