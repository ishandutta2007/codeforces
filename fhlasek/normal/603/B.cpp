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

#define MOD 1000000007

#define MAXN 1111111
bool done[MAXN];

int main(int argc, char *argv[]) {
  int P, K;
  scanf("%d%d", &P, &K);
  if (K == 0) {
    int ans = 1;
    REP(i, P - 1) ans = ((long long)ans * P) % MOD;
    printf("%d\n", ans);
    return 0;
  }
  if (K == 1) {
    int ans = 1;
    REP(i, P) ans = ((long long)ans * P) % MOD;
    printf("%d\n", ans);
    return 0;
  }
  int ans = 1;
  FOR(i, 1, P - 1) if (!done[i]) {
    int tmp = i;
    while (!done[tmp]) {
      done[tmp] = true;
      tmp = ((long long)tmp * K) % P;
    }
    ans = ((long long)ans * P) % MOD;
  }
  printf("%d\n", ans);
  return 0;
}