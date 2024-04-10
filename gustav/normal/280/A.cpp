#include <cstdio>
#include <cassert>
#include <cstring>

#include <algorithm>
#include <iostream>
#include <complex>

using namespace std;
typedef long long llint;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

const long double pi = acos(-1);
const long double eps = 1e-9;

bool lt(long double a, long double b) { return a + eps < b; }
bool gt(long double a, long double b) { return lt(b, a); }
bool eq(long double a, long double b) { return !lt(a, b) && !lt(b, a); }

bool lte(long double a, long double b) { return !gt(a, b); }
typedef complex< long double > Comp;

struct Pt {
  long double x, y;
};

Pt rotate(Pt p, long double alpha) {
  Comp c = {p.x, p.y};
  c = c * Comp(cos(alpha), sin(alpha));
  return {c.real(), c.imag()};
}

long double cross(Pt a, Pt b) {
  return a.x * b.y - a.y * b.x;
}

long double ccw(Pt a, Pt b, Pt c) {
  long double ret = 0;
  ret += a.x * (b.y - c.y);
  ret += b.x * (c.y - a.y);
  ret += c.x * (a.y - b.y);
  return ret;
}

long double dist(Pt a, Pt b) {
  long double dx = a.x - b.x;
  long double dy = a.y - b.y;
  return sqrt(dx * dx + dy * dy);
}

int main(void) 
{
  double w, h, a;
  scanf("%lf%lf%lf", &w, &h, &a);
  w /= 1000;
  h /= 1000;

  a /= 360.0;
  a *= 2 * pi;

  vector< Pt > r1;
  r1.push_back({0.5 * w, 0.5 * h});
  r1.push_back({-0.5 * w, 0.5 * h});
  r1.push_back({-0.5 * w, -0.5 * h});
  r1.push_back({0.5 * w, -0.5 * h});

  vector< Pt > r2;
  for (Pt p : r1) r2.push_back(rotate(p, a));

  vector< Pt > p;

  auto append_duals = [&](vector< Pt > &r) {
    REP(i, 4) {
      int j = (i + 1) % 4;
    
      long double A = r[i].y - r[j].y;
      long double B = r[j].x - r[i].x;
      long double C = -(A * r[i].x + B * r[i].y);

      assert(fabs(C) > 1e-9);

      p.push_back({A / C, B / C});
    }
  };

  append_duals(r1);
  append_duals(r2);

  sort(p.begin(), p.end(), [](Pt a, Pt b) {
      if (!eq(a.x, b.x)) return lt(a.x, b.x);
      return lt(a.y, b.y);
    });

  sort(p.begin() + 1, p.end(), [&](Pt a, Pt b) {
      long double c = ccw(p[0], a, b);
      if (!eq(c, 0)) return gt(c, 0);
      return lt(dist(p[0], a), dist(p[0], b));
    });
  {
    vector< Pt > h;
    for (auto q : p) {
      while (h.size() >= 2 &&
	     lte(ccw(h[h.size() - 2], h[h.size() - 1], q), 0))
	h.pop_back();
      h.push_back(q);
    }

    int n = h.size();
    vector< Pt > poly;

    REP(i, n) {
      int j = (i + 1) % n;
      Pt p1 = h[i];
      Pt p2 = h[j];

      long double x = (p2.y - p1.y) / cross(p1, p2);
      long double y = (p2.x - p1.x) / cross(p2, p1);
      poly.push_back({x, y});
    }

    long double sol = 0.0;
    REP(i, n) {
      int j = (i + 1) % n;
      sol += cross(poly[i], poly[j]);
    }

    printf("%.10lf\n", double(0.5 * fabs(sol)) * 1e6);
  }

  return 0;
}