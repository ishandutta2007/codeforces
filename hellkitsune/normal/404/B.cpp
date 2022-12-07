#include <cstdio>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); e++)
typedef long long LL;
typedef pair<int, int> PII;

using namespace std;

const double eps = 1e-9;
double a, d;
int n;

int main()
{
  scanf("%lf%lf%d", &a, &d, &n);
  int k = 0;
  double c = 0;
  REP(i, n) {
    double dist = d;
    dist -= floor(dist / (4 * a) - eps) * (4 * a);
    c += dist;
    while (c > a) {
      c -= a;
      ++k;
    }
    k %= 4;
    double x, y;
    switch (k) {
      case 0: {x = c; y = 0; break;}
      case 1: {x = a; y = c; break;}
      case 2: {x = a - c; y = a; break;}
      default: {x = 0; y = a - c; break;}
    }
    printf("%.9lf %.9lf\n", x, y);
  }
  return 0;
}