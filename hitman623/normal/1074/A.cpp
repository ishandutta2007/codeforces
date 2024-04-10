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
int n,m,ans=hell;
vi ranges;
vi v;
void solve(){
    cin>>n>>m;
    rep(i,0,n){
        int x;
        cin>>x;
        v.pb(x);
    }
    rep(i,0,m){
        int x1,x2,y;
        cin>>x1>>x2>>y;
        if(x1==1) ranges.pb(x2);
    }
    v.pb(1e9);
    sort(all(v));
    v.resize(unique(all(v))-v.begin());
    sort(all(ranges));
    int cur=0,ver=0;
    rep(i,0,sz(v)){
        while(cur<sz(ranges) and ranges[cur]<v[i]){
            cur++;
        }
        ans=min(ans,ver+sz(ranges)-cur);
        ver++;
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