#include <iostream>
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std;
using ll = long long int;
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
        //cout<<a<<" "<<b<<"\n";
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
struct Edge{
    int u,v,w,idx;
    int k,c;
    Edge(int u,int v,int w,int idx) : u(u), v(v), w(w), idx(idx) {}
    Edge() {}
    bool operator<(const Edge &e){
        return w<e.w;
    }
};
void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<Edge>> adj(n);
    vector<Edge> edges(m);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        --u;--v;
        adj[u].pb(Edge(u,v,w,i));
    }
    for(int i=0;i<n;i++){
        sort(adj[i].begin(), adj[i].end());
        for(int j=0;j<(int)adj[i].size();j++){
            adj[i][j].k = adj[i].size() - 1;
            adj[i][j].c = j;
            edges[adj[i][j].idx] = adj[i][j];
        }
    }
    vector<bool> selfedge(11*k);
    const int MAXN = 2e5 + 7;
    vector<bitset<MAXN>> sol(11*k);
    vector<vector<bool>> allow(11*k, vector<bool>(11*k, 1));
    auto allowed = [&](const pair<int,int> &x, const pair<int,int> &y){
        if(selfedge[y.first*10 + y.second]) return false;
        return bool(allow[10*x.first + x.second][10*y.first + y.second]);
    };
    for(const auto &e : edges){
        if(sol[10*e.k + e.c][e.v]){
            selfedge[10*e.k + e.c] = 1;
        }
        sol[10*e.k + e.c][e.v] = 1;
    }
    for(int i=0;i<11*k;i++){
        for(const auto &e : edges){
            if(10*e.k + e.c == i) continue;
            if(sol[i][e.v]){
                allow[i][10*e.k + e.c] = 0;
                allow[10*e.k + e.c][i] = 0;
            }
        }
    }
    ll ans = 0;
    function<void(vector<int>&)> recurse = [&](vector<int>& curr){
        if((int)curr.size()==k){
            /*for(const auto &x : curr){
                cout<<x<<" ";
            }
            cout<<"\n";
            */
            ++ans;
            return;
        }
        int idx = curr.size();
        for(int i=0;i<=idx;i++){
            bool poss = 1;
            if(selfedge[10*idx + i]) continue;
            for(int j=0;j<(int)curr.size();j++){
                if(!allowed({j, curr[j]}, {idx, i})){
                    poss = 0;
                }
            }
            if(!poss) continue;
            curr.pb(i);
            recurse(curr);
            curr.pop_back();
        }
    };
    vector<int> use;
    recurse(use);
    cout<<ans<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}