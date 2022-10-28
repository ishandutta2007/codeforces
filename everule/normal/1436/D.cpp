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
    vector<vector<int>> adj(n);
    for(int i=1;i<n;i++){
        int p;
        cin>>p;
        --p;
        adj[p].pb(i);
    }
    vector<int> a(n);
    cin>>a;
    vector<ll> lv(n), sum(n);
    ll ans = 0;
    function<void(int)> dfs = [&](int u){
        if(adj[u].size()==0) lv[u] = 1;
        for(const auto &v : adj[u]){
            dfs(v);
            sum[u]+=sum[v];
            lv[u]+=lv[v];
        }
        sum[u]+=a[u];
        ans = max(ans, (sum[u] + lv[u] - 1)/lv[u]);
    };
    dfs(0);
    cout<<ans<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}