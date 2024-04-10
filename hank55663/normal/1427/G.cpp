#include<bits/stdc++.h>

/*#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
#define mp make_pair
#define pb push_back
#define pll pair<LL,LL>
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
int cnt2=0;
int en=0;
struct Dinic{
    static const int MXN = 100000;
    struct Edge{ int v,f,re; Edge(int a,int b,int c):v(a),f(b),re(c){}};
    int n,s,t,level[MXN];
    vector<Edge> E[MXN];
    void init(int _n, int _s, int _t){
        n = _n; s = _s; t = _t;
        for (int i=0; i<=n; i++) E[i].clear();
    }
    void add_edge(int u, int v, int f,int flag=0){
       // printf("edge:%d %d %d\n",u,v,f);
        en+=2;
        if(flag){
        E[u].pb(Edge(v,f,E[v].size()));
        E[v].pb(Edge(u,f,E[u].size()-1));
        }
        else{
        E[u].pb(Edge(v,f,E[v].size()));
        E[v].pb(Edge(u,0,E[u].size()-1));//direct
        }
    }
    bool BFS(){
        MEMS(level);
        queue<int> que;
        que.push(s);
        level[s] = 0;
        while (!que.empty()){
            //cnt2++;
            int u = que.front(); que.pop();
            for (auto &it : E[u]){
                cnt2++;
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
             cnt2++;
            if (it.f > 0 && level[it.v] == level[u]+1){
               /* if(it.v==t){
                    printf("%d %d\n",u,t);
                }*/
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
        while ( BFS() ){
            res += DFS(s,2147483647);
           
        }
        return res;
    }
}flow;
int vis[100005];
bool dfs(int x){
    if(vis[x])return false;
    if(x==0)return true;
    vis[x]=1;
    for(auto &it:flow.E[x]){
        cnt2++;
        if(it.f&&dfs(it.v)){
            it.f--;
            flow.E[it.v][it.re].f++;
            return true;
        }
    }
    return false;
}
bool dfs2(int x){
    if(vis[x])return false;
    if(x==flow.t)return true;
    vis[x]=1;
    for(auto &it:flow.E[x]){
        cnt2++;
        if(it.f&&dfs2(it.v)){
            it.f--;
            flow.E[it.v][it.re].f++;
            return true;
        }
    }
    return false;
}
void solve(){
    int n;
    scanf("%d",&n);
    int a[205][205];
    flow.init(n*n*2+2,0,n*n*2+1);
    int X[4]={0,0,-1,1};
    int Y[4]={1,-1,0,0};
    for(int i = 0;i<n;i++){
        for(int j =0;j<n;j++){
           // a[i][j]=rand()%1000000000;
            scanf("%d",&a[i][j]);
        }
    }
    /*
    for(int i = 1;i<n-1;i++){
        for(int j=1;j<n-1;j++){
            //a[i][j]=rand()%10;
            //if(a[i][j]==0)a[i][j]=-1;
            a[i][j]=0;
        }
    }*/
    /*for(int i = 1;i<n-1;i++){
        a[i][0]=rand();
        a[0][i]=rand();
        a[n-1][i]=rand();
        a[i][n-1]=rand();
    }*/
    for(int i = 0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]!=-1){
                flow.add_edge(i*n+j+1,i*n+j+n*n+1,1000000,1);
                //flow.add_edge(i*n+j+1+n*n,i*n+j+1,1000000);
                for(int k = 0;k<4;k++){
                    int x=X[k]+i,y=Y[k]+j;
                    if(x>=0&&x<n&&y>=0&&y<n&&a[x][y]!=-1&&(a[i][j]==0||a[x][y]==0)){
                        flow.add_edge(i*n+j+1,x*n+y+n*n+1,1);
                    }
                }
            }
        }
    }
    vector<pair<int,pii> > v;
    for(int i = 1;i<n-1;i++){
        v.pb(mp(a[0][i],mp(0,i)));
        flow.add_edge(n*n+i+1,n*n*2+1,1);
        v.pb(mp(a[n-1][i],mp(n-1,i)));
        flow.add_edge(n*n+i+(n-1)*n+1,n*n*2+1,1);
        v.pb(mp(a[i][0],mp(i,0)));
        flow.add_edge(n*n+i*n+1,n*n*2+1,1);
        v.pb(mp(a[i][n-1],mp(i,n-1)));
        flow.add_edge(n*n+i*n+n-1+1,n*n*2+1,1);
    }
    LL ans=0;
    for(int i = 0;i<n-1;i++){
        ans+=abs(a[0][i+1]-a[0][i]);
        ans+=abs(a[i][0]-a[i+1][0]);
        ans+=abs(a[n-1][i]-a[n-1][i+1]);
        ans+=abs(a[i][n-1]-a[i+1][n-1]);
    }
    sort(v.begin(),v.end());
    LL now=0;
    LL last=0;
    int tot=0;
    int cnt=0;
    for(auto it:v){
        fill(vis,vis+100005,0);
        while(dfs2(0)){
            now++;
            fill(vis,vis+100005,0);
        }
       // int tmp=flow.flow();
       // now+=tmp;//flow.flow();
       // tot+=tmp;
        //cnt++;
      //  printf("%d %d\n",cnt,tmp);
     //   printf("%lld %d %lld\n",now,it.x,last);
        ans+=now*(it.x-last);
        last=it.x;
        int x=it.y.x*n+it.y.y+1;
        flow.add_edge(0,x,1);
        for(auto &it:flow.E[x+n*n]){
            if(it.v==n*n*2+1){
                if(it.f==1){
                    it.f=0;
     //               printf("%d ??\n",x+n*n);
                }
                else{
                    flow.E[it.v][it.re].f=0;
                    now--;
       //             printf("?\n");
                    fill(vis,vis+100005,0);
                    dfs(x+n*n);
                }
            }
        }
    }
   // printf("%d %d %d\n",cnt,cnt2,en);
    printf("%lld\n",ans);
}

int main(){
/*    for(int i = 0;i<=1000;i++){
        p[i]=mp(-1,-1);
    }
    for(int i = 0;i*5<=1000;i++){
        for(int j = 0;i*5+j*7<=1000;j++){
            p[i*5+j*7]=mp(i,j);
        }
    }*/
    int t=1;
    while(t--){
        solve();
    }
}
/*


*/
/*
1 6 6
2 7 4
3 5 2
4 3 1
5 2 5
6 4 0
7 1 3
*/
/*
100
5
5 4
4 2
4 2 3
5 4 2 3 1
*/