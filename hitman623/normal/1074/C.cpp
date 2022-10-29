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
int n,mxx=-hell,mnx=hell,mxy=-hell,mny=hell;
int x[300005],y[300005];
void solve(){
    cin>>n;
    rep(i,0,n){
        cin>>x[i]>>y[i];
        mxx=max(mxx,x[i]);
        mnx=min(mnx,x[i]);
        mxy=max(mxy,y[i]);
        mny=min(mny,y[i]);
    }
    int ans=0;
    rep(i,0,n){
        ans=max(ans,max(mxx-x[i],x[i]-mnx)+max(mxy-y[i],y[i]-mny));
    }
    cout<<2*ans<<" ";
    rep(i,4,n+1){
        cout<<2*(mxx+mxy-mnx-mny)<<" ";
    }
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