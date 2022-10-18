#include<iostream>
#include<cstdio>
#include<queue>
#include<cmath>
using namespace std;
#define int long long
struct edge
{
    int nxt,to,weight;
}e[1000001<<3];
int n,m,tot=1,s,t,h[200001],dep[200001],cur[200001],ans,tag[200001],a[200001],d[200001],sum;
bool vis[200001];
pair<int,int> p[200001];
inline int read()
{
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-')
            f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x*f;
}
inline void add(int x,int y,int w)
{
    e[++tot]={h[x],y,w};
    h[x]=tot;
}
inline bool bfs()
{
    queue<int> q;
    for(int i=0;i<=t;++i)
    {
        vis[i]=0;
        dep[i]=0x3f3f3f3f;
        cur[i]=h[i];
    }
    dep[s]=0;
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
        ans+=f;
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
    n=read(),m=read();
    s=n+m+1;
    t=s+2;
    for(int i=1;i<=n;++i)
        tag[i]=read();
    for(int i=1;i<=n;++i)
        a[i]=read();
    for(int i=1;i<=m;++i)
    {
        int x=read(),y=read();
        ++d[x],++d[y];
        add(s,i,1);
        add(i,s,0);
        add(i,x+m,1);
        add(x+m,i,0);
        add(i,y+m,1);
        add(y+m,i,0);
        p[i]={x,y};
    }
    for(int i=1;i<=n;++i)
    {
        if(!tag[i])
        {
            add(i+m,t-1,d[i]);
            add(t-1,i+m,0);
            continue;
        }
        if(abs(a[i])>d[i]||(d[i]&1)!=(abs(a[i])&1))
        {
            cout<<"NO\n";
            return 0;
        }
        sum+=(a[i]+d[i])>>1;
        add(i+m,t,(a[i]+d[i])>>1);
        add(t,i+m,0);
    }
    if(sum>m)
    {
        cout<<"NO\n";
        return 0;
    }
    add(t-1,t,m-sum);
    add(t,t-1,0);
    dinic();
    if(ans^m)
    {
        cout<<"NO\n";
        return 0;
    }
    for(int k=1;k<=m;++k)
        for(int i=h[k];i;i=e[i].nxt)
            if(!e[i].weight&&e[i].to>m&&e[i].to<=n+m)
            {
                if(p[k].first==e[i].to-m)
                    swap(p[k].first,p[k].second);
                break;
            }
    cout<<"YES\n";
    for(int i=1;i<=m;++i)
        cout<<p[i].first<<" "<<p[i].second<<'\n';
    return 0;
}