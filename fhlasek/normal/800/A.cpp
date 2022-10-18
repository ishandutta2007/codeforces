/* Written by Filip Hlasek 2017 */
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <iostream>

#define FOR(i, a, b)   for (int i = (a); i <= (b); i++)
#define FORD(i, a, b)  for (int i = (a); i >= (b); i--)
#define REP(i, b)      for (int i =  0 ; i <  (b); i++)

using namespace std;

#define MAXN 1111111
int A[MAXN], B[MAXN];
int N, P;

bool ok(double t) {
  double total = 0;
  REP(i, N) {
    double h = A[i] * t;
    if (h > B[i]) {
      total += (h - B[i]) / P;
    }
  }
  // printf("t: %lf total: %lf\n", t, total);
  return total <= t;
}

int main(int argc, char *argv[]) {
  scanf("%d%d", &N, &P);
  REP(i, N) scanf("%d%d", A + i, B + i);
  double l = 0, r = 1000000000000000000LL;
  if (ok(r)) printf("-1\n");
  else {
    REP(i, 200) {
      double m = (l + r) / 2;
      if (ok(m)) l = m;
      else r = m;
    }
    printf("%.9lf\n", l);
  }
  return 0;
}