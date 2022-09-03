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
#define cpdd const pdd
#define rank Rank
#define KK 500
#define N 100005
struct Dinic{
    static const int MXN = 10000;
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
int a[2005],b[2005];
vector<int> v[2][2005];
vector<int> stk;
int op;
void dfs(int x,int f,vector<int> *v,int st,int *a){
    stk.pb(x);
    for(auto it:v[x]){
        dfs(it,x,v,st,a);
    }
    if(a[x]!=0){
        if(op){
            for(int i = 1;i<stk.size();i++)
            flow.add_edge(a[x],st+stk[i],1);
        }
        else{
            for(int i = 1;i<stk.size();i++)
            flow.add_edge(st+stk[i],a[x],1);
        }
    }
    stk.pop_back();
}
int main(){
    int n;
    scanf("%d",&n);
    int x;
    scanf("%d",&x);
    for(int i = 2;i<=x;i++){
        int aa;
        scanf("%d",&aa);
        v[0][aa].pb(i);
    }
    for(int i = 1;i<=n;i++){
        int aa;
        scanf("%d",&aa);
        a[aa]=i;
    }
    int y;
    scanf("%d",&y);
    for(int i = 2;i<=y;i++){
        int aa;
        scanf("%d",&aa);
        v[1][aa].pb(i);
    }
    for(int i = 1;i<=n;i++){
        int aa;
        scanf("%d",&aa);
        b[aa]=i;
    }
 
    flow.init(1+x+n+y+1,0,1+x+y+n);
    for(int i = 2;i<=x;i++)
    flow.add_edge(0,i+n,1);
    for(int i = 2;i<=y;i++)
    flow.add_edge(n+x+i,x+y+n+1,1);
    dfs(1,0,v[0],n,a);
    op=1;
    dfs(1,0,v[1],n+x,b);
    printf("%d\n",x+y-2-flow.flow());
}