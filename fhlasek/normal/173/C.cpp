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
#define REP(i,b) for(int i=0;i<b;i++)

using namespace std;

#define MAXN 555

int a[MAXN][MAXN];
int pref[MAXN][MAXN];
int N,M;

int main(int argc, char *argv[]){
  scanf("%d%d",&N,&M);
  REP(i,N) REP(j,M) scanf("%d",&(a[i][j]));
  REP(i,N) REP(j,M) pref[i+1][j+1] = pref[i+1][j] + pref[i][j+1] + a[i][j] - pref[i][j];
  int ans = -1000 * 500 * 500, tmp;
  FOR(x,1,N-2) FOR(y,1,M-2){
    tmp = a[x][y];
    for(int n = 1; x - n >= 0 && y - n >= 0 && x + n < N && y + n <M; n++){
      tmp = pref[x+n+1][y+n+1] - pref[x-n][y+n+1] - pref[x+n+1][y-n] + pref[x-n][y-n] - tmp - a[x-n+1][y-n];
      ans = max(ans, tmp);
    }
  }
  printf("%d\n",ans);
  return 0;
}