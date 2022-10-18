#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
struct edge
{
    int nxt,to,weight;
}e[505*505*2];
int s,t,n,m,tot,h[505<<1],dep[505<<1],cur[505<<1],ans,flow;
bool vis[501<<1];
bool mp[501][501],tmp[501][501],used[501][501],sum[505][505];
inline void add(int x,int y,int w)
{
    e[++tot].nxt=h[x];
    h[x]=tot;
    e[tot].to=y;
    e[tot].weight=w;
}
inline bool bfs()
{
    for(register int i=0;i<=t;++i)
    {
        vis[i]=0;
        dep[i]=0x3f3f3f3f;
        cur[i]=h[i];
    }
    queue<int> q;
    q.push(s);
    dep[s]=0;
    while(!q.empty())
    {
        int k=q.front();
        q.pop();
        vis[k]=0;
        for(register int i=h[k];i;i=e[i].nxt)
            if(e[i].weight&&dep[e[i].to]>dep[k]+1)
            {
                dep[e[i].to]=dep[k]+1;
                if(!vis[e[i].to])
                {
                    vis[e[i].to]=1;
                    q.push(e[i].to);
                }
            }
    }
    return dep[0]^dep[t];
}
int dfs(int k,int f)
{
    if(k==t)
    {
        flow+=f;
        return f;
    }
    int r=0,used=0;
    for(register int i=cur[k];i;i=e[i].nxt)
    {
        cur[k]=i;
        if(e[i].weight&&dep[e[i].to]==dep[k]+1)
            if((r=dfs(e[i].to,min(e[i].weight,f-used))))
            {
                e[i].weight-=r;
                e[i^1].weight+=r;
                used+=r;
                if(f==used)
                    break;
            }
    }
    return used;
}
inline void dinic()
{
    while(bfs())
        dfs(s,1<<20);
}
int main()
{
    cin>>n>>m;
    for(register int i=1;i<=n;++i)
        for(register int j=1;j<=m;++j)
        {
            char c;
            cin>>c;
            if(c=='B')
                mp[i][j]=1;
        }
    for(register int i=n;i;--i)
        for(register int j=m;j;--j)
        {
            sum[i][j]^=sum[i+1][j]^sum[i][j+1]^sum[i+1][j+1];
            if(tmp[i][j]^sum[i][j]^mp[i][j])
            {
                ++ans;
                sum[i][j]^=1;
                used[i][j]=1;
            }
        }
    /*for(register int i=1;i<=n;++i,cout<<endl)
        for(register int j=1;j<=m;++j)
            cout<<vis[i][j];*/
    s=n+m+1;
    t=s+1;
    for(register int i=1;i<n;++i)
    {
        add(s,i,1);
        add(i,s,0);
    }
    for(register int i=1;i<m;++i)
    {
        add(i+n,t,1);
        add(t,i+n,0);
    }
    for(register int i=1;i<n;++i)
        for(register int j=1;j<m;++j)
            if(used[i][m]&&used[n][j]&&used[i][j])
            {
                add(i,j+n,1);
                add(j+n,i,0);
            }
    dinic();
    if(used[n][m])
        cout<<ans-(flow+1)/2*2<<endl;
    else
        cout<<ans-flow/2*2<<endl;
    return 0;
}