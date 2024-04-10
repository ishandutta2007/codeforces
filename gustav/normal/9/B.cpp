#include <cstdio>
#include <cassert>
#include <cstring>

#include <algorithm>
#include <iostream>

using namespace std;
typedef long long llint;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

const int MAXN = 105;

const double eps = 1e-9;

bool lt(double a, double b) { return a + eps < b; }
bool gt(double a, double b) { return lt(b, a); }
bool eq(double a, double b) { return !lt(a, b) && !gt(a, b); }

double sq(double x) { return x * x; }

int n;
int vb, vs;
int xu, yu;
int x[MAXN];

int main(void) 
{
  scanf("%d%d%d", &n, &vb, &vs);
  REP(i, n) scanf("%d", x + i);
  scanf("%d%d", &xu, &yu);

  double best = 1e100;
  int sol = 0;

  FOR(i, 1, n) {
    double sb = x[i];
    double ss = sqrt(sq(x[i] - xu) + sq(yu));
    double t = sb / vb + ss / vs;

    if (lt(t, best)) {
      best = t;
      sol = i;
    } else if (eq(t, best)) {
      double dbest = sqrt(sq(x[sol] - xu) + sq(yu));
      double di = sqrt(sq(x[i] - xu) + sq(yu));
      if (lt(di, dbest)) {
	sol = i;
      }
    }
  }

  printf("%d\n", sol + 1);

  return 0;
}