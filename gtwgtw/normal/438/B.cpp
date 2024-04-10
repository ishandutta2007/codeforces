#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;


struct e
{
    int u,v,w,pre,id;
    e(int U=0,int V=0,int W=0,int P=0,int I=0){u=U;v=V;w=W;pre=P;id=I;}
}edge[200005];
int w[500005],n,m;
int dex=-1;e Edge[800005];
int adj[500005];
int f[500005],sz[500005];
long long ans;


int get(int x)
{
    return (f[x]==x)?(x):(f[x]=get(f[x]));
}


int cmp(const e &c,const e &f)
{
    return c.w>f.w;
}


int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&w[i]);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        int ww=min(w[u],w[v]);
        edge[i]=e(u,v,ww,0,i);
    }
    sort(edge+1,edge+m+1,cmp);
    memset(adj,-1,sizeof(adj));
    for(int i=1;i<=n;i++)
    {
        f[i]=i;
        sz[i]=1;
    }
    for(int i=1;i<=m;i++)
    {
        int u=edge[i].u,v=edge[i].v;
        u=get(u);v=get(v);
        int z=edge[i].id+n;
        if(u!=v)
        {
            f[u]=v;
            ans+=(1ll*sz[v]*sz[u])*edge[i].w;
            sz[v]+=sz[u];
        }
    }
    double G=(1.*2ll*ans)/(1ll*n*(n-1));
    printf("%.6lf\n",G);
    return 0;
}