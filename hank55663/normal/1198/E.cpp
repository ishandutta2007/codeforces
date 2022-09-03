#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define pdd pair<double,double>
#define cpdd const pdd
#define MXN 30005
#define next Next
#define index Index
struct Dinic{
    struct Edge{ int v,f,re; Edge(int a,int b,int c):v(a),f(b),re(c){}};
    int n,s,t,level[MXN];
    vector<Edge> E[MXN];
    void init(int _n, int _s, int _t){
        n = _n; s = _s; t = _t;
        for (int i=0; i<=n; i++) E[i].clear();
    }
    void add_edge(int u, int v, int f){
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
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    pair<pii,pii> p[55];
    map<int,int> x,y;
    int valx[500],valy[500];
    for(int i = 0;i<m;i++){
        int x1,y1,x2,y2;
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        p[i]=mp(mp(x1,x2+1),mp(y1,y2+1));
        x[x1];x[x2+1];
        y[y1];y[y2+1];
    }
    int last=0,indexx=0;
    for(auto& it:x){
        valx[indexx]=it.x-last;
        indexx++;
        it.y=indexx;
        last=it.x;
    }
    int indexy=0;
    last=0;
    for(auto &it:y){
        valy[indexy]=it.x-last;
        indexy++;
        it.y=indexy;
        last=it.x;
    }
    flow.init(indexx+indexy+10,0,indexx+indexy+1);
    for(int i = 1;i<indexx;i++){
        flow.add_edge(0,i,valx[i]);
    }
    for(int i = 1;i<indexy;i++){
        flow.add_edge(indexx+i,indexx+indexy+1,valy[i]);
    }
    for(int i = 0;i<m;i++){
        int l1=x[p[i].x.x],r1=x[p[i].x.y];
        int l2=y[p[i].y.x],r2=y[p[i].y.y];
        for(int j = l1;j<r1;j++){
            for(int  k=l2;k<r2;k++){
                flow.add_edge(j,k+indexx,1e9);
            }
        }
    }
    printf("%d\n",flow.flow());
}
/*

100
2 3
0 500000000 1000000000
1000000000 1000000000 1000000000
 */