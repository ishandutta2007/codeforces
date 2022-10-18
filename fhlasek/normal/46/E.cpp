#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <string>
#include <algorithm>
#include <cmath>

#define FOR(i,n) for(i=0;i<n;i++)
#define MAXN 1600

using namespace std;

typedef long long int int64;

int N,M;
int m[MAXN][MAXN];
long long dp[MAXN][MAXN];

int main(int argc, char *argv[]){
  int i,j;
  scanf("%d%d",&N,&M);
  FOR(i,N) FOR(j,M){ scanf("%d",&(m[i][j])); }
  long long s=0;
  FOR(i,M) s+=(long long)m[0][i];
  dp[0][M-1]=s;
  for(i=M-2;i>0;i--){ s-=(long long)m[0][i+1]; dp[0][i]=max(dp[0][i+1],s); }
  for(i=1;i<N;i++){
    if(i%2){
      s=(long long)m[i][0];
      dp[i][0]=dp[i-1][1]+s;
      for(j=1;j<M-1;j++){ s+=(long long)m[i][j]; dp[i][j]=max(dp[i][j-1],dp[i-1][j+1]+s); }
    }
    else{
      s=0;
      FOR(j,M) s+=(long long)m[i][j];
      dp[i][M-1]=s+dp[i-1][M-2];
      for(j=M-2;j>0;j--){ s-=(long long)m[i][j+1]; dp[i][j]=max(dp[i][j+1],s+dp[i-1][j-1]); }
    }
  }
  long long mx;
  if((N-1)%2){ mx=dp[N-1][0]; FOR(i,M-1) mx=max(mx,dp[N-1][i]); }
  else{ mx=dp[N-1][1]; FOR(i,M-1) mx=max(mx,dp[N-1][i+1]); }
  printf("%lld\n",mx);
  return 0;
}