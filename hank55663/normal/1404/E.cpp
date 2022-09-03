#include<bits/stdc++.h>

/*#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
#define mp make_pair
#define pb push_back
#define pll pair<LL,LL>
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
struct Dinic{
    static const int MXN = 200000;
    struct Edge{ int v,f,re; Edge(int a,int b,int c):v(a),f(b),re(c){}};
    int n,s,t,level[MXN];
    vector<Edge> E[MXN];
    void init(int _n, int _s, int _t){
        n = _n; s = _s; t = _t;
        for (int i=0; i<=n; i++) E[i].clear();
    }
    void add_edge(int u, int v, int f){
     //   printf("%d %d\n",u,v);
        E[u].pb(Edge(v,f,E[v].size()));
        E[v].pb(Edge(u,0,E[u].size()-1));//direct
    }
    bool BFS(){
        MEMS(level);
        queue<int> que;
        que.push(s);
        level[s] = 0;
        while (!que.empty()){
            int u = que.front(); que.pop();
            for (auto it : E[u]){
                if (it.f > 0 && level[it.v] == -1){
                    level[it.v] = level[u]+1;
                    que.push(it.v);
                }
            }
        }
        return level[t] != -1;
    }
    int DFS(int u, int nf){
        if (u == t) return nf;
        int res = 0;
        for (auto &it : E[u]){
            if (it.f > 0 && level[it.v] == level[u]+1){
                int tf = DFS(it.v, min(nf,it.f));
                res += tf; nf -= tf; it.f -= tf;
                E[it.v][it.re].f += tf;
                if (nf == 0) return res;
            }
        }
        if (!res) level[u] = -1;
        return res;
    }
    int flow(int res=0){
        while ( BFS() )
        res += DFS(s,2147483647);
        return res;
    }
}flow;

void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    flow.init(1+(n+1)*m+n*(m+1)+n*m+1,0,1+(n+1)*m+n*(m+1)+n*m);
    char c[205][205];
    MEM(c);
    for(int i = 1;i<=n;i++)scanf("%s",c[i]+1);
    int tot=0;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            if(c[i][j]=='#')tot++;
        }
    }
    for(int i = 1;i<=(n+1)*m;i++)flow.add_edge(0,i,1);
    /*for(int i = 1;i<=n*(m+1);i++){
        
        flow.add_edge((n+1)*m+i,1+(n+1)*m+n*(m+1)+n*m,1);
    }*/
  //  printf("?\n");
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            if(c[i][j]=='#'&&c[i+1][j]=='#'){
                tot--;
               // printf("!! %d %d\n",i,j);
                flow.add_edge(i*m+j,(n+1)*m+j*n+i,1e9);
                flow.add_edge(i*m+j,(n+1)*m+j*n+i+1,1e9);
                flow.add_edge(i*m+j,(n+1)*m+(j-1)*n+i,1e9);
                flow.add_edge(i*m+j,(n+1)*m+(j-1)*n+i+1,1e9);
            }
            if(c[i][j]=='#'&&c[i][j+1]=='#'){
                tot--;
                flow.add_edge((n+1)*m+j*n+i,1+(n+1)*m+n*(m+1)+n*m,1);
                //printf("??%d %d\n",i,j);
                //flow.add_edge((i)*m+j,(n+1)*m+(j-1)*n+i,1);
            }
        }
    }
    printf("%d\n",tot+flow.flow());
}
int main(){
    int t=1;
    //scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*
100
5
5 4
4 2
4 2 3
5 4 2 3 1
*/