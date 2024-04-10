/**
 *    author:  gary
 *    created: 22.02.2022 21:04:20
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
const int MAXN=3e5+20;
int n,m,dep[MAXN],fa[MAXN][19],cf[MAXN],mxdep[MAXN];
vector<int> g[MAXN];
void init(int now,int pre=0){
    fa[now][0]=pre;
    rb(i,1,18) fa[now][i]=fa[fa[now][i-1]][i-1];
    for(auto it:g[now]) dep[it]=dep[now]+1,init(it,now);
}
int jump(int now,int k){
    rep(i,19) if((k>>i)&1) now=fa[now][i];
    return now;
}
int lca(int u,int v){
    if(dep[u]>dep[v]) u=jump(u,dep[u]-dep[v]);
    else v=jump(v,dep[v]-dep[u]);
    if(u==v) return u;
    rl(i,18,0) if(fa[u][i]!=fa[v][i]) u=fa[u][i],v=fa[v][i];
    return fa[u][0];
}
pair<int,bool> dfs(int now){
    int cnt=0;
    vector<pair<int,bool> > v;
    for(auto it:g[now]){
        auto tmp=dfs(it);
        cnt+=tmp.second;
        v.PB(tmp);
    }
    int mx=-INF;
    if(cnt>=2) v.clear();
    else
    if(cnt==1){
        pair<int,bool> gg;
        for(auto it:v) if(it.second) gg=it;
        mx=gg.first;
    }
    else
    for(auto it:v) check_max(mx,it.first);
    bool cho=(cnt!=0);
    if(mx==dep[now]-1){
        cf[now]=1;
        mx=-INF;
        cho=1;
    }
    check_max(mx,mxdep[now]);
    if(mx==dep[now]-1){
        cout<<"-1"<<endl;
        exit(0);
    }
    // cout<<now<<' '<<mx<<' '<<cho<<endl;
    return II(mx,cho);
}
void dfs2(int now){
    for(auto it:g[now]){
        dfs2(it);
        cf[now]+=cf[it];
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    rb(i,2,n){
        int par;
        cin>>par;
        g[par].PB(i);
    }
    init(1);
    vector<mp> ano;
    rb(i,1,n) mxdep[i]=-INF;
    rb(i,1,m){
        int u,v;
        cin>>u>>v;
        int l=lca(u,v);
        if(l==v) swap(u,v);
        // cout<<u<<' '<<v<<' '<<l<<endl;
        if(l!=u){
            ano.PB(II(u,v));
        }
        else{
            check_max(mxdep[v],dep[u]);
        }
    }
    dfs(1);
    dfs2(1);
    int answer=cf[1];
    bool ok=1;
    for(auto it:ano){
        ok&=cf[1]!=(cf[it.first]+cf[it.second]);
    }
    cout<<answer+(!ok)<<endl;
    return 0;
}