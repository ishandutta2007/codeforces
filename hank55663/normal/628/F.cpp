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
#define pi acosl(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MAXN 205
#define N 262144
struct Dinic{
    static const int MXN = 50000;
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
    int n,b,q;
    scanf("%d %d %d",&n,&b,&q);
    pii p[10005];
    for(int i = 0;i<q;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        p[i]=mp(x,y);
    }
    p[q]=mp(b,n);
    sort(p,p+q+1);
    for(int i = 0;i<q;i++){
        if(p[i].y>p[i+1].y){
            printf("unfair\n");
            return 0;
        }
        /*if(i!=0){
            p[i].y-=p[i-1].y;
        }*/
    }
    for(int i = q;i>0;i--){
        p[i].y-=p[i-1].y;
    }
    //p[q].y-=p[q-1].y;
    flow.init(b+q+1+1+1+5,0,b+q+1+1+5);
    for(int i=0;i<=q;i++){
        flow.add_edge(0,i+1,p[i].y);
        int st=1;
        if(i!=0)st=p[i-1].x+1;
        //printf("%d %d %d\n",st,p[i].x,p[i].y);
        for(int j=st;j<=p[i].x;j++){
            flow.add_edge(i+1,j+q+1,1);
        }
    }
    for(int i=1;i<=b;i++){
        flow.add_edge(q+1+i,q+1+b+i%5+1,1);
    }
    for(int i = 1;i<=5;i++){
        flow.add_edge(q+1+b+i,q+b+1+5+1,n/5);
    }
    if(flow.flow()==n){
        printf("fair\n");
    }
    else{
        printf("unfair\n");
    }
}

/*
5 5
1 1 1 2 2
1 2 100
2 3 100
3 4 1
4 5 1
5 1 100
3
1 3 1 0
1 3 2 0
1 3 1 1

200
102
102
*/