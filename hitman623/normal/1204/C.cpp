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
int n,dp[101][101],m,b[1000006];
string s[101];
void solve(){
    cin>>n;
    rep(i,0,n) cin>>s[i];
    rep(i,0,n){
        rep(j,0,n){
            dp[i+1][j+1]=s[i][j]-'0';
            if(dp[i+1][j+1]==0) dp[i+1][j+1]=hell;
        }
    }
    rep(k,1,n+1){
        rep(i,1,n+1){
            rep(j,1,n+1){
                dp[i][j]=min(dp[i][k]+dp[k][j],dp[i][j]);
            }
        }
    }
    cin>>m;
    rep(i,0,m) cin>>b[i];
    vi v;
    int cur=0;
    v.pb(b[cur]);
    rep(i,1,m){
        if(dp[b[cur]][b[i]]!=i-cur or v.back()==b[i]){
            v.pb(b[i-1]);
            cur=i-1;
            i--;
        }
    }
    v.pb(b[m-1]);
    cout<<sz(v)<<endl;
    for(auto i:v) cout<<i<<" ";
    cout<<endl;
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