/* Written by Filip Hlasek 2019 */
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

#define MAXN 333333
int fac[MAXN];

int main(int argc, char *argv[]) {
  int N, MOD;
  scanf("%d%d", &N, &MOD);
  fac[0] = 1;
  REP(i, N) fac[i + 1] = ((long long)fac[i] * (i + 1)) % MOD;
  int ans = 0;

  FOR(l, 1, N) {
    ans = (ans + (long long)(N - l + 1) * (N - l + 1) % MOD * fac[l] % MOD * fac[N - l] % MOD) % MOD;
  }
  printf("%d\n", ans);
  return 0;
}