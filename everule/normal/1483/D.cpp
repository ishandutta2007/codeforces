#include <bits/stdc++.h>
#include<immintrin.h>
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
const ll INFLL = 1e18;
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<ll>> adj(n, vector<ll>(n, INFLL));
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        --u;--v;
        adj[u][v] = adj[v][u] = w;
    }
    vector<vector<ll>> dist = adj;
    for(int i=0;i<n;i++) dist[i][i] = 0;
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dist[i][k] + dist[k][j] < dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    //cout*adj*dist;
    vector<vector<ll>> chk(n, vector<ll>(n, -INFLL));
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int u,v,l;
        cin>>u>>v>>l;
        --u;--v;
        for(int j=0;j<n;j++){
            chk[j][v] = max(chk[j][v], l - dist[u][j]);
            chk[j][u] = max(chk[j][u], l - dist[v][j]);
        }
    }
    //cout<<"\n";
    //cout*chk;
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            bool isuseful = 0;
            for(int k=0;k<n;k++){
                if(chk[i][k] >= adj[i][j] + dist[j][k])
                    isuseful = 1;
            }
            ans += isuseful;
        }
    }
    cout<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}