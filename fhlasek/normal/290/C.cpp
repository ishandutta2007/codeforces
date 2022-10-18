/* Written by Filip Hlasek 2013 */
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

int main(int argc, char *argv[]){
  int N, a, s = 0;
  scanf("%d", &N);
  double best = 0;
  REP(i, N) {
    scanf("%d", &a);
    s += a;
    best = max(best, (double)s / (i + 1));
  }
  printf("%.9lf\n", best);
  return 0;
}