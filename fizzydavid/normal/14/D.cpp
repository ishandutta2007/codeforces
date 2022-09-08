//while(true)rp++;
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
const int maxn=211;
vector<pair<int,int> >con[maxn];
vector<pair<int,int> >edge;
bool vis[maxn];
int n,t,tmx,tv,ans;
void dfs(int x,int dis)
{
    vis[x]=1;
    if(dis>tmx)
        tmx=dis,tv=x;
    for(int i=0;i<con[x].size();i++)
        if(!vis[con[x][i].FF]&&t!=con[x][i].SS)
            dfs(con[x][i].FF,dis+1);
}
int go(int x)
{
    memset(vis,0,sizeof(vis));
    tmx=tv=0,dfs(x,0);
    memset(vis,0,sizeof(vis));
    tmx=0,dfs(tv,0);
    return tmx;
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    int x,y;
    for(int i=1;i<n;i++)
    {
        cin>>x>>y;
        con[x].PB(MP(y,i));
        con[y].PB(MP(x,i));
        edge.PB(MP(x,y));
    }
    for(t=1;t<n;t++)
        ans=max(ans,go(edge[t-1].FF)*go(edge[t-1].SS));
    cout<<ans<<endl;
    return 0;
}