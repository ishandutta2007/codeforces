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
int n,h,sum[200005];
vii v;
void solve(){
    cin>>n>>h;
    rep(i,0,n){
        int x,y;
        cin>>x>>y;
        v.pb({x,y});
    }
    v.pb({2*hell,2*hell+1});
    sort(all(v));
    for(int i=n-1;i>=0;i--){
        sum[i]=v[i+1].x-v[i].y;
    }
    int p=0,cur=0,ans=0;
    rep(i,0,sz(v)-1){
        while(cur<h) cur+=sum[p++];
        ans=max(ans,h-(cur-sum[p-1])+v[p-1].y-v[i].x);
        cur-=sum[i];
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