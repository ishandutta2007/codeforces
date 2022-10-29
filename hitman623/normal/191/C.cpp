#include <bits/stdc++.h>

#define ll          long long
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
int n,q,height[100005],val[100005],s[100005],dp[20][100005];
vi a[100005];
vii edges;
void dfs(int node,int par){
    height[node]=height[par]+1;
    s[node]=val[node];
    dp[0][node]=par;
    for(auto i:a[node]){
        if(i==par) continue;
        dfs(i,node);
        s[node]+=s[i];
    }
}
void pre(){
    rep(i,1,20){
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
void solve(){
    cin>>n;
    rep(i,0,n-1){
        int x,y;
        cin>>x>>y;
        a[x].pb(y);
        a[y].pb(x);
        edges.pb({x,y});
    }
    dfs(1,0);
    pre();
    cin>>q;
    while(q--){
        int x,y;
        cin>>x>>y;
        val[x]++;
        val[y]++;
        val[lca(x,y)]-=2;
    }
    dfs(1,0);
    for(auto i:edges){
        if(height[i.x]<height[i.y]) swap(i.x,i.y);
        cout<<s[i.x]<<" ";
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