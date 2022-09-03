#include<bits/stdc++.h>
using namespace std;
#pragma optimizer(-Ofast)
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
#define pdd pair<double,double>
#define cpdd const pdd
#define rank Rank
#define MXN 200005
struct Scc{
    int n, nScc, vst[MXN], bln[MXN];
    vector<int> E[MXN], rE[MXN], vec;
    void init(int _n){
        n = _n;
        for (int i=0; i<MXN; i++){
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
        MEM(vst);
        for (int i=0; i<n; i++)
        if (!vst[i]) DFS(i);
        reverse(vec.begin(),vec.end());
        MEM(vst);
        for (auto v : vec){
           // printf("%d\n",v);
            if (!vst[v]){
                rDFS(v);
                nScc++;
            }
        }
    }
}g;
char ans[200005];
vector<int> v[200005];
int degree[200005];
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int p[200005],q[200005];
    for(int i = 1;i<=n;i++){
        scanf("%d",&p[i]);
        p[i]--;
    }
    for(int i = 1;i<=n;i++){
        scanf("%d",&q[i]);
        q[i]--;
    }
    g.init(n);
    for(int i = 1;i<n;i++){
        g.add_edge(p[i],p[i+1]);
        g.add_edge(q[i],q[i+1]);
    }
    g.solve();
    if(g.nScc<k){
        printf("NO\n");
    }
    else{
        printf("YES\n");
        for(int i = 1;i<n;i++){
            if(g.bln[p[i]]!=g.bln[p[i+1]]){
                v[g.bln[p[i]]].pb(g.bln[p[i+1]]);
                degree[g.bln[p[i+1]]]++;
            }
            if(g.bln[q[i]]!=g.bln[q[i+1]]){
                v[g.bln[q[i]]].pb(g.bln[q[i+1]]);
                degree[g.bln[q[i+1]]]++;
            }
        }
        queue<int> q;
        for(int i = 0;i<g.nScc;i++){
            if(degree[i]==0)
            q.push(i);
        }
        char now='a';
        while(!q.empty()){
            int x=q.front();
           // printf("%d\n",x);
            q.pop();
            ans[x]=now;
            if(now!='z')now++;
            for(auto it:v[x]){
                if(--degree[it]==0)
                    q.push(it);
            }
        }
        for(int i = 0;i<n;i++){
            printf("%c",ans[g.bln[i]]);
        }
        printf("\n");
    }
    return 0;
}