/* Written by Filip Hlasek 2015 */
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

#define MAXN 111111
int H[MAXN];
int N;
int L[MAXN], R[MAXN];

int main(int argc, char *argv[]) {
  scanf("%d", &N);
  REP(i, N) scanf("%d", H + i);
  int last = 0;
  REP(i, N) L[i] = last = min(last + 1, H[i]);
  last = 0;
  FORD(i, N - 1, 0) R[i] = last = min(last + 1, H[i]);
  int ans = 0;
  REP(i, N) ans = max(ans, min(L[i], R[i]));
  printf("%d\n", ans);
  return 0;
}