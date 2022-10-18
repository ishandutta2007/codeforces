/* Written by Filip Hlasek 2018 */
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

#define MAXM 11
#define MAXN 111111

int P[MAXM][MAXN], R[MAXM][MAXN];
int N, M;

int main(int argc, char *argv[]) {
  scanf("%d%d", &N, &M);
  REP(i, M) {
    REP(j, N) {
      scanf("%d", &(P[i][j]));
      P[i][j]--;
      R[i][P[i][j]] = j;
    }
  }
  REP(i, M) P[i][N] = -2;
  P[0][N] = -1;
  int cur = 0;
  long long ans = 0;
  FORD(i, N - 1, 0) {
    REP(j, M) if (P[0][i + 1] != P[j][R[j][P[0][i]] + 1]) cur = 0;
    cur++;
    ans += cur;
  }
  cout << ans << endl;
  return 0;
}