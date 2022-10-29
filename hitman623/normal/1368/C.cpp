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

void solve(){
    int k;
    cin>>k;
    vii v;
    int cur=0;
    rep(i,0,k+1){
        rep(j,0,3){
            rep(l,0,3){
                if(j==1 and l==1) continue;
                v.pb({cur+j,cur+l});
            }
        }
        cur+=2;
    }
    sort(all(v));
    v.resize(unique(all(v))-v.begin());
    cout<<sz(v)<<endl;
    for(auto i:v) cout<<i.x<<" "<<i.y<<endl;
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