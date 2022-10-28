#include <bits/stdc++.h>
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
    DSU(int N){
        n=N;
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
    void join_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (sizof[a] < sizof[b]){
                swap(a, b);
            }
            parent[b] = a;
            sizof[a] += sizof[b];
        }
    }
};
const int INF = 1e9;
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<array<int, 2>>> g(n);
    vector<array<int, 2>> edges;
    edges.reserve(m);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        --u;--v;
        g[u].push_back({v, i});
        g[v].push_back({u, i});
        edges.push_back({u, v});
    }
    vector<int> dep(n);
    vector<int> par(n);
    vector<int> par_edge(n);
    vector<bool> used(m);
    [&](){
        vector<bool> vis(n);
        dep[0] = 0;
        function<void(int)> dfs = [&](int u){
            vis[u] = 1;
            for(const auto &[v, idx] : g[u]){
                if(vis[v]) continue;
                par[v] = u;
                par_edge[v] = idx;
                used[idx] = 1;
                dep[v] = dep[u] + 1;
                dfs(v);
            }
        };
        dfs(0);
    }();
    if(m != n+2){
        for(int i=0;i<m;i++) cout<<used[i];
        cout<<"\n";
        return;
    }
    vector<array<int, 2>> ex_edges;
    vector<int> ex_edges_id;
    for(int i=0;i<m;i++){
        if(used[i] == 0){
            ex_edges.push_back(edges[i]);
            ex_edges_id.push_back(i);
        }
    }
    DSU dsu1(n), dsu2(n);
    for(int i=0;i<m;i++){
        if(used[i]){
            dsu1.join_sets(edges[i][0], edges[i][1]);
        }
        else{
            dsu2.join_sets(edges[i][0], edges[i][1]);
        }
    }
    int cc = 0;
    for(int i=0;i<n;i++){
        cc += (dsu1.parent[i] == i) + (dsu2.parent[i] == i);
    }
    if(cc == 2 * n - m){
        for(int i=0;i<m;i++) cout<<used[i];
        cout<<"\n";
        return;
    }
    used[ex_edges_id[0]] = 1;
    int rem_parent_node = -1;
    if(dep[ex_edges[0][0]] > dep[ex_edges[0][1]]){
        rem_parent_node = ex_edges[0][0];
    }
    else{
        rem_parent_node = ex_edges[0][1];
    }
    used[par_edge[rem_parent_node]] = 0;
    for(int i=0;i<m;i++) cout<<used[i];
    cout<<"\n";
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