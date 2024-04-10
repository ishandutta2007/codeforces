#include <iostream>
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std;
using ll = long long int;
void solve(){
    int n;
    cin>>n;
    vector<vector<int>> adj(n);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        --u;--v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<vector<ll>> dp(n, vector<ll>(n, -1));
    vector<vector<int>> subtree(n, vector<int>(n, 1));
    vector<vector<int>> par(n, vector<int>(n));
    ll ans = -1;
    function<void(int,int,int)> getsubtreesize = [&](int u, int p, int root){
        par[root][u] = p;
        for(const auto &v : adj[u]){
            if(v==p) continue;
            getsubtreesize(v, u, root);
            subtree[root][u]+=subtree[root][v];
        }
    };
    for(int i=0;i<n;i++){
        getsubtreesize(i, -1, i);
    }
    function<ll(int,int)> solve = [&](int u,int v){
        if(u==v) return 0ll;
        if(~dp[u][v]) return dp[u][v];
        return dp[u][v] = (ll)subtree[u][v]*subtree[v][u] + max(solve(u, par[u][v]), solve(v, par[v][u]));
    };
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans = max(ans, solve(i,j));
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            assert(dp[i][j]==dp[j][i]);
        }
    }
    cout<<ans<<"\n";

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}