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

#define MAXN 2111111
int A[MAXN];
int last[MAXN];
int N;

int main(int argc, char *argv[]) {
  scanf("%d", &N);
  REP(i, N) { scanf("%d", A + i); last[A[i]] = A[i]; }
  REP(i, MAXN - 1) if (!last[i + 1]) last[i + 1] = last[i];
  int best = 0;
  FOR(i, 1, MAXN - 1) if (last[i] != last[i - 1]) {
    for (int j = 2; i * j < MAXN; ++j) if (last[i * j - 1] >= i * (j - 1)) {
      best = max(best, last[i * j - 1] - i * (j - 1));
    }
  }
  printf("%d\n", best);
  return 0;
}