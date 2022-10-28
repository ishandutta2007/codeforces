#include <iostream>
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std;
using ll = long long int;
void solve(){
    int n,k;
    cin>>n>>k;
    vector<vector<int>> dp(n, vector<int>(k + 1));
    vector<vector<int>> adj(n);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        --u;--v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    function<ll(int,int)> dfs = [&](int u, int par){
        dp[u][0]=1;
        ll ans=0;
        for(const auto &node : adj[u]){
            if(node==par){
                continue;
            }
            ans+=dfs(node, u);
            for(int i=0;i<k;i++){
                ans+=(ll)dp[u][i]*dp[node][k-i-1];
            }
            for(int i=0;i<k;i++){
                dp[u][i+1]+=dp[node][i];
            }
        }
        return ans;
    };
    cout<<dfs(0,-1)<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}