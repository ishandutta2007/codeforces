




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
#define N 100005
#define MXN 2000005
struct Scc{
    int n, nScc, vst[MXN], bln[MXN];
    vector<int> E[MXN], rE[MXN], vec;
    vector<vector<int> > Scc;
    vector<int> tmp;
    void init(int _n){
        n = _n;
        for (int i=0; i<MXN; i++){
            E[i].clear();
            rE[i].clear();
        }
    }
    void add_edge(int u, int v){
      //  printf("%d %d\n",u,v);
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
        tmp.pb(u);
        bln[u] = nScc;
        for (auto v : rE[u])
        if (!vst[v]) rDFS(v);
    }
    void solve(){
        nScc = 0;
        vec.clear();
        MEM(vst);
        for (int i=1; i<=n; i++)
        if (!vst[i]) DFS(i);
        reverse(vec.begin(),vec.end());
       // printf("%d\n",vec.size());
        MEM(vst);
        for (auto v : vec){
        //    printf("%d ",v);
            if (!vst[v]){
                tmp.clear();
                rDFS(v);
                Scc.pb(tmp);
                nScc++;
            }
        }
       // printf("\n");
    }
    int ans[MXN];
    void solve_ans(int n){
        for(int i = 1;i<=n;i++){
            if(bln[i]>bln[i+n]){
                ans[i]=1;
            }
            else{
                ans[i]=0;
            }
           // printf("%d ",ans[i]);
        }
       // printf("\n");
    }
}scc;

int main(){
    int n,p,M,m;
    scanf("%d %d %d %d",&n,&p,&M,&m);
    scc.init((p+M)*2);
    for(int i = 1;i<=M;i++){
        if(i>1)
        scc.add_edge(p+i,p+i-1);
        if(i<M)
        scc.add_edge(p+i+p+M,p+i+p+M+1);
    }
    for(int i = 0;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        scc.add_edge(x+p+M,y);
        scc.add_edge(y+p+M,x);
    }
    for(int i=1;i<=p;i++){
        int l,r;
        scanf("%d %d",&l,&r);
        //if(l!=1)
        scc.add_edge(i,l+p);
        scc.add_edge(l+p+p+M,p+M+i);
        if(r!=M){
            scc.add_edge(i,p+M+p+r+1);
            scc.add_edge(p+r+1,i+p+M);
        }
    }
    for(int i = 0;i<m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        scc.add_edge(x,y+p+M);
        scc.add_edge(y,x+p+M);
    }
    scc.solve();
    for(int i = 1;i<=p+M;i++){
        if(scc.bln[i]==scc.bln[i+p+M]){
            printf("-1\n");
            return 0;
        }
    }
    scc.solve_ans(p+M);
    int f=M;
    for(int i=1;i<=M;i++){
        //printf("%d %d\n",p+i,scc.ans[p+i]);
        if(scc.ans[p+i]==0){
            f=i-1;
            break;
        }
    }
    vector<int> res;
    for(int i = 1;i<=p;i++){
        if(scc.ans[i]==1)
            res.pb(i);
    }
    printf("%d %d\n",res.size(),f);
    for(auto it:res)
    printf("%d ",it);
    printf("\n");
    return 0;
}