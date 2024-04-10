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
int n,r,a[1001],dp[2001][2001];
int sol(int x,int y){
    if(x>n){
        if(y+r-1>=n) return 0;
        return hell;
    }
    if(dp[x][y+n]!=-1) return dp[x][y+n]; 
    int ans=hell;
    if(a[x] and (x-r+1)-(y+r-1)<=1) ans=min(ans,1+sol(x+1,x));
    ans=min(ans,sol(x+1,y));
    return dp[x][y+n]=ans;
}
void solve(){
    cin>>n>>r;
    rep(i,1,n+1){
        cin>>a[i];
    }
    memset(dp,-1,sizeof dp);
    int ans=sol(1,1-r);
    if(ans<1e8) cout<<ans<<endl;
    else cout<<-1<<endl;
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