#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int maxn=6e5+10;
typedef long long ll;
ll a[maxn],b[maxn];
int n,_,l[maxn],r[maxn],id[maxn],cc,res,ans;
vector<int> F[maxn],G[maxn];
void dfs(int u){
    l[u]=++cc; id[cc]=u;
    for (auto v:G[u]) dfs(v);
    r[u]=cc;
}
void add1(int x,ll y){while (x<maxn) a[x]+=y,x+=x&(-x);}
void add2(int x,ll y){while (x<maxn) b[x]+=y,x+=x&(-x);}
ll qry1(int x){int ret=0;while (x) ret+=a[x],x-=x&(-x);return ret;}
ll qry2(int x){int ret=0;while (x) ret+=b[x],x-=x&(-x);return ret;}
ll qry(int x){return qry1(x)*x+qry2(x);}
void f(int l,int r,ll val){
    add1(l,val); add1(r,-val);
    add2(r,val*r);
    add2(l,-val*(l-1));
}
void add(int x){res++;f(l[x],r[x],x);}
void del(int x){res--;f(l[x],r[x],-x);}
ll gs(int l,int r){return qry(r)-qry(l-1);}
void dfs2(int u){
    int x=0,y=0;
    ll sum=gs(l[u],r[u]),self=gs(l[u],l[u]);
    if (!sum){
        x=u;
    } else if (self){
        x=u; y=self;
    }
    if (x) add(x);
    if (y) del(y);
    ans=max(ans,res);
    for (auto v:F[u]) dfs2(v);
    if (x) del(x);
    if (y) add(y);
}
void solve(){
    ans=0;
    scanf("%d",&n);
    for (int i=1;i<=n;i++) F[i].clear(),G[i].clear();
    for (int i=2;i<=n;i++){
        int x;scanf("%d",&x);
        F[x].pb(i);
    }
    for (int i=2;i<=n;i++){
        int x;scanf("%d",&x);
        G[x].pb(i);
    }
    cc=0; dfs(1);
    dfs2(1);
    printf("%d\n",ans);
}
int main(){
    scanf("%d",&_);
    while (_--){
        solve();
    }
    return 0;
}