#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const int M=998244353;
const int maxn=160000;
const int E=160;
vector <int> h[maxn],G[maxn];
int n,inv,q,a[maxn],Fa[maxn],fa[maxn],sz[maxn],L[maxn],R[maxn],id[maxn],tot,re,val[maxn],ans;
void add(int &x,int y){x+=y;if (x>=M)x-=M;}
void sub(int &x,int y){x-=y;if (x<0) x+=M;}
void dfs(int u,int w){
    fa[u]=w;
    for (auto v:h[u]){
        if (v==w) continue;
        G[u].pb(v); dfs(v,u);
    }
}
void dfs2(int u){
    id[u]=++tot;
    L[u]=tot; sz[u]=1;
    for (auto v:G[u]){
        if (G[u].size()>E) Fa[v]=v;
        else Fa[v]=Fa[u];
        dfs2(v); sz[u]+=sz[v];
    }
    R[u]=tot;
}
void work(int x,int v){while (x<maxn) add(a[x],v),x+=x&(-x);}
int qry(int x){int ret=0;while (x) add(ret,a[x]),x-=x&(-x);return ret;}
int pow_(int x,int y){int ret=1;while (y){if (y&1) ret=1ll*ret*x%M;x=1ll*x*x%M;y>>=1;}return ret;}
void Add(int l,int r,int v){
    work(l,v);
    work(r+1,M-v);
}
void Sub(int l,int r,int v){
    work(l,M-v);
    work(r+1,v);
}
int main(){
    scanf("%d%d",&n,&q);
    for (int i=1;i<n;i++){
        int u,v;scanf("%d%d",&u,&v);
        h[u].pb(v); h[v].pb(u);
    }
    dfs(1,0);
    Fa[1]=0; tot=0; dfs2(1);
    inv=pow_(n,M-2);
    while (q--){
        int tp; scanf("%d",&tp);
        if (tp==1){
            int u,d; scanf("%d%d",&u,&d);
            add(re,d);
            Sub(1,n,1ll*(n-sz[u])*d%M);
            Add(L[u],R[u],1ll*(n-sz[u])*d%M);
            if (G[u].size()>E) add(val[u],d);
            else for (auto v:G[u]) {
                Sub(L[v],R[v],1ll*sz[v]*d%M);
            }
        } else {
            int u; scanf("%d",&u);
            int ret=qry(id[u]);
            while (Fa[u]){
                u=Fa[u];
                sub(ret,1ll*val[fa[u]]*sz[u]%M);
                u=fa[u];
            }
            ans=re; add(ans,1ll*ret*inv%M);
            printf("%d\n",ans);
        }
    }
    return 0;
}