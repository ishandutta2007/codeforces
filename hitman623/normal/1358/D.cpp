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
int n,x,d[400005],w[400005],p[400005];
void solve(){
    cin>>n>>x;
    rep(i,1,n+1) cin>>d[i];
    rep(i,n+1,2*n+1) d[i]=d[i-n];
    n*=2;
    rep(i,1,n+1) p[i]=p[i-1]+d[i];
    rep(i,1,n+1) w[i]=w[i-1]+d[i]*(d[i]+1)/2;
    int ans=0;
    rep(i,1,n+1){
        int l=upper_bound(p,p+n+1,p[i]-x)-p;
        if(l==0) continue;
        int rem=x-p[i]+p[l];
        int cur=w[i]-w[l]+d[l]*(d[l]+1)/2-(d[l]-rem)*(d[l]-rem+1)/2;
        ans=max(ans,cur);
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