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

#define MAXN 4444

int t[MAXN],d[MAXN],N,K;
int dp[MAXN][MAXN], suff[MAXN][MAXN];

int main(int argc, char *argv[]){
  scanf("%d%d",&N,&K);   
  REP(i,N) scanf("%d%d",t+i,d+i);
  t[N] = 86401;
  REP(k,K+1) dp[0][k] = suff[0][k] = t[0] - 1;
  FOR(n,1,N) FOR(k,0,K){
    suff[n][k] = t[n] - t[n-1] - d[n-1] + min(0,suff[n-1][k]); 
    if(k) suff[n][k] = max(suff[n][k], t[n] - t[n-1] + suff[n-1][k-1]);
    dp[n][k] = max(dp[n-1][k], suff[n][k]);
    if(k) dp[n][k] = max(dp[n][k], suff[n-1][k-1] + t[n] - t[n-1]);
  }
  printf("%d\n",dp[N][K]);
  return 0;
}