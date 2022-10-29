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
#define hell        998244353
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,dp[300005][2][2];
vi a[300005];
void dfs(int node,int par){
    int c10c11=1;
    int c10=1;
    int c00c01=1;
    for(auto i:a[node]){
        if(i!=par){
            dfs(i,node);
            c10c11=c10c11*(dp[i][1][0]+dp[i][1][1])%hell;
            c10=c10*dp[i][1][0]%hell;
            c00c01=c00c01*(dp[i][0][0]+dp[i][0][1])%hell;
        }
    }
    dp[node][0][0]=(c10c11-c10+c00c01+hell)%hell;
    dp[node][0][1]=(c10c11+c00c01)%hell;
    dp[node][1][0]=(c10c11-c10+c00c01+hell)%hell;
    dp[node][1][1]=c00c01;        
}
void solve(){
    cin>>n;
    rep(i,0,n-1){
        int x,y;
        cin>>x>>y;
        a[x].pb(y);
        a[y].pb(x);
    }
    dfs(1,-1);
    cout<<(dp[1][0][0]+hell-1)%hell<<endl;
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