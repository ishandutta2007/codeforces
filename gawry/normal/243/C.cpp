#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long int64;
int n,l[1010];
char d[1010];
char b[3010][3010];
#define INF 10000000000LL
vector<int64> sx,sy;
void mark(int64 x0,int64 y0,int64 x1,int64 y1){
  x0=lower_bound(sx.begin(),sx.end(),x0)-sx.begin();
  y0=lower_bound(sy.begin(),sy.end(),y0)-sy.begin();
  x1=lower_bound(sx.begin(),sx.end(),x1)-sx.begin();
  y1=lower_bound(sy.begin(),sy.end(),y1)-sy.begin();
  if(x0>x1)swap(x0,x1);if(y0>y1)swap(y0,y1);
  for(int i=x0;i<=x1;i++)for(int j=y0;j<=y1;j++)b[i][j]=1;
}
void dfs(int x,int y){
  if(x<0||x>=sx.size()||y<0||y>=sy.size()||b[x][y])return;
  b[x][y]=2;
  dfs(x-1,y);
  dfs(x+1,y);
  dfs(x,y-1);
  dfs(x,y+1);
}
main(){
  scanf("%d",&n);
  int64 x=INF/2,y=INF/2;
  sx.push_back(0);
  sx.push_back(INF+1);
  sy.push_back(0);
  sy.push_back(INF+1);
  for(int i=0;i<=n;i++){
    sx.push_back(x);
    sx.push_back(x+1);
    sy.push_back(y);
    sy.push_back(y+1);
    if(i==n)break;
    scanf(" %c %d",&d[i],&l[i]);
    if(d[i]=='L')x-=l[i];else if(d[i]=='R')x+=l[i];else if(d[i]=='U')y-=l[i];else if(d[i]=='D')y+=l[i];
  }
  sort(sx.begin(),sx.end());
  sx.erase(unique(sx.begin(),sx.end()),sx.end());
  sort(sy.begin(),sy.end());
  sy.erase(unique(sy.begin(),sy.end()),sy.end());
  x=INF/2;y=INF/2;
  for(int i=0;i<n;i++){
    int64 xx=x,yy=y;
    if(d[i]=='L')x-=l[i];else if(d[i]=='R')x+=l[i];else if(d[i]=='U')y-=l[i];else if(d[i]=='D')y+=l[i];
    mark(xx,yy,x,y);
  }
  dfs(0,0);
  int64 r=0;
  for(int i=0;i+1<sx.size();i++)for(int j=0;j+1<sy.size();j++)if(b[i][j]!=2){
    r+=(sx[i+1]-sx[i])*(sy[j+1]-sy[j]);
  }
  cout<<r<<endl;
}