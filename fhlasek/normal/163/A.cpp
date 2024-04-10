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

#define MAXN 5555
#define MOD 1000000007
char s[MAXN],t[MAXN];
int S,T,dp[MAXN][MAXN];

int main(int argc, char *argv[]){
  scanf("%s",s);
  scanf("%s",t);
  S = strlen(s);
  T = strlen(t);
  REP(i,S) REP(j,T){
    if(s[i] == t[j]) dp[i][j] = (i&&j)?(1+dp[i-1][j-1]):1;
    if(j) dp[i][j] = (dp[i][j] + dp[i][j-1])%MOD;
  }
  int ans = 0;
  REP(i,S) ans = (ans + dp[i][T-1])%MOD;
  printf("%d\n",ans);
  return 0;
}