#include<iostream>
#include<cstdio>
#include<cstring>
#define N 200010
#define ll long long
#define mod 1000000007
using namespace std;
int nxt[N<<1],to[N<<1],head[N],cnt;
ll w[N<<1];
void add(int u,int v,ll w1)
{
    nxt[++cnt]=head[u];
    to[cnt]=v;
    w[cnt]=w1;
    head[u]=cnt;
}
ll b[62],bt;
void insert(ll x)
{
    for(int i=60;i>=0;i--)
    if((x>>i)&1)
    {
        if(!b[i]){b[i]=x;++bt;return;}
        else x^=b[i];
    }
}
bool vis[N];
ll dis[N];
int qid[N],tot;
void dfs(int u)
{
    qid[++tot]=u;
    vis[u]=true;
    for(int i=head[u];i;i=nxt[i])
    {
        int v=to[i];
        if(vis[v]){insert(dis[u]^dis[v]^w[i]);continue;}
        dis[v]=dis[u]^w[i];
        dfs(v);
    }
}
void clear(){memset(b,0,sizeof(b));tot=bt=0;}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        ll w;
        scanf("%d%d%lld",&u,&v,&w);
        add(u,v,w),add(v,u,w);
    }
    ll ans=0;
    for(int i=1;i<=n;i++)
    if(!vis[i])
    {
        clear();
        dfs(i);
        bt=1ll<<bt;
        for(int j=0;j<=60;j++)
        {
            bool have=0;
            ll res=0;
            for(int k=0;k<=60;k++) if((b[k]>>j)&1) have=true;
            if(have) res=1ll*tot*(tot-1)/2%mod*(bt/2%mod)%mod;
            else
            {
                for(int k=1;k<=tot;k++) res+=(dis[qid[k]]>>j)&1;
                res=1ll*bt%mod*res%mod*(tot-res)%mod;
            }
            ans=(ans+res*((1ll<<j)%mod))%mod;
        }
    }
    printf("%lld\n",ans);
    return 0;
}