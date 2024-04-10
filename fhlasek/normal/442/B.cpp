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

#define MAXN 111
int N;
double P[MAXN];

int main(int argc, char *argv[]) {
  scanf("%d", &N);
  REP(i, N) scanf("%lf", P + i);
  double best = 0;
  sort(P, P + N);
  reverse(P, P + N);
  while (P[N - 1] == 0) --N;
  if (P[0] > 1 - 1e-9) { printf("%.15lf\n", 1.); return 0; }
  FOR(n, 1, N) {
    double prod = 1, sum = 0;
    REP(i, n) {
      prod *= 1 - P[i];
      sum += P[i] / (1 - P[i]);
    }
    best = max(best, prod * sum);
  }
  printf("%.15lf\n", best);
  return 0;
}