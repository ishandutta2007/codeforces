/* Written by Filip Hlasek 2014 */
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

#define EPS 1e-11
class Vector{
  public:
    double x, y;
    Vector(double _x = 0, double _y = 0) { x = _x; y = _y; }
    Vector operator +(Vector a) const { return Vector(x + a.x, y + a.y); }
    Vector operator +=(Vector a) { return *this = *this + a; }
    Vector operator -(Vector a) const { return Vector(x - a.x, y - a.y); }
    Vector operator -=(Vector a) { return *this = *this - a; }
    Vector operator *(double p) const { return Vector(x * p, y * p); }
    Vector operator *=(double p) { return *this = *this * p; }
    bool operator <(const Vector a) const { if(x == a.x) return y < a.y; return x < a.x; }
    double len() const{ return sqrt(x * x + y * y); }
    double angle() const { return atan2(x, y); }
};

double EQ(double a, double b) { return abs(a - b) < EPS; }

typedef pair<Vector, Vector> Line;
struct LineEQ{ double a, b, c; };

double len(Vector a) { return sqrt(a.x * a.x + a.y * a.y); }
double cross(Vector a, Vector b) { return a.x * b.y - a.y * b.x; }
double scalar(Vector a, Vector b) { return a.x * b.x + a.y * b.y; }
bool parallel(Line a, Line b) { return abs(cross(a.first - a.second, b.first - b.second)) < EPS; }

Vector lineline(Line a, Line b) {
  double x1 = a.first.x, y1 = a.first.y, x2 = a.second.x, y2 = a.second.y, x3 = b.first.x, y3 = b.first.y, x4 = b.second.x, y4 = b.second.y;
  double den = (x1-x2)*(y3-y4) - (y1-y2)*(x3-x4);
  return Vector(
    ((x1*y2-y1*x2) * (x3-x4)  -  (x1-x2) * (x3*y4-y3*x4))   /   den,
    ((x1*y2-y1*x2) * (y3-y4)  -  (y1-y2) * (x3*y4-y3*x4))   /   den
  );
}

bool onSegment(Line l, Vector v) {
  int endpoints = 1; // endpoints counted
  bool ok1, ok2;
  if(l.first.x > l.second.x) swap(l.first, l.second);
  ok1 = l.first.x - endpoints * EPS < v.x && v.x - endpoints * EPS < l.second.x;
  if(l.first.y > l.second.y) swap(l.first, l.second);
  ok2 = l.first.y - endpoints * EPS < v.y && v.y - endpoints * EPS < l.second.y;
  return ok1 && ok2;
}

bool segmentsegment(Line a, Line b) {
  if(parallel(a, b)) return false;
  Vector i = lineline(a, b);
  // printf("[%lf %lf], [%lf %lf] x [%lf %lf], [%lf %lf]\n", a.first.x, a.first.y, a.second.x, a.second.y, b.first.x, b.first.y, b.second.x, b.second.y);
  // printf("intersection: %lf %lf\n", i.x, i.y);
  return onSegment(a, i) && onSegment(b, i);
}

#define MOD 1000000007
#define MAXN 222
int N;
Vector point[MAXN];
bool inside[MAXN][MAXN];

int next(int a) { a += 1; return a == N ? 0 : a; }

int dp[MAXN][MAXN];
int solve(int a, int b) {
  if (next(a) == b) return 1;
  if (dp[a][b] != -1) return dp[a][b];

  int ans = 0;
  for (int i = next(a); i != b; i = next(i)) {
    if ((inside[a][i] || i == next(a)) && (inside[b][i] || next(i) == b)) {
      ans = (ans + (long long)solve(a, i) * solve(i, b)) % MOD;
    }
  }

  return dp[a][b] = ans;
}


bool inside_polygon(Vector p) {
  double angle = 0.0;
  REP(i, N) {
    double a = (point[next(i)] - p).angle();
    a -= (point[i] - p).angle();
    if (a < -M_PI) a += 2.0 * M_PI;
    if (a > M_PI) a -= 2.0 * M_PI;
    if (EQ(p.x, point[i].x) && EQ(p.y, point[i].y)) return false;
    if (EQ(abs(abs(a) - M_PI), 0)) return false;
    angle += a;
  }
  return !EQ(angle, 0.0);
}

int main() {
  scanf("%d", &N);
  REP(i, N) {
    int x, y;
    scanf("%d%d", &x, &y);
    point[i] = Vector(x, y);
  }

  REP(i, N) REP(j, i) {
    inside[i][j] = inside[j][i] = true;
    if (!inside_polygon((point[i] + point[j]) * 0.5)) {
      inside[i][j] = inside[j][i] = false;
      continue;
    }
    REP(k, N) {
      int l = next(k);
      if (k != i && k != j && l != i && l != j &&
            segmentsegment(make_pair(point[i], point[j]), make_pair(point[k], point[l]))) {
          inside[i][j] = inside[j][i] = false;
          break;
      }
    }
  }
  REP(i, N) REP(j, N) dp[i][j] = -1;
  printf("%d\n", solve(0, N - 1));
  return 0;
}