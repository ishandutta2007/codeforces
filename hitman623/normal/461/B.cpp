#include <bits/stdc++.h>

#define int         long long
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
int n,dp[100005][2],col[100005];
vi a[100005];
void dfs(int node){
    for(auto i:a[node]) dfs(i);
    dp[node][0]=col[node]==0;
    dp[node][1]=1;
    for(auto i:a[node]){
        dp[node][0]=dp[node][0]*(dp[i][0]+dp[i][1])%hell;
        if(col[node]==1) dp[node][1]=dp[node][1]*(dp[i][0]+dp[i][1])%hell;
    }
    if(col[node]==1) return;
    dp[node][1]=0;
    if(!sz(a[node])) return;
    vi prefix(sz(a[node]));
    vi suffix(sz(a[node]));
    prefix[0]=dp[a[node][0]][0]+dp[a[node][0]][1];
    rep(i,1,sz(a[node])){
        prefix[i]=prefix[i-1]*(dp[a[node][i]][1]+dp[a[node][i]][0])%hell;
    }
    suffix[sz(a[node])-1]=dp[a[node].back()][0]+dp[a[node].back()][1];
    for(int i=sz(a[node])-2;i>=0;i--){
        suffix[i]=suffix[i+1]*(dp[a[node][i]][1]+dp[a[node][i]][0])%hell;
    }
    rep(i,0,sz(a[node])){
        int cur=dp[a[node][i]][1];
        if(i) cur=cur*prefix[i-1]%hell;
        if(i<sz(a[node])-1) cur=cur*suffix[i+1]%hell;
        dp[node][1]+=cur;
        dp[node][1]%=hell;
    }
}
void solve(){
    cin>>n;
    rep(i,1,n){
        int x;
        cin>>x;
        a[x].pb(i);
    }
    rep(i,0,n) cin>>col[i];
    dfs(0);
    cout<<dp[0][1]<<endl;
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