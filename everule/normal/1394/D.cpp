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
    vector<int> t(n), h(n);
    cin>>t>>h;
    vector<vector<int>> adj(n);
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        --u;--v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<array<ll,2>> dp(n); //to, from
    function<void(int,int)> dfs = [&](int u,int p){
        int d = adj[u].size();
        int cntin = 0, cntout = 0;
        vector<ll> gain;
        ll curr = 0;
        for(const auto &v : adj[u]){
            if(v == p) continue;
            dfs(v,u);
            if(h[v] >= h[u]){
                cntout++;
                curr += dp[v][0];
            }
            else{
                cntin++;
                curr += dp[v][1];
            }
            if(h[v] == h[u]){
                gain.push_back(dp[v][1] - dp[v][0]);
            }
        }
        dp[u][0] = curr + 1LL * max(cntout, (d - cntout)) * t[u];
        dp[u][1] = curr + 1LL * max(cntin, (d - cntin)) * t[u];
        sort(gain.begin(), gain.end());
        for(auto &g : gain){
            cntin++;
            cntout--;
            curr += g;
            dp[u][0] = min(dp[u][0], curr + 1LL * max(cntout, (d - cntout)) * t[u]);
            dp[u][1] = min(dp[u][1], curr + 1LL * max(cntin, (d - cntin)) * t[u]);
        }
    };
    dfs(0,0);
    cout<<dp[0][0]<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}