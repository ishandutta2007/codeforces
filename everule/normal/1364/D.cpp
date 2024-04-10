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
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<int>> adj(n);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        --u;--v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<bool> vis(n);
    vector<int> depth(n);
    vector<int> par(n, -1);
    function<void(int)> dfs = [&](int u){
        for(const auto &node : adj[u]){
            if(vis[node]){
                continue;
            }
            par[node]=u;
            depth[node]=depth[u]+1;
            vis[node]=1;
            dfs(node);
        }
    };
    vis[0]=1;
    dfs(0);
    int cyclelen=1e9;
    int top=-1, bottom=-1;
    for(int i=0;i<n;i++){
        for(int j=0;j<adj[i].size();j++){
            if(std::abs(depth[i]-depth[adj[i][j]])==1){
                continue;
            }
            if(cyclelen>std::abs(depth[i]-depth[adj[i][j]]) + 1){
                cyclelen=std::abs(depth[i]-depth[adj[i][j]]) + 1;
                top=i;
                bottom=adj[i][j];
                if(depth[top]>depth[bottom]){
                    swap(top, bottom);
                }
            }
        }
    }
    if(cyclelen<=k){
        cout<<2<<"\n";
        cout<<cyclelen<<"\n";
        int len=0;
        while(len<cyclelen){
            assert(~bottom);
            cout<<bottom+1<<" ";
            bottom=par[bottom];
            ++len;
        }
        return;
    }
    vector<int> ans1, ans2;
    for(int i=0;i<n;i++){
        if(depth[i]<k){
            if(depth[i]&1){
                ans1.pb(i);
            }
            else{
                ans2.pb(i);
            }
        }
    }
    if(ans1.size()<ans2.size()){
        swap(ans1, ans2);
    }
    cout<<"1\n";
    for(int i=0;i<(k+1)/2;i++){
        cout<<ans1[i]+1<<" ";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}