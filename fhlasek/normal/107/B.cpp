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
#define L long double

using namespace std;

L c(int n,int k){
  L res=1,i;
  FOR(i,k) res*=(L)(n-i)/(i+1);
  return res;
}

int main(int argc, char *argv[]){
  int sum=0,i,N,M,H,S,x;
  scanf("%d%d%d",&N,&M,&H); 
  N--;
  FOR(i,M){
    scanf("%d",&x);
    if(i+1==H){ x--; S=x; }
    sum+=x;
  }
  if(sum<N){ printf("%lf\n",-1.0); return 0; }
  printf("%.9lf\n",1-(double)(c(sum-S,N)/c(sum,N)));
  return 0;
}