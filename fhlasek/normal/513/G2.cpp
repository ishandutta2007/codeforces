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
#include <ctime>
#include <cstring>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

#define MAXN 33
#define MAXK 222
double dp[MAXK][MAXN][MAXN];

int main(int argc, char *argv[]) {
  vector<int> p;
  int N, K;
  scanf("%d%d", &N, &K);
  REP(i, N) {
    int a;
    scanf("%d", &a);
    p.push_back(a);
  }
  double ans = 0;
  double options = N * (N + 1) / 2;
  REP(opos1, N) REP(opos2, N) if (p[opos1] < p[opos2]) dp[0][opos1][opos2] = 1;
  REP(k, K + 1) REP(pos1, N) REP(pos2, N) if (dp[k][pos1][pos2]) {
    // printf("k: %d pos1: %d pos2: %d ans: %lf\n", k, pos1, pos2, dp[k][pos1][pos2]);
    REP(i, N) REP(j, i + 1) {
      int npos1 = pos1, npos2 = pos2;
      if (j <= pos1 && pos1 <= i) npos1 = i + j - pos1;
      if (j <= pos2 && pos2 <= i) npos2 = i + j - pos2;
      dp[k + 1][npos1][npos2] += dp[k][pos1][pos2] / options;
    }
  }
  REP(pos1, N) REP(pos2, pos1) ans += dp[K][pos1][pos2];

  printf("%.12lf\n", ans);
  return 0;
}