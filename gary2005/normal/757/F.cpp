/**
 *    author:  gary
 *    created: 11.06.2022 13:29:33
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
const int MAXN=2e5+20;
int n,m,s;
LL dist[MAXN];
vector<mp> g[MAXN];
vector<int> tree[MAXN],ztree[MAXN];
vector<int> fas[MAXN];
int depth[MAXN];
int siz[MAXN],fa[MAXN][18];
int lca(int u,int v){
    if(depth[u]<depth[v]) swap(u,v);
    int d=depth[u]-depth[v];
    rep(j,18) if((d>>j)&1) u=fa[u][j];
    if(u==v) return u;
    rl(j,17,0) if(fa[u][j]!=fa[v][j]){u=fa[u][j],v=fa[v][j];}
    return fa[u][0];
}
void dfs2(int now){
    siz[now]=1;
    for(auto it:ztree[now]) dfs2(it),siz[now]+=siz[it];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>s;
    vector<pair<mp,int> > edges;
    rb(i,1,m){
        int u,v,w;
        cin>>u>>v>>w;
        edges.PB(II(II(u,v),w));
        g[u].PB(II(v,w));
        g[v].PB(II(u,w));
    }
    rb(i,1,n) dist[i]=1e18;
    dist[s]=0;
    priority_queue<pair<LL,int> ,vector<pair<LL,int> > ,greater<pair<LL,int> > > heap;
    heap.push(II(0,s));
    while (!heap.empty())
    {
        auto now=heap.top();
        if(now.first!=dist[now.second]){
            heap.pop();
            continue;
        }
        int v=now.second;
        heap.pop();
        for(auto it:g[v]) if(dist[it.first]>dist[v]+it.second){
            dist[it.first]=dist[v]+it.second;
            heap.push(II(dist[it.first],it.first));
        }
    }
    rb(i,1,n) if(dist[i]!=1e18&&i!=s){
        for(auto it:g[i]) if(dist[it.first]+it.second==dist[i]){
            tree[it.first].PB(i);
            break;
        }
        for(auto it:g[i]) if(dist[it.first]+it.second==dist[i]){
            fas[i].PB(it.first);
        }
    }
    for(auto it:tree[s]) heap.push(II(dist[it],it));
    while (!heap.empty()){
        int now=heap.top().second;
        heap.pop();
        int A=fas[now][0];
        for(auto it:fas[now]) A=lca(A,it);
        fa[now][0]=A;
        rb(j,1,17) fa[now][j]=fa[fa[now][j-1]][j-1];
        depth[now]=depth[A]+1;
        ztree[A].PB(now);
        for(auto it:tree[now]){
            heap.push(II(dist[it],it));
        }
    }
    dfs2(s);
    int ans=0;
    rb(i,1,n) if(i!=s) check_max(ans,siz[i]);
    cout<<ans<<endl;
    return 0;
}