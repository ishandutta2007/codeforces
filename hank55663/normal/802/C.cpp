#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define LL long long
#define ULL unsigned long long 
#define y second
#define sqr(x) ((x)*(x))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define pi acos(-1)
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
struct CostFlow {
    static const int MXN = 205;
    static const long long INF = 102938475610293847LL;
    struct Edge {
        int v, r;
        long long f, c;
        Edge(int a,int b,int _c,int d):v(a),r(b),f(_c),c(d){
		}
    };
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
            for (int i=0; i<n; i++) {
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
            cost += tf * dis[t];
            fl += tf;
        }
        //printf("%d\n",fl);
        return {fl, cost};
    }
}flow;
int last[85];
int cnt[85];
int c[85];
int main(){ 
    int n,k;
    scanf("%d %d",&n,&k);
    vector<pair<pii,int> > v;
    int ans=0;
    for(int i = 1;i<=n;i++){
        int x;
        scanf("%d",&x);
        cnt[x]++;
        if(last[x]==0);
        else{
            if(last[x]==i-1){
                cnt[x]--;
            }
            else
                v.pb(mp(mp(last[x]+1,i-1),x));
        }
        last[x]=i;
    }
    for(int i = 1;i<=n;i++){
        scanf("%d",&c[i]);
        ans+=cnt[i]*c[i];
    }
    flow.init(n+2,0,n+1);
    flow.add_edge(0,1,k-1,0);
    for(int i = 1;i<=n;i++){
        flow.add_edge(i,i+1,100,0);
    }
    //printf("%d\n",ans);
    for(auto it:v){
        //printf("%d %d %d\n",it.x.x,it.x.y,-c);
        flow.add_edge(it.x.x,it.x.y+1,1,-c[it.y]);
    }
    printf("%lld\n",ans+flow.flow().y);
}
/*

5
AACCMMAA
A
AA
MM
ACA
ACMAA


5
0 9 7 1 100
-1 0 -1 -1 91
-1 5 0 -1 96
-1 8 9 0 99
-1 -1 -1 -1 0
3 4
3 5
5 6
5 7
3 or 4
3 or 5
5 or 6
5 or 7

dp[x]=max(dp[x-w_i*j]+j*t_i-delta t_i*j*(j-1)/2)
dp[x]=max(dp[j]+x*t_i-j*t_i-delta t_i*(x-j)*(x-j-1)/2)
dp[x]=max(dp[j]-j*t_i-delta t_i *(j^2/2+j/2) - 
        delta t_i * xj + x*t_i + delta t_i * (x^2/2-x/2))
dp[x]=max(dp[j] + g(j) - delta t_i *xj + w(i) )
g(j)= dp[j]-j*t_i-delta t_i *(j^2/2+j/2)
w(i)=  x*t_i + delta t_i * (x^2/2-x/2)
x^2/2 -xj -x/2  +j^2/2 +j/2
*/

/*
 

*/