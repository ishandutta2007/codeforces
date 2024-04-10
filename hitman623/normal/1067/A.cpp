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
#define hell        998244353
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,dp[100005][202][2],sum[100005][202][2],a[100005];
void solve(){
    cin>>n;
    rep(i,1,n+1) cin>>a[i];
    if(a[1]==-1){
        rep(j,1,201){
            dp[1][j][0]=1;
            dp[1][j][1]=0;
        }
    }
    else{
        dp[1][a[1]][0]=1;
    }
    rep(j,1,201){
        sum[1][j][0]=(0LL+sum[1][j-1][0]+dp[1][j][0])%hell;
        sum[1][j][1]=(0LL+sum[1][j-1][1]+dp[1][j][1])%hell;
    }
    rep(i,2,n+1){
        if(a[i]!=-1){
            rep(j,1,201){
                if(j<a[i]) dp[i][a[i]][0]=(0LL+dp[i][a[i]][0]+dp[i-1][j][0]+dp[i-1][j][1])%hell;
                if(j>=a[i]) dp[i][a[i]][1]=(0LL+dp[i][a[i]][1]+(j==a[i]?dp[i-1][j][0]:0)+dp[i-1][j][1])%hell;
            }
        }
        else{
            rep(j,1,201){
                dp[i][j][0]=(0LL+dp[i][j][0]+sum[i-1][j-1][1]+sum[i-1][j-1][0])%hell;
                dp[i][j][1]=(0LL+dp[i][j][1]+dp[i-1][j][0]+dp[i-1][j][1]+sum[i-1][200][1]-sum[i-1][j][1]+hell+hell)%hell;
            }
        }
        rep(j,1,201){
            sum[i][j][0]=(0LL+sum[i][j-1][0]+dp[i][j][0])%hell;
            sum[i][j][1]=(0LL+sum[i][j-1][1]+dp[i][j][1])%hell;
        }
    }
    cout<<sum[n][200][1]<<endl;
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