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
#define hell        100000000000007LL
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,dp[505][505];
int go(int l,int r){
    if(abs(l-r)<=1) return 0;
    int &ans=dp[l][r];
    if(ans!=-1) return ans;
    ans=hell; 
    rep(i,l+1,r) ans=min(ans,l*i*r+go(l,i)+go(i,r));
    return ans;
}
void solve(){
    cin>>n;
    memset(dp,-1,sizeof dp);
    cout<<go(1,n)<<endl;  
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