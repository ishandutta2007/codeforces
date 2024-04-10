/* Writen by Filip Hlasek 2012 */
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

#define MAXN 333
#define INF 1000000000
int dp[2][MAXN][MAXN], a[MAXN][MAXN];
int N;

const int D[2][2] = {{1,0}, {0,1}};

int main(int argc, char *argv[]){
  scanf("%d", &N);
  REP(i, N) REP(j, N) scanf("%d", &(a[i][j]));
  REP(i, N) REP(j, N) dp[0][i][j]  = -INF;
  dp[0][0][0] = a[0][0];
  int act = 0;
  REP(step, 2 * N - 2){
    REP(i, N) REP(j, N) dp[1-act][i][j] = -INF;
    REP(x1, N){
      int y1 = step - x1;
      if(y1 < 0 || y1 >= N) continue;
      REP(x2, N){
        int y2 = step - x2;
        if(y2 < 0 || y2 >= N) continue;
        if(dp[act][x1][x2] == -INF) continue;
        REP(d1,2) REP(d2,2){
          int nx1 = x1 + D[d1][0], ny1 = y1 + D[d1][1];
          int nx2 = x2 + D[d2][0], ny2 = y2 + D[d2][1];
          if(nx1 == N || nx2 == N || ny1 == N || ny2 == N) continue;
          int cur = dp[act][x1][x2];
          if((nx1 == nx2 && ny1 == ny2)) cur += a[nx1][ny1];
          else cur += a[nx1][ny1] + a[nx2][ny2];
          dp[1-act][nx1][nx2] = max(dp[1-act][nx1][nx2], cur);
        }
      }
    }
    act = 1 - act;
  }
  printf("%d\n", dp[act][N-1][N-1]);
  return 0;
}