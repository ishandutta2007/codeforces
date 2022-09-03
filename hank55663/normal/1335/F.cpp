#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define LL long long 
#define y second
#define sqr(x) ((x)*(x))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<long double,long double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acosl(-1)
//#define N 524288
#define ld long double
using namespace std;
const int MXN=1020005;
struct Scc{
    int n, nScc, vst[MXN], bln[MXN];
    vector<vector<int>> E, rE;
    vector<int> vec;
    vector<vector<int> > scc;
    void init(int _n){
        n = _n;
       // for (int i=0; i<=n; i++){
            E.clear();
            rE.clear();
       // }
       E.resize(n);
       rE.resize(n);
        scc.clear();
    }
    void add_edge(int u, int v){
       // printf("%d %d\n",u,v);
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
        scc.back().pb(u);
        for (auto v : rE[u])
        if (!vst[v]) rDFS(v);
    }
    void solve(){
        nScc = 0;
        vec.clear();
        fill(vst,vst+n+1,0);
        for (int i=0; i<n; i++)
        if (!vst[i]) DFS(i);
        reverse(vec.begin(),vec.end());
        fill(vst,vst+n+1,0);
        for (auto v : vec){
            if (!vst[v]){
                scc.pb(vector<int>());
                rDFS(v);
                nScc++;
            }
        }
    }
}g;
int go[1000005][22];
int val[1000005];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d %d",&n,&m);
        g.init(n*m);
        vector<vector<char> > a(n,vector<char>(m)),b(n,vector<char>(m));
        for(int i = 0;i<n;i++){
            for(int j=0;j<m;j++){
                scanf(" %c",&a[i][j]);
                val[i*m+j]=0;
            }
        }
        for(int i = 0;i<n;i++){
            for(int j=0;j<m;j++){
                scanf(" %c",&b[i][j]);
                int x=i,y=j;
                if(b[i][j]=='R')y++;
                if(b[i][j]=='L')y--;
                if(b[i][j]=='U')x--;
                if(b[i][j]=='D')x++;
                g.add_edge(i*m+j,x*m+y);
                go[i*m+j][0]=x*m+y;
            }
        }
        g.solve();
        int ans=0;
        for(auto& it:g.scc){
            if(it.size()>1)ans+=it.size();
        }
        printf("%d",ans);
        for(int i = 1;i<22;i++){
            for(int j=0;j<n*m;j++){
                go[j][i]=go[go[j][i-1]][i-1];
            }
        }
        ans=0;
        for(int i = 0;i<n*m;i++){
            if(a[i/m][i%m]=='1')continue;
            LL step=n*m;
            int now=i;
            for(int j = 0;j<22;j++){
                if(step&(1ll<<j))now=go[now][j];
            } 
            int Size=g.scc[g.bln[now]].size();
            step=(Size/(n*m)+1)*(n*m);
            now=i;
            for(int j=0;j<22;j++){
                if(step&(1ll<<j))now=go[now][j];
            }
            val[now]=1;
        }
        for(int i = 0;i<n*m;i++){
            ans+=val[i];
        }
        printf(" %d\n",ans);
    }

}
/*
00 00
01 10
10 11
11 01
2 1 3 0 2
3 1 3 0 2
3 2 3 0 2
3 2 4 0 2
3 2 4 1 2
3 2 4 1 3
*/