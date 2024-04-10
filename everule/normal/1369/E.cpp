
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
    vector<int> dish(n);
    cin>>dish;
    vector<set<pair<int,int>>> adj(n);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        --u;--v;
        adj[u].insert(mp(v, i));
        adj[v].insert(mp(u, i));
    }
    set<pair<int,int>> left;
    vector<int> ans;
    ans.reserve(m);
    for(int i=0;i<n;i++){
        left.insert(mp((int)adj[i].size() - dish[i], i));
    }
    while(!left.empty()){
        if((*left.begin()).first > 0){
            cout<<"DEAD\n";
            return;
        }
        int u = (*left.begin()).second;
        left.erase(left.begin());
        for(const auto &edge : adj[u]){
            ans.pb(edge.second + 1);
            if(left.find(mp((int)adj[edge.first].size() - dish[edge.first], edge.first)) == left.end()){
                continue;
            }
            left.erase(mp((int)adj[edge.first].size() - dish[edge.first], edge.first));
            adj[edge.first].erase(mp(u, edge.second));
            left.insert(mp((int)adj[edge.first].size() - dish[edge.first], edge.first));
        }
    }
    reverse(ans.begin(), ans.end());
    cout<<"ALIVE\n";
    cout+ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}