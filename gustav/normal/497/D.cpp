#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

const double eps = 1e-9;

bool lt(double a, double b) { return a + eps < b; }
bool gt(double a, double b) { return lt(b, a); }
bool lte(double a, double b) { return !gt(a, b); }
bool gte(double a, double b) { return !lt(a, b); }

struct Pt { double x, y; void read() { scanf("%lf%lf", &x, &y); } };
Pt operator-(Pt p) { return {-p.x, -p.y}; }

void translate(Pt &a, Pt d) {
  a.x += d.x;
  a.y += d.y;
}

double sq(double x) { return x * x; }

double sdist(Pt a, Pt b) {
  return sq(a.x - b.x) + sq(a.y - b.y);
}

double len(Pt p) { return sdist(p, {0, 0}); }

bool intersect(Pt a, Pt b, Pt c) { 
  double A = sq(b.x - a.x) + sq(b.y - a.y);
  double B = 2.0 * (a.x * (b.x - a.x) + a.y * (b.y - a.y));
  double t = -B / 2.0 / A;

  Pt r = {a.x + t * (b.x - a.x), a.y + t * (b.y - a.y)};

  double lo = min(len(a), len(b));
  double hi = max(len(a), len(b));

  if (gte(t, 0.0) && lte(t, 1.0))
    lo = len(r);

  double R = len(c);

  if (gte(R, lo) && lte(R, hi)) 
    return true;

  return false;
}

const int MAXN = 1005;

Pt p; Pt a[MAXN];
Pt q; Pt b[MAXN];

bool check(Pt *a, int n, Pt p, Pt *b, int m, Pt q) {
  Pt nq = q; translate(nq, -p);

  REP(i, n) REP(j, m) {
    Pt bb = b[j]; translate(bb, -p);
    Pt r = {bb.x - nq.x, bb.y - nq.y};
    translate(bb, -r);

    int ni = (i + 1) % n;
    Pt a1 = a[i]; translate(a1, -p); translate(a1, -r);
    Pt a2 = a[ni]; translate(a2, -p); translate(a2, -r);

    if (intersect(a1, a2, bb))
      return true;
  }
  
  return false;
}

int main(void)
{
  int n; p.read(); scanf("%d", &n); REP(i, n) a[i].read();
  int m; q.read(); scanf("%d", &m); REP(i, m) b[i].read();

  if (check(a, n, p, b, m, q)) { puts("YES"); exit(0); }
  if (check(b, m, q, a, n, p)) { puts("YES"); exit(0); }

  puts("NO");

  return 0;
}