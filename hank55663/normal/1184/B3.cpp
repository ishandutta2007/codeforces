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
vector<int> v[100005];
struct Dinic{
    static const int MXN = 250000;
    struct Edge{ LL v,f,re; Edge(LL a,LL b,LL c):v(a),f(b),re(c){}};
    int n,s,t,level[MXN];
    vector<Edge> E[MXN];
    void init(int _n, int _s, int _t){
        n = _n; s = _s; t = _t;
        for (int i=0; i<=n; i++) E[i].clear();
    }
    void add_edge(int u, int v, LL f){
        E[u].pb(Edge(v,f,E[v].size()));
        E[v].pb(Edge(u,0,E[u].size()-1));//direct
     //   printf("%d %d %d\n",u,v,f);
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
    LL DFS(int u, LL nf){
        if (u == t) return nf;
        LL res = 0;
        for (auto &it : E[u]){
            if (it.f > 0 && level[it.v] == level[u]+1){
                LL tf = DFS(it.v, min(nf,(LL)it.f));
                res += tf; nf -= tf; it.f -= tf;
                E[it.v][it.re].f += tf;
                if (nf == 0) return res;
            }
        }
        if (!res) level[u] = -1;
        return res;
    }
    LL flow(LL res=0){
        while ( BFS() )
        res += DFS(s,1e18);
        return res;
    }
}flow;
int vis[100005],s;
void go(int x,int t){
    for(auto it:v[x]){
        if(vis[it]!=t){
            flow.add_edge(t,it+s,1e18);
            vis[it]=t;
            go(it,t);
        }
    }
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int dis[105][105];
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++)
            dis[i][j]=1e9;
        dis[i][i]=0;
    }
    for(int i = 0;i<m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        dis[x][y]=dis[y][x]=1;
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            for(int k = 1;k<=n;k++){
                dis[j][k]=min(dis[j][i]+dis[i][k],dis[j][k]);
            }
        }
    }
    int B,k;
    scanf("%d %d %d",&s,&B,&k);
    int x[100005],a[100005],f[100005],p[100005];
    vector<pii> base[105];
    for(int i = 1;i<=s;i++){
        scanf("%d %d %d %d",&x[i],&a[i],&f[i],&p[i]);
    }
    for(int i = 0;i<B;i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        base[a].pb(mp(b,c));
    }
    for(int i = 1;i<=n;i++){
    //    base[i].pb(mp(0,0));
        sort(base[i].begin(),base[i].end());
        vector<pii> tmp=base[i];
        base[i].clear();
        base[i].pb(mp(0,0));
        for(auto it:tmp){
            if(it.y>base[i].back().y){
                base[i].pb(it);
            }
        }
       // for(auto it:base[i])
       // printf("%d %d ",it.x,it.y);
       // printf("\n");
    }
    int val[100005];
    for(int i = 1;i<=s;i++){
        val[i]=-p[i];
        for(int j = 1;j<=n;j++){
            if(dis[x[i]][j]<=f[i]){
              //  printf("%d %d\n",i,j);
                val[i]=max(val[i],(lower_bound(base[j].begin(),base[j].end(),mp(a[i],1000000009))-1)->y-p[i]);
                //printf("%d\n",(lower_bound(base[i].begin(),base[i].end(),mp(a[i],1000000000))-1)->y)
            }
        }
     //   printf("%d\n",val[i]);
    }
    for(int i = 0;i<k;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        v[b].pb(a);
    }
    flow.init(2*s+10,0,2*s+1);
    LL ans=0;
    for(int i =1;i<=s;i++){
        if(val[i]>0){
            ans+=val[i];
            flow.add_edge(i+s,2*s+1,val[i]);
        }
        else if(val[i]<0){
            if(val[i]==-p[i])
            flow.add_edge(0,i,1e18);
            else
            flow.add_edge(0,i,-val[i]);
            go(i,i);
        }

    }   
  //  printf("%lld\n",ans);
    printf("%lld\n",ans-flow.flow());
}