#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<numeric>
#include<map>
#include<set>
#include<cstdlib>
#include<string>
#include<cassert>
#include<iostream>
using namespace std;
typedef vector<int> vi;
typedef long long int64;
#define FOR(i,n)for(int i=0;i<(int)(n);i++)
int n,d,a[100],x[100],y[100],t[100];
main(){
  scanf("%d %d",&n,&d);
  for(int i=1;i<n-1;i++)scanf("%d",&a[i]);
  FOR(i,n)scanf("%d %d",&x[i],&y[i]);
  FOR(i,n)t[i]=1000000000;
  t[n-1]=0;
  FOR(z,n){
    FOR(i,n)FOR(j,n)if(i!=j){
      int dist=d*(abs(x[i]-x[j])+abs(y[i]-y[j]));
      t[i]=min(t[i],dist+max(0,t[j]-a[j]));
//      printf("%d -> %d %d+%d %d\n",i,j,dist,t[j]-a[j],t[i]);
    }
//    FOR(i,n)printf("%d ",t[i]);puts("");
  }
  printf("%d\n",t[0]);
}