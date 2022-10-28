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
template<typename T>
struct RangeUpdate{ //requires commutativity and associativity
    int n;
    vector<T> segtree;
    function<T(const T&, const T&)> join;
    T base;
    RangeUpdate(int n, function<T(const T&,const T&)> join, T base) : n(n), join(join), base(base){
        segtree.resize(n<<1, base);
    }
    RangeUpdate(vector<T> &seq, function<T(const T&,const T&)> join, T base) : n(seq.size()), join(join), base(base){
        segtree.resize(n<<1, base);
        for(int i=0;i<n;i++){
            segtree[n+i] = seq[i];
        }
    }
    T query(int pos){
        pos+=n;
        T ans = segtree[pos];
        pos>>=1;
        while(pos){
            ans = join(ans, segtree[pos]);
            pos>>=1;
        }
        return ans;
    }
    void update(int l,int r,T val){
        l+=n;
        r+=n+1;
        while(l < r){
            if(l&1){
                segtree[l] = join(segtree[l], val);
                ++l;
            }
            if(r&1){
                --r;
                segtree[r] = join(segtree[r], val);
            }
            l>>=1;
            r>>=1;
        }
    }
};
template<typename T>
struct segment_tree {
    int n;
    vector<T> segtree;
    function<T(const T&,const T&)> join;
    T base = T();
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
    int n;
    cin>>n;
    vector<vector<int>> g1(n), g2(n);
    for(int i=1;i<n;i++){
        int p;
        cin>>p;
        --p;
        g1[p].push_back(i);
    }
    for(int i=1;i<n;i++){
        int p;
        cin>>p;
        --p;
        g2[p].push_back(i);
    }
    vector<int> tin(n), tout(n);
    {
        int t = 0;
        function<void(int)> dfs = [&](int u){
            tin[u] = t++;
            for(auto &v : g2[u]){
                dfs(v);
            }
            tout[u] = t - 1;
        };
        dfs(0);
    }
    int ans = 0;
    int c_leaf = 0;
    segment_tree<int> active_nodes(n, [&](int x,int y){
        return x + y;
    }, 0);
    RangeUpdate<int> has_leaf_par(n, [&](int x, int y){
        return x + y;
    }, 0);
    has_leaf_par.update(0, n-1, -1);
    vector<int> prev_leaf(n, -1);
    auto add = [&](int u){
        active_nodes.set(tin[u], 1);
        if(active_nodes.query(tin[u], tout[u]) > 1) return;
        c_leaf++;
        auto par = has_leaf_par.query(tin[u]);
        has_leaf_par.update(tin[u], tout[u], u + 1);
        if(par == -1) return;
        prev_leaf[u] = par;
        has_leaf_par.update(tin[par], tout[par], -par - 1);
        --c_leaf;
    };
    auto sub = [&](int u){
        active_nodes.set(tin[u], 0);
        if(has_leaf_par.query(tin[u]) != u) return;
        has_leaf_par.update(tin[u], tout[u], -u - 1);
        --c_leaf;
        if(prev_leaf[u] == -1) return;
        has_leaf_par.update(tin[prev_leaf[u]], tout[prev_leaf[u]], prev_leaf[u] + 1);
        ++c_leaf;
    };
    function<void(int)> dfs = [&](int u){
        add(u);
        ans = max(ans, c_leaf);
        for(auto &v : g1[u]){
            dfs(v);
        }
        sub(u);
    };
    dfs(0);
    cout<<ans<<"\n";
    //assert(c_leaf == 0);
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