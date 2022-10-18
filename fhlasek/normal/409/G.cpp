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
  int N;
  double sum = 0, x, y;
  scanf("%d", &N);
  REP(i, N) { scanf("%lf%lf", &x, &y); sum += y; }
  printf("%.4lf\n", 5 + sum / N);
  return 0;
}