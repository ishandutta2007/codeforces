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

const int MAXN2 = 20;
void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> mask_left(n), mask_right(n);
    vector<vector<int>> g(n);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        --u;--v;
        g[u].push_back(v);
        g[v].push_back(u);
        if(v < MAXN2){
            mask_left[u] |= (1<<v);
        }
        else{
            mask_right[u] |= (1<<(v - MAXN2));
        }
        swap(u, v);
        if(v < MAXN2){
            mask_left[u] |= (1<<v);
        }
        else{
            mask_right[u] |= (1<<(v - MAXN2));
        }
    }
    int connected_components = 0;
    int is_bipartite = 1;
    int lone_nodes = 0;
    for(int i=0;i<n;i++) lone_nodes += (g[i].size() == 0);
    {
        vector<bool> vis(n);
        vector<int> col(n);
        function<void(int)> dfs = [&](int u){
            vis[u] = 1;
            for(auto &v : g[u]){
                if(vis[v]){
                    if(col[u] == col[v]) is_bipartite = 0;
                    continue;
                }
                col[v] = col[u] ^ 1;
                dfs(v);
            }
        };
        for(int i=0;i<n;i++){
            if(vis[i]) continue;
            dfs(i);
            connected_components++;
        }
    }
    int left_count = min(MAXN2, n);
    int right_count = n - left_count;
    vector<int> ind_set_left(1<<left_count), ind_set_right(1<<right_count);
    ind_set_left[0] = ind_set_right[0] = 1;
    for(int i=1;i<(1<<left_count);i++){
        int bit = __builtin_ctz(i);
        ind_set_left[i] = ((mask_left[bit] & i) == 0) & ind_set_left[i ^ (1<<bit)];
    }
    for(int i=1;i<(1<<right_count);i++){
        int bit = __builtin_ctz(i);
        ind_set_right[i] = ((mask_right[bit + MAXN2] & i) == 0) & ind_set_right[i ^ (1<<bit)];
    }
    vector<int> ind_set_left_right(1<<right_count);
    for(int i=0;i<(1<<left_count);i++){
        if(ind_set_left[i] == 0) continue;
        int msk = 0;
        for(int j=0;j<left_count;j++){
            if((1<<j) & i) msk |= mask_right[j];
        }
        ind_set_left_right[msk]++;
    }
    for(int bit=0;bit<right_count;bit++){
        for(int m=0;m<(1<<right_count);m++){
            if(m & (1<<bit)) ind_set_left_right[m] += ind_set_left_right[m ^ (1<<bit)];
        }
    }
    ll tot_ind_set = 0;
    for(int i=0;i<(1<<right_count);i++){
        if(ind_set_right[i] == 0) continue;
        int mask = (1ll<<right_count) - 1 - i;
        tot_ind_set += ind_set_left_right[mask];
    }
    ll ans = (1ll<<n) - 2 * tot_ind_set - (1ll<<connected_components) * (1 - is_bipartite) + 2 * (1ll<<lone_nodes) - (1ll<<n) * (m == 0); 
    cout<<ans<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}