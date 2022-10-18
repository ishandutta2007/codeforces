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

#define MAX 555
double level[MAX], ans;

int main(int argc, char *argv[]) {
  int N, K;
  scanf("%d%d", &N, &K);
  level[1] = K;
  REP(i, N) {
    FORD(l, MAX - 2, 1) {
      double p = level[l] / K / (l + 1);
      ans += p * (l * (l + 1) / 2 + l);
      level[l + 1] += p; level[l] -= p;
    }
//    printf("step: %d\n", i); REP(j, MAX) if (j % 100 == 0) printf(" %.8lf", level[j]); printf("\n");
  }
  printf("%.15lf\n", ans);
  return 0;
}