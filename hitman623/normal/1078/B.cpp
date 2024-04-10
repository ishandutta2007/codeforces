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
int dp[2][10001][101],f[101];
int n,a[101],ans,s;
void solve(){
    memset(dp,-1,sizeof dp);
    cin>>n;
    rep(i,1,n+1){
        cin>>a[i];
        s+=a[i];
        f[a[i]]++;
    }
    dp[0][0][0]=0;
    rep(i,1,n+1){
        rep(j,0,s+1){
            rep(k,0,n+1){
                int f1=dp[!(i&1)][j][k]!=-1;
                int f2=(j>=a[i] and k>=1 and dp[!(i&1)][j-a[i]][k-1]!=-1);
                if(!f1 and !f2) dp[i&1][j][k]=-1;
                else if(!f1 and f2) dp[i&1][j][k]=dp[!(i&1)][j-a[i]][k-1];
                else if(f1 and !f2) dp[i&1][j][k]=(!dp[!(i&1)][j][k] or dp[!(i&1)][j][k]==a[i]?a[i]:hell);
                else if(dp[!(i&1)][j][k] and dp[!(i&1)][j][k]!=a[i]) dp[i&1][j][k]=hell;
                else if(dp[!(i&1)][j-a[i]][k-1] and dp[!(i&1)][j-a[i]][k-1]!=a[i]) dp[i&1][j][k]=hell;
                else dp[i&1][j][k]=a[i];
            }
        }
    }
    rep(i,0,s+1){
        rep(j,0,n+1){            
            if(dp[n&1][i][j]!=-1 and dp[n&1][i][j]!=hell and dp[n&1][i][j]){
                int cur=n-j;
                if(j and i%j==0 and f[i/j]==j) cur+=j;
                ans=max(ans,cur);
            }
        }
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