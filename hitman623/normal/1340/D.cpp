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
int n;
vi a[100005];
vii v;
void dfs(int node,int val,int par){
    int w=val;
    if(val>sz(a[node])){
        val-=sz(a[node]);
        v.pb({node,val});
    }
    for(auto i:a[node]){
        if(i==par) continue;
        ++val;
        if(val>w and val>sz(a[node])){
            val-=sz(a[node]);
            v.pb({node,val-1});
        }
        v.pb({i,val});
        dfs(i,val,node);
    }
    val++;
    if(par and val!=w){
        v.pb({node,w-1});
        val=w;
    }
    if(par) v.pb({par,val});
}
void solve(){
    cin>>n;
    rep(i,1,n){
        int x,y;
        cin>>x>>y;
        a[x].pb(y);
        a[y].pb(x);
    }
    v.pb({1,0});
    dfs(1,0,0);
    cout<<sz(v)<<endl;
    for(auto i:v) cout<<i.x<<' '<<i.y<<endl;
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