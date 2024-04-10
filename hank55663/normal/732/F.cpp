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
#define EPS 1e-3
#define arg ARG
#define pdd pair<double,double>
#define cpdd const pdd
const int MXN = 416004;
struct BccVertex {
    int n,nScc,step,dfn[MXN],low[MXN];
    vector<int> E[MXN],sccv[MXN];
    int top,stk[MXN];
    void init(int _n) {
        n = _n;
        nScc = step = 0;
        for (int i=0; i<n; i++) E[i].clear();
    }
    void add_edge(int u, int v) {
        E[u].pb(v);
        E[v].pb(u);
    }
    void DFS(int u, int f) {
        dfn[u] = low[u] = step++;
        stk[top++] = u;
        for (auto v:E[u]) {
            if (v == f) continue;
            if (dfn[v] == -1) {
                DFS(v,u);
                low[u] = min(low[u], low[v]);
                if (low[v] > dfn[u]) {
                    int z;
                    sccv[nScc].clear();
                    do {
                       // if(stk[top-1]==v)
                        //break;
                        z = stk[--top];
                        sccv[nScc].pb(z);
                    } while (z != v);
                   // sccv[nScc].pb(u);
                    nScc++;
                }
            } else {
                low[u] = min(low[u],dfn[v]);
            }
        }
    }
    vector<vector<int>> solve() {
        vector<vector<int>> res;
        for (int i=0; i<n; i++) {
            dfn[i] = low[i] = -1;
        }
        for (int i=0; i<n; i++) {
            if (dfn[i] == -1) {
                top = 0;
                DFS(i,i);
            }
        }
        for(int i=0;i<nScc;i++) res.pb(sccv[i]);
        return res;
    }
}graph;
pii p[400005];
set<int> v[400005];
int weight[400005];
int ok[400005];
int vis[400005];
int instk[400005];
set<pii> remain;
int t;
void dfs(int x,int f){
   // printf("x:%d %d\n",x,f);
    vis[x]=++t;
    instk[x]=1;
    for(auto it:v[x]){
        if(it!=f){
            if(ok[it]&&!vis[it]){
                remain.insert(mp(x,it));
             //   printf("add:%d %d\n",x,it);
                dfs(it,x);
            }
            if(instk[it]){
                remain.insert(mp(x,it));
               // printf("add:%d %d\n",x,it);
            }
        }
    }
    instk[x]=0;
}
int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    graph.init(n+1);
    for(int i = 0;i<m;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        p[i]=mp(a,b);
        v[a].insert(b);
        v[b].insert(a);
        graph.add_edge(a,b);
    }
    graph.add_edge(0,1);
    if(m==n-1){
        printf("1\n");
        for(int i = 0;i<m;i++){
            printf("%d %d\n",p[i].x,p[i].y);
        }
        return 0;
    }
    vector<vector<int>> res=graph.solve();
    int Max=0;
    for(auto it:res){
       /*  for(auto it2:it){
            printf("%d ",it2);
        }
        printf("\n");*/
        Max=max(Max,(int)it.size());
    }
    for(auto it:res){
        if(it.size()==Max){
            for(auto ver:it){
                ok[ver]=1;
              //  printf("%d\n",ver);
            }
            dfs(it[0],0);
         //   printf("%d\n",it[0]);
            for(auto it:remain){
           //     printf("r:%d %d\n",it.x,it.y);
                v[it.x].erase(it.y);
                v[it.y].erase(it.x);
            }
            //for(int i =0;i<m;i++){
            //    if(ok[p[i].x]&&ok[p[i].y]){
            queue<int> q;
            for(auto ver:it){
                weight[ver]=1;
                q.push(ver);
            }
            int now=2;
            while(!q.empty()){
                int x;
                x=q.front();
                q.pop();
              //   printf("!%d\n",x);
                for(auto ver:v[x]){
                    if(weight[ver]==0){
                        weight[ver]=now++;
                        q.push(ver);
                    }
                }
            }
          //  for(int j=1;j<=n;j++)
            //    printf("%d ",weight[j]);
           // printf("\n");
            for(int j=0;j<m;j++){
                if(weight[p[j].x]<weight[p[j].y]){
                    swap(p[j].x,p[j].y);
                }
                if(remain.find(mp(p[j].y,p[j].x))!=remain.end()){
                    swap(p[j].x,p[j].y);
                }
            }
            break;
        }
    }
    printf("%d\n",Max);
    for(int i = 0;i<m;i++){
        printf("%d %d\n",p[i].x,p[i].y);
    }
    return 0;
}