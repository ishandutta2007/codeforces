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
struct Directed_Graph{
    int n;
    vector<vector<int>> adj;
    vector<bool> vis;
    vector<int> topologicalsort;
    Directed_Graph(int n) : n(n), adj(n) {}
    void add_edge(int u,int v){
        adj[u].push_back(v);
    }
    void TopologicalSortDFS(int u, int &pos){
        vis[u] = 1;
        for(int v : adj[u]){
            if(!vis[v]){
                TopologicalSortDFS(v, pos);
            }
        }
        topologicalsort[u] = --pos;
    }
    void ComputeTopologicalSort(){
        vis.assign(n, 0);
        topologicalsort.assign(n, 0);
        int idx = n;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                TopologicalSortDFS(i, idx);
            }
        }
    }
};
struct Edge{
    int u,v,w;
    Edge(int u,int v,int w) : u(u), v(v), w(w) {}
    Edge() {}
};
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> adj(n);
    vector<Edge> edges(m);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        --u;--v;
        adj[u].emplace_back(v,w);
        edges[i] = Edge(u,v,w);
    }
    ll mn = 0, mx = 1e9;
    auto check = [&](int currans){
        vector<bool> vis(n);
        vector<bool> instack(n);
        bool cycle = 0;
        function<void(int)> dfs = [&](int u){
            if(instack[u]) cycle = 1;
            if(vis[u]) return;
            vis[u] = 1;
            instack[u] = 1;
            for(const auto &[v,w] : adj[u]){
                if(w <= currans) continue;
                dfs(v);
            }
            instack[u] = 0;
        };
        for(int i=0;i<n;i++) if(!vis[i]) dfs(i);
        return (cycle == 0);
    };
    while(mn < mx){
        int mid = (mn + mx) >> 1;
        if(check(mid)){
            mx = mid;
        }
        else{
            mn = mid + 1;
        }
    }
    Directed_Graph dag(n);
    for(int u=0;u<n;u++){
        for(const auto &[v,w] : adj[u]){
            if(w > mn){
                dag.add_edge(u,v);
            }
        }
    }
    dag.ComputeTopologicalSort();
    vector<int> ans;
    for(int i=0;i<m;i++){
        const auto &[u,v,w] = edges[i];
        if(w > mn) continue;
        if(dag.topologicalsort[u] > dag.topologicalsort[v]) ans.push_back(i);
    }
    cout<<mn<<" "<<ans.size()<<"\n";
    for(const auto &idx : ans) cout<<idx + 1 <<" ";
    cout<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}