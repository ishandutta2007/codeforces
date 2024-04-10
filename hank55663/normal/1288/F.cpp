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
struct CostFlow {
    static const int MXN = 505;
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
        return {fl, cost};
    }
}flow;

int main(){
    int n1,n2,m,r,b;
    scanf("%d %d %d %d %d",&n1,&n2,&m,&r,&b);
    flow.init(n1+n2+10,n1+n2+2,n1+n2+3);
    char c1[205],c2[205];
    scanf("%s %s",c1+1,c2+1);
    pii p[205];
    for(int i = 0;i<m;i++){
        int x,y;
       
        scanf("%d %d",&x,&y);
         p[i]=mp(x,y);
        flow.add_edge(x,n1+y,1,r);
        flow.add_edge(n1+y,x,1,b);
    }
    int val[405];
    MEM(val);
    for(int i = 1;c1[i]!=0;i++){
        if(c1[i]=='R'){
            flow.add_edge(0,i,1e9,0);
            val[i]++;
            val[0]--;
        }
        else if(c1[i]=='B'){
            flow.add_edge(i,n1+n2+1,1e9,0);
            val[i]--;
            val[n1+n2+1]++;
        }
        else{
            flow.add_edge(0,i,1e9,0);
            flow.add_edge(i,n1+n2+1,1e9,0);
        }
    }
    for(int i = 1;c2[i]!=0;i++){
        if(c2[i]=='R'){
            flow.add_edge(i+n1,n1+n2+1,1e9,0);
            val[n1+n2+1]++;
            val[i+n1]--;
        }
        else if(c2[i]=='B'){
            flow.add_edge(0,i+n1,1e9,0);
            val[0]--;
            val[i+n1]++;
        }
        else{
            flow.add_edge(0,i+n1,1e9,0);
            flow.add_edge(n1+i,n1+n2+1,1e9,0);
        }
    }
    flow.add_edge(n1+n2+1,0,1e9,0);
    LL sum=0;
    for(int i = 0;i<=n1+n2+1;i++){
        if(val[i]>0){
            sum+=val[i];
            flow.add_edge(n1+n2+2,i,val[i],0);
        }
        if(val[i]<0){
            flow.add_edge(i,n1+n2+3,-val[i],0);
        }
    }
    pll pp=flow.flow();
    if(pp.x!=sum){
        printf("-1\n");
    }
    else{
        printf("%lld\n",pp.y);
        map<pii,vector<char> > ma;
        for(int i = 1;i<=n1;i++){
            for(auto it:flow.E[i]){
                if(it.v>n1&&it.v<=n1+n2&&it.f==0&&it.c>0){
                 //   printf("%d %d %d %d\n",i,it.v,it.f,it.c);
                    ma[mp(i,it.v-n1)].pb('R');
                }
            }
        }
        for(int i = 1;i<=n2;i++){
            for(auto it:flow.E[i+n1]){
                if(it.v>0&&it.v<=n1&&it.f==0&&it.c>0){
                 //   printf("%d %d %d %d\n",i+n1,it.v,it.f,it.c);
                    ma[mp(it.v,i)].pb('B');
                }
            }
        }
        for(int i = 0;i<m;i++){
            if(ma.find(p[i])!=ma.end()&&ma[p[i]].size()){
                printf("%c",ma[p[i]].back());
                ma[p[i]].pop_back();
            }
            else printf("U");
        }
        printf("\n");
    }
    
}
//a+a+1=10a+1
//3a+2=10a+2