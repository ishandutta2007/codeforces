#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;++i)
#define debug(x) cerr<<#x<<": "<<x<<endl
#define sz(x) (int)(x).size()
#define trav(a,x) for(auto &a:x)
#define all(x) x.begin(), x.end()
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin>>n>>k;
    vector<vector<int>> g(n);
    rep(i,0,n-1) {
        int u,v;
        cin>>u>>v;
        --u;--v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> subsz(n,1), depth(n,0);
    function<void(int,int)> dfs = [&](int u, int p) {
        for(int v:g[u]) {
            if(v==p) continue;
            depth[v] = depth[u]+1;
            dfs(v,u);
            subsz[u] += subsz[v];
        }
        
    };
    dfs(0,-1);
    vector<ll> vals(n);
    rep(i,0,n) vals[i]=-(depth[i]-subsz[i]+1);
    sort(all(vals));
    ll ans=0;
    rep(i,0,k) ans-=vals[i];
    cout<<ans<<endl;
}