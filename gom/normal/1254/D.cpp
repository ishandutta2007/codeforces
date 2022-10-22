#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<db,db> pdb;
typedef tuple<int,int,int> tii;
typedef tuple<ll,ll,ll> tll;
typedef vector<vector<ll>> mat;
const ll mod=998244353;
const int N=2e5+5;
struct seg{
    ll tree[4*N]={0},lazy[4*N]={0};
    void pushdown(int nd,int l,int r){
        tree[nd]+=lazy[nd]*((ll)r-l+1);
        if(l!=r){
            lazy[nd<<1]+=lazy[nd];
            lazy[nd<<1|1]+=lazy[nd];
        }
        lazy[nd]=0;
    }
    void add(int nd,int l,int r,int s,int e,ll v){
        pushdown(nd,l,r);
        if(r<s||e<l) return;
        if(s<=l&&r<=e){
            lazy[nd]+=v;
            pushdown(nd,l,r);
            return;
        }
        int m=(l+r)>>1;
        add(nd<<1,l,m,s,e,v); add(nd<<1|1,m+1,r,s,e,v);
        tree[nd]=tree[nd<<1]+tree[nd<<1|1];
    }
    ll qry(int nd,int l,int r,int s,int e){
        pushdown(nd,l,r);
        if(r<s||e<l) return 0;
        if(s<=l&&r<=e) return tree[nd];
        int m=(l+r)>>1;
        return (qry(nd<<1,l,m,s,e)+qry(nd<<1|1,m+1,r,s,e))%mod;
    }
}t1,t2;
ll q,p[N],in[N],out[N],sz[N],curOdr;
int head[N],grp[N],nxt[N],curClr;
ll n,invn,cnt[N],sum;
vector<int> g[N],c[N];
ll ipow(ll a,ll b){
    if(!b) return 1;
    ll tmp=ipow(a,b>>1);
    if(b&1) return tmp*tmp%mod*a%mod;
    return tmp*tmp%mod;
}
void dfs(int u,int par)
{
    sz[u]=1;
    for(auto &it : g[u]) if(it!=par){
        p[it]=u;
        dfs(it,u);
        sz[u]+=sz[it];
        c[u].emplace_back(it);
    }
}
void dfs2(int u,int clr){
    in[u]=++curOdr; grp[u]=clr;
    for(auto &it : c[u]) if(sz[it]>sz[c[u][0]]) swap(it,c[u][0]);
    if(c[u].size()){
        nxt[u]=c[u][0];
        dfs2(c[u][0],clr);
    }
    for(auto &it : c[u]) if(it!=c[u][0]){
        head[++curClr]=it;
        dfs2(it,curClr);
    }
    out[u]=curOdr;
}
void Do(int v,ll d){
    (sum+=sz[v]*d%mod*invn%mod)%=mod;
    (cnt[v]+=d)%=mod;
    t1.add(1,1,n,in[v],out[v],sz[v]*d%mod*invn%mod);
    if(nxt[v]) t2.add(1,1,n,in[nxt[v]],in[nxt[v]],(n-sz[nxt[v]]+mod)%mod*invn%mod*d%mod);
}
ll Get(int v)
{
    ll res=sum;
    res=(res+cnt[v]-t1.qry(1,1,n,in[v],in[v])+mod)%mod;
    while(v){
        int u=head[grp[v]];
        res=(res+t2.qry(1,1,n,in[u],in[v]))%mod;
        res=(res+cnt[p[u]]*(n-sz[u]+mod)%mod*invn%mod)%mod;
        v=p[u];
    }
    return res;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
	cin>>n>>q; invn=ipow(n,mod-2);
    for(int u,v,i=1;i<n;i++){
        cin>>u>>v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs(1,0); curClr=1; head[1]=1; dfs2(1,1);
    for(int c,v,d,i=1;i<=q;i++){
        cin>>c;
        if(c==1){
            cin>>v>>d;
            Do(v,d);
        }
        if(c==2){
            cin>>v;
            cout<<Get(v)<<"\n";
        }
    }
    return 0;
}