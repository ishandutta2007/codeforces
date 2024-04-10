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

int a[111][111],A[111],N,M,dp[111][111],sum[111];
int res[111][11111];

int count(int n,int k){
  int tmp = 0,best;
  REP(i,k) tmp+=a[n][i];
  best = tmp;
  REP(i,A[n]-k){
    tmp -= a[n][i];
    tmp += a[n][i+k];
    best = min(best,tmp);
  }
  return best;
}

int main(int argc, char *argv[]){
  scanf("%d%d",&N,&M);
  REP(i,N){ 
    scanf("%d",A+i);
    REP(j,A[i]) scanf("%d",&(a[i][j]));
  }
  REP(i,N) REP(j,A[i]) sum[i] += a[i][j];
  REP(i,N) REP(k,A[i]+1) dp[i][k] = sum[i] - count(i,A[i]-k);
  REP(i,N) REP(j,M+1){
    res[i+1][j] = 0;
    REP(k,min(j,A[i])+1) res[i+1][j] = max(res[i+1][j],dp[i][k]+res[i][j-k]);
  }
  printf("%d\n",res[N][M]);
  return 0;
}