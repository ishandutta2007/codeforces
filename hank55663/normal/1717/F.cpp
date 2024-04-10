#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
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
const int mod=1e9+7;
struct Dinic{
    static const int MXN = 20000;
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
int val[100005];
int a[100005];
int s[100005];
void solve(int T){
    int n,m;
    scanf("%d %d",&n,&m);

    for(int i =1;i<=n;i++)scanf("%d",&s[i]);
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    flow.init(n+3,n+1,n+2);
    for(int i = 0;i<m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        val[x]--;
        val[y]++;
        flow.add_edge(y,x,1);
    }
    int z=0;
    LL sum=0;
    for(int i = 1;i<=n;i++){
        if(s[i]==0)flow.add_edge(0,i,n),flow.add_edge(i,0,n);
        else{
            int d=abs(a[i]-val[i]);
            if(d%2==1){
                printf("NO\n");
                return;
            }
            if(a[i]>val[i]){
                //flow.add_edge(i,0,n);
                flow.add_edge(i,n+2,(a[i]-val[i])/2);
                sum+=a[i]-val[i];
                z+=a[i]-val[i];
            }
            else if(a[i]<val[i]){
                flow.add_edge(n+1,i,(val[i]-a[i])/2);
                z-=val[i]-a[i];
            }
        }
    }
    if(z>0)flow.add_edge(n+1,0,z/2);
    else flow.add_edge(0,n+2,-z/2),sum-=z;
    sum/=2;
    if(flow.flow()==sum){
        printf("YES\n");
        for(int i = 1;i<=n;i++){
            for(auto it:flow.E[i]){
                if(it.v<=n&&it.v>=1){
                  //   printf("%d %d %d\n",i,it.v,it.f);
                    if(!it.f){
                        printf("%d %d\n",i,it.v);
                    }
                }
            }
        }
    }
    else{
        printf("NO\n");
    }
}
int main(){
    int t=1;
   // scanf("%d",&t);
    for(int T=1;T<=t;T++){
        solve(T);
    }
   // printf("%d\n",s.size());
}

/*
*/