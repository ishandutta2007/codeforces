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
const int INF = 1e9 + 7;
void solve(){
    int n;
    cin>>n;
    vector<int> t(n);
    cin>>t;
    vector<vector<int>> adj(n);
    for(int i=1;i<n;i++){
        int p;
        cin>>p;
        --p;
        adj[p].push_back(i);
    }
    int k = 0;
    for(int i=0;i<n;i++) k += (adj[i].size() == 0);
    function<int(int)> dfs = [&](int u){
        if(adj[u].size() == 0) return 1;
        if(t[u] == 1){
            int ans = INF;
            for(auto &v : adj[u]) ans = min(ans, dfs(v));
            return ans;
        }
        else{
            int ans = 0;
            for(auto &v : adj[u]) ans += dfs(v);
            return ans;
        }
    };
    cout<<k + 1 - dfs(0)<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}