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
  int N, M;
  scanf("%d%d", &N, &M);
  if (N == 1) printf("1.0\n");
  else printf("%.15lf\n", (double)(M * (N * M - 1) + (N - 1) * M * (M - 1)) / ((long long)N * M * (N * M - 1)));
  return 0;
}