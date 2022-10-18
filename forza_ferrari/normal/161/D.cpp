#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct edge
{
    int nxt,to,weight;
}e[50001<<1];
int root,n,tot,h[50001],s[50001],maxn[50001],dep[50001],cnt;
long long ans;
bool vis[50001];
inline int read()
{
    int x=0;
    char c=getchar();
    while(c<'0'||c>'9')
        c=getchar();
    while(c>='0'&&c<='9')
    {
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x;
}
inline void add(int x,int y,int w)
{
    e[++tot].nxt=h[x];
    h[x]=tot;
    e[tot].to=y;
    e[tot].weight=w;
}
void find(int k,int f,int g)
{
    s[k]=1;
    maxn[k]=0;
    for(register int i=h[k];i;i=e[i].nxt)
    {
        if(e[i].to==f||vis[e[i].to])
            continue;
        find(e[i].to,k,g);
        s[k]+=s[e[i].to];
        maxn[k]=max(maxn[k],s[e[i].to]);
    }
    maxn[k]=max(maxn[k],g-s[k]);
    if(maxn[k]<maxn[root])
        root=k;
}
void calc(int k,int f,int deep)
{
    dep[++cnt]=deep;
    for(register int i=h[k];i;i=e[i].nxt)
    {
        if(e[i].to==f||vis[e[i].to])
            continue;
        calc(e[i].to,k,deep+e[i].weight);
    }
}
inline long long solve(int x)
{
    sort(dep+1,dep+cnt+1);
    long long res=0;
    for(register int i=1;i<cnt;++i)
    {
        if(dep[i]+dep[i+1]>x)
            break;
        int j=max(lower_bound(dep+1,dep+cnt+1,x-dep[i])-dep,i+1),k=upper_bound(dep+1,dep+cnt+1,x-dep[i])-dep-1;
        res+=k-j+1;
    }
    return res;
}
void dfs(int k,int x)
{
    vis[k]=1;
    cnt=0;
    calc(k,0,0);
    ans+=solve(x);
    for(register int i=h[k];i;i=e[i].nxt)
    {
        if(vis[e[i].to])
            continue;
        cnt=0;
        calc(e[i].to,0,e[i].weight);
        ans-=solve(x);
        root=0;
        find(e[i].to,k,s[e[i].to]);
        dfs(root,x);
    }
}
int main()
{
    maxn[0]=1<<30;
    n=read();
    int x=read();
    for(register int i=1;i<n;++i)
    {
        int x=read(),y=read();
        add(x,y,1);
        add(y,x,1);
    }
    find(1,0,n);
    dfs(root,x);
    printf("%lld\n",ans);
    return 0;
}