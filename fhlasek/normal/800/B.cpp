/* Written by Filip Hlasek 2017 */
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cmath>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

#define EPS 1e-11
bool EQ(double a, double b) { return abs(a - b) < EPS; }

class Vector {
  public:
    double x, y;
    Vector(double _x = 0, double _y = 0) : x(_x), y(_y) {}
    Vector operator +(Vector a) const { return Vector(x + a.x, y + a.y); }
    Vector operator +=(Vector a) { return *this = *this + a; }
    Vector operator -(Vector a) const { return Vector(x - a.x, y - a.y); }
    Vector operator -=(Vector a) { return *this = *this - a; }
    Vector operator *(double p) const { return Vector(x * p, y * p); }
    Vector operator *=(double p) { return *this = *this * p; }
    bool operator <(const Vector a) const { return EQ(x, a.x) ? y < a.y : x < a.x; }
    bool operator ==(const Vector a) const { return EQ(x, a.x) && EQ(y, a.y); }
    double len() const { return sqrt(x * x + y * y); }
    double angle() const { return atan2(x, y); }
};

double len(Vector a) { return a.len(); }
double cross(Vector a, Vector b) { return a.x * b.y - a.y * b.x; }
double dot(Vector a, Vector b) { return a.x * b.x + a.y * b.y; }

struct LineEQ{ double a, b, c; };
class Line {
  public:
    Vector p1, p2;
    Line(Vector _p1 = Vector(), Vector _p2 = Vector()) : p1(_p1), p2(_p2) {}

    double distance(Vector v) const {
      Vector l = p2 - p1, vn = v - p1;
      return abs(cross(l, vn)) / l.len();
    }

    bool operator ||(Line a) const { return EQ(cross(p1 - p2, a.p1 - a.p2), 0); }
};

#define MAXN 1111
Vector p[MAXN];

int main() {
  int N;
  scanf("%d", &N);
  REP(i, N) {
    int x, y;
    scanf("%d%d", &x, &y);
    p[i] = Vector(x, y);
  }
  double ans = 1000000000000000000LL;
  REP(i, N) {
    Vector a = p[i], b = p[(i + 1) % N], c = p[(i + 2) % N];
    double d = Line(a, c).distance(b);
    if (i == 0 || d < ans) ans = d;
  }
  printf("%.9lf\n", ans / 2);
  return 0;
}