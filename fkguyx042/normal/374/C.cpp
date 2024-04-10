#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int X[4]={0,0,-1,1};
const int Y[4]={-1,1,0,0};
int dp[1001][1001],Vis[1001][1001];
char c[1001][1001];
int vis[1001][1001],i,j,m,n,p,k,ans;
bool check(int x,int y,int xx,int yy)
{  if(x<0||y<0||x>n||y>=m) return false;
   if (c[x][y]=='D'&&c[xx][yy]=='A') return true;
   if (c[x][y]=='I'&&c[xx][yy]=='D') return true;
   if (c[x][y]=='M'&&c[xx][yy]=='I') return true;
   if (c[x][y]=='A'&&c[xx][yy]=='M') return true;
   return false;
}
int dfs(int x,int y)
{ if (Vis[x][y]) return dp[x][y];
  if (vis[x][y]) { printf("Poor Inna!\n"); exit(0); }
  vis[x][y]=1; int i;
  for (i=0;i<4;i++)
  if (check(x+X[i],y+Y[i],x,y))
  dp[x][y]=max(dp[x][y],dfs(x+X[i],y+Y[i]));
  if (c[x][y]=='A') dp[x][y]++;
  vis[x][y]=0;
  Vis[x][y]=1;
  return dp[x][y];
}
int main()
{ scanf("%d%d",&n,&m);
  for (i=1;i<=n;i++)
   scanf("%s",&c[i]);
  for (i=1;i<=n;i++)
   for (j=0;j<m;j++)
   if (c[i][j]=='D')
    ans=max(ans,dfs(i,j));
   if (!ans) printf("Poor Dima!\n");
   else printf("%d\n",ans);
}