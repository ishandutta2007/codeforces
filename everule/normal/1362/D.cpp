//https://codeforces.com/contest/1362/problem/D
#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
#define mp make_pair
#define pb push_back
using namespace std;
int MEX(vector<int> &x){
    vector<bool> found(x.size());
    for(int i=0;i<x.size();i++){
        if(x[i]<x.size()){
            found[x[i]]=1;
        }
    }
    for(int i=0;i<x.size();i++){
        if(!found[i]){
            return i;
        }
    }
    return x.size();
}
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
    vector<vector<int>> adj(n);
    vector<vector<int>> topic(n);
    vector<int> topicof(n);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        --u;--v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for(int i=0;i<n;i++){
        int topi;
        cin>>topi;
        --topi;
        topic[topi].pb(i);
        topicof[i]=topi;
    }
    vector<int> ans;
    ans.reserve(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<topic[i].size();j++){
            vector<int> found;
            found.reserve(adj[topic[i][j]].size());
            for(const auto &edge : adj[topic[i][j]]){
                found.pb(topicof[edge]);
            }
            int l=MEX(found);
            if(l!=i){
                cout<<"-1\n";
                return;
            }
            ans.pb(topic[i][j]);
        }
    }
    for(auto &x : ans){
        cout<<x+1<<" ";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}