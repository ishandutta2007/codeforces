#include <iostream>
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std;
using ll = long long int;
const int p = 998244353;
void solve(){
    int n;
    cin>>n;
    vector<vector<int>> adj(n);
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        --u;--v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<ll> dp1(n, 1);//includes root, and root in independent set
    vector<ll> dp2(n, 1);//includes root and root not in independent set
    vector<ll> dp3(n, 1);//doesn't include root
    function<void(int,int)> dfs = [&](int u,int par){
        for(const auto &v : adj[u]){
            if(v==par) continue;
            dfs(v, u);
            dp1[u] *= (1 + dp1[v] + dp2[v] + dp3[v] + dp2[v] + (1+dp3[v]))%p;
            dp2[u] *= (1 + dp1[v] + dp2[v] + dp3[v] + dp1[v] + dp2[v] + 2*(1+dp3[v]))%p;
            dp3[u] *= (1 + dp1[v] + dp2[v] + dp3[v]);
            dp1[u]%=p;
            dp2[u]%=p;
            dp3[u]%=p;
        }
        dp1[u]-=dp3[u];
        dp2[u]-=dp3[u];
        --dp3[u];
    };
    dfs(0, -1);
    ll ans = dp1[0] + dp2[0] + dp3[0];
    ans%=p;
    if(ans<0){
        ans+=p;
    }
    cout<<ans<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}