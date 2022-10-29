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
#define hell        1000000000000000007LL
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,m,a[102][102],dp[102][102];
void solve(){
    vi v;
    cin>>n>>m;
    rep(i,1,n+1){
        rep(j,1,m+1){
            cin>>a[i][j];
            a[i][j]-=(i+j-2);
            v.pb(a[i][j]);
        }
    }
    sort(all(v));
    v.resize(unique(all(v))-v.begin());
    int ans=hell;
    for(auto k:v){
        rep(i,1,n+1){
            rep(j,1,m+1){
                if(a[i][j]<k) dp[i][j]=hell;
                else if(i+j==2) dp[i][j]=(a[i][j]-k);
                else dp[i][j]=min((i-1?dp[i-1][j]:hell),(j-1?dp[i][j-1]:hell))+(a[i][j]-k);
            }
        }
        ans=min(ans,dp[n][m]);
    }
    cout<<ans<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}