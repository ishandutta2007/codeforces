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
using namespace std;

#define ALL(t) t.begin(),t.end()
#define FOR(i,n) for (int i=0;i<(int)(n);i++)
#define FOREACH(i,t) for (typeof(t.begin())i=t.begin();i!=t.end();i++)
typedef vector<int> vi;
typedef long long int64;

const int MAX=1010;
int n,m,T[MAX][MAX],a[MAX][MAX],b[MAX][MAX],c[MAX][MAX],d[MAX][MAX];
int main(){
  scanf("%d %d",&n,&m);
  for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)scanf("%d",&T[i][j]);
  for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
    if(i>1)a[i][j]=max(a[i][j],a[i-1][j]);
    if(j>1)a[i][j]=max(a[i][j],a[i][j-1]);
    a[i][j]+=T[i][j];
  }
  for(int i=1;i<=n;i++)for(int j=m;j>=1;j--){
    if(i>1)b[i][j]=max(b[i][j],b[i-1][j]);
    if(j<m)b[i][j]=max(b[i][j],b[i][j+1]);
    b[i][j]+=T[i][j];
  }
  for(int i=n;i>=1;i--)for(int j=m;j>=1;j--){
    if(i<n)c[i][j]=max(c[i][j],c[i+1][j]);
    if(j<m)c[i][j]=max(c[i][j],c[i][j+1]);
    c[i][j]+=T[i][j];
  }
  for(int i=n;i>=1;i--)for(int j=1;j<=m;j++){
    if(i<n)d[i][j]=max(d[i][j],d[i+1][j]);
    if(j>1)d[i][j]=max(d[i][j],d[i][j-1]);
    d[i][j]+=T[i][j];
  }
  int ans=-1;
  for(int i=2;i<n;i++)for(int j=2;j<m;j++){
    ans=max(ans,a[i-1][j]+b[i][j+1]+c[i+1][j]+d[i][j-1]);
    ans=max(ans,a[i][j-1]+b[i-1][j]+c[i][j+1]+d[i+1][j]);
  }
  printf("%d\n",ans);
  return 0;
}