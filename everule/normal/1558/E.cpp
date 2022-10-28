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
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> g_main(n);
    vector<int> a(n), b(n);
    for(int i=1;i<n;i++) cin>>a[i];
    for(int i=1;i<n;i++) cin>>b[i];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        --u;--v;
        g_main[u].push_back(v);
        g_main[v].push_back(u);
    }
    auto solve = [&](ll init){
        DSU dsu(n);
        vector<int> used(n);
        auto g = g_main;
        array<int, 2> no_path = array<int, 2>({-1, -1});
        auto get_augmenting_path = [&](){
            queue<int> bfs;
            vector<int> par(n, -1);
            vector<ll> pwr(n);
            pwr[0] = init;
            par[0] = 0;
            bfs.push(0);
            array<int, 2> node_ends = no_path;
            while(!bfs.empty()){
                int u = bfs.front();
                bfs.pop();
                int par_cnt = 0;
                for(auto &v : g[u]){
                    if(v == par[u]){
                        par_cnt++;
                        if(par_cnt > 1 && !used[u]){
                            node_ends = {u, u};
                            while(!bfs.empty()) bfs.pop();
                            break;
                        }
                        continue;
                    }
                    if(par[v] != -1 && par[v] != u){
                        node_ends = {u, v};
                        while(!bfs.empty()) bfs.pop();
                        break;
                    }
                    if(a[v] < pwr[u]){
                        bfs.push(v);
                        par[v] = u;
                        pwr[v] = pwr[u] + b[v] * (!used[v]);
                    }
                }
            }
            //cout<<node_ends[0]<<" "<<node_ends[1]<<"\n";
            //cout+par+pwr;
            if(node_ends == no_path) return;
            auto [u, v] = node_ends;
            while(u != 0){
                if(!used[u]){
                    init += b[u];
                    used[u] = 1;
                }
                u = par[u];
            }
            while(v != 0){
                if(!used[v]){
                    init += b[v];
                    used[v] = 1;
                }
                v = par[v];
            }
            vector<vector<int>> ng(n);
            for(int u=0;u<n;u++) for(auto &v : g[u]) if(u != 0 && v != 0 && used[u] && used[v]) dsu.join_sets(u, v);
            for(int u=0;u<n;u++) for(auto &v : g[u]) if(dsu.find_set(u) != dsu.find_set(v)) ng[dsu.find_set(u)].push_back(dsu.find_set(v));
            swap(g, ng);
        };
        while(true){
            ll o_init = init;
            get_augmenting_path();
            if(init == o_init) break;
        }
        return count(used.begin(), used.end(), 0) == 1;
    };
    ll mn = 0, mx = *max_element(a.begin(), a.end()) + 1; 
    while(mn < mx){
        int mid = (mn + mx) / 2;
        if(solve(mid)){
            mx = mid;
        }
        else{
            mn = mid + 1;
        }
        //cout<<mn<<" "<<mid<<" "<<mx<<"\n";
    }
    cout<<mn<<"\n";
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