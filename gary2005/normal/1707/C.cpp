/**
 *    author:  gary
 *    created: 16.07.2022 22:28:40
**/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=(b);a<=(c);++a)
#define rl(a,b,c) for(int a=(b);a>=(c);--a)
#define rep(a,b) for(int a=0;a<(b);++a)
#define LL long long
#define II(a,b) make_pair(a,b)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
const int MAXN=1e5+20;
int n,m;
int fa[MAXN],dfn[MAXN],siz[MAXN],cnt,cf[MAXN],jump[MAXN][17],depth[MAXN],up[MAXN];
vector<mp> g[MAXN];
int root(int x){
    return fa[x]=(fa[x]==x? x:root(fa[x]));
}
void dfs1(int now,int pre){
    jump[now][0]=pre;
    rb(i,1,16) jump[now][i]=jump[jump[now][i-1]][i-1];
    dfn[now]=++cnt;
    siz[now]=1;
    for(auto it:g[now]) if(it.first!=pre){
        depth[it.first]=depth[now]+1;
        up[it.first]=it.second;
        dfs1(it.first,now);
        siz[now]+=siz[it.first];
    }
}
bool isanc(int u,int v){
    return dfn[v]<=dfn[u]+siz[u]-1&&dfn[v]>=dfn[u];
}
void dfs2(int now,int pre){
    for(auto it:g[now]) if(it.first!=pre) {
        cf[it.first]+=cf[now];
        dfs2(it.first,now);
        // cf[now]+=cf[it.first];
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    rb(i,1,n) fa[i]=i;
    vector<mp> edges;
    rb(i,1,m){
        int u,v;
        cin>>u>>v;
        edges.emplace_back(u,v);
    }
    vector<pair<mp,int> > nottree;
    int id=0;
    for(auto it:edges){
        if(root(it.first)!=root(it.second)){
            g[it.first].emplace_back(it.second,++id);
            g[it.second].emplace_back(it.first,id);
            fa[root(it.first)]=root(it.second);
        }
        else{
            nottree.emplace_back(II(it.first,it.second),++id);
        }
    }
    dfs1(1,0);
    for(auto it:nottree){
        int w,u,v;
        u=it.first.first;
        v=it.first.second;
        w=it.second;
        if(depth[v]<depth[u]){
            swap(u,v);
        }
        if(isanc(u,v)){
            if(up[v]<w)
            cf[v]++;
            rl(i,16,0) if(jump[v][i]&&depth[jump[v][i]]>depth[u]) v=jump[v][i];
            if(up[v]<w){
                cf[1]++;
                cf[v]--;
            }
        }
        else{
            // cout<<u<<" "<<v<<" "<<w<<" "<<up[u]<<" "<<up[v]<<endl;
            if(up[v]<w) cf[v]++;
            if(up[u]<w) cf[u]++;
        }
    }
    dfs2(1,0);
    rb(i,1,n){
        cout<<(cf[i]==nottree.size());
    }
    return 0;
}