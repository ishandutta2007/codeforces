#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
struct edge
{
    int nxt,to;
}e[200001<<1];
int t,n,tot,h[200001],ans;
bool vis[200001];
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
inline void add(int x,int y)
{
    e[++tot].nxt=h[x];
    h[x]=tot;
    e[tot].to=y;
}
void dfs(int k,int f)
{
    for(register int i=h[k];i;i=e[i].nxt)
    {
        if(e[i].to==f)
            continue;
        dfs(e[i].to,k);
        ans-=vis[e[i].to];
        vis[k]|=vis[e[i].to]^1;
    }
    ans+=vis[k]^1;
}
int main()
{
    t=read();
    while(t--)
    {
        for(register int i=1;i<=n;++i)
            vis[i]=h[i]=0;
        tot=ans=0;
        n=read();
        for(register int i=1;i<n;++i)
        {
            int x=read(),y=read();
            add(x,y);
            add(y,x);
        }
        dfs(1,0);
        printf("%d\n",ans);
    }
    return 0;
}