#include<bits/stdc++.h>
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
#define index Index
#define MXN 1000000
struct Scc{
    int n, nScc, vst[MXN], bln[MXN];
    vector<int> E[MXN], rE[MXN], vec;
    void init(int _n){
        n = _n;
        for (int i=0; i<_n+10; i++){
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
        bln[u] = nScc;
     //   printf("?%d %d\n",u,nScc);
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
                rDFS(v);
                nScc++;
            }
        }
    }
}g;

void solve(){
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    k--;
    g.init(2*k*n);
    for(int i = 0;i<n;i++){
        for(int j = 0;j<k-1;j++){
            g.add_edge(2*k*i+j,2*k*i+j+1);
            //a_i <= j// 2*k*i+j
        }
        for(int j = 1;j<k;j++){
            g.add_edge(2*k*i+j+k,2*k*i+j+k-1);
            //a_i >j // 2*k*i+k+j
        }
    }
    for(int i = 0;i<n-1;i++){
        for(int j = 0;j<k;j++){
            g.add_edge(2*k*i+j+k,2*k*(i+1)+j+k);
        }
    }
    for(int i = 1;i<n;i++){
        for(int j =0;j<k;j++){
            g.add_edge(2*k*i+j,2*k*(i-1)+j);
        }
    }
    for(int i = 0;i<m;i++){
        int t;
        scanf("%d",&t);
        if(t==1){
            int p,x;
            scanf("%d %d",&p,&x);
            p--;
            if(x!=1){
          
                if(x!=k+1){
                    g.add_edge(2*k*p+x-1,2*k*p+x-2);
                    g.add_edge(2*k*p+k+x-2,2*k*p+k+x-1);
                }
                else{
                g.add_edge(2*k*p+k+x-2,2*k*p+x-2);
                }
            }
            else
             g.add_edge(2*k*p+x-1,2*k*p+x-1+k);
        }
        if(t==2){
            int a,b,x;
            scanf("%d %d %d",&a,&b,&x);
            a--;
            b--;
            for(int i = 2;i<=k+1;i++){
                if(i>=x){
                    g.add_edge(2*k*a+i+k-2,2*k*a+i-2);
                    g.add_edge(2*k*b+i+k-2,2*k*b+i-2);
                } else{
                    if(x-i<=k){
                        g.add_edge(2*k*a+i+k-2,2*k*b+(x-i)-1);
                        g.add_edge(2*k*b+i+k-2,2*k*a+(x-i)-1);
                    }
                }
            }
        }
        if(t==3){
            int a,b,x;
            scanf("%d %d %d",&a,&b,&x);
            a--;
            b--;
            for(int i = 1;i<=k;i++){
                if(i+k+1<x){
                    g.add_edge(2*k*a+i-1,2*k*a+i+k-1);
                    g.add_edge(2*k*b+i-1,2*k*b+i+k-1);
                } else{
                    if(i+1<x){
                        g.add_edge(2*k*a+i-1,2*k*b+(x-i-1)+k-1);
                        g.add_edge(2*k*b+i-1,2*k*a+(x-i-1)+k-1);
                    }
                }
            }
        }
    }
    g.solve();
    vector<int> r;
    for(int i = 0;i<n;i++){
        int ans=k+1;
        for(int j = 0;j<k;j++){
            if(g.bln[2*k*i+j]==g.bln[2*k*i+j+k]){
                printf("-1\n");
                return;
            }
        }
        for(int j=0;j<k;j++){
            if(g.bln[2*k*i+j]>g.bln[2*k*i+j+k]){
                ans=j+1;
                break;
            }
        }
        r.pb(ans);
    }
    for(auto it:r)printf("%d ",it);
    printf("\n");
}
int main(){
 //   srand(time(NULL));
    int t=1;0000;
    scanf("%d",&t);
    //int res=0;
   
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}