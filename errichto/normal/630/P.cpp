// geo from swistakk's library
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORD(i,a,b) for(int i = (a); i >= (b); --i)
#define RI(i,n) FOR(i,1,(n))
#define REP(i,n) FOR(i,0,(n)-1)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#define mp make_pair
#define pb push_back
#define st first
#define nd second
#define sz(w) (int) w.size()
using namespace std;
typedef long double LD;
typedef long double ld;
const LD kEps = 1e-9;
const LD kPi = 2 * acos(0);
struct Point {
  LD x, y;
  Point(LD a = 0, LD b = 0) : x(a), y(b) {}
  Point(const Point& a) : x(a.x), y(a.y) {}
  void operator=(const Point& a) { x = a.x; y = a.y; }
  Point operator+(const Point& a) const { Point p(x + a.x, y + a.y); return p; }
  Point operator-(const Point& a) const { Point p(x - a.x, y - a.y); return p; }
  Point operator*(LD a) const { Point p(x * a, y * a); return p; }
  Point operator/(LD a) const { assert(a > kEps); Point p(x / a, y / a); return p; }
  Point& operator+=(const Point& a) { x += a.x; y += a.y; return *this; }
  Point& operator-=(const Point& a) { x -= a.x; y -= a.y; return *this; }
  Point& operator*=(LD a) { x *= a; y *= a; return *this;}
  Point& operator/=(LD a) { assert(a > kEps); x /= a; y /= a; return *this; }
  
  bool IsZero() const {
    return fabs(x) < kEps && fabs(y) < kEps;
  }
  bool operator==(const Point& a) const {
    return (*this - a).IsZero();
  }
  LD CrossProd(const Point& a) const {
    return x * a.y - y * a.x;
  }
  LD CrossProd(Point a, Point b) const {
    a -= *this;
    b -= *this;
    return a.CrossProd(b);
  }
  LD DotProd(const Point& a) const {
    return x * a.x + y * a.y;
  }
  LD Norm() const {
    return sqrt(x * x + y * y);
  }
  void NormalizeSelf() {
    *this /= Norm();
  }
  Point Normalize() {
    Point res(*this);
    res.NormalizeSelf();
    return res;
  }
  LD Dist(const Point& a) const {
    return (*this - a).Norm();
  }
  LD Angle() const {
    return atan2(y, x);
  }
  void RotateSelf(LD angle) {
    LD c = cos(angle);
    LD s = sin(angle);
    LD nx = x * c - y * s;
    LD ny = y * c + x * s;
    y = ny;
    x = nx;
  }
  Point Rotate(LD angle) const {
    Point res(*this);
    res.RotateSelf(angle);
    return res;
  }
  static bool LexCmp(const Point& a, const Point& b) {
    if (fabs(a.x - b.x) > kEps) {
      return a.x < b.x;
    }
    return a.y < b.y;
  }
  friend ostream& operator<<(ostream& out, Point m);
};

ostream& operator<<(ostream& out, Point p) {
  out << "(" << p.x << ", " << p.y << ")";
  return out;
}

struct Line {
  Point p[2];
  bool is_seg;
  Line(Point a, Point b, bool is_seg_ = false) {
    p[0] = a;
    p[1] = b;
    is_seg = is_seg_;
  }
  Line() {
  }
  Point& operator[](int a) {
    return p[a];
  }
  static bool VectorsInOneHalfPlaneCmp(Line a, Line b) {
    return (a[1] - a[0]).CrossProd(b[1] - b[0]) > 0;
  }
  Point NormalVector() {
    Point perp = p[1] - p[0];
    perp.RotateSelf(kPi / 2);
    perp.NormalizeSelf();
    return perp;
  }
  vector<LD> LineEqNormLD() { // seems ok
    LD A = p[1].y - p[0].y;
    LD B = p[0].x - p[1].x;
    LD C = -(A * p[0].x + B * p[0].y);
    assert(fabs(A * p[1].x + B * p[1].y + C) < kEps);
    LD norm = sqrt(A * A + B * B);
    vector<LD> res{A, B, C};
    for (auto& x : res) { x /= norm; }
    if (A < -kEps || (fabs(A) < kEps && B < -kEps)) {
      for (auto& x : res) { x *= -1; }
    }
    return res;
  }
};

  Point InterLineLine(Line a, Line b) { // working fine
    Point vec_a = a[1] - a[0];
    Point vec_b1 = b[1] - a[0];
    Point vec_b0 = b[0] - a[0]; 
    LD tr_area = vec_b1.CrossProd(vec_b0);
    LD quad_area = vec_b1.CrossProd(vec_a) + vec_a.CrossProd(vec_b0);
//     if (abs(quad_area) < kEps) {
//       throw Parallel();
//     }
    return Point(a[0] + vec_a * (tr_area / quad_area));
  }

ld area(Point a, Point b, Point c) {
	return abs(a.CrossProd(b) + b.CrossProd(c) + c.CrossProd(a)) / 2;
}

int main() {
	int n, r;
	scanf("%d%d", &n, &r);
	Point a = Point(r, 0);
	ld angle = kPi * 2 / n;
	Point b = a.Rotate(angle);
	//cout << a << " " << b << "\n";
	Point a2 = a.Rotate(angle * (n / 2));
	Point b2 = b.Rotate(angle * (n / 2 + 1));
	Point s = InterLineLine(Line(a, a2), Line(b, b2));
	ld ans = area(Point(0,0), a, b) - area(s, a, b);
	ans *= n;
	printf("%.10lf\n", (double) ans);
	return 0;
}