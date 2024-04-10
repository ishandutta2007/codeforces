/**
 *    author:  gary
 *    created: 23.05.2022 22:32:11
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
const int N=1<<19;
const int MAXN=5e5+10;
int fa[MAXN],siz[MAXN];
int root(int x){
    return (fa[x]==x? x:root(fa[x]));
}
vector<pair<int,mp > > mem;
void merge(int u,int v){
    u=root(u);
    v=root(v);
    assert(u!=v);
    if(siz[u]>siz[v]) swap(u,v);
    mem.PB(II(u,II(fa[u],siz[u])));
    mem.PB(II(v,II(fa[v],siz[v])));
    fa[u]=v;
    siz[v]+=siz[u];
}
void undo(){
    int x=mem.back().first;
    fa[x]=mem.back().second.first;
    siz[x]=mem.back().second.second;
    mem.pop_back();
    x=mem.back().first;
    fa[x]=mem.back().second.first;
    siz[x]=mem.back().second.second;
    mem.pop_back();
}
vector<mp> tree[N+N];
void insert(int a,int b,mp x,int now=1,int l=1,int r=N+1){
    if(r<=a||l>=b) return ;
    if(r<=b&&l>=a){
        tree[now].PB(x);
        return ;
    }
    int mid=(l+r)>>1;
    insert(a,b,x,now<<1,l,mid);
    insert(a,b,x,now<<1|1,mid,r);
}
LL ans=0;
vector<mp> Edge[MAXN];
int n;
void dfs(int now=1,int l=1,int r=N+1){
    for(auto it:tree[now]){
        merge(it.first,it.second);
    }
    if(l==r-1){
        if(l<=n)
        for(auto it:Edge[l]){
            ans+=1ll*siz[root(it.first)]*siz[root(it.second)];
        }
    }
    else{
        int mid=(l+r)>>1;
        dfs(now<<1,l,mid);
        dfs(now<<1|1,mid,r);
    }
    for(auto it:tree[now]){
        undo();
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    rb(i,1,n) fa[i]=i,siz[i]=1;
    rb(i,1,n-1){
        int u,v,c;
        cin>>u>>v>>c;
        Edge[c].PB(II(u,v));
        if(c!=1) insert(1,c,II(u,v));
        if(c!=n) insert(c+1,n+1,II(u,v));
    }
    dfs();
    cout<<ans<<endl;
    return 0;
}