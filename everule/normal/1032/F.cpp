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
const int p = 998244353;
void solve(){
    int n;
    cin>>n;
    vector<vector<int>> adj(n);
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        --u;--v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<array<ll,3>> dp(n); //maximum unique matching requires root, doesnt require root, free 
    function<void(int,int)> dfs = [&](int u,int par){
        dp[u][0] = 0;
        dp[u][1] = 1;
        dp[u][2] = 1;
        for(const auto &v : adj[u]){
            if(v == par) continue;
            dfs(v,u);
            dp[u][0] *= (2 * dp[v][0] + dp[v][2]);
            dp[u][0] %= p;
            dp[u][0] += dp[u][1] * dp[v][1];
            dp[u][0] %= p;
            dp[u][2] *= (dp[v][0] + dp[v][2]);
            dp[u][2] %= p;
            dp[u][1] *= (2 * dp[v][0] + dp[v][2]); 
            dp[u][1] %= p;
        }
    };
    dfs(0,0);
    cout<< (dp[0][0] + dp[0][2])% p <<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}