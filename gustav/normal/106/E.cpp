#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

typedef long long llint;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

const double eps = 1e-9;
inline bool lt(double a, double b) { return a + eps < b; }
inline bool gt(double a, double b) { return lt(b, a); }
inline bool eq(double a, double b) { return !lt(a, b) && !gt(a, b); }
inline bool lte(double a, double b) { return !gt(a, b); }

inline double sq(double x) { return x * x; }

struct Pt {
  double x, y, z;
  void read() {
    scanf("%lf%lf%lf", &x, &y, &z);
  }
  void output() {
    printf("%.10lf %.10lf %.10lf\n", x, y, z);
  }
};

inline Pt operator+(const Pt &a, const Pt &b) { return {a.x + b.x, a.y + b.y, a.z + b.z}; }
inline Pt operator-(const Pt &a, const Pt &b) { return {a.x - b.x, a.y - b.y, a.z - b.z}; }
inline Pt operator*(double d, const Pt &p) { return {d * p.x, d * p.y, d * p.z}; }
inline bool operator==(Pt a, Pt b) {
  return eq(a.x, b.x) && eq(a.y, b.y) && eq(a.z, b.z);
}

inline double dist(const Pt &a, const Pt &b) {
  double ret = 0;
  ret += sq(a.x - b.x);
  ret += sq(a.y - b.y);
  ret += sq(a.z - b.z);
  return sqrt(ret);
}

inline double norm(const Pt &p) {
  return dist({0.0, 0.0, 0.0}, p);
}

inline Pt cross(const Pt &a, const Pt &b) {
  Pt ret;
  ret.x = a.y * b.z - a.z * b.y;
  ret.y = -(a.x * b.z - b.x * a.z);
  ret.z = a.x * b.y - a.y * b.x;
  return ret;
}

inline double dot(const Pt &a, const Pt &b) {
  return a.x * b.x + a.y * b.y + a.z * b.z;
}

struct Line { Pt p, v; };

inline bool intersection(const Line &a, const Line &b, Pt &c) {
  Pt kl = cross({a.v.x, -b.v.x, a.p.x - b.p.x}, 
		{a.v.y, -b.v.y, a.p.y - b.p.y});
  if (eq(kl.z, 0)) return false;
  double k = kl.x / kl.z;
  double l = kl.y / kl.z;
  if (!(a.p + k * a.v == b.p + l * b.v)) return false;
  c = a.p + k * a.v;
  return true;
}

inline Pt normal(const Pt &a, const Pt &b, const Pt &c) {
  return cross(b - a, c - a);
}

inline Pt center2(const Pt &a, const Pt &b) { return 0.5 * (a + b); }

inline bool center3(const Pt &a, const Pt &b, const Pt &c, Pt &cc) {
  Pt n = normal(a, b, c);
  Line l1 = {0.5 * (a + b), cross(n, b - a)};
  Line l2 = {0.5 * (a + c), cross(n, c - a)};
  return intersection(l1, l2, cc);
}

inline bool center4(const Pt &a, const Pt &b, const Pt &c, const Pt &d, Pt &cc) {
  Pt c1; center3(a, b, c, c1);
  Pt c2; center3(b, c, d, c2);
  Line l1 = {c1, normal(a, b, c)};
  Line l2 = {c2, normal(b, c, d)};
  return intersection(l1, l2, cc);
}

struct Sphere {
  Pt p;
  double r;

  bool contains(Pt q) {
    return lte(dist(p, q), r);
  }
};

Sphere MES(vector< Pt > p, vector< Pt > f, Sphere s) {
  if (f.size() == 4) return s;
  if (p.empty()) return s;

  vector< Pt > q(f.begin(), f.end()); // tocke koje sam vec uzeo
  random_shuffle(p.begin(), p.end());

  while (!p.empty()) {
    Pt cur = p.back(); p.pop_back();
    if (s.contains(cur)) {
      q.push_back(cur);
      continue;
    } else {
      vector< Pt > g = f;
      g.push_back(cur);
      Sphere z;
      if (g.size() == 1)
	z.p = g[0];
      else if (g.size() == 2)
	z.p = center2(g[0], g[1]);
      else if (g.size() == 3)
	center3(g[0], g[1], g[2], z.p);
      else
	center4(g[0], g[1], g[2], g[3], z.p);
      z.r = dist(z.p, g[0]);
      s = MES(q, g, z);
      q.push_back(cur);
    }
  }

  return s;
}

const int MAXN = 105;

int n;
vector< Pt > p;

int main(void) {
  scanf("%d", &n);
  REP(i, n) {
    Pt cp; cp.read();
    p.push_back(cp);
  }

  MES(p, {}, {p[0], 0.0}).p.output();
}