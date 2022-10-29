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
int dp[2002][2002],n,m,l,cur,ans;
string s;
void solve(){
    dp[0][0]=1;
    rep(i,1,2001){
        rep(j,0,2001){
            dp[i][j]=((j?dp[i-1][j-1]:0)+dp[i-1][j+1])%hell;
        }
    }
    cin>>n>>m>>s;
    for(auto i:s){
        if(i=='(') cur++;
        else cur--;
        l=max(l,-cur);
    }
    rep(i,0,n-m+1){
        rep(j,l,n-m+1){
            if(j+cur<2001){
                ans=ans+dp[i][j]*dp[n-m-i][j+cur];
                ans%=hell;
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