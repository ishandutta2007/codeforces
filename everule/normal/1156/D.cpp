#include <iostream>
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std;
using ll = long long int;
template<typename T>
ostream& operator+(ostream& out, const vector<T> &vec){
    for(const auto &x : vec){
        out<<x<<" ";
    }
    out<<"\n";
    return out;
}
template<typename T>
ostream& operator*(ostream& out, const vector<T> &vec){
    for(const auto &x : vec){
        out+x;
    }
    return out;
}
template<typename T>
istream& operator>>(istream& in, vector<T> &vec){
    for(auto &x : vec){
        in>>x;
    }
    return in;
}
void solve(){
    int n;
    cin>>n;
    vector<vector<pair<int,int>>> adj(n);
    for(int i=0;i<n-1;i++){
        int u,v,w;
        cin>>u>>v>>w;
        --u;--v;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }
    vector<pair<ll,ll>> dp(n);//only 0, only 1
    vector<pair<ll,ll>> dp2(n);//1s at the top, 0s at the top
    vector<bool> vis;
    ll ans = 0;
    function<void(int,int)> dfs = [&](int u,int p){
        for(const auto &edge : adj[u]){
            if(edge.first == p){
                continue;
            }
            dfs(edge.first, u);
            if(edge.second){
                ans+=dp[u].first * (dp[edge.first].second) + dp[u].second * (2*dp[edge.first].second + dp2[edge.first].first + dp[edge.first].first) + dp2[u].first * (dp[edge.first].second);
                ans+=dp[edge.first].first + 2*dp[edge.first].second + dp2[edge.first].first;
                ans+=2*dp[u].second + dp[u].first + dp2[u].first;
                dp[u].second+=dp[edge.first].second+1;
                dp2[u].first+=dp2[edge.first].first+dp[edge.first].first;
            }
            else{
                ans+= dp[u].first * (2*dp[edge.first].first + dp[edge.first].second + dp2[edge.first].second) + dp[u].second * (dp[edge.first].first) + dp2[u].second * (dp[edge.first].first);
                ans+=2*dp[edge.first].first + dp[edge.first].second + dp2[edge.first].second;
                ans+=2*dp[u].first + dp[u].second + dp2[u].second;
                dp[u].first+=dp[edge.first].first+1;
                dp2[u].second += dp2[edge.first].second + dp[edge.first].second;
            }
            ans+=2;
        }
    };
    dfs(0, -1);
    cout<<ans<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}