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
int n,k,dp[2002][4004],s[2002];
int go(int pos,int del){
    if(pos==1){
        if(del==0) return k-2*(s[1]!=s[n]);
        if(s[1]==s[n]) return 0;
        if(del==1) return 1;
        if(del==-1) return 1;
        return 0;
    }
    int &ans=dp[pos][del+2002];
    if(ans!=-1) return ans;
    ans=0;
    if(s[pos]==s[pos-1]) ans=(ans+k*go(pos-1,del))%hell;
    else ans=(ans+go(pos-1,del-1)+go(pos-1,del+1)+(k-2)*go(pos-1,del))%hell;
    return ans;
}
void solve(){
    cin>>n>>k;
    rep(i,1,n+1) cin>>s[i];
    memset(dp,-1,sizeof dp);
    int ans=0;
    rep(i,1,n+1) ans=(ans+go(n,i))%hell;
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