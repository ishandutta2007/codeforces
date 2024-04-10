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
int n,m,d,a[303],b[303],t[300005],dp[300005][2],ans=-hell;
void solve(){
    cin>>n>>m>>d;
    rep(i,0,m){
        cin>>a[i]>>b[i]>>t[i];
    }
    rep(j,1,n+1){
        dp[j][0]=b[0]-abs(a[0]-j);
    }
    rep(i,1,m){
        int k=min(n,(t[i]-t[i-1])*d),K=2*k+1;
        deque<pii> window;
        rep(j,1,n+k+1){
            if(j>n) dp[j][!(i&1)]=LLONG_MIN;
            while(!window.empty() && window.back().first<=dp[j][!(i&1)]){
                window.pop_back();
            }
            window.push_back({dp[j][!(i&1)],j});
            while(window.front().second<=j-K){
                window.pop_front();
            }
            if(j>k){
                dp[j-k][i&1]=b[i]-abs(a[i]-j+k)+window.front().first;
            }
        }
        if(i==m-1){
            rep(j,1,n+1){
                ans=max(ans,dp[j][i&1]);
            }
        }
    }
    cout<<ans<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}