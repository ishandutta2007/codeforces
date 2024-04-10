/* Written by Filip Hlasek 2017 */
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
#include <iostream>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

#define MAXN 599
int N, M;

#define LOG 61
bool way[LOG][MAXN][MAXN], iway[LOG][MAXN][MAXN];
bool wayAny[LOG][MAXN], iwayAny[LOG][MAXN];
unsigned long long wayFrom[LOG][MAXN][MAXN / 30], wayTo[LOG][MAXN][MAXN / 30];
unsigned long long iwayFrom[LOG][MAXN][MAXN / 30], iwayTo[LOG][MAXN][MAXN / 30];

long long dp[MAXN][LOG][2];

long long furthest(int v, int l, bool w) {
  if (dp[v][l][w]) return dp[v][l][w];
  if (l == 0) return w ? wayAny[0][v] : iwayAny[0][v];
  long long ans = furthest(v, l - 1, w);
  if (w) {
    if (wayAny[l][v]) return 1LL << l;
    REP(i, N) if (way[l - 1][v][i]) {
      ans = max(ans, (1LL << (l - 1)) + furthest(i, l - 1, !w));
    }
  } else {
    if (iwayAny[l][v]) return 1LL << l;
    REP(i, N) if (iway[l - 1][v][i]) {
      ans = max(ans, (1LL << (l - 1)) + furthest(i, l - 1, !w));
    }
  }
  return dp[v][l][w] = ans;
}

int main(int argc, char *argv[]) {
  scanf("%d%d", &N, &M);
  REP(i, M) {
    int a, b, t;
    scanf("%d%d%d", &a, &b, &t);
    a--; b--;
    if (t) {
      iwayAny[0][a] = iway[0][a][b] = true;
      iwayFrom[0][a][b / 32] |= 1 << (b % 32);
      iwayTo[0][b][a / 32] |= 1 << (a % 32);
    }
    else {
      wayAny[0][a] = way[0][a][b] = true;
      wayFrom[0][a][b / 32] |= 1 << (b % 32);
      wayTo[0][b][a / 32] |= 1 << (a % 32);
    }
  }
  REP(i, LOG - 1) REP(a, N) REP(b, N) {
    REP(j, MAXN / 32) if (wayFrom[i][a][j] & iwayTo[i][b][j]) {
    // REP(c, N) if (way[i][a][c] && iway[i][c][b]) {
      wayAny[i + 1][a] = way[i + 1][a][b] = true;
      wayFrom[i + 1][a][b / 32] |= 1 << (b % 32);
      wayTo[i + 1][b][a / 32] |= 1 << (a % 32);
      break;
    }
    REP(j, MAXN / 32) if (iwayFrom[i][a][j] & wayTo[i][b][j]) {
    // REP(c, N) if (iway[i][a][c] && way[i][c][b]) {
      iwayAny[i + 1][a] = iway[i + 1][a][b] = true;
      iwayFrom[i + 1][a][b / 32] |= 1 << (b % 32);
      iwayTo[i + 1][b][a / 32] |= 1 << (a % 32);
      break;
    }
  }

  long long ans = furthest(0, LOG - 1, true);
  if (ans > 1000000000000000000LL) {
    printf("-1\n");
  } else {
    cout << ans << endl;
  }

  return 0;
}