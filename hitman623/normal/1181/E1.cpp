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
bool go(vector<pair<pii,pii>> v){
    if(sz(v)<=2) return true;
    int n=sz(v);
    vi active(n,0);
    vector<pair<int,pii>> w;
    rep(j,0,sz(v)){
        auto i=v[j];
        w.pb({i.x.x,{1,j}});
        w.pb({i.y.x,{-1,j}});
    }
    sort(all(w));
    int cur=0;
    for(auto i:w){
        cur+=i.y.x;
        if(i.y.x==1) active[i.y.y]=1;
        if(cur==0){
            vector<pair<pii,pii>> v1,v2;
            rep(j,0,n){
                if(active[j]) v1.pb(v[j]);
                else v2.pb(v[j]);
            }
            if(sz(v1)==n) break;
            return go(v1) and go(v2);
        }
    }
    w.clear();
    rep(j,0,sz(v)){
        auto i=v[j];
        w.pb({i.x.y,{1,j}});
        w.pb({i.y.y,{-1,j}});
    }
    active.clear();
    active.resize(n);
    sort(all(w));
    cur=0;
    for(auto i:w){
        cur+=i.y.x;
        if(i.y.x==1) active[i.y.y]=1;
        if(cur==0){
            vector<pair<pii,pii>> v1,v2;
            rep(j,0,n){
                if(active[j]) v1.pb(v[j]);
                else v2.pb(v[j]);
            }
            if(sz(v1)==n) break;
            return go(v1) and go(v2);
        }
    }
    return false;
}
void solve(){
    int n;
    vector<pair<pii,pii>> v;
    cin>>n;
    rep(i,0,n){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        v.pb({{a,b},{c,d}});
    }
    if(go(v)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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