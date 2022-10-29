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
int n,h[2][100005],dp[100005][2],ans;
void solve(){
    cin>>n;
    rep(i,0,2){
        rep(j,1,n+1){
            cin>>h[i][j];
        }
    }
    rep(i,1,n+1){
        dp[i][0]=max(dp[i-1][1],i>=2?max(dp[i-2][0],dp[i-2][1]):0)+h[0][i];
        dp[i][1]=max(dp[i-1][0],i>=2?max(dp[i-2][0],dp[i-2][1]):0)+h[1][i];
        ans=max(ans,dp[i][0]);
        ans=max(ans,dp[i][1]);
    }
    cout<<ans<<endl;
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