#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,ll>pi;
const int maxn=1e5+10;
vector<pi> G[maxn];
ll sum,f[maxn],ans,pre[maxn],be[maxn];
int n;
void dfs(int u,int fa){
    pi x=(pi){-1,0},y=(pi){-1,0};
    f[u]=0;
    for (auto e:G[u]){
        int v=e.F;
        if (v==fa) continue;
        dfs(v,u); pre[v]=e.S;
        ll len=f[v]+e.S;
        f[u]=max(f[u],len);
        if (len>x.S){
            y=x;
            x=(pi){v,len};
        } else if (len>y.S){
            y=(pi){v,len};
        }
        be[u]=max(be[u],be[v]);
    }
    be[u]=max(be[u],x.S+y.S);
}
void dfs2(int u,int fa,ll r,ll best){
    ans=min(ans,(sum-pre[u])*2-best-be[u]);
    pi x=(pi){-1,r},y=(pi){-1,0},z=(pi){-1,0},w=(pi){-1,0};
    pi px=(pi){-1,best},py=(pi){-1,0};
    for (auto e:G[u]){
        int v=e.F;
        if (v==fa) continue;
        ll len=f[v]+e.S;
        if (len>x.S){
            w=z; z=y; y=x;
            x=(pi){v,len};
        } else if (len>y.S){
            w=z; z=y;
            y=(pi){v,len};
        } else if (len>z.S){
            w=z;
            z=(pi){v,len};
        } else if (len>w.S){
            w=(pi){v,len};
        }
        if (be[v]>px.S){
            py=px;
            px=(pi){v,be[v]};
        } else if (be[v]>py.S){
            py=(pi){v,be[v]};
        }
    }
    ans=min(ans,sum*2-x.S-y.S-z.S-w.S);
    for (auto e:G[u]){
        int v=e.F;
        if (v==fa) continue;
        ll clen=(x.F==v)?e.S+y.S:e.S+x.S,cbest=(px.F==v)?py.S:px.S;
        if (x.F==v) cbest=max(cbest,y.S+z.S);
        else if (y.F==v) cbest=max(cbest,x.S+z.S);
        else cbest=max(cbest,x.S+y.S);
        dfs2(v,u,clen,cbest);
    }
}
int main(){
    scanf("%d",&n);
    ans=1e17;
    if (n==1){puts("0");return 0;}
    for (int i=1;i<n;i++){
        int u,v,w; scanf("%d%d%d",&u,&v,&w);
        G[u].pb((pi){v,w});
        G[v].pb((pi){u,w});
        sum+=w;
    }
    dfs(1,0);
    dfs2(1,0,0,0);
    printf("%lld\n",ans);
}