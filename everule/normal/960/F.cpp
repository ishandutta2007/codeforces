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
template<typename T>
struct segment_tree {
    int n;
    vector<T> segtree;
    function<T(const T&,const T&)> join;
    T base = T();
    segment_tree() {}
    segment_tree(int n, function<T(const T&,const T&)> join, T base = T()) : n(n), join(join), base(base){
        segtree.resize(n << 1, base);
    }
    void build() {
        for (int i = n - 1; i > 0; --i) {
            segtree[i] = join(segtree[(i << 1)], segtree[(i << 1) | 1]);
        }
    }
    segment_tree(vector<T> seq, function<T(const T&,const T&)> join, T base = T()) : n(seq.size()), join(join), base(base){
        segtree.resize(n << 1, base);
        for (int i = 0; i < n; i++) {
            segtree[n + i] = seq[i];
        }
        build();
    }
    void calc(int pos){
        pos >>= 1;
        while (pos) {
            segtree[pos] = join(segtree[pos << 1], segtree[(pos << 1) | 1]);
            pos >>= 1;
        }
    }
    void set(int pos, T val){
        pos+=n;
        segtree[pos] = val;
        calc(pos);
    }
    void increment(int pos, T val){
        pos+=n;
        segtree[pos] = join(segtree[pos], val);
        calc(pos);
    }
    T query(int l, int r) {
        T ansl = base;
        T ansr = base;
        l += n;
        r += n + 1;
        while (l < r) {
            if (l & 1) {
                ansl = join(ansl, segtree[l++]);
            }
            if (r & 1) {
                ansr = join(segtree[--r], ansr);
            }
            l >>= 1;
            r >>= 1;
        }
        return join(ansl, ansr);
    }
};
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<array<int, 2>>> g(n), gt(n);
    vector<array<int, 3>> edges;
    for(int i=0;i<m;i++){
        int u,v,w;    
        cin>>u>>v>>w;
        --u;--v;
        g[u].push_back({v, w});
        gt[v].push_back({u, w});
        edges.push_back({u, v, w});
    }
    auto edge_cmp =  [&](array<int, 2> x, array<int, 2> y){
        return make_pair(x[1], x[0]) < make_pair(y[1], y[0]);
    };
    for(int i=0;i<n;i++) sort(gt[i].begin(), gt[i].end(), edge_cmp);
    vector<segment_tree<int>> sts(n);
    for(int i=0;i<n;i++){
        sts[i] = segment_tree<int>(gt[i].size(), [&](int x,int y){
            return max(x, y);
        }, 0);
    }
    for(auto &[u, v, w] : edges){
        int idx_to = lower_bound(gt[v].begin(), gt[v].end(), array<int, 2>({u, w}), edge_cmp) - gt[v].begin();
        int idx_from = lower_bound(gt[u].begin(), gt[u].end(), array<int, 2>({-1, w}), edge_cmp) - gt[u].begin() - 1;
        //cout<<u<<" "<<v<<" "<<w<<"\n";
        //cout<<idx_from<<" "<<idx_to<<"\n";
        if(idx_from < 0) sts[v].increment(idx_to, 1);
        sts[v].increment(idx_to, sts[u].query(0, idx_from) + 1);
    }
    int ans = 0;
    for(int i=0;i<n;i++) ans = max(ans, sts[i].query(0, sts[i].n - 1));
    cout<<ans<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}