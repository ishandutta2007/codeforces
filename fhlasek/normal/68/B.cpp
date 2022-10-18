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
#define MAXN 11111

using namespace std;

int N,K;
int a[MAXN];

bool possible(double m){
  double sum=0;
  int i;
  FOR(i,N){
    if(a[i]<m) sum-=m-a[i];
    else sum+=(a[i]-m)*K/100;
  }
  return sum>0;
}

int main(int argc, char *argv[]){
  double left=0,right=1001,m;
  int i;
  scanf("%d%d",&N,&K);
  K=100-K;
  FOR(i,N) scanf("%d",a+i);
  while(right-left>1e-8){
    m=(left+right)/2;
    if(possible(m)) left=m;
    else right=m;
  }
  printf("%.8lf\n",(left+right)/2);
  return 0;
}