#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-6
const double PI = acos(-1.0);

double DEG_to_RAD(double d) { return d * PI / 180.0; }
double RAD_to_DEG(double r) { return r * 180.0 / PI; }

inline int cmp(double a, double b) {
  return (a < b - EPS) ? -1 : ((a > b + EPS) ? 1 : 0);
}

struct Point
{
  double x, y;
  Point(double x = 0.0, double y = 0.0) : x(x), y(y) {}

  Point operator + (const Point& a) const { return Point(x+a.x, y+a.y); }
  Point operator - (const Point& a) const { return Point(x-a.x, y-a.y); }
  Point operator * (double k) const { return Point(x*k, y*k); }
  Point operator / (double k) const { return Point(x/k, y/k); }

  double operator * (const Point& a) const { return x*a.x + y*a.y; } // dot product
  double operator % (const Point& a) const { return x*a.y - y*a.x; } // cross product

  int cmp(Point q) const { if (int t = ::cmp(x,q.x)) return t; return ::cmp(y,q.y); }

  Point conj() { return Point(x, -y); }
  double norm() { return x*x + y*y; }

  // Note: There are 2 ways for implementing len():
  // 1. sqrt(norm()) --> fast, but inaccurate (produce some values that are of order X^2)
  // 2. hypot(x, y) --> slow, but much more accurate
  double len() { return sqrt(norm()); }

  Point rotate(double alpha) {
    double cosa = cos(alpha), sina = sin(alpha);
    return Point(x * cosa - y * sina, x * sina + y * cosa);
  }
};

struct Line 
{
  double a, b, c;
  Point A, B;

  Line(double a, double b, double c) : a(a), b(b), c(c) {} 

  Line(Point A, Point B) : A(A), B(B) {
    a = B.y - A.y;
    b = A.x - B.x;
    c = - (a * A.x + b * A.y);
  }
  Line(Point P, double m) {
    a = -m; b = 1;
    c = -((a * P.x) + (b * P.y));
  }
  double f(Point A) {
    return a*A.x + b*A.y + c;
  }
};

bool areParallel(Line l1, Line l2) {
  return cmp(l1.a*l2.b, l1.b*l2.a) == 0;
}

bool areIntersect(Line l1, Line l2, Point &p) {
  if (areParallel(l1, l2)) return false;
  double dx = l1.b*l2.c - l2.b*l1.c;
  double dy = l1.c*l2.a - l2.c*l1.a;
  double d  = l1.a*l2.b - l2.a*l1.b;
  p = Point(dx/d, dy/d);
  return true;
}

int n;
Point p[1010];

double calc(Point a, Point b, Point c)
{
  Line bc = Line(b, c);
  Line ah = Line(-bc.b, bc.a, bc.b * a.x - bc.a * a.y);
  Point p;
  if (!areIntersect(bc, ah, p))
    return 1e18;
  return (p - a).len() / 2;
}

double calcTriple(Point a, Point b, Point c)
{
  return min(calc(a, b, c), min(calc(b, c, a), calc(c, a, b)));
}

int main()
{
  double x, y;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> p[i].x >> p[i].y;

  double ans = 1e18;
  for (int i = 0; i < n; i++)
    ans = min(ans, calcTriple(p[i], p[(i + 1) % n], p[(i + 2) % n]));
  cout << fixed << setprecision(9) << ans << endl;
}