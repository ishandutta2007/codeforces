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
const int MAXC = 1e5;
void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> color(n);
    cin>>color;
    vector<vector<int>> adj(n);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        --u;--v;
        adj[u].pb(v);
        adj[v].pb(u);    
    }
    vector<int> colcount(MAXC + 1);
    for(const auto &x : color) colcount[x]++;
    vector<set<int>> V(MAXC + 1);
    for(int i=0;i<n;i++){
        for(const auto &v : adj[i]){
            V[color[i]].insert(color[v]);
        }
    }
    int sz = -1;
    int ans = -1;
    for(int i=1;i<=MAXC;i++){
        if(colcount[i]==0) continue;
        V[i].erase(i); 
        if((int)V[i].size() > sz){
            sz = V[i].size();
            ans = i;
        }
    }
    cout<<ans<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}