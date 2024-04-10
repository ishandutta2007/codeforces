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
struct DSU{
    vector<int> parent;
    vector<int> sizof;
    int n;
    int roots = 0;
    DSU(int n) : n(n), roots(n){
        parent.resize(n);
        sizof.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
            sizof[i]=1;
        }
    }
    int get_size(int x){
        return sizof[find_set(x)];
    }
    int find_set(int v){
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }
    void join_sets(int a, int b){
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            --roots;
            if (sizof[a] < sizof[b]){
                swap(a, b);
            }
            parent[b] = a;
            sizof[a] += sizof[b];
        }
    }
};
void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> c(k);
    cin>>c;
    vector<int> color(n);
    for(int i=0,j=0;i<k;i++){
        for(int o=0;o<c[i];o++){
            color[j+o] = i;
        }
        j+=c[i];
    }
    const ll INF = 1e15;
    vector<vector<ll>> adj(k, vector<ll>(k, INF));
    vector<pair<int,int>> idk;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        --u;--v;
        if(w==0) idk.push_back({u,v});
        u = color[u];
        v = color[v];
        adj[u][v] = min(adj[u][v], (ll)w);
        adj[v][u] = min(adj[v][u], (ll)w);
    }
    for(int i=0;i<k;i++){
        adj[i][i] = 0;
    }
    DSU graph(n);
    for(const auto &[u,v] : idk){
        graph.join_sets(u,v);
    }
    for(int i=0,j=0;i<k;i++){
        int par = graph.find_set(j);
        for(int o=1;o<c[i];o++){
            if(graph.find_set(j+o)!=par){
                cout<<"No\n";
                return;
            }
        }
        j+=c[i];
    }
    for(int K=0;K<k;K++){
        for(int i=0;i<k;i++){
            for(int j=0;j<k;j++){
                adj[i][j] = min(adj[i][j], adj[i][K] + adj[K][j]);
            }
        }
    }
    cout<<"Yes\n";
    for(auto &vec : adj){
        for(auto &x : vec){
            if(x==INF) cout<<"-1 "; 
            else cout<<x<<" "; 
        }
        cout<<"\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}