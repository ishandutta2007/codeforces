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
int n,a[100005],dp[100005];
int sol(int in){
    if(in<=0) return 0;
    if(dp[in]!=-1) return dp[in];
    return dp[in]=max(a[in]*in+sol(in-2),sol(in-1));
}
void solve(){
    memset(dp,-1,sizeof dp);
    cin>>n;
    rep(i,0,n){
        int x;
        cin>>x;
        a[x]++;
    }
    cout<<sol(100000)<<endl;
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