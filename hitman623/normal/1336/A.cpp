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
int n,k,h[200005],s[200005],ans;
vi a[200005];
void dfs(int node,int par){
    h[node]=h[par]+1;
    s[node]=1;
    for(auto i:a[node]){
        if(i!=par){
            dfs(i,node);
            s[node]+=s[i];
        }
    }
}
vi v;
void solve(){
    cin>>n>>k;
    rep(i,0,n-1){
        int x,y;
        cin>>x>>y;
        a[x].pb(y);
        a[y].pb(x);
    }
    dfs(1,0);
    rep(i,1,n+1) v.pb(h[i]-s[i]);
    sort(all(v));
    reverse(all(v));
    rep(i,0,k) ans+=v[i];
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