#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define rep(i,n) for(int i=1;i<=(n);i++)
using namespace std;

int vis[25][25],n,m;
char row[55],col[55];

void dfs(int x,int y)
{
    if(x>n||x<=0)return;
    if(y>m||y<=0)return;
    if(vis[x][y])return;
    vis[x][y]=1;
    if(row[x]=='>')dfs(x,y+1);else dfs(x,y-1);
    if(col[y]=='^')dfs(x-1,y);else dfs(x+1,y);
}

int main()
{
    scanf("%d%d",&n,&m);
    scanf("%s",row+1);
    scanf("%s",col+1);
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    {
        memset(vis,0,sizeof(vis));
        dfs(i,j);
        for(int k=1;k<=n;k++)
        for(int l=1;l<=m;l++)
        if(!vis[k][l]){puts("NO");return 0;}
    }
    puts("YES");
    return 0;
}