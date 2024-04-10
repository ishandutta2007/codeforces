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
#define MXN 1000005
#define hash Hash
struct Scc{
    int n, nScc, vst[MXN], bln[MXN];
    vector<int> E[MXN], rE[MXN], vec;
    void init(int _n){
        n = _n;
        for (int i=0; i<=n; i++){
            E[i].clear();
            rE[i].clear();
        }
    }
    void add_edge(int u, int v){
        E[u].pb(v);
        rE[v].pb(u);
    }
    void DFS(int u){
        vst[u]=1;
        for (auto v : E[u])
        if (!vst[v]) DFS(v);
        vec.pb(u);
    }
    void rDFS(int u){
        vst[u] = 1;
        bln[u] = nScc;
        for (auto v : rE[u])
        if (!vst[v]) rDFS(v);
    }
    void solve(){
        nScc = 0;
        vec.clear();
        fill(vst,vst+n+1,0);
        for (int i=1; i<=n; i++)
        if (!vst[i]) DFS(i);
        reverse(vec.begin(),vec.end());
        fill(vst,vst+n+1,0);
        for (auto v : vec){
            if (!vst[v]){
                rDFS(v);
                nScc++;
            }
        }
    }
}g;
int outdegree[1000005];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d %d",&n,&m);
        fill(outdegree,outdegree+n+1,0);
        g.init(n);
        vector<pii> v;
        for(int i = 0;i<m;i++){
            int x,y;
            scanf("%d %d",&x,&y);
            if(x==y){
            }
            else{
                g.add_edge(x,y);
                v.pb(mp(x,y));
               // g.add_edge(y+n,x+n);
            }
        }
        g.solve();
        if(g.nScc==1){
            printf("No\n");
        }
        else{
            printf("Yes\n");
            vector<int> v1,v2;
            for(auto it:v){
                if(g.bln[it.x]!=g.bln[it.y]){
                    outdegree[g.bln[it.x]]=1;
                }
            }
            int val;
            for(int i = 0;i<g.nScc;i++){
                if(outdegree[i]==0)val=i;
               // printf("%d %d\n",i,outdegree[i]);
            }
            for(int i = 1;i<=n;i++){
                //printf("%d\n",g.bln[i]);
                if(g.bln[i]==val)v1.pb(i);
                else v2.pb(i);
            }
            printf("%d %d\n",v1.size(),v2.size());
            for(auto it:v1)printf("%d ",it);
            printf("\n");
            for(auto it:v2)printf("%d ",it);
            printf("\n");
        }
    }
}