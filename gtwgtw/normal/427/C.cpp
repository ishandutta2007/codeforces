#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 100005
using namespace std;


struct e
{
    int u,v,pre;
    e(int U=0,int V=0,int P=0){u=U;v=V;pre=P;}
}edge[maxn*3];int dex,adj[maxn];
int low[maxn],dfn[maxn],vis[maxn],instack[maxn],f[maxn];
int num[maxn],stack[maxn],top,minv[maxn],way[maxn];
long long ans,ans2;
int Index,w[maxn],cnt,n,m;


inline void tarjan(int x)
{
    low[x]=dfn[x]=++Index;
    stack[++top]=x;instack[x]=1;vis[x]=1;
    for(int i=adj[x];i!=-1;i=edge[i].pre)
    {
        int v=edge[i].v;
        if(!vis[v])
        {
            tarjan(v);
            low[x]=min(low[x],low[v]);
        }else if(instack[v])low[x]=min(low[x],dfn[v]);
    }
    if(low[x]==dfn[x])
    {
        cnt++;
        minv[cnt]=2100000000;
        int v;
        do
        {
            v=stack[top--];
            if(w[v]<minv[cnt])
            {
                minv[cnt]=w[v];
                way[cnt]=1;
            }else
            if(w[v]==minv[cnt])way[cnt]++;
            f[v]=cnt;
            num[cnt]++;
            instack[v]=false;           
        }while(x!=v);
    }
}
 


int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&w[i]);
    scanf("%d",&m);
    memset(adj,-1,sizeof(adj));
    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        edge[++dex]=e(u,v,adj[u]);  adj[u]=dex;
    }
    for(int i=1;i<=n;i++)if(!vis[i])tarjan(i);
    ans2=1ll;
    for(int i=1;i<=cnt;i++)ans+=minv[i],ans2=(1ll*ans2*way[i])%1000000007;
    printf("%I64d %I64d\n",ans,ans2);
    return 0;
}