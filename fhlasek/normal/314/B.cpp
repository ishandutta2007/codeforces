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

#define MAXN 222
char a[MAXN], b[MAXN];
int X, Y, A, B; 

int dp[MAXN][MAXN], pos[MAXN], dist[MAXN];

int main(int argc, char *argv[]){
  scanf("%d%d", &X, &Y);
  scanf("%s", a);
  scanf("%s", b);
  A = strlen(a);
  B = strlen(b);

  REP(i, B) REP(j, A) {
    REP(k, A) if (a[(j + k) % A] == b[i]) { dp[i][j] = k + 1; break; }
    if(!dp[i][j]) { printf("0\n"); return 0; }
  }
  FORD(i, B-2, 0) REP(j, A) dp[i][j] += dp[i+1][(j+dp[i][j]) % A];

  long long YY = 0, da = 0;

  REP(i, A) pos[i] = dist[i] = -1;
  while(da < X * A) {
    if(pos[da % A] != -1 && da - dist[da % A] < X * A - da) {
      long long q = (X * A - da) / (da - dist[da % A]);
      YY += q * (YY - pos[da % A]);
      da += q * (da - dist[da % A]);
    }
    else {
      if (da + dp[0][da % A] > X * A) break;
      pos[da % A] = YY;
      dist[da % A] = da;
      da += dp[0][da % A];
      YY++;
    }
  }
  printf("%d\n", (int)(YY / Y));
  return 0;
}