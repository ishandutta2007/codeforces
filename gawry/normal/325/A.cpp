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
int n;
main(){
  scanf("%d",&n);
  int x0[5],y0[5],x1[5],y1[5],x[2],y[2];
  x[0]=32000;
  x[1]=0;
  y[0]=32000;
  y[1]=0;
  int area=0;
  FOR(i,n){
    scanf("%d %d %d %d",&x0[i],&y0[i],&x1[i],&y1[i]);
    x[0]=min(x[0],x0[i]);
    x[1]=max(x[1],x1[i]);
    y[0]=min(y[0],y0[i]);
    y[1]=max(y[1],y1[i]);
    area+=(x1[i]-x0[i])*(y1[i]-y0[i]);
  }
  puts(x[1]-x[0]==y[1]-y[0]&&area==(x[1]-x[0])*(y[1]-y[0])?"YES":"NO");
}