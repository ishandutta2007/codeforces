#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define debug(x) cerr<<#x<<": "<<x<<endl
#define trav(a,x) for(auto &a:x)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
const ll MOD = 998244353;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    rep(i,0,n-1) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> par(n,-1);
    function<tuple<ll,ll,ll>(int)> dfs = [&](int u) {
        ll x = 0;
        ll y = 1;
        ll z = 1;
        for(int v:g[u]) {
            if(v!=par[u]) {
                ll s, must, un;
                par[v] = u;
                tie(s,must,un) = dfs(v);
                ll xx = (x*(2*s+un)+y*must)%MOD;
                ll yy = (y*(2*s+un))%MOD;
                z = (z*(s+un))%MOD;
                x = xx;
                y = yy;
            }
        }
        return make_tuple(x,y,z);
    };
    ll x,y,z;
    tie(x,y,z) = dfs(0);
    // debug(x);
    // debug(y);
    // debug(z);
        
    ll ans = (x+z)%MOD;
    cout<<ans<<endl;
}