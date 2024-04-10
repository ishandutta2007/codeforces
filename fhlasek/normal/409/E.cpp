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

int main(int argc, char *argv[]) {
  int besta = -1, besth = -1;
  double bestdiff = 10;
  double R;
  scanf("%lf", &R);
  FOR(a, 1, 10) FOR(h, 1, 10) {
    double x = sqrt((double)a * a / 4 + h * h);
    double r = a * h / x / 2, diff = abs(r - R);
    // printf("a: %d h: %d r: %lf diff: %lf bestdiff: %lf\n", a, h, r, diff, bestdiff);
    if (diff < bestdiff) {
      bestdiff = diff;
      besta = a;
      besth = h;
    }
  }
  printf("%d %d\n", besta, besth);
  return 0;
}