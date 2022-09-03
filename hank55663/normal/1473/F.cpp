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
#define Point pdd
#define Polygon vector<Point>
#define Line pair<Point,Point>
#define N 100000
#define rank Rank

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
vector<int> v[105];
bool solve(){
    int n;
    scanf("%d",&n);
    int a[3005],b[3005];
    for(int i = 1;i<=n;i++)scanf("%d",&a[i]);
    int sum=0;
    flow.init(n+10,0,n+1);
    for(int i = 1;i<=n;i++){
        scanf("%d",&b[i]);
        if(b[i]<0){
            v[a[i]].pb(i);
            flow.add_edge(0,i,-b[i]);
        }
        else{
            sum+=b[i];
            flow.add_edge(i,n+1,b[i]);
        }
    }
    for(int i = 1;i<=100;i++){
        for(int j = 1;j<v[i].size();j++){
            flow.add_edge(v[i][j-1],v[i][j],1e9);
        }
    }
    for(int i = 1;i<=n;i++){
        if(b[i]>0){
            for(int j  =1;j<=100;j++){
                if(a[i]%j==0){
                    for(int k=v[j].size()-1;k>=0;k--){
                        if(v[j][k]<i){
                            flow.add_edge(v[j][k],i,1e9);
                            break;
                        }
                    }
                }
            }
        }
    }
    printf("%d\n",sum-flow.flow());
}
int main(){
    int t=1;//00000;
  //  scanf("%d",&t);
    while(t--)solve();
}
/*
1 4 10100
1 6 1010100
1 8 101010100
1 y 10100  (y+1)  y/2
2 5 1100100
2 6 11001100
2 7 110011000
2 8 1100110000
2 9 11001100100
*/