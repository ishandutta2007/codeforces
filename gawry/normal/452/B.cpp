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
int n,m;
double ans=-1.0;
int x[4],y[4];
void check(int x0,int y0,int x1,int y1,int x2,int y2,int x3,int y3,bool s){
  int tx[4]={x0,x1,x2,x3};
  int ty[4]={y0,y1,y2,y3};
  FOR(i,4)FOR(j,i)if(tx[i]==tx[j]&&ty[i]==ty[j])return;
  double tmp=0.0;
  for(int i=1;i<4;i++)tmp+=hypot(tx[i]-tx[i-1],ty[i]-ty[i-1]);
  if(tmp>ans){
    ans=tmp;
    FOR(i,4){x[i]=tx[i];y[i]=ty[i];if(s)swap(x[i],y[i]);}
  }
}
int main(){
  cin>>n>>m;
  bool s=false;
  FOR(z,2){
    check(0,0,n,m,n,0,0,m,s);
    if(n)check(1,0,n,m,0,0,n-1,m,s);
    swap(n,m);
    s=true;
  }
  FOR(i,4)printf("%d %d\n",x[i],y[i]);
  //printf("%.6lf\n",ans);
  return 0;
}