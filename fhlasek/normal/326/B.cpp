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

#define MAXN 111111
char s[MAXN];
int N = 0;

#define MAXM 111
int dp[MAXN][111], prefi[MAXN][111], prefj[MAXN][111];
int last[MAXN][MAXM];

int best = 0;
char tmp[MAXN];
char ans[MAXN];

int main(int argc, char *argv[]){
  scanf("%s", s);
  N = strlen(s);

  REP(i, 26) last[0][i] = -1;
  REP(i, N) {
    REP(j, 26) last[i+1][j] = last[i][j];
    last[i+1][s[i]-'a'] = i;
  }

  REP(j, MAXN) dp[0][j] = -1;
  dp[0][0] = N;
  REP(i, N) REP(j, 55) if(dp[i][j] >= i) {
    //printf("ok i: %d j: %d dp[i][j]: %d\n", i, j, dp[i][j]);
    int len = 2 * j + (dp[i][j] > i);
    if(len <= 100 && best < len) {
      best = len;
      int ii = i, jj = j;
      int n = 0;
      while(jj) {
        int ni = prefi[ii][jj], nj = prefj[ii][jj];
        if (nj != jj) tmp[n++] = s[ni];
        ii = ni; jj = nj;
      }
      int A = 0;
      REP(k, n) ans[A++] = tmp[n - 1 - k];
      if (dp[i][j] > i) ans[A++] = s[i];
      REP(k, n) ans[A++] = tmp[k];
    }
    if(dp[i][j] > dp[i+1][j]) {
      prefi[i+1][j] = i; prefj[i+1][j] = j;
      dp[i+1][j] = dp[i][j];
    }
    if(last[dp[i][j]][s[i]-'a'] > dp[i+1][j+1]) {
      prefi[i+1][j+1] = i; prefj[i+1][j+1] = j;
      dp[i+1][j+1] = last[dp[i][j]][s[i]-'a'];
    }
  }
  //printf("%d\n", best);
  ans[best] = '\0';
  printf("%s\n", ans);
  return 0;
}