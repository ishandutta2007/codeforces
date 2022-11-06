#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define N 610
#define M 50010
using namespace std;
int nxt[M<<1],to[M<<1],head[N],cnt;
void add(int u,int v)
{
    nxt[++cnt]=head[u];
    to[cnt]=v;
    head[u]=cnt;
}
int pre[N],link[N],vis[N],tvis;
int f[N];
int find(int x){return f[x]==x?f[x]:(f[x]=find(f[x]));}
int lca(int x,int y)
{
    tvis++;
    for(x=find(x),y=find(y);vis[x]!=tvis;)
    {
        vis[x]=tvis;
        x=find(pre[link[x]]);
        if(y) swap(x,y);
    }
    return x;
}
int clr[N],n;
queue<int>q;
void merge(int x,int y,int w)
{
    for(;find(x)!=w;x=pre[y])
    {
        pre[x]=y,y=link[x];
        if(clr[y]==2) clr[y]=1,q.push(y);
        if(x==find(x)) f[x]=w;
        if(y==find(y)) f[y]=w;
    }
}
bool check(int s)
{
    while(!q.empty()) q.pop();
    for(int i=1;i<=n;i++) f[i]=i,pre[i]=clr[i]=0;
    q.push(s);
    clr[s]=1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=head[u];i;i=nxt[i])
        {
            int v=to[i];
            if(clr[v]==2 || find(u)==find(v)) continue;
            if(clr[v]==0)
            {
                clr[v]=2;pre[v]=u;
                if(!link[v])
                {
                    for(int x=v,y;x;x=y) y=link[pre[x]],link[x]=pre[x],link[pre[x]]=x;
                    return true;
                }
                q.push(link[v]);clr[link[v]]=1;
            }
            else
            {
                int w=lca(u,v);
                merge(u,v,w);
                merge(v,u,w);
            }
        }
    }
    return false;
}
char mp[N][N];
int main()
{
    int t;
    scanf("%d",&t);
    while(t --> 0)
    {
        memset(link,0,sizeof(link));
        memset(mp,0,sizeof(mp));
        memset(head,0,sizeof(head));
        cnt=tvis=0;
        memset(vis,0,sizeof(vis));
        int n1,m;
        scanf("%d%d",&n1,&m);
        for(int i=1;i<=n1;i++)
            scanf("%s",mp[i]+1);
        n=2*n1+m;
        for(int i=1;i<=n1;i++) add(m+i,m+n1+i),add(m+n1+i,m+i);
        for(int i=1;i<=n1;i++)
            for(int j=1;j<=m;j++)
            if(mp[i][j]=='1')add(m+i,j),add(j,m+i);
        for(int i=1;i<=n1;i++)
            for(int j=1;j<=m;j++)
            if(mp[i][j]=='1')add(m+n1+i,j),add(j,m+n1+i);
        int ans=-n1;
        for(int i=1;i<=n;i++)
        if(!link[i])ans+=check(i);
        printf("%d\n",ans);
    }
    
    return 0;
}