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
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 300000
#define N 100005
struct Scc{
    int n,nScc,vst[MXN],bln[MXN];
    vector<int> E[MXN],rE[MXN],vec;
    vector<vector<int> > scc;
    vector<int> tmp;
    vector<int> sccE[MXN];
    vector<int> topo;
    int sbln[MXN];
    void init(int _n){
        n=_n;
        for(int i = 0;i<MXN;i++){
            E[i].clear();
            rE[i].clear();
        }
    }
    void add_edge(int u,int v){
        E[u].pb(v);
        rE[v].pb(u);
    }
    void DFS(int u){
        vst[u]=1;
        for(auto v:E[u])
        if(!vst[v])DFS(v);
        vec.pb(u);
    }
    void rDFS(int u){
        vst[u]=1;
        bln[u]=nScc;
        tmp.pb(u);
        for(auto v:rE[u])
        if(!vst[v])rDFS(v);
    }
    void solve(){
        nScc=0;
        vec.clear();
        MEM(vst);
        for(int i = 1;i<=n;i++){
            if(!vst[i])DFS(i);
        }
        reverse(vec.begin(),vec.end());
        MEM(vst);
        for(auto v:vec){
            if(!vst[v]){
                rDFS(v);
                scc.pb(tmp);
                tmp.clear();
                nScc++;
            }
        }
        int degree[15];
        MEM(degree);
        for(int i = 0;i<nScc;i++){
            for(auto it:scc[i])
            for(auto it2:E[it]){
                if(bln[it2]!=i){
                    degree[bln[it2]]++;
                }
            }
        }
        queue<int> q;
        for(int i = 0;i<nScc;i++){
            if(degree[i]==0)q.push(i);
        }
        while(!q.empty()){
            int x=q.front();
            q.pop();
            sbln[x]=topo.size();
            topo.pb(x);
            for(auto it:scc[x]){
                for(auto it2:E[it])
                if(bln[it2]!=x&&--degree[bln[it2]]==0){
                    q.push(bln[it2]);
                }
            }
         /*   printf("%d\n",x);
            for(auto it:scc[x])
                printf("%d ",it);
            printf("\n");*/
        }
    }
}graph;
int main(){
    int n;
    scanf("%d",&n);
    graph.init(n);
    for(int i = 1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int x;
            scanf("%d",&x);
            if(x){
                graph.add_edge(i,j);
            }
        }
    }
    graph.solve();
    char c[20][17][10];
    MEM(c);
    for(int i=0;i<18;i++){
        if(i&1){
            for(int j=0;j<17;j++){
                for(int k=0;k<3;k++)
                    c[i][j][k]='#';
            }
            for(int j=0;j<17;j+=2){
                if(j!=i-1)
                c[i][j][2]='.';
 
            }
        }
        else{
            for(int j=0;j<17;j++){
                c[i][j][0]='.';
                c[i][j][1]='#';
                c[i][j][2]='#';
            }
            for(int j=0;j<17;j+=2){
                c[i][j][2]='.';
                if(j==i)
                c[i][j][1]='.';
            }
        }
        //for(int j=0;j<17;j++)
        //    printf("%s\n",c[i][j]);
        //printf("\n");
    }
    for(int i = 0;i<graph.topo.size();i++){
        for(auto it:graph.scc[graph.topo[i]]){
            c[i*2][(it-1)*2][0]=it+'0';
            for(auto it2:graph.E[it]){
                if(graph.bln[it]!=graph.bln[it2]){
                    c[i*2][graph.sbln[graph.bln[it2]]*2][1]='.';
                }
            }
        }
    }
    printf("17 3 18\n");
    for(int i = 0;i<18;i++){
        for(int k=0;k<3;k++){
            for(int j=0;j<17;j++)
                printf("%c",c[i][j][k]);
            printf("\n");
        }
        printf("\n");
    }
}