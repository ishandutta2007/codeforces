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
int n,m,a[2002],b[2002],ans,x;
void solve(){
    cin>>n>>m;
    rep(i,0,n){
        cin>>a[i];
    }
    rep(i,0,m){
        cin>>b[i];
    }
    vii v;
    rep(i,0,m){
        int cur=0;
        rep(j,i,m){
            cur+=b[j];
            v.pb({cur,j-i+1});
        }
    }
    sort(all(v));
    rep(i,1,sz(v)){
        v[i].y=max(v[i].y,v[i-1].y);
    }
    cin>>x;
    rep(i,0,n){
        int cur=0;
        rep(j,i,n){
            cur+=a[j];
            int d=x/cur;
            pii temp={d,INT_MAX};
            int l=upper_bound(all(v),temp)-v.begin()-1;
            if(l>=0) ans=max(ans,(j-i+1)*v[l].y);
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