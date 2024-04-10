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
    int n,m;
    cin>>n>>m;
    vector<char> r(n), c(m);
    cin>>r>>c;
    vector<vector<int>> adj(n*m);
    for(int i=0;i<n;i++){
        for(int j=1;j<m;j++){
            if(r[i]=='<'){
                adj[i*m + j].pb(i*m + j-1);
            }
            else{
                adj[i*m+j-1].pb(i*m + j);
            }
        }
    }
    for(int j=0;j<m;j++){
        for(int i=1;i<n;i++){
            if(c[j]=='^'){
                adj[i*m + j].pb((i-1)*m + j);
            }
            else{
                adj[(i-1)*m + j].pb(i*m + j);
            }
        }
    }
    vector<bool> vis;
    function<void(int)> dfs = [&](int u){
        vis[u] = 1;
        for(const auto &x : adj[u]){
            if(vis[x]) continue;
            dfs(x);
        }
    };
    bool ans = 1;
    for(int i=0;i<n*m;i++){
        vis = vector<bool>(n*m);
        dfs(i);
        for(int j=0;j<n*m;j++){
            ans&=vis[j];
        }
    }
    cout<<(ans ? "YES" : "NO");
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}