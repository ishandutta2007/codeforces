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
    vector<int> w(n);
    cin>>w;
    for(int i=1;i<n;i++){
        int u,v,c;
        cin>>u>>v>>c;
        --u;--v;
        adj[u].pb({v,c});
        adj[v].pb({u,c});
    }
    function<void(int,int)> removepar = [&](int u,int p){
        for(int i=0;i<(adj[u].size());i++){
            if(adj[u][i].first==p){
                adj[u].erase(adj[u].begin() + i);
                break;
            }
        }
        for(const auto &[v,c] : adj[u]){
            removepar(v,u);
        }
    };
    removepar(0,0);
    vector<vector<ll>> dppre(n);
    vector<vector<ll>> dpsuf(n);
    vector<ll> dproot(n);
    vector<ll> dp1(n);
    function<void(int)> rootdp = [&](int u){
        int x = adj[u].size();
        dppre[u].resize(x+1), dpsuf[u].resize(x+1);
        dppre[u][0] = dpsuf[u][x] = w[u];
        for(int i=0;i<x;i++){
            const auto &[v,c] = adj[u][i];
            rootdp(v);
            dppre[u][i+1] = max(dppre[u][i], dp1[v] - c + w[u]); 
            dpsuf[u][i] = max(dpsuf[u][i+1], dp1[v] - c + w[u]);
        }
        dp1[u] = dppre[u][x];
    };
    rootdp(0);
    function<void(int,ll)> rerootdp = [&](int u, ll parv){
        dproot[u] = max(dp1[u], parv);
        int x = adj[u].size();
        for(int i=0;i<x;i++){
            const auto &[v,c] = adj[u][i];
            rerootdp(v, max({parv, dppre[u][i], dpsuf[u][i+1]})-c+w[v]);
        }
    };
    rerootdp(0,w[0]);
    cout<<*max_element(dproot.begin(), dproot.end())<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}