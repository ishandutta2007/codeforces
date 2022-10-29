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
#define hell        2000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,m[2],x[2][2005],dp[2][2001],h[2][2005],s[2][2005],id[2][2005],cost[2][2001][2001];
vi a[2][2005],b[2][2005];
void dfs(int node,int par,int f){
    s[f][node]=1;
    h[f][node]=h[f][par]+1;
    int leaf=1;
    for(auto i:a[f][node]){
        if(i!=par){
            leaf=0;
            dfs(i,node,f);
            for(auto j:b[f][i]) b[f][node].pb(j);
            s[f][node]+=s[f][i];
        }
    }
    if(leaf) b[f][node].pb(id[f][node]);
    int l=n+1,r=0;
    for(auto i:b[f][node]) l=min(l,i),r=max(r,i);
    cost[f][l][r]=max(cost[f][l][r],s[f][node]);
}
void solve(){
    cin>>n;
    rep(f,0,2){
        cin>>m[f];
        rep(i,2,m[f]+1){
            int w;
            cin>>w;
            a[f][w].pb(i);
            a[f][i].pb(w);
        }
        rep(i,1,n+1){
            cin>>x[f][i];
            id[f][x[f][i]]=i;
        }        
    }
    dfs(1,1,0);
    dfs(1,1,1);
    cost[0][1][n]--;
    cost[1][1][n]--;
    rep(i,1,n+1){
        for(int j=i;j>=1;j--){
            dp[0][i]=max(dp[0][i],max(dp[1][j-1],dp[0][j-1])+cost[0][j][i]);
            dp[1][i]=max(dp[1][i],max(dp[1][j-1],dp[0][j-1])+cost[1][j][i]);
        }
    }
    cout<<max(dp[0][n],dp[1][n])<<endl;
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