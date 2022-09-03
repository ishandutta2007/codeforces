#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define N 131072
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
pair<pii,int> p[1000005];
#define MXN 1000005
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
    LL cal(int w){
        LL Max=30000,Min=0;
        while(Max>Min+1){
            int mid=(Max+Min)/2;
            int tot=mid*(mid+1)/2;
            if(tot>w){
                Max=mid;
            }
            else{
                Min=mid;
            }
        }
        return w*(Min+1)-(Min+1)*(1+Min)*Min/2+Min*(Min+1)*(2*Min+1)/6;
    }
    LL solve(int s,int m){
        nScc = 0;
        vec.clear();
        MEM(vst);
        for (int i=1; i<=n; i++)
        if (!vst[i]) DFS(i);
        reverse(vec.begin(),vec.end());
        MEM(vst);
        for (auto v : vec){
            if (!vst[v]){
                rDFS(v);
                nScc++;
            }
        }
        int degree[MXN];
        fill(degree,degree+nScc,0);
        LL ans[MXN];
        fill(ans,ans+nScc,-1e18);
        LL add[MXN];
        fill(add,add+nScc,0);
        vector<vector<pii>> v(nScc);
        for (int i=0;i<m;i++){
            int x=p[i].x.x;
            int y=p[i].x.y;
            int w=p[i].y;
            if(bln[x]==bln[y]){
                add[bln[x]]+=cal(w);
              //  printf("%d %lld\n",w,cal(w));
            }
            else{
                v[bln[x]].pb(mp(bln[y],w));
                degree[bln[y]]++;
            }
        }
        ans[bln[s]]=0;
        queue<int> q;
        for(int i = 0;i<nScc;i++){
            if(degree[i]==0)
            q.push(i);
        }
        LL res=0;
        while(!q.empty()){
            int x=q.front();
            q.pop();
            ans[x]+=add[x];
            res=max(res,ans[x]);
            for(auto it:v[x]){
                ans[it.x]=max(ans[it.x],ans[x]+it.y);
                if(--degree[it.x]==0)
                    q.push(it.x);
            }
        }
        return res;
    }
}graph;

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    graph.init(n+1);
    for(int i = 0;i<m;i++){
        int x,y,w;
        scanf("%d %d %d",&x,&y,&w);
        p[i]=mp(mp(x,y),w);
        graph.add_edge(x,y);
    }
    int s;
    scanf("%d",&s);
    printf("%lld\n",graph.solve(s,m));
}
/*
1 4 2 3
1 3 6 12
k(a+b) = a*b;
k*a+k*b = a*b;
b= (k*a)/(a-k);

k*(k+i)/i
*/