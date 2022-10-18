#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define int long long
struct edge
{
    int nxt,to,weight;
}e[200001<<1];
int t,n,tot,h[200001],s[200001],maxn,minn;
inline void add(int x,int y,int w)
{
    e[++tot].nxt=h[x];
    h[x]=tot;
    e[tot].to=y;
    e[tot].weight=w;
}
void dfs1(int k,int f)
{
    s[k]=1;
    for(register int i=h[k];i;i=e[i].nxt)
    {
        if(e[i].to==f)
            continue;
        dfs1(e[i].to,k);
        s[k]+=s[e[i].to];
        minn+=(s[e[i].to]&1)*e[i].weight;
    }
}
void dfs2(int k,int f)
{
    for(register int i=h[k];i;i=e[i].nxt)
    {
        if(e[i].to==f)
            continue;
        dfs2(e[i].to,k);
        maxn+=min(s[e[i].to],n-s[e[i].to])*e[i].weight;
    }
}
signed main()
{
    scanf("%d",&t);
    while(t--)
    {
        tot=0;
        scanf("%lld",&n);
        n<<=1;
        for(register int i=1;i<=n;++i)
            h[i]=s[i]=0;
        maxn=minn=0;
        for(register int i=1;i<n;++i)
        {
            int x,y,w;
            scanf("%lld%lld%lld",&x,&y,&w);
            add(x,y,w);
            add(y,x,w);
        }
        dfs1(1,0);
        dfs2(1,0);
        printf("%lld %lld\n",minn,maxn);
    }
    return 0;
}