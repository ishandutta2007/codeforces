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
int n,x[100005],y[100005],z[100005];
map<int,vi> vx;
vii ans;
void solve(){
    cin>>n;
    rep(i,1,n+1){
        cin>>x[i]>>y[i]>>z[i];
        vx[x[i]].pb(i);
    }
    vi dextra;
    for(auto i:vx){
        map<int,vii> vy;
        for(auto j:i.y){
            vy[y[j]].pb({z[j],j});
        }
        vi extra;
        for(auto j:vy){
            sort(all(j.y));
            rep(k,0,sz(j.y)/2){
                ans.pb({j.y[2*k].y,j.y[2*k+1].y});
            }
            if(sz(j.y)%2) extra.pb(j.y.back().y); 
        }
        rep(k,0,sz(extra)/2){
            ans.pb({extra[2*k],extra[2*k+1]});
        }
        if(sz(extra)%2) dextra.pb(extra.back());
    }
    rep(k,0,sz(dextra)/2){
        ans.pb({dextra[2*k],dextra[2*k+1]});
    }
    for(auto i:ans) cout<<i.x<<" "<<i.y<<endl;
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