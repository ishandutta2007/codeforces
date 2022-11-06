#include<iostream>
#include<cstdio>
#include<cstring>
#define N 1000010
using namespace std;
int nxt[N<<1],to[N<<1],head[N],cnt;
void add(int u,int v)
{
    nxt[++cnt]=head[u];
    to[cnt]=v;
    head[u]=cnt;
}
int dis[N],md;
void dfs(int u,int p,int d)
{
    dis[u]=d=min(d,u);
    for(int i=head[u];i;i=nxt[i])
    {
        int v=to[i];
        if(v==p) continue;
        dfs(v,u,d);
    }
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v),add(v,u);
    }
    int rt=0;
    scanf("%*d%d",&rt);
    rt=rt%n+1;
    dfs(rt,0,n+1);
    m--;
    md=dis[rt];
    int las=0;
    while(m --> 0)
    {
        int op,r;
        scanf("%d%d",&op,&r);
        r=(r+las)%n+1;
        if(op==1) md=min(md,dis[r]);
        else printf("%d\n",las=min(md,dis[r]));
    }
    return 0;
}