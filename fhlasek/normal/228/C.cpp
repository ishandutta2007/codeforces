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

int N, M;
char a[555][555];

bool fractal[11][555][555], black[11][555][555];

int q(int a0, int a1, int a2, int a3){ return (a0 << 0) + (a1 << 1) + (a2 << 2) + (a3 << 3); }

int main(int argc, char *argv[]){
  scanf("%d%d", &N, &M);
  int ans = 0;
  REP(i, N) scanf("%s", a[i]);
  REP(i, N) REP(j, M) black[0][i][j] = (a[i][j] == '*');
  REP(b, 10) REP(i, N) REP(j, M){
    int ii = i + (1 << b), jj = j + (1 << b);
    if(ii < N && jj < M)
      black[b+1][i][j] = black[b][i][j] && black[b][ii][j] && black[b][i][jj] && black[b][ii][jj];
  }
  REP(mask, 1 << 4){
    REP(i, N-1) REP(j, M-1) fractal[1][i][j] = (mask == q(black[0][i][j], black[0][i+1][j], black[0][i][j+1], black[0][i+1][j+1]));
    FOR(b, 1, 9) REP(i, N) REP(j, M){
      int ii = i + (1 << b), jj = j + (1 << b);
      if(ii < N && jj < M)
        ans += (fractal[b+1][i][j] = (
                             ((mask & (1 << 0)) ? black[b][i][j] : fractal[b][i][j]) &&
                             ((mask & (1 << 1)) ? black[b][ii][j]: fractal[b][ii][j]) &&
                             ((mask & (1 << 2)) ? black[b][i][jj]: fractal[b][i][jj]) &&
                             ((mask & (1 << 3)) ? black[b][ii][jj]: fractal[b][ii][jj])));
    }
  }
  printf("%d\n", ans);
  return 0;
}