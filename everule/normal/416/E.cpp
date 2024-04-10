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
const int INF = 1e9;
void solve(){
    int n,m;
    cin>>n>>m;
    vector adj(n, vector<int>(n, INF));
    for(int i=0;i<m;i++){
        int x,y,l;
        cin>>x>>y>>l;
        --x;--y;
        adj[x][y] = adj[y][x] = l;
    }
    auto dist = adj;
    for(int i=0;i<n;i++) dist[i][i] = 0;
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
            }
        }
    }
    vector goodedges(n, vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                goodedges[i][j] += (dist[i][k] + adj[k][j] == dist[i][j] && dist[i][j]!=INF);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int ans = 0;
            for(int k=0;k<n;k++){
                if(dist[i][k] + dist[k][j] == dist[i][j]){
                    ans += goodedges[i][k];
                }
            }
            cout<<ans<<" ";
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}