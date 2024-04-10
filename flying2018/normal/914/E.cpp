#include<iostream>
#include<cstdio>
#include<cstring>
#define N 200010
#define C 20
#define ll long long
using namespace std;
char s[N];
int a[N];
int nxt[N<<1],to[N<<1],head[N],cnt;
void add(int u,int v)
{
    nxt[++cnt]=head[u];
    to[cnt]=v;
    head[u]=cnt;
}
ll sum[1<<C],ans[N];
bool ban[N];
int siz[N],all,rt,mrt;
void get_rt(int u,int p)
{
    siz[u]=1;int mt=0;
    for(int i=head[u];i;i=nxt[i])
    {
        int v=to[i];
        if(v==p || ban[v]) continue;
        get_rt(v,u);
        siz[u]+=siz[v];mt=max(mt,siz[v]);
    }
    mt=max(mt,all-siz[u]);
    if(mt<mrt) mrt=mt,rt=u;
}
void dfs(int u,int p,int d,int v0)
{
    d^=a[u];sum[d]+=v0;
    for(int i=head[u];i;i=nxt[i])
    {
        int v=to[i];
        if(v==p || ban[v]) continue;
        dfs(v,u,d,v0);
    }
}
ll solve(int u,int p,int d)
{
    d^=a[u];ll res=sum[d];
	for(int i=0;i<C;i++) res+=sum[d^(1<<i)];
    for(int i=head[u];i;i=nxt[i])
    {
        int v=to[i];
        if(v==p || ban[v]) continue;
        res+=solve(v,u,d);
    }
    ans[u]+=res;
    return res;
}
void work(int u)
{
    all=siz[u],mrt=1e7,rt=0;
    get_rt(u,0);u=rt;
    ban[u]=true;
    dfs(u,0,0,1);
	ll res=sum[0];
	for(int i=0;i<C;i++) res+=sum[1<<i];
    for(int i=head[u];i;i=nxt[i])
    {
        int v=to[i];
        if(ban[v]) continue;
        dfs(v,0,a[u],-1);
        res+=solve(v,0,0);
        dfs(v,0,a[u],1);
    }
    dfs(u,0,0,-1);
    ans[u]+=res/2;
    for(int i=head[u];i;i=nxt[i])
    if(!ban[to[i]]) work(to[i]);
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v),add(v,u);
    }
    scanf("%s",s+1);
    for(int i=1;i<=n;i++) a[i]=1<<(s[i]-'a');
    mrt=1e7,siz[1]=n;
    work(1);
    for(int i=1;i<=n;i++) printf("%lld ",ans[i]+1);
    return 0;
}