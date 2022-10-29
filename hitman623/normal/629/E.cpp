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
#define hell2       1000000009
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,m,par[100005],dis[100005],dp[20][100005],vis[100005];
vi a[100005];
double cnt[100005],sum[100005],rootsum[100005];
void dfs(int node){
    vis[node]=1;
    cnt[node]=1;
    for(auto i:a[node]){
        if(!vis[i]){
            par[i]=node;
            dis[i]=dis[node]+1;
            dfs(i);
            cnt[node]+=cnt[i];
            sum[node]+=sum[i]+cnt[i];
        }
    }
}
void dfs2(int node){
    vis[node]=1;
    for(auto i:a[node]){
        if(!vis[i]){
            rootsum[i]=rootsum[node]-2*cnt[i]+n;
            dfs2(i);
        }
    }
}
void pre(){
    rep(j,0,20){
        rep(i,1,n+1){
            if(j==0) dp[j][i]=par[i];
            else dp[j][i]=dp[j-1][dp[j-1][i]];
        }
    }
}
int lca(int u,int v){
    if(u==v) return u;
    if(dis[u]<dis[v]) return lca(v,u);
    for(int j=19;j>=0;j--){
        if(dis[u]-(1<<j)>=dis[v]){
            u=dp[j][u];
        }
    }
    if(u==v) return u;
    for(int j=19;j>=0;j--){
        if(dp[j][u]!=dp[j][v]){
            u=dp[j][u];
            v=dp[j][v];
        }
    }
    return par[u];
}
int f(int u,int v){
    for(int j=19;j>=0;j--){
        if(dis[v]-(1<<j)>dis[u]){
            v=dp[j][v];
        }
    }
    return v;
}
void solve(){
    cin>>n>>m;
    rep(i,0,n-1){
        int x,y;
        cin>>x>>y;
        a[x].pb(y);
        a[y].pb(x);
    }
    dfs(1);
    pre();
    rootsum[1]=sum[1];
    memset(vis,0,sizeof vis);
    dfs2(1);
    rep(i,0,m){
        int u,v;
        cin>>u>>v;
        int l=lca(u,v);
        double ans=dis[u]+dis[v]-2*dis[l]+1;
        if(l==u){
            int g=f(u,v);
            ans+=(rootsum[u]-(sum[g]+cnt[g]))/(n-cnt[g])+sum[v]/cnt[v];
        }
        else if(l==v){
            int g=f(v,u);
            ans+=(rootsum[v]-(sum[g]+cnt[g]))/(n-cnt[g])+sum[u]/cnt[u];
        }
        else{
            ans+=sum[u]/cnt[u]+sum[v]/cnt[v];
        }
        cout<<fixed<<setprecision(10)<<ans<<endl;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
//    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}