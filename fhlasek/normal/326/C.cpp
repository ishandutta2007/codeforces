/* Written by Filip Hlasek 2013 */
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

int R;
#define MAXN 1111
bool m[MAXN][2];

int sg[MAXN][MAXN][3][3];
int ex[10 * MAXN], STEP = 1;

int main(int argc, char *argv[]){
  int Q;
  scanf("%d%d", &R, &Q);
  while(Q--) {
    int r, c;
    scanf("%d%d", &r, &c);
    m[r-1][c-1] = true;
  }
  FOR(l, 1, R) REP(i, R) REP(m1, 3) REP(m2, 3) {
    int j = i + l;
    if (j > R) continue;
    STEP++;
    FOR(r, i, j-1) FOR(c, 1, 2) {
      if (m[r][c-1]) continue;
      bool ok = true;
      FOR(d, -1, 1) if(r + d >= i && r + d < j && m[r + d][2 - c]) ok = false;
      if(!ok) continue;
      if (r == i    && c + m1 == 3) continue;
      if (r == j-1  && c + m2 == 3) continue;
      ex[sg[i][r][m1][c] ^ sg[r+1][j][c][m2]] = STEP;
    }
    while(ex[sg[i][j][m1][m2]] == STEP) sg[i][j][m1][m2]++;
  }
  if(sg[0][R][0][0]) printf("WIN\n");
  else printf("LOSE\n");
  return 0;
}