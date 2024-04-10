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
int n,dp[505][505];
string s;
int go(int l,int r){
    if(l>r) return 0;
    int &ans=dp[l][r];
    if(ans!=-1) return ans;
    ans=go(l+1,r)+1;
    rep(j,l+1,r+1){
        if(s[j]==s[l]) ans=min(ans,go(l+1,j-1)+go(j,r));
    }
    return ans;
}
void solve(){
    cin>>n>>s;
    memset(dp,-1,sizeof dp);
    cout<<go(0,n-1)<<endl;
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