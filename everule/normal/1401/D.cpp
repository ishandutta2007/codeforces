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
const int p = 1e9 + 7;
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
    int m;
    cin>>m;
    vector<int> prime(m);
    cin>>prime;
    while(m<n-1){
        prime.pb(1);
        ++m;
    }
    vector<ll> value;
    vector<int> subtree(n,1);
    function<void(int,int)> dfs = [&](int u,int par){
        for(const auto &v : adj[u]){
            if(v==par) continue;
            dfs(v,u);
            subtree[u]+=subtree[v];
        }
        if(subtree[u]==n) return;
        value.pb((ll)subtree[u]*(n - subtree[u]));
    };
    dfs(0,0);
    sort(value.begin(), value.end());
    sort(prime.begin(), prime.end());
    assert(value.size()==n-1);
    ll ans = 0;
    for(int i=0;i<n-2;i++){
        ans+=(value[i]%p) * prime[i];
        ans%=p;
    }
    ll last = 1;
    for(int i=n-2;i<m;i++){
        last*=prime[i];
        last%=p;
    }
    ans+=last*value[n-2];
    ans%=p;
    cout<<ans<<"\n";
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