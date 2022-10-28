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
    vector<int> fr;
    vector<bool> used(n), unusable(n);
    vector<vector<int>> adj(n);
    DSU dsu(n);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        --u;--v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        dsu.join_sets(u,v);
    }
    if(dsu.get_size(0) != n){
        cout<<"NO\n";
        return;
    }
    auto add = [&](int u){
        used[u] = 1;
        for(auto &x : adj[u]){
            if(unusable[x]) continue;
            unusable[x] = 1;
            for(auto &v : adj[x]) fr.push_back(v);
        }
    };
    fr.push_back(0);
    while(!fr.empty()){
        if(used[fr.back()] || unusable[fr.back()]){
            fr.pop_back();
            continue;
        }
        int x = fr.back();
        fr.pop_back();
        add(x);
    }
    int ans = accumulate(used.begin(), used.end(), 0);
    cout<<"YES\n";
    cout<<ans<<"\n";
    for(int i=0;i<n;i++){
        if(used[i]) cout<<i+1<<" ";
    }
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