#include <cstdio>
#include <cstring>
#include <cmath>

#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
const double eps = 1e-9;

bool lt(double a, double b) { return a + eps < b; }
bool gt(double a, double b) { return lt(b, a); }
bool eq(double a, double b) { return !lt(a, b) && !gt(a, b); }

struct point {
  double x, y;
  point() {}
  point(double x, double y) :
    x(x), y(y) {}
};

point midpoint(point a, point b) {
  return point(0.5 * (a.x + b.x), 0.5 * (a.y + b.y));
}

struct bisector {
  double A, B, C;
  double ang;
  double hyp;
  int id;

  bisector(double A, double B, double C, double hyp) :
    A(A), B(B), C(C), hyp(hyp) { 
      ang = atan2(A, B); 
      id = -1;
    }

  bisector(point a, point b, int id) : id(id) {
    point m = midpoint(a, b);
    A = b.x - a.x;
    B = b.y - a.y;
    C = - A * m.x - B * m.y;
    ang = atan2(A, B);
    hyp = hypot(A, B);
  }
};

bool operator<(bisector a, bisector b) {
  if (eq(a.ang, b.ang))
    return gt(a.hyp, b.hyp);
  return lt(a.ang, b.ang);
}

#define MAX 1005

int w, h, n;
vector< point > p;

double X, Y;
bool isect(bisector a, bisector b) {
  double det = a.A * b.B - a.B * b.A;
  X = -(a.C * b.B - a.B * b.C) / det;
  Y = +(a.C * b.A - a.A * b.C) / det;
  return !eq(det, 0.0);
}

bool shadowed(bisector a, bisector b, bisector c) {
  isect(a, b);
  return gt(c.A * X + c.B * Y + c.C, 0.0);
}

deque< bisector > cell(int i, vector< point > &p) {
  vector< bisector > bs;
  int n = p.size();

  bs.push_back(bisector(-1, 0, 0, 2 * p[i].x)); // x = 0
  bs.push_back(bisector(0, -1, 0, 2 * p[i].y)); // y = 0
  bs.push_back(bisector(1, 0, -w, 2 * (w - p[i].x))); // x = w
  bs.push_back(bisector(0, 1, -h, 2 * (h - p[i].y))); // y = h

  for (int j = 0; j < n; ++j) {
    if (i == j) continue;
    bs.push_back(bisector(p[i], p[j], j));
  }

  sort(bs.begin(), bs.end());

  deque< bisector > stk;

  for (int j = 0; j < bs.size(); ++j) {
    while (!stk.empty() && eq(bs[j].ang, stk.back().ang))
      stk.pop_back();

    while (stk.size() >= 2 && shadowed(stk[stk.size() - 2], stk[stk.size() - 1], bs[j]))
      stk.pop_back();

    stk.push_back(bs[j]);
  }

  bool change = true;

  while (change) {
    change = false;
    while (stk.size() >= 3 && shadowed(stk[1], stk[0], stk.back())) 
      stk.pop_front(), change = true;
    
    while (stk.size() >= 3 && shadowed(stk[stk.size() - 1], stk[stk.size() - 2], stk[0])) 
      stk.pop_back(), change = true;
  }

  return stk;
}

void voronoi(vector< point > &cand, vector< point > &p) {
  int n = p.size();
  for (int i = 0; i < n; ++i) {
    deque< bisector > bs = cell(i, p);

    for (int j = 0; j < bs.size(); ++j) {
      int k = (j + 1) % bs.size();
      if (isect(bs[j], bs[k])) {
        cand.push_back(point(X, Y));
      }
    }
  }
}

double sq(double x) {
  return x * x;
}

bool operator<(point a, point b) {
  if (eq(a.x, b.x))
    return lt(a.y, b.y);
  return lt(a.x, b.x);
}

bool operator==(point a, point b) {
  return eq(a.x, b.x) && eq(a.y, b.y);
}

int main(void)
{
  scanf("%d%d%d", &w, &h, &n);

  p.resize(n);

  for (int i = 0; i < n; ++i)
    scanf("%lf%lf", &p[i].x, &p[i].y);

  vector< point > cand;

  for (int i = 0; i < n; ++i) {
    deque< bisector > bs = cell(i, p);

    vector< point > q;
    for (int j = 0; j < bs.size(); ++j)
      if (bs[j].id != -1) {
        q.push_back(p[bs[j].id]);
      }

    voronoi(cand, q);
  }

  double sol = 0.0;

  sort(cand.begin(), cand.end());
  cand.resize(unique(cand.begin(), cand.end()) - cand.begin());

  for (int i = 0; i < cand.size(); ++i) {
    vector< double > dist;
    for (int j = 0; j < n; ++j) 
      dist.push_back(sq(cand[i].x - p[j].x) + sq(cand[i].y - p[j].y));
    sort(dist.begin(), dist.end());
    sol = max(sol, dist[1]);
  }

  printf("%.9lf\n", sqrt(sol));

  return 0;
}