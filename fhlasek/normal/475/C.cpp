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

#define MAXN 1111
#define INF (MAXN * MAXN)
int N, M;
char m[MAXN][MAXN], mm[MAXN][MAXN];
bool done[MAXN][MAXN];

int solve() {
  REP(i, N) REP(j, M) if (m[i][j] == 'X') {
    int h = 0, w = 0;
    while (j + h < M && m[i][j + h] == 'X') ++h;
    while (i + w < N && m[i + w][j] == 'X') ++w;
    int w2 = 0;
    if (j + h < M) while (w2 < w && m[i + w2][j + h] == '.') ++w2;
    else w2 = w;
    w = max(1, w - w2);
    // REP(ii, N) { REP(jj, M) printf("%c", m[ii][jj]); printf("\n"); }
    // printf("h: %d w: %d\n", h, w);
    REP(ii, N) REP(jj, M) done[ii][jj] = false;
    REP(ii, w) REP(jj, h) done[i + ii][j + jj] = true;
    while (true) {
      if (j + h < M && m[i][j + h] == 'X') {
        REP(ii, w) done[i + ii][j + h] = true;
        j++;
      }
      else if (i + w < N && m[i + w][j] == 'X') {
        REP(jj, h) done[i + w][j + jj] = true;
        i++;
      }
      else break;
    }
    REP(ii, N) REP(jj, M) if ((m[ii][jj] == 'X') != done[ii][jj]) return INF;
    return w * h;
  }
  return INF; // should never happen
}

int main(int argc, char *argv[]) {
  scanf("%d%d", &N, &M);
  int ans = INF;
  REP(i, N) scanf("%s", m[i]);
  ans = min(ans, solve());
  REP(i, N) REP(j, M) mm[j][i] = m[i][j];
  swap(N, M);
  REP(i, N) REP(j, M) m[i][j] = mm[i][j];
  ans = min(ans, solve());
  if (ans == INF) printf("-1\n");
  else printf("%d\n", ans);
  return 0;
}