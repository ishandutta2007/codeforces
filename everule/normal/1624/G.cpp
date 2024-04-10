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
    vector<vector<array<int, 2>>> g(n);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        --u;--v;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    int ans = (1<<30) - 1;
    auto check = [&](int msk){
        vector<int> q(n);
        int sz = 0,ps = 0;
        q[sz++] = 0;
        vector<bool> vis(n);
        vis[0] = 1;
        while(ps < sz){
            int u = q[ps++];
            for(auto &[v,w] : g[u]){
                if(!vis[v] && ((w & ~msk) == 0)){
                    vis[v] = 1;
                    q[sz++] = v;
                }
            }
        }
        return (accumulate(vis.begin(), vis.end(), 0) == n);
    };
    for(int b=29;b>=0;--b){
        if(check(ans ^ (1<<b))) ans ^= (1<<b);
    }
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