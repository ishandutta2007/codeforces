/**
 *    author:  gary
 *    created: 18.02.2022 18:43:32
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
const int MAXN=4e5+1;
int n,k,r;
bool rest[MAXN];
int app[MAXN],dist[MAXN];
int fa[MAXN],newid[MAXN],newrest[MAXN];
int root(int x){
    return fa[x]=(fa[x]==x? x:root(fa[x]));
}
struct TREE{
    int fa[MAXN][19],heavy[MAXN],siz[MAXN],dfn[MAXN],tp[MAXN],dep[MAXN];
    int cnt;
    TREE(){
        memset(fa,0,sizeof(fa));
        memset(heavy,0,sizeof(heavy));
        memset(siz,0,sizeof(siz));
        memset(dfn,0,sizeof(dfn));
        memset(tp,0,sizeof(tp));
        memset(dep,0,sizeof(dep));
        cnt=0;
    }
    vector<int> g[MAXN];
    map<mp,bool> added;
    void addedge(int u,int v){
        if(u==v) return ;
        if(added.find(II(u,v))!=added.end()) return ;
        // cout<<u<<' '<<v<<endl;
        added[II(u,v)]=added[II(v,u)]=1;
        g[u].PB(v);
        g[v].PB(u);
    }
    void init1(int now,int pre){
        siz[now]=1;
        fa[now][0]=pre;
        rb(j,1,18) fa[now][j]=fa[fa[now][j-1]][j-1];
        for(auto it:g[now]) if(it!=pre) dep[it]=dep[now]+1,init1(it,now),siz[now]+=siz[it];
        for(auto it:g[now]) if(it!=pre&&siz[it]>siz[heavy[now]]) heavy[now]=it;
    }
    void init2(int now,int pre){
        dfn[now]=++cnt;
        if(!heavy[now]) return ;
        tp[heavy[now]]=tp[now];
        init2(heavy[now],now);
        for(auto it:g[now]) if(it!=pre&&it!=heavy[now]) tp[it]=it,init2(it,now);
    }
    int jump(int now,int k){
        rep(j,19) if((k>>j)&1) now=fa[now][j];
        return now;
    }
    int lca(int u,int v){
        if(dep[u]<dep[v]) swap(u,v);
        u=jump(u,dep[u]-dep[v]);
        if(u==v) return u;
        rl(i,18,0) if(fa[u][i]!=fa[v][i]) u=fa[u][i],v=fa[v][i];
        return fa[u][0];
    }
    void init(int root){
        tp[root]=root;
        init1(root,0);
        init2(root,0);
    }
}old;
int main(){
    scanf("%d%d%d",&n,&k,&r);
    k*=2;
    rb(i,1,n-1){
        int u,v;
        scanf("%d%d",&u,&v);
        old.addedge(u,n+i);
        old.addedge(v,n+i);
    }
    n+=n-1;
    rb(i,1,n) fa[i]=i;
    rb(i,1,r){
        int ai;
        scanf("%d",&ai);
        rest[ai]=1;
    }
    queue<int> q;
    memset(dist,63,sizeof(dist));
    rb(i,1,n) if(rest[i]) q.push(i),dist[i]=0,app[i]=i;
    map<mp,int> era;
    while(!q.empty()){
        int now=q.front();
        q.pop();
        if(dist[now]==k/2) continue;
        for(auto it:old.g[now]){
            if(dist[it]==INF){
                dist[it]=dist[now]+1;
                app[it]=app[now];
                q.push(it);
            }
            else{
                if(app[it]==app[now]) continue;
                assert((dist[it]-dist[now])<=1);
                if(root(app[it])==root(app[now])) continue;
                era[II(it,now)]=era[II(now,it)]=1;
                fa[root(app[it])]=root(app[now]);
            }
        }
    }
    old.init(1);
    int Q;
    cin>>Q;

    while(Q--){
        int u,v;
        scanf("%d%d",&u,&v);
        int l;
        l=old.lca(u,v);
        if(old.dep[u]-old.dep[l]*2+old.dep[v]<=k){
            puts("YES");
            continue;
        }
        int L1,L2,L;
        L1=old.dep[u]-old.dep[l];
        L2=old.dep[v]-old.dep[l];
        L=L1+L2;
        if(L1<L2){
            swap(L1,L2);
            swap(u,v);
        }
        if(L2>=k/2) v=old.jump(v,k/2);
        else v=old.jump(u,L-k/2);
        u=old.jump(u,k/2);
        if(app[u]&&app[v]&&root(app[u])==root(app[v])){
            puts("YES");
            continue;
        }
        puts("NO");
    }
    return 0;
}