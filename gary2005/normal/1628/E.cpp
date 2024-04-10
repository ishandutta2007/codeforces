/**
 *    author:  gary
 *    created: 23.01.2022 00:00:00
**/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define rep(a,b) for(int a=0;a<b;++a)
#define LL long long
#define PB push_back
#define POB pop_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
namespace Kruskal{
    // , -1
    const int MAXN=(3e5+1)*2;// *2
    const int LG=19;
    // O(log n) LCA , by youknowwho
    vector<int> g[MAXN];
    int par[MAXN][LG + 1], dep[MAXN], sz[MAXN];
    void dfs(int u, int p = 0) {
    par[u][0] = p;
    dep[u] = dep[p] + 1;
    sz[u] = 1;
    for (int i = 1; i <= LG; i++) par[u][i] = par[par[u][i - 1]][i - 1];
    for (auto v: g[u]) if (v != p) {
        dfs(v, u);
        sz[u] += sz[v];
    }
    }
    int lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    for (int k = LG; k >= 0; k--) if (dep[par[u][k]] >= dep[v]) u = par[u][k];
    if (u == v) return u;
    for (int k = LG; k >= 0; k--) if (par[u][k] != par[v][k]) u = par[u][k], v = par[v][k];
    return par[u][0];
    }
    int kth(int u, int k) {
    assert(k >= 0);
    for (int i = 0; i <= LG; i++) if (k & (1 << i)) u = par[u][i];
    return u;
    }
    int dist(int u, int v) {
    int l = lca(u, v);
    return dep[u] + dep[v] - (dep[l] << 1);
    }
    //kth node from u to v, 0th node is u
    int go(int u, int v, int k) {
    int l = lca(u, v);
    int d = dep[u] + dep[v] - (dep[l] << 1);
    assert(k <= d);
    if (dep[l] + k <= dep[u]) return kth(u, k);
    k -= dep[u] - dep[l];
    return kth(v, dep[v] - dep[l] - k);
    }
    vector<pair<int,mp> > e;
    int fa[MAXN],dfn[MAXN],cnt,val[MAXN];
    int root(int x){
        return fa[x]=(fa[x]==x? x:root(fa[x]));
    }
    void addedge(int u,int v,int w){
        e.PB(II(w,II(u,v)));
    }
    void getdfn(int now,int pre){
        dfn[now]=++cnt;
        for(auto it:g[now]){
            if(it!=pre) getdfn(it,now);
        }
    }
    void init(int n){
        rep(i,MAXN) fa[i]=i;
        vector<mp> edg;
        rb(i,1,MAXN-1) val[i]=-1;
        sort(ALL(e));
        // reverse(ALL(e));// 
        cnt=n;
        for(auto it:e){
            int u,v;
            tie(u,v)=it.SEC;
            cnt++;
            val[cnt]=it.FIR;
            int r1,r2;
            r1=root(u);
            r2=root(v);
            fa[r1]=cnt;
            fa[r2]=cnt;
            edg.PB(II(r1,cnt));
            edg.PB(II(r2,cnt));
        }
        for(auto it:edg) g[it.FIR].PB(it.SEC),g[it.SEC].PB(it.FIR);
        int r=cnt;
        cnt=0;
        dfs(r);
        getdfn(r,0);
    }
    int getpath(int u,int v){// answer in O(logn)
        int l=lca(u,v);
        return val[l];
    }
}
using namespace Kruskal;
int n,q;
const int NN=1<<19;
mp tree[NN+NN];
mp old[NN+NN];
int tag[NN+NN];
void pu(int now){
    if(tree[now<<1].FIR==-1||tree[now<<1|1].FIR==-1){
        if(tree[now<<1].FIR==-1) tree[now]=tree[now<<1|1];
        else tree[now]=tree[now<<1];
    }
    else{
        if(dfn[tree[now<<1|1].FIR]<dfn[tree[now<<1].FIR]) tree[now].FIR=tree[now<<1|1].FIR;
        else tree[now].FIR=tree[now<<1].FIR;
        if(dfn[tree[now<<1|1].SEC]>dfn[tree[now<<1].SEC]) tree[now].SEC=tree[now<<1|1].SEC;
        else tree[now].SEC=tree[now<<1].SEC;
    }
}
void pd(int now){
    if(tag[now]!=-1){
        if(tag[now]==1){
            tree[now]=old[now];
        }
        else{
            tree[now]=II(-1,-1);
        }
        if(now<NN){
            tag[now<<1]=tag[now];
            tag[now<<1|1]=tag[now];
        }
        tag[now]=-1;
    }
}
void clr(int a,int b,int now=1,int l=1,int r=NN+1){
    pd(now);
    if(r<=a||l>=b) return ;
    if(r<=b&&l>=a){
        tag[now]=0;
        pd(now);
        return ;
    }
    int mid=(l+r)>>1;
    clr(a,b,now<<1,l,mid);
    clr(a,b,now<<1|1,mid,r);
    pu(now);
}
void add(int a,int b,int now=1,int l=1,int r=NN+1){
    pd(now);
    if(r<=a||l>=b) return ;
    if(r<=b&&l>=a){
        tag[now]=1;
        pd(now);
        return ;
    }
    int mid=(l+r)>>1;
    add(a,b,now<<1,l,mid);
    add(a,b,now<<1|1,mid,r);
    pu(now);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>q;
    rb(i,1,n-1){
        int u,v,w;
        cin>>u>>v>>w;
        addedge(u,v,w);
    }
    init(n);
    rb(i,1,NN+NN-1) tag[i]=-1;
    rb(i,1,NN){
        tree[i+NN-1]=i<=n? II(i,i):II(-1,-1);
    }
    rl(i,NN-1,1){
        pu(i);
    }
    rb(i,1,NN+NN-1) old[i]=tree[i];
    clr(1,n+1);
    rb(T,1,q){
        int t;
        cin>>t;
        if(t==1||t==2){
            int l,r;
            cin>>l>>r;
            if(t==1){
                add(l,r+1);
            }
            else{
                clr(l,r+1);
            }
        }
        else{
            int x;
            cin>>x;
            mp Tmp=tree[1];
            vector<int> V;
            if(Tmp==II(-1,-1)){
                cout<<-1<<endl;
            }
            else{
                cout<<max(getpath(x,Tmp.FIR),getpath(x,Tmp.SEC))<<endl;
            }
        }
    }
    return 0;
}