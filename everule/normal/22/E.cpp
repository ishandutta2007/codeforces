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
    vector<int> p(n);
    cin>>p;
    for(auto &f : p) --f;
    vector<vector<int>> adj(n);
    vector<bool> leaf(n,1);
    for(int i=0;i<n;i++){
        adj[i].pb(p[i]);
        adj[p[i]].pb(i);
        leaf[p[i]] = 0;
    }
    vector<vector<int>> components;
    vector<vector<int>> leaves;
    vector<bool> vis(n);
    function<void(int)> dfs = [&](int u){
        vis[u] = 1;
        components.back().push_back(u);
        if(leaf[u]) leaves.back().push_back(u);
        for(const auto &v : adj[u]){
            if(!vis[v]){
                dfs(v);
            }
        }
    };
    for(int i=0;i<n;i++){
        if(!vis[i]){
            components.push_back({});
            leaves.push_back({});
            dfs(i);
        }
    }
    vis.assign(n, 0);
    function<int(int)> findrep = [&](int x){
        vis[x] = 1;
        if(!vis[p[x]]) return findrep(p[x]);
        else return x;
    };
    int c = components.size();
    vector<pair<int,int>> ans;
    vector<int> rep(c);
    for(int i=0;i<c;i++){
        rep[i] = findrep(components[i][0]);
    }
    for(int i=0;i<c;i++){
        if(leaves[(i+1)%c].size() == 0 && c!=1){
            ans.push_back(pair(rep[i], rep[(i+1)%c]));
            continue;
        }
        for(const auto &l : leaves[(i+1)%c]){
            ans.push_back(pair(rep[i], l));
        }
    }
    cout<<ans.size()<<"\n";
    for(const auto &[x,y] : ans){
        cout<<x+1<<" "<<y+1<<"\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}