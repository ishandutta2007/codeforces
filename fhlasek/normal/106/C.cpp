/* Writen by Filip Hlasek 2011 */
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

using namespace std;

int N,M,c0,d0,a[11],b[11],c[11],d[11],dp[1111][11];

int solve(int n,int start){
  if(start==M) return 0;
  if(dp[n][start]!=-1) return dp[n][start];
  int i;
  dp[n][start]=0;
  for(i=0;;i++){
    if(i*b[start]>a[start]||i*c[start]>n) break;
    dp[n][start]=max(dp[n][start],i*d[start]+solve(n-i*c[start],start+1));
  }
  return dp[n][start];
}

int main(int argc, char *argv[]){
  scanf("%d%d%d%d",&N,&M,&c0,&d0); 
  int i,best=0,j;
  FOR(i,M) scanf("%d%d%d%d",a+i,b+i,c+i,d+i);
  FOR(i,N+1) FOR(j,M+1) dp[i][j]=-1;
  FOR(i,N/c0+1) if(N-i*c0>=0) best=max(best,d0*i+solve(N-i*c0,0));
  printf("%d\n",best);
  return 0;
}