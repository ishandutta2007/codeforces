#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;


int adj[1005],dex=-1;
struct e
{
    int u,v,pre;
    e(int U=0,int V=0,int P=0){u=U;v=V;pre=P;}
}edge[5005];
struct Node
{
    int w,id;
}a[1005];
int n,m,ans,vis[1005],idx[1005];


int cmp(const Node &e,const Node &f)
{
    return e.w>f.w;
}


int main()
{
    scanf("%d%d",&n,&m);
    memset(adj,-1,sizeof(adj));
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i].w);
        a[i].id=i;
    }
    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        edge[++dex]=e(u,v,adj[u]);  adj[u]=dex;
        edge[++dex]=e(v,u,adj[v]);  adj[v]=dex;
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)idx[a[i].id]=i;
    for(int i=1;i<=n;i++)
    {
        int u=a[i].id;
        vis[u]=1;
        for(int i=adj[u];i!=-1;i=edge[i].pre)
        {
            int v=edge[i].v;
            if(vis[v])continue;
            ans+=a[idx[v]].w;
        }
    }
    printf("%d\n",ans);
    return 0;
}