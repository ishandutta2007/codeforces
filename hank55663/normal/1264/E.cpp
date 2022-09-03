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
int tot[55];
int vis[55][55];
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    pii p[3000];
    for(int i=0;i<m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        tot[x]++;
        vis[x][y]=vis[y][x]=1;
        p[i]=mp(x,y);
    }
    int Max=n,Min=0;
    flow.init(n+n*n+2,0,n+n*n+1);
    int cnt=n+1;
    for(int i = 1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(!vis[i][j]){
                flow.add_edge(i,cnt,1);
                flow.add_edge(j,cnt,1);
                flow.add_edge(cnt,n+n*n+1,1);
                cnt++;
            }
        }
    }
    int res=0;
    for(int t = 1;t<n;t++){
        for(int i = 1;i<=n;i++){
            if(tot[i]<t){
                flow.add_edge(0,i,1);
            }
        }
        res=flow.flow(res);
        if(res==cnt-n-1){
            break;
        }
    }
   // printf("%d\n",Max);
    cnt=n+1;
    int ans[55][55];
    MEM(ans);
    for(int i = 1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(!vis[i][j]){
                for(auto &it:flow.E[cnt]){
                    if(it.f&&(it.v==i||it.v==j)){
                        ans[it.v][i+j-it.v]=1;
                        tot[it.v]++;
                    }
                }
                cnt++;
            }
        }
    }
    for(int i = 0;i<m;i++)
        ans[p[i].x][p[i].y]=1;
    LL rres=n*(n-1)*(n-2);
    for(int i= 1;i<=n;i++){
        rres-=tot[i]*(tot[i]-1)/2*6;
      //  printf("i %d\n",tot[i]);
    }
    //printf("%lld\n",rres/2);
    for(int i = 1;i<=n;i++,printf("\n"))
        for(int j=1;j<=n;j++)
            printf("%d",ans[i][j]);
}
/*

b[i]*K!/(i)!*(K-i)!
*/