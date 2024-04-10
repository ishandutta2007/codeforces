#include<bits/stdc++.h>
using namespace std;
int n,m;bool vis[100111];
vector<int>g[100111];
void dfs(int x)
{
    if(vis[x])return;vis[x]=1;
    for(int i=0;i<g[x].size();i++)dfs(g[x][i]);
    cout<<x<<" ";
}
int main()
{
    scanf("%d%d",&n,&m);int x,y;
    for(int i=1;i<=m;i++)scanf("%d%d",&x,&y),g[x].push_back(y);
    for(int i=1;i<=n;i++)if(!vis[i])dfs(i);
}