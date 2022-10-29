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
int n,Y,ans;
vii v;
mi f;
void solve(){
    cin>>n>>Y;
    rep(i,0,n){
        int y;
        cin>>y;
        v.pb({y,0});
        f[y]++;
    }
    cin>>n>>Y;
    rep(i,0,n){
        int y;
        cin>>y;
        v.pb({y,1});
        f[y]++;
    }
    for(auto i:f) ans=max(ans,i.y);
    int cur=1;
    rep(i,0,31){
        map<int,map<pii,int>> mp;
        for(auto j:v){
            mp[j.x%cur][{(j.x/cur)%2,j.y}]++;
        }
        for(auto j:mp){
            ans=max(ans,j.y[{0,0}]+j.y[{1,1}]);
            ans=max(ans,j.y[{1,0}]+j.y[{0,1}]);
        }
        cur*=2;
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