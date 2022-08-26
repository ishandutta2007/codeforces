#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int>pi;
const int maxn=1e6+10;
const int M=998244353;
vector<pi> G[2][maxn];
bool V[maxn];
int n,m,d[2][maxn],cnt[2],X[maxn],Y[maxn],W[maxn],last,Ans,dc[maxn];
int to[2][maxn],op[2][maxn],dir[2][maxn],id[2][maxn],ans[maxn];
struct edge{
    int u,v,id;
};
vector<edge> E[2][maxn];
bool vis[maxn],flag;
void dfs(int p,int u){
    bool o=0;
    for (auto e:G[p][u]){
        if (vis[e.S]) continue;
        int v=e.F;
        vis[e.S]=1; d[p][u]^=1; d[p][v]^=1; dfs(p,v);
        o=1; E[p][cnt[p]].pb((edge){u,v,e.S});
        if (flag) break;
    }
    if (!o) last=u,flag=1;
}
void dfs0(int p,int u){
    for (auto e:G[p][u]){
        if (vis[e.S]) continue;
        int v=e.F;
        vis[e.S]=1; d[p][u]^=1; d[p][v]^=1; dfs0(p,v);
        if (u==X[e.S]) ans[e.S]=1; else ans[e.S]=2;
    }
}
void Dfs(int p,int u){
    if (V[u]) return; V[u]=1;
    if (!to[p][u]) return;
    dir[p][id[p][u]]=op[p][u];
    Dfs(p^1,to[p][u]);
}
void Dfs2(int p,int u){
    if (!to[p][u]) return;
    dir[p][id[p][u]]=op[p][u]^1;
    if (!V[to[p][u]]) Dfs2(p^1,to[p][u]);
}
void _fill(int p,int x,int o){
    for (auto e:E[p][x]){
        if ((!o)^(e.u==X[e.id])) ans[e.id]=1; else ans[e.id]=2;
    }
}
mt19937_64 gen(19260817);
int main(){
    cin >> n >> m;
    for (int i=1;i<=m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        /*
        while (1){
            u=gen()%n+1;
            v=gen()%n+1;
            w=gen()%2+1;
            if (u!=v) break;
        }
        */
        X[i]=u; Y[i]=v; W[i]=w;
        G[w-1][u].pb((pi){v,i});
        G[w-1][v].pb((pi){u,i});
        d[w-1][u]^=1; d[w-1][v]^=1;
    }
    for (int p=0;p<=1;p++){
        for (int i=1;i<=n;i++) if (d[p][i]){
            flag=0; cnt[p]++; dfs(p,i);
            if (p==0) Ans+=2;
            reverse(E[p][cnt[p]].begin(),E[p][cnt[p]].end());
            int m=E[p][cnt[p]].size();
            int j=last;
            id[p][i]=id[p][j]=cnt[p];
            to[p][i]=j; op[p][i]=0;
            to[p][j]=i; op[p][j]=1;
        }
        for (int i=1;i<=n;i++) dfs0(p,i);
    }
    memset(dir,-1,sizeof(dir));
    for (int i=1;i<=n;i++) if (to[0][i]&&!V[i]){
        int k=id[0][i];
        if (dir[0][k]!=-1) continue;
        Dfs(0,i);
        Dfs2(1,i);
        if (to[1][i]) dir[1][id[1][i]]=op[1][i]^1;
    }
    for (int p=0;p<=1;p++)
    for (int i=1;i<=cnt[p];i++){
        if (dir[p][i]==-1) dir[p][i]=0;
        _fill(p,i,dir[p][i]);
    }
    cout << Ans << endl;
    for (int i=1;i<=m;i++) printf("%d",ans[i]); puts("");

    for (int i=1;i<=m;i++){
        if (ans[i]==1) dc[X[i]]+=W[i],dc[Y[i]]-=W[i];
        else if (ans[i]==2) dc[X[i]]-=W[i],dc[Y[i]]+=W[i];
    }
    for (int i=1;i<=n;i++) assert(abs(dc[i])<=2);
    return 0;
}