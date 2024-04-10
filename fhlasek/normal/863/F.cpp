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

#define MAXN 1111
#define INF 1000000000

int cap[MAXN][MAXN], cost[MAXN][MAXN];
// Warning: Don't forget to add inverse cost to opposite edges!!!

int minCostMaxFlow(int N, int s, int t) {
  int res = 0;
  while(true) {
    int prev[MAXN], dist[MAXN];
    REP(i, N) dist[i] = INF;
    dist[s] = 0;
    bool updated = true;
    while(updated) {
      updated = false;
      REP(i, N) if (dist[i] < INF) REP(j, N) if (cap[i][j] > 0 && dist[i] + cost[i][j] < dist[j]) {
        dist[j] = dist[i] + cost[i][j];
        prev[j] = i;
        updated = true;
      }
    }
    if (dist[t] >= INF) break;
    res += dist[t];
    int cur = t;
    while (cur != s) {
      int pr = prev[cur];
      --cap[pr][cur];
      ++cap[cur][pr];
      cur = pr;
    }
  }
  return res;
}

int N, Q;
int T[MAXN], L[MAXN], R[MAXN], V[MAXN];

int main(int argc, char *argv[]) {
  scanf("%d%d", &N, &Q);
  REP(i, N) cap[3 * N][i] = 1;
  REP(i, N) REP(j, N) cap[N + i][2 * N + j] = 1;
  REP(i, N) {
    cap[2 * N + i][3 * N + 1] = N;
    cost[2 * N + i][3 * N + 1] = 2 * i + 1;
    cost[3 * N + 1][2 * N + i] = -(2 * i + 1);
  }

  REP(i, Q) scanf("%d%d%d%d", T + i, L + i, R + i, V + i);
  REP(i, N) {
    int low = 1, high = N;
    REP(q, Q) if (L[q] <= i + 1 && i + 1 <= R[q]) {
      if (T[q] == 1) {
        low = max(low, V[q]);
      } else {
        high = min(high, V[q]);
      }
    }
    if (low > high) {
      printf("-1\n");
      return 0;
    }
    FOR(k, low, high) cap[i][N + k - 1] = 1;
  }
  printf("%d\n", minCostMaxFlow(3 * N + 2, 3 * N, 3 * N + 1));


  return 0;
}