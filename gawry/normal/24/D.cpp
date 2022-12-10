#include<cstdio>
#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<numeric>
#include<cmath>
#include<queue>
#include<cstring>
using namespace std;

#define ALL(t) t.begin(),t.end()
#define FOR(i,n) for (int i=0; i<(int)(n); i++)
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
typedef vector<int> vi;
typedef long long int64;

int n,m,x,y;
double t[1010][1010],a[1010],b[1010],c[1010],d[1010];
main() {
  cin>>n>>m>>x>>y;
  n-=x;
  --y;
  for(int i=n-1;i>=0;i--){
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    memset(d,0,sizeof(d));
    FOR(j,m){
      int deg=2;
      if(j+1<m)c[j]=-1,deg++;
      if(j>0)a[j]=-1,deg++;
      b[j]=deg-1;
      d[j]=t[i+1][j]+deg;
    }
    c[0]/=b[0];
    d[0]/=b[0];
    for(int j=1;j<m;j++){
		  double id=1./(b[j]-c[j-1]*a[j]);
		  c[j]*=id;
		  d[j]=(d[j]-d[j-1]*a[j])*id;
	  }     
    t[i][m-1]=d[m-1];
    for(int j=m-2;j>=0;j--)t[i][j]=d[j]-c[j]*t[i][j+1];
  }
  printf("%.8lf\n",t[0][y]);
}