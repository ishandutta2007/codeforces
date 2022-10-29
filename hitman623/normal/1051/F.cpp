#include <bits/stdc++.h>

#define int         long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,m,vis[100005],dp[20][100005],height[100005],dis[100005];
vii a[100005];
vector<pair<pii,pii>> edges;
void dfs(int node,int d,int par){
    dis[node]=d;
    vis[node]=1;
    height[node]=height[par]+1;
    dp[0][node]=par;
    for(auto i:a[node]){
        if(i.x==par) continue;
        if(vis[i.x]){
            if(i.x<node){
                edges.pb({{i.x,node},{i.y,abs(dis[node]-dis[i.x])}});
            }
            continue;
        }
        dfs(i.x,d+i.y,node);
    }
}
void pre(){
    rep(i,1,18){
        rep(j,1,n+1){
            dp[i][j]=dp[i-1][dp[i-1][j]];
        }
    }
}
int lca(int u,int v){
    if(height[u]>height[v])swap(u,v);
    for(int i=17;i>=0;i--){
        if(height[v]-(1<<i)>=height[u])v=dp[i][v];
    }
    if(u==v)return u;
    for(int i=17;i>=0;i--){
        if(dp[i][u]!=dp[i][v])u=dp[i][u],v=dp[i][v];
    }
    return dp[0][u];
}
int path[55][55];
void solve(){
    cin>>n>>m;
    rep(i,0,m){
        int u,v,d;
        cin>>u>>v>>d;
        a[u].pb({v,d});
        a[v].pb({u,d});
    }
    dfs(1,0,0);
    pre();
    mi s;
    for(auto i:edges){
        s[i.x.x];
        s[i.x.y];
    }
    int cnt=0;
    for(auto &i:s){
        i.y=cnt++;
    }
    vii nodes(all(s));
    memset(path,1,sizeof path);
    rep(i,0,sz(nodes)) path[i][i]=0;
    for(auto i:edges){
        path[s[i.x.x]][s[i.x.y]]=min({path[s[i.x.x]][s[i.x.y]],i.y.x,i.y.y});
        path[s[i.x.y]][s[i.x.x]]=min({path[s[i.x.y]][s[i.x.x]],i.y.x,i.y.y});
    }
    for(auto i:nodes){
        for(auto j:nodes){
            path[i.y][j.y]=min(path[i.y][j.y],dis[i.x]+dis[j.x]-2*dis[lca(i.x,j.x)]);
            path[j.y][i.y]=min(path[j.y][i.y],dis[i.x]+dis[j.x]-2*dis[lca(i.x,j.x)]);
        }
    }
    rep(k,0,sz(nodes)){
        rep(i,0,sz(nodes)){
            rep(j,0,sz(nodes)){
                path[i][j]=min(path[i][j],path[i][k]+path[k][j]);
            }
        }
    }
    int q;
    cin>>q;
    while(q--){
        int u,v,store[2][55],ans;
        cin>>u>>v;
        ans=dis[u]+dis[v]-2*dis[lca(u,v)];
        rep(i,0,sz(nodes)){
            store[0][i]=lca(u,nodes[i].x);
            store[1][i]=lca(v,nodes[i].x);
        }
        rep(i,0,sz(nodes)){
            rep(j,0,sz(nodes)){
                ans=min(ans,dis[u]+dis[nodes[i].x]-2*dis[store[0][i]]+path[i][j]+dis[v]+dis[nodes[j].x]-2*dis[store[1][j]]);
            }
        }
        cout<<ans<<endl;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}