#include<sstream>
#include<string>
#include<vector>
#include <cstdio>
using namespace std;
#define MAX 1510
#define INF 1000000000
int n,cost[MAX][MAX],s[2][MAX],r,d[2][MAX],from[2][MAX],add[2][MAX],v[2][MAX];

bool augment() {
  int i,b_x,b_y,x,y;
  
  for (y=1; y<=n; y++) {
    d[0][y]=s[0][y]?INF:0;
    d[1][y]=INF;
    v[0][y]=v[1][y]=false;
  }
  for (i=0; i<2*n; i++) {
    b_y=0;
    for (x=0; x<2; x++) for (y=1; y<=n; y++) if (!v[x][y] && d[x][y]<INF && (!b_y || d[x][y]<d[b_x][b_y])) {
      b_x=x;
      b_y=y;
    }
    v[b_x][b_y]=true;
    if (b_x==1) {
      y=s[1][b_y];
      if (d[1][b_y]-cost[y][b_y]+add[1][b_y]-add[0][y]<d[0][y]) {
        d[0][y]=d[1][b_y]-cost[y][b_y]+add[1][b_y]-add[0][y];
        from[0][y]=b_y;
      }
    }
    else for (y=1; y<=n; y++) if (s[0][b_y]!=y && d[0][b_y]+cost[b_y][y]+add[0][b_y]-add[1][y]<d[1][y]) {
      d[1][y]=d[0][b_y]+cost[b_y][y]+add[0][b_y]-add[1][y];
      from[1][y]=b_y;
    }      
  }
  b_y=0;
  for (y=1; y<=n; y++) if (!s[1][y] && (!b_y || d[1][y]<d[1][b_y])) b_y=y;
  if (!b_y || d[1][b_y]==INF) return false;
  for (x=0; x<2; x++) for (y=1; y<=n; y++) add[x][y]+=d[x][y];
  r+=add[1][b_y];
  while (b_y) {
    y=from[1][b_y];
    s[0][y]=b_y;
    s[1][b_y]=y;
    b_y=from[0][y];
  }
  return true;
}

int matching() {
  r=0;
  for (int i=1; i<=n; i++) augment();
  return r;
}

int k,m,a[MAX];

int main() {
  scanf("%d %d",&k,&m);
  for(int i=1;i<=k;i++)scanf("%d",&a[i]);
  n=k+m;
  for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)cost[i][j]=INF;
  for(int i=1;i<=k;i++)for(int j=i+1;j<=k;j++)cost[i][j]=a[i]==a[j]?0:__builtin_popcount(a[j]);
  for(int i=1;i<=m;i++)for(int j=1;j<=k;j++)cost[k+i][j]=__builtin_popcount(a[j]);
  for(int i=1;i<=m;i++)for(int j=1;j<=n;j++)cost[j][k+i]=0;
  int c=matching(),nr[MAX]={};
  vector<string> ans;
  //for(int i=1;i<=n;i++)printf("%d %d\n",s[1][i],cost[s[1][i]][i]);
  for(int i=1;i<=k;i++){
    int tmp=s[1][i];
    if(tmp<i){
      if(a[tmp]!=a[i]){
        ostringstream z;
        z<<string(1,'a'+nr[tmp]-1)<<"="<<a[i];
        ans.push_back(z.str());
      }
      nr[i]=nr[tmp];
    }else{
      nr[i]=tmp-k;
      ostringstream z;
      z<<string(1,'a'+nr[i]-1)<<"="<<a[i];
      ans.push_back(z.str());
    }
    ans.push_back("print(" + string(1,'a'+nr[i]-1) + ")");
  }
  printf("%d %d\n",(int)ans.size(),c);
  for(int i=0;i<ans.size();i++)puts(ans[i].c_str());
  return 0;
}