#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define int long long
struct edge
{
    int nxt,to;
}e[500001<<1];
int t,n,m,x,y,tot,h[500001],s1,s2;
bool vis[500001][2];
inline void add(int x,int y)
{
    e[++tot].nxt=h[x];
    h[x]=tot;
    e[tot].to=y;
}
void dfs1(int k,int qyc)
{
    if(vis[k][0])
        return;
    vis[k][0]=1;
    if(k==qyc)
        return;
    for(register int i=h[k];i;i=e[i].nxt)
        dfs1(e[i].to,qyc);
}
void dfs2(int k,int qyc)
{
    if(vis[k][1])
        return;
    vis[k][1]=1;
    if(k==qyc)
        return;
    for(register int i=h[k];i;i=e[i].nxt)
        dfs2(e[i].to,qyc);
}
signed main()
{
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld%lld%lld",&n,&m,&x,&y);
        for(register int i=1;i<=n;++i)
        {
            h[i]=0;
            vis[i][0]=vis[i][1]=0;
        }
        s1=s2=0;
        tot=0;
        for(register int i=1;i<=m;++i)
        {
            int a,b;
            scanf("%lld%lld",&a,&b);
            add(a,b);
            add(b,a);
        }
        dfs1(x,y);
        dfs2(y,x);
        for(register int i=1;i<=n;++i)
            if(vis[i][0]^vis[i][1])
            {
                s1+=vis[i][0];
                s2+=vis[i][1];
            }
        printf("%lld\n",s1*s2);
    }
    return 0;
}