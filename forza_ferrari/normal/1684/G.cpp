#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
#define int long long
struct edge
{
    int nxt,to,weight;
}e[1000001<<1];
int n,m,s,t,tot=1,h[1005],a[1001],dep[1005],cur[1005],maxn,cnt;
bool vis[1005],tag[1005];
vector<pair<int,int> > ans;
inline void add(int x,int y,int w)
{
    e[++tot].nxt=h[x];
    h[x]=tot;
    e[tot].to=y;
    e[tot].weight=w;
}
inline bool bfs()
{
    for(int i=0;i<=t;++i)
    {
        vis[i]=0;
        cur[i]=h[i];
        dep[i]=0x3f3f3f3f;
    }
    dep[s]=0;
    queue<int> q;
    q.emplace(s);
    while(!q.empty())
    {
        int k=q.front();
        q.pop();
        vis[k]=0;
        for(int i=h[k];i;i=e[i].nxt)
            if(e[i].weight&&dep[e[i].to]>dep[k]+1)
            {
                dep[e[i].to]=dep[k]+1;
                if(!vis[e[i].to])
                {
                    vis[e[i].to]=1;
                    q.emplace(e[i].to);
                }
            }
    }
    return dep[t]^dep[0];
}
inline int dfs(int k,int f)
{
    if(k==t)
    {
        maxn+=f;
        return f;
    }
    int r=0,used=0;
    for(int i=cur[k];i;i=e[i].nxt)
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
        dfs(s,1<<30);
}
signed main()
{
    cin>>n>>m;
    s=n+1,t=n+2;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        if(a[i]>m/3)
        {
            ++cnt;
            add(s,i,1);
            add(i,s,0);
            for(int j=1;j<i;++j)
                if(a[j]<=m/3&&a[i]%a[j]==0&&2*a[i]+a[j]<=m)
                {
                    add(i,j,1);
                    add(j,i,0);
                }
        }
        else
        {
            add(i,t,1);
            add(t,i,0);
            for(int j=1;j<i;++j)
                if(a[j]>m/3&&a[j]%a[i]==0&&a[i]+2*a[j]<=m)
                {
                    add(j,i,1);
                    add(i,j,0);
                }
        }
    }
    dinic();
    if(maxn^cnt)
    {
        cout<<"-1\n";
        return 0;
    }
    for(int k=1;k<=n;++k)
        if(a[k]>m/3)
            for(int i=h[k];i;i=e[i].nxt)
                if(e[i].to>=1&&e[i].to<=n&&!e[i].weight)
                {
                    ans.emplace_back(2*a[k]+a[e[i].to],a[k]+a[e[i].to]);
                    tag[k]=tag[e[i].to]=1;
                    break;
                }
    for(int i=1;i<=n;++i)
        if(a[i]<=m/3&&!tag[i])
            ans.emplace_back(3*a[i],2*a[i]);
    cout<<ans.size()<<'\n';
    for(auto i:ans)
        cout<<i.first<<" "<<i.second<<'\n';
    return 0;
}