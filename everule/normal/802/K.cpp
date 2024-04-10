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
    int n,k;
    cin>>n>>k;
    vector<vector<array<int, 2>>> g(n);
    vector<array<int, 2>> dp(n, {0,0});
    for(int i=1;i<n;i++){
        int u,v,c;
        cin>>u>>v>>c;
        g[u].push_back({v, c});
        g[v].push_back({u, c});
    }
    function<void(int,int)> dfs = [&](int u,int p){
        vector<int> op;
        for(auto &[v,w] : g[u]){
            if(v == p) continue;
            dfs(v, u);
            op.push_back(dp[v][0] + w);
        }
        sort(op.begin(), op.end(), greater<int>());
        dp[u][0] = accumulate(op.begin(), op.begin() + min(k-1, (int)op.size()), 0ll);
        int bd = 0;
        for(auto [v,w] : g[u]){
            if(v == p) continue;
            if(dp[v][1] - max(k - 1 < op.size() ? op[k-1] : 0, dp[v][0] + w) + (k - 1 < op.size() ? op[k-1] : 0) + w > bd){
                bd = dp[v][1] - max(k - 1 < op.size() ? op[k-1] : 0, dp[v][0] + w) + (k - 1 < op.size() ? op[k-1] : 0) + w;
            }
        }
        dp[u][1] = dp[u][0] + bd;
    };
    dfs(0,0);
    //for(auto &[x,y] : dp) cout<<x<<" "<<y<<"\n";
    cout<<dp[0][1]<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}