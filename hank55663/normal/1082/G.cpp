#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<assert.h>
#include<map>
#include<set>
#include<utility>
#include<iostream>
#include<cmath>
#include<sstream>
#include<queue>
#include<bitset>
#define LL long long 
#define pll pair<LL,LL>
#define pii pair<int,int> 
#define pdd pair<double,double>
#define cpdd const pdd
#define pb push_back
#define sqr(x) ((x)*(x))
#define mp make_pair
#define x first
#define y second
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
#define search Search
#define index Index
#define transform Transform
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define Line pll
#define EPS 1e-12
struct Dinic{
    static const int MXN = 10000;
    struct Edge{ LL v,f,re; Edge(LL a,LL b,LL c):v(a),f(b),re(c){}};
    int n,s,t,level[MXN];
    vector<Edge> E[MXN];
    void init(int _n, int _s, int _t){
        n = _n; s = _s; t = _t;
        for (int i=0; i<=n; i++) E[i].clear();
    }
    void add_edge(int u, int v, LL f){
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
    LL DFS(int u, LL nf){
        if (u == t) return nf;
        LL res = 0;
        for (auto &it : E[u]){
            if (it.f > 0 && level[it.v] == level[u]+1){
                LL tf = DFS(it.v, min(nf,it.f));
                res += tf; nf -= tf; it.f -= tf;
                E[it.v][it.re].f += tf;
                if (nf == 0) return res;
            }
        }
        if (!res) level[u] = -1;
        return res;
    }
    LL flow(LL res=0){
        while ( BFS() )
        res += DFS(s,1e18);
        return res;
    }
}flow;
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    flow.init(n+m+2,0,n+m+1);
    for(int i=1;i<=n;i++){
        int a;
        scanf("%d",&a);
        flow.add_edge(0,i,a);
    }
    LL ans=0;
    for(int i=1;i<=m;i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        flow.add_edge(a,i+n,1e18);
        flow.add_edge(b,i+n,1e18);
        flow.add_edge(i+n,n+m+1,c);
        ans+=c;
    }
    printf("%lld\n",ans-flow.flow());
}