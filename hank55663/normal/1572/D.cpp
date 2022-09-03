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
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
    static const int MXN = 20000+2;
const int mod=998244353;
LL dis[MXN];
struct CostFlow {

    static const long long INF = 102938475610293847LL;
    struct Edge {
        int v, r;
        long long f, c;
        Edge(int a,int b,int _c,int d):v(a),r(b),f(_c),c(d){
		}
    };
    int n, s, t, prv[MXN], prvL[MXN], inq[MXN];
    long long fl, cost;
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
    static bool cmp(const int &a,const int &b){
        return dis[a]>dis[b];
    }
    pll flow(int k) {
        while (true) {
            for (int i=0; i<n; i++) {
                dis[i] = INF;
                inq[i] = 0;
            }
            dis[s] = 0;
            vector<int> que;
            que.pb(s);
            while (!que.empty()) {
                int u = que.back(); que.pop_back();
                inq[u] = 0;
                for (int i=0; i<E[u].size(); i++) {
                    int v = E[u][i].v;
                    long long w = E[u][i].c;
                    if (E[u][i].f > 0 && dis[v] > dis[u] + w) {
                        prv[v] = u; prvL[v] = i;
                        dis[v] = dis[u] + w;
                        if (!inq[v]) {
                            inq[v] = 1;
                            que.push_back(v);
                        }
                    }
                }
                if(u==s){
                    sort(que.begin(),que.end(),cmp);
                }
            }
            if (dis[t] == INF) break;
            long long tf = INF;
            for (int v=t, u, l; v!=s; v=u) {
                u=prv[v]; l=prvL[v];
                tf = min(tf, E[u][l].f);
            }
            for (int v=t, u, l; v!=s; v=u) {
                u=prv[v]; l=prvL[v];
                E[u][l].f -= tf;
                E[v][E[u][l].r].f += tf;
            }
            if(dis[t]>0)break;
            cost += tf * dis[t];
            fl += tf;
            if(fl==k)break;
        }
        return {fl, cost};
    }
}flow;
#define index Index
int val[1<<20];
int index;
void solve(){
    int n,k;
    scanf("%d %d",&n,&k);
    int a[1<<20];
    for(int i = 0;i<(1<<n);i++)scanf("%d",&a[i]);
    priority_queue<pair<int,pii> ,vector<pair<int,pii>>,greater<pair<int,pii>>> pq;
    for(int i = 0;i<(1<<n);i++){
        if(__builtin_popcount(i)&1){
            for(int j =0;j<n;j++){
                //if(i&(1<<j)){
                pq.push(mp(a[i]+a[i^(1<<j)],mp(i,i^(1<<j))));
                //}
            }
            while(pq.size()>2*n*k)pq.pop();
        }
    }
    vector<pair<int,pii>> v;
    while(!pq.empty()){
        v.pb(pq.top());
        pq.pop();
    }
    for(int i = 0;i<n*k*2&&i<v.size();i++){
        int a=v[i].y.x,b=v[i].y.y;
        if(!val[a]){
            val[a]=++index;
        }
        if(!val[b]){
            val[b]=++index;
        }
    }
    flow.init(index+2,0,index+1);
    for(int i = 0;i<(1<<n);i++){
        if(val[i]){
            if(__builtin_popcount(i)&1)flow.add_edge(0,val[i],1,-a[i]);
            else flow.add_edge(val[i],index+1,1,-a[i]);
        }
    }
    for(int i = 0;i<n*k*2&&i<v.size();i++){
        flow.add_edge(val[v[i].y.x],val[v[i].y.y],1,0);
    }
    printf("%lld\n",-flow.flow(k).y);
}
int main(){
    int t=1;
    //scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
000010000
001010000
001010100
001011100

1 1 2
1 1 2 1
2 1
2


XOXOXOXOOXOXXOXOXOXOOXOX

*/