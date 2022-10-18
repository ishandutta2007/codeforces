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
int P[MAXN];

int main(int argc, char *argv[]) {
  int N;
  scanf("%d", &N);
  REP(i, N) {
    int p;
    scanf("%d", &p);
    P[p] = i;
  }
  int pos = -1, len = 0, ans = 0;
  FOR(i, 1, N) {
    if (P[i] < pos) len = 0;
    len++; pos = P[i];
    ans = max(ans, len);
  }
  printf("%d\n", N - ans);
  return 0;
}