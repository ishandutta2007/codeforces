#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-6;
const double INF = 1e9;

int cmp(double x, double y) {
  if (fabs(x - y) < EPS) return 0;
  if (x < y) return -1;
  return 1;
}

double O(0.0), PI(acos((double) -1.0));

struct Point {
  double x, y;

  Point() {}
  Point(double x, double y) : x(x), y(y) {}

  int cmp(Point q) const { if (int t = ::cmp(x,q.x)) return t; return ::cmp(y,q.y); }

  #define Comp(x) bool operator x (Point q) const { return cmp(q) x 0; }
  Comp(>) Comp(<) Comp(==) Comp(>=) Comp(<=) Comp(!=)
  #undef Comp

  Point operator + (const Point& a) const { return Point(x+a.x, y+a.y); }
  Point operator - (const Point& a) const { return Point(x-a.x, y-a.y); }
  Point operator * (const double& k)     const { return Point(x*k, y*k); }
  Point operator / (const double& k)     const { assert(k != double(0)); return Point(x/k, y/k); }

  double operator * (const Point& a)     const { return x*a.x + y*a.y; } // dot
  double operator % (const Point& a)     const { return x*a.y - y*a.x; } // cross

  friend istream& operator >> (istream& cin, Point& a) {
    cin >> a.x >> a.y;
    return cin;
  }
  friend ostream& operator << (ostream& cout, Point& a) {
    cout << a.x << ' ' << a.y;
    return cout;
  }

  double norm() { return x*x + y*y; }
  double len() { return hypot(x, y); }

  Point rotate(double alpha) {
    double cosa = cos(alpha), sina = sin(alpha);
    return Point(x * cosa - y * sina, x * sina + y * cosa);
  }

  Point normalize(double l) {
    return Point(x, y) * l / len();
  }
};

struct Line {
  double a, b, c;
  Point A, B;

  Line(double a, double b, double c) : a(a), b(b), c(c) {}

  Line(Point A, Point B) : A(A), B(B) {
    a = B.y - A.y;
    b = A.x - B.x;
    c = double(0) - (a * A.x + b * A.y);
  }
  double f(const Point &p) {
    return a * p.x + b * p.y + c;
  }

  double dist(Point p) {
    return fabs(a * p.x + b * p.y + c) / sqrt(a * a + b * b);
  }
};

int areParallel(Line l1, Line l2) {
  return fabs(l1.a * l2.b - l1.b * l2.a) < EPS;
}

int areIntersect(Line l1, Line l2, Point &p) {
  if (areParallel(l1, l2)) return 0;
  double dx = l1.b * l2.c - l2.b * l1.c;
  double dy = l1.c * l2.a - l2.c * l1.a;
  double d = l1.a * l2.b - l2.a * l1.b;
  p = Point(dx / d, dy / d);
  return 1;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, cx, cy;
  cin >> n >> cx >> cy;
  vector<Point> a;
  double minDist = INF, maxDist = 0;
  for (int i = 0; i < n; i++)
  {
    int x, y;
    cin >> x >> y;
    a.push_back(Point(x - cx, y - cy));
    minDist = min(minDist, a[i].len());
    maxDist = max(maxDist, a[i].len());
  }

  for (int i = 0; i < n; i++)
  {
    int ii = (i + 1) % n;
    Line l(a[i], a[ii]);
    Line h(-l.b, l.a, 0);
    Point u;
    if (areIntersect(l, h, u))
      if ((u - a[i]).len() + (u - a[ii]).len() < (a[i] - a[ii]).len() + EPS)
        minDist = min(minDist, u.len());
  }
  cout << fixed << setprecision(12) << PI * (maxDist * maxDist - minDist * minDist) << endl;
}