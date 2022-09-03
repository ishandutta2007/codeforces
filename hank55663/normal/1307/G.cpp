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
#define MXN 205

struct CostFlow {
    //static const int MXN = 205;
    static const long long INF = 102938475610293847LL;
    struct Edge {
        int v, r;
        long long f, c;
        Edge(int a,int b,int _c,int d):v(a),r(b),f(_c),c(d){
		}
    };
    vector<int> ans;
    int n, s, t, prv[MXN], prvL[MXN], inq[MXN];
    long long dis[MXN], fl, cost;
    vector<Edge> E[MXN];
    void init(int _n, int _s, int _t) {
        n = _n; s = _s; t = _t;
        for (int i=0; i<n; i++) E[i].clear();
        fl = cost = 0;
    }
    void add_edge(int u, int v, long long f, long long c)
    {
        E[u].pb(Edge(v, E[v].size() , f, c));
        E[v].pb(Edge(u, E[u].size()-1, 0, -c));
    }
    pll flow() {
        while (true) {
            for (int i=1; i<=n; i++) {
                dis[i] = INF;
                inq[i] = 0;
            }
            dis[s] = 0;
            queue<int> que;
            que.push(s);
            while (!que.empty()) {
                int u = que.front(); que.pop();
                inq[u] = 0;
                for (int i=0; i<E[u].size(); i++) {
                    int v = E[u][i].v;
                    long long w = E[u][i].c;
                    if (E[u][i].f > 0 && dis[v] > dis[u] + w) {
                        prv[v] = u; prvL[v] = i;
                        dis[v] = dis[u] + w;
                        if (!inq[v]) {
                            inq[v] = 1;
                            que.push(v);
                        }
                    }
                }
            }
            if (dis[t] == INF) break;
            //long long tf = INF;
            for (int v=t, u, l; v!=s; v=u) {
                u=prv[v]; l=prvL[v];
              //  tf = min(tf, E[u][l].f);
            }
            int tf=1;
            for (int v=t, u, l; v!=s; v=u) {
                u=prv[v]; l=prvL[v];
                E[u][l].f -= tf;
                E[v][E[u][l].r].f += tf;
            }
            cost += tf * dis[t];
            fl += tf;
            ans.pb(cost);
        }
        return {fl, cost};
    }
}flow;

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    flow.init(n,1,n);
    for(int i = 1 ; i <= m ; i++){
        int x,y,w;
        scanf("%d %d %d",&x,&y,&w);
        flow.add_edge(x,y,1,w);
    }
    flow.flow();
    int q;
    scanf("%d",&q);
    while(q--){
        int x;
        scanf("%d",&x);
        double ans=1e9;
        int now=1;
        for(auto it:flow.ans){
            ans=min(ans,(it+x)*1.0/now);
            now++;
        }
        printf("%.12lf\n",ans);
    }
}
/*
[1,2,4,3,5,6]
concat(sorted([4,2,1]),sorted([5,3,6]))
concat(shuffle([2,1]),shuffle([2,3]))
concat(shuffle([2,1,3]),shuffle([3]))
*/