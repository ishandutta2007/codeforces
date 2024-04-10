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
    vector<array<int, 2>> rg(n);
    for(auto &[l, r] : rg) cin>>l>>r;
    vector<vector<int>> g(n);
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        --u;--v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<array<ll, 2>> dp(n, {0, 0});
    function<void(int, int)> dfs = [&](int u, int par){
        for(auto &v : g[u]){
            if(v == par) continue;
            dfs(v, u);
            dp[u][0] += max(abs(rg[u][0] - rg[v][0]) + dp[v][0], abs(rg[u][0] - rg[v][1]) + dp[v][1]);
            dp[u][1] += max(abs(rg[u][1] - rg[v][0]) + dp[v][0], abs(rg[u][1] - rg[v][1]) + dp[v][1]);
        }
    };
    dfs(0, 0);
    cout<<max(dp[0][0], dp[0][1])<<'\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}