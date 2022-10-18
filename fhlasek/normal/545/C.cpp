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
int N, X[MAXN], H[MAXN];

int main(int argc, char *argv[]) {
  scanf("%d", &N);
  REP(i, N) scanf("%d%d", X + i, H + i);
  X[N] = 2000000002;
  int ans = 1, last = X[0];
  FOR(i, 1, N - 1) {
    if (X[i] - H[i] > last) { ans++; last = X[i]; }
    else if (X[i] + H[i] < X[i + 1]) { ans++; last = X[i] + H[i]; }
    else last = X[i];
  }
  printf("%d\n", ans);
  return 0;
}