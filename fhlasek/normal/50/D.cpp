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
#define MAXN 111

using namespace std;

int N,X[MAXN],Y[MAXN],K,e,X0,Y0;
double dp[MAXN][MAXN];

double p(double r,int n){
  double d=sqrt((X[n]-X0)*(X[n]-X0)+(Y[n]-Y0)*(Y[n]-Y0));
  if(d<r) return 1;
  return exp(1-d*d/(r*r));
}

bool ok(double r){
  int i,j;
  double x;
  FOR(i,N+1) dp[0][i]=0;
  dp[0][0]=1;
  for(i=1;i<=N;i++){
    x=p(r,i-1);
    for(j=0;j<=N;j++){
      if(j) dp[i][j]=dp[i-1][j-1]*x+dp[i-1][j]*(1-x);
      else dp[i][j]=dp[i-1][j]*(1-x);
    }
  }
  x=0;
  FOR(i,K) x+=dp[N][i];
  return 1000*x<e;
}

int main(int argc, char *argv[]){
  scanf("%d",&N);
  scanf("%d%d",&K,&e);
  scanf("%d%d",&X0,&Y0);
  int i;
  FOR(i,N) scanf("%d%d",X+i,Y+i);
  double left=0,right=10000;
  while(right-left>1e-9){
    if(ok((left+right)/2)) right=(left+right)/2;
    else left=(left+right)/2;
  }
  printf("%.9lf\n",left);
  return 0;
}