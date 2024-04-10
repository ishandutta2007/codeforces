#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define last Last
#define MXN 200005
struct Scc{
    int n, nScc, vst[MXN], bln[MXN];
    vector<int> E[MXN], rE[MXN], vec;
    void init(int _n){
        n = _n;
        for (int i=0; i<MXN; i++){
            E[i].clear();
            rE[i].clear();
        }
    }
    void add_edge(int u, int v){
        E[u].pb(v);
        rE[v].pb(u);
    }
    void DFS(int u){
        vst[u]=1;
        for (auto v : E[u])
        if (!vst[v]) DFS(v);
        vec.pb(u);
    }
    void rDFS(int u){
        vst[u] = 1;
        bln[u] = nScc;
        for (auto v : rE[u])
        if (!vst[v]) rDFS(v);
    }
    void solve(){
        nScc = 0;
        vec.clear();
        MEM(vst);
        for (int i=1; i<=n; i++)
        if (!vst[i]) DFS(i);
        reverse(vec.begin(),vec.end());
        MEM(vst);
        for (auto v : vec){
            if (!vst[v]){
                rDFS(v);
                nScc++;
            }
        }
    }
}g;
vector<pii> v[200005],rv[200005];
int vis[200005];
int rvis[200005];
int vis3[200005];
LL dis[200005];
LL rdis[200005];
LL ans[200005];
int f[200005];
void dfs(int x){
    vis[x]=1;
    for(auto it:v[x]){
        if(!vis[it.x]){
            dis[it.x]=dis[x]+it.y;
            dfs(it.x);
        }
    }
}
void rdfs(int x){
    rvis[x]=1;
    for(auto it:rv[x]){
        if(!rvis[it.x]){
            rdis[it.x]=rdis[x]+it.y;
            rdfs(it.x);
        }
    }
}
void dfs3(int x,int s){
    f[x]=s;
    vis3[x]=1;
    for(auto it:v[x]){
      //  printf("%d\n",dis[x]+rdis[it.x]+it.y);
        ans[s]=__gcd(ans[s],dis[x]+rdis[it.x]+it.y);
        if(!vis3[it.x]){
            dfs3(it.x,s);
        }
    }
}
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    g.init(n);
    pair<pii,int> p[200005];
    for(int i = 0;i<m;i++){
        int x,y,l;
        scanf("%d %d %d",&x,&y,&l);
        p[i]=mp(mp(x,y),l);
        g.add_edge(x,y);
    }
    g.solve();
    for(int i = 0;i<m;i++){
        if(g.bln[p[i].x.x]==g.bln[p[i].x.y]){
            v[p[i].x.x].pb(mp(p[i].x.y,p[i].y));
            rv[p[i].x.y].pb(mp(p[i].x.x,p[i].y));
        }
    }
    for(int i = 1;i<=n;i++){
        if(!vis[i]){
            dfs(i);
            rdfs(i);
            dfs3(i,i);
        //    printf("%d\n",ans[i]);
        }
    }
    int q;
    scanf("%d",&q);
    while(q--){
        int v,s,t;
        scanf("%d %d %d",&v,&s,&t);
        int gcd=__gcd(s,t);
        gcd=__gcd(gcd*1ll,ans[f[v]]);
        //t/=gcd;
        //t/=gcd;
        if(__gcd(t*1ll,ans[f[v]])==gcd){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
}
int main(){
  //  for(int i = 1;i*i<=1e9;i++)s.insert(i*i);
    int t=1;00000;
   // scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*
36
6x+s=ty
x x<<13  x>>7  x<<13>>7
x<<17  x<<30 x>>7<<17 x<<23

*/