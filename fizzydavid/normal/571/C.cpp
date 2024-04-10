//by yjz
// 
#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<"="<<x<<endl;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
//My own input/output stream
#define geti(x) x=getnum()
#define getii(x,y) geti(x),geti(y)
#define getiii(x,y,z) getii(x,y),geti(z)
#define puti(x) putnum(x),putsp()
#define putii(x,y) puti(x),putnum(y),putsp()
#define putiii(x,y,z) putii(x,y),putnum(z),putsp()
#define putsi(x) putnum(x),putendl()
#define putsii(x,y) puti(x),putnum(y),putendl()
#define putsiii(x,y,z) putii(x,y),putnum(z),putendl()
inline ll getnum()
{
    register ll r=0;register bool ng=0;register char c;c=getchar();
    while(c!='-'&&(c<'0'||c>'9'))c=getchar();
    if(c=='-')ng=1,c=getchar();
    while(c!=' '&&c!='\n')r=r*10+c-'0',c=getchar();
    if(ng)r=-r;return r;
}
template <class T> inline void putnum(T x)
{
    if(x<0)putchar('-'),x=-x;
    register short a[20]={},sz=0;
    while(x>0)a[sz++]=x%10,x/=10;
    if(sz==0)putchar('0');
    for(int i=sz-1;i>=0;i--)putchar('0'+a[i]);
}
inline void putsp(){putchar(' ');}
inline void putendl(){putchar('\n');}
inline char mygetchar(){register char c=getchar();while(c==' '||c=='\n')c=getchar();return c;}
int n,m;
int a[200111],b[200111],g[200111],dfn[200111],ti,nxt[200111];
bool ans[200111],ok[200111],vis[200111],cycle[200111],vis2[200111],used[200111];
struct edge
{
    int to,id,type;
}e[400111];
int head[400111],nxte[400111],etot;
void add_edge(int x,int y,int i)
{
//  cout<<x<<"-"<<y<<" "<<i<<endl;
    nxte[++etot]=head[x];
    head[x]=etot;
    e[etot].to=y;
    e[etot].id=i;
    e[etot].type=1;
    nxte[++etot]=head[y];
    head[y]=etot;
    e[etot].to=x;
    e[etot].id=i;
    e[etot].type=0;
}
void setok(int x)
{
    ok[x]=1;vis[x]=1;
    for(int i=head[x];i>0;i=nxte[i])
    {
        int u=e[i].to;
        if(!ok[u])
        {
            ans[e[i].id]=!e[i].type;
            setok(u);
        }
    }
}
void setcolor(int x,int c)
{
    g[x]=c;
    for(int i=head[x];i>0;i=nxte[i])
    {
        int u=e[i].to;
        if(g[u]==0)
        {
            setcolor(u,c);
        }
    }
}
bool findpath(int x,int pre,int y)
{
    vis2[x]=1;
    if(x==y)return true;
    for(int i=head[x];i>0;i=nxte[i])
    {
        int u=e[i].to;
        if(e[i].id!=pre&&!vis2[u])
        {
            if(findpath(u,e[i].id,y))
            {
                nxt[x]=u;
                return true;
            }
        }
    }
    return false;
}
bool findcycle(int x,int pre)
{
    vis[x]=1;
    for(int i=head[x];i>0;i=nxte[i])
    {
        int u=e[i].to;
        if(!vis[u])
        {
            if(findcycle(u,x))return true;
        }
        else if(u!=pre)
        {
            cycle[g[x]]=1;
            nxt[u]=x;
            findpath(x,e[i].id,u);
            return true;
        }
    }
    return false;
}
void dfs(int x)
{
//  cout<<"dfs:"<<x<<endl;
    ok[x]=1;
    for(int i=head[x];i>0;i=nxte[i])
    {
        int u=e[i].to;
        if(u==nxt[x]&&!used[e[i].id])
        {
            ans[e[i].id]=e[i].type;
            used[e[i].id]=1;
            if(!ok[u])dfs(u);
            setok(x);
            return;
        }
    }
}
int main()
{
    getii(n,m);
    for(int i=1;i<=n;i++)
    {
        int k;
        geti(k);
        for(int j=1;j<=k;j++)
        {
            int x,y;
            geti(x);
            if(x<0)y=-x,x=-i;else y=x,x=i;
            if(a[y]==0)a[y]=x;else b[y]=x;
        }
    }
    ok[0]=1;
    for(int i=1;i<=m;i++)
    {
        if(a[i]>0&&b[i]>0)
        {
            ans[i]=1;
            ok[a[i]]=1;
            ok[b[i]]=1;
        }
        else if(a[i]<0&&b[i]<0)
        {
            ans[i]=0;
            ok[-a[i]]=1;
            ok[-b[i]]=1;
        }
        else if(b[i]==0)
        {
            if(a[i]<0)add_edge(0,-a[i],i);else add_edge(a[i],0,i);
        }
        else if(a[i]>0&&b[i]<0)
        {
            add_edge(a[i],-b[i],i);
        }
        else if(a[i]<0&&b[i]>0)
        {
            add_edge(b[i],-a[i],i);
        }
    }
    for(int i=0;i<=n;i++)
    {
        if(ok[i]&&!vis[i])
        {
            setok(i);
        }
    }
    memset(vis,0,sizeof(vis));
    int tot=0;
    for(int i=0;i<=n;i++)
    {
        if(!ok[i]&&g[i]==0)
        {
            setcolor(i,++tot);
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i]&&!ok[i]&&!cycle[g[i]])
        {
            findcycle(i,-1);
        }
    }
    for(int i=1;i<=tot;i++)
    {
        if(!cycle[i])
        {
            puts("NO");
            return 0;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(nxt[i]>0&&!ok[i])
        {
            dfs(i);
        }
    }
//  for(int i=1;i<=n;i++)cout<<ok[i]<<" ";cout<<endl;
    puts("YES");
    for(int i=1;i<=m;i++)putchar('0'+ans[i]);
    return 0;
}