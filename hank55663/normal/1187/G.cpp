#include<bits/stdc++.h>
using namespace std;
#define LL long long
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
#define MXN 10005
#define less Less
struct CostFlow {
    struct Edge {
        int v, r;
        long long f, c;
        Edge(int a,int b,int _c,int d):v(a),r(b),f(_c),c(d){
		}
    };
    int n, s, t, prv[MXN], prvL[MXN], inq[MXN];
    LL dis[MXN], fl, cost;
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
    void SPFA(){
        fill(dis,dis+n+1,1e18);
        fill(inq,inq+n+1,0);
        dis[s] = 0;
        queue<int> q;
        q.push(s);
        while(!q.empty()){
            int x=q.front();
            q.pop();
            inq[x]=0;
            int cnt=0;
            for(auto it:E[x]){
                if(it.f>0&&dis[it.v]>dis[x]+it.c){
                    prv[it.v]=x;prvL[it.v]=cnt;
                    dis[it.v]=dis[x]+it.c;
                    if(!inq[it.v]){
                        inq[it.v]=1;
                        q.push(it.v);
                    }
                }
                cnt++;
            }
        }
    }
    pll flow() {
        while (true) {
            SPFA();
            if (dis[t] == 1e18) break;
            long long tf = 1e18;
            for (int v=t, u, l; v!=s; v=u) {
                u=prv[v]; l=prvL[v];
                tf = min(tf, E[u][l].f);
            }
            for (int v=t, u, l; v!=s; v=u) {
                u=prv[v]; l=prvL[v];
                E[u][l].f -= tf;
                E[v][E[u][l].r].f += tf;
            }
            cost += tf * dis[t];
            fl += tf;
        }
        return {fl, cost};
    }
}flow;
int main(){
    int n,m,k,c,d;
    scanf("%d %d %d %d %d",&n,&m,&k,&c,&d);
    int a[105];
    flow.init(n*200+1,0,n*200);
    for(int i=0;i<k;i++){
        scanf("%d",&a[i]);
        flow.add_edge(0,a[i],1,0);
    }
    for(int i = 1;i<=n;i++){
        for(int j=0;j<=100;j++){
            flow.add_edge(j*n+i,(j+1)*n+i,1e9,c);
        }
    }
    for(int i = 0;i<m;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        for(int j = 0;j<=100;j++){
            for(int k = 1;k<=50;k++){
                flow.add_edge(j*n+a,(j+1)*n+b,1,(k*k-(k-1)*(k-1))*d+c);
                flow.add_edge(j*n+b,(j+1)*n+a,1,(k*k-(k-1)*(k-1))*d+c);
            }
        }
    }
    for(int i = 0;i<=100;i++){
        flow.add_edge(i*n+1,n*200,1e9,0);
    }
    printf("%lld\n",flow.flow().y);
}