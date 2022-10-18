/* Written by Filip Hlasek 2017 */
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <iostream>

#define FOR(i, a, b)   for (int i = (a); i <= (b); i++)
#define FORD(i, a, b)  for (int i = (a); i >= (b); i--)
#define REP(i, b)      for (int i =  0 ; i <  (b); i++)

using namespace std;

#define MOD 1000000007
int K;

#define MAXN 444
long long paths[MAXN][MAXN];

int main(int argc, char *argv[]) {
  scanf("%d", &K);
  paths[0][1] = 1;
  paths[1][1] = 1;

  FOR(k, 2, K) {
    FOR(p, 0, K + 1) {
      FOR(a, 0, p - 1) paths[p][k] = (
        paths[p][k] + paths[a][k - 1] * paths[p - 1 - a][k - 1]
      ) % MOD;
      FOR(a, 0, p) paths[p][k] = (
        paths[p][k] + paths[a][k - 1] * paths[p - a][k - 1] % MOD * (2 * p + 1)
      ) % MOD;
      FOR(a, 0, p + 1) paths[p][k] = (
        paths[p][k] + paths[a][k - 1] * paths[p + 1 - a][k - 1] % MOD * (p + 1) % MOD * p
      ) % MOD;
    }
  }
  printf("%d\n", (int)(paths[1][K]));
  return 0;
}