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
int n,k,dp[2002][2][2][2002];
int sol(int in,int c1,int c2,int cnt){
    if(cnt>k) return 0;
    if(in==n) return cnt==k;
    if(dp[in][c1][c2][cnt]!=-1) return dp[in][c1][c2][cnt]; 
    int ans=0;
    rep(i,0,2){
        rep(j,0,2){
            int d=0;
            if(i!=c1 and i!=j) d++;
            if(j!=c2 and j!=i) d++;
            if(i==j and i!=c1 and j!=c2) d++;
            ans=(ans+sol(in+1,i,j,cnt+d))%hell;
        }
    }
    return dp[in][c1][c2][cnt]=ans;
}
void solve(){
    cin>>n>>k;
    int ans=0;
    rep(i,0,2){
        rep(j,0,2){
            memset(dp,-1,sizeof dp);
            ans=(ans+sol(1,i,j,2-(i==j)))%hell;
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