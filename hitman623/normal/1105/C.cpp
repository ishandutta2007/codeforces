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
int n,l,r;
int dp[200005][3];
void solve(){
    cin>>n>>l>>r;
    int f[]={r/3-(l-1)/3,(r+1)/3-l/3,(r+2)/3-(l+1)/3};
    dp[0][0]=1;
    rep(i,1,n+1){
    	rep(j,0,3){
    		rep(k,0,3){
    			dp[i][j]=(dp[i][j]+dp[i-1][(j-k+3)%3]*f[k])%hell;
    		}
    	}
    }
    cout<<dp[n][0]<<endl;
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