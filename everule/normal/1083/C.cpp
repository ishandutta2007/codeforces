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
        pos += n;
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
    //returns last true
    pair<int, T> prefix_search(function<bool(T)> cmp){
        int curr = 1;
        int r = n;
        T currv = base;
        int ans = 0;
        while(curr < n){
            r >>= 1;
            curr *= 2;
            if(cmp(join(currv, segtree[curr]))){
                currv = join(currv, segtree[curr++]);
                ans += r;
            }
        }
        currv = join(currv, segtree[curr]);
        if(cmp(currv)) ans++;
        return {ans, currv};
    }
};
template<typename T, int lgn>
struct static_RMQ{
    int n;
    array<vector<T>, lgn> spt;
    static constexpr int B = 60;
    vector<ll> msk;
    vector<T> a;
    static constexpr T INF = numeric_limits<T>::max();
    static_RMQ() {}
    static_RMQ(vector<T> _a) : n(_a.size()), msk(_a.size()), a(_a){
        build();
    }
    void set_array(vector<T> _a){
        a = _a;
        n = a.size();
        msk.assign(a.size(), 0);
        build();
    }
    void build(){
        for(int i=0;i<lgn;i++) spt[i] = vector<int>(n / B + 1, n);
        a.push_back(INF);
        for(int i=0;i*B<n;i++){
            vector<int> stk;
            msk[i*B] = 1;
            stk.push_back(i*B);
            for(int j=i*B+1;j<min(n, (i+1)*B);j++){
                msk[j] = msk[j-1];
                msk[j] |= (1ll<<(j - i*B));
                while(stk.size() > 0 && a[stk.back()] >= a[j]){
                    msk[j] ^= (1ll<<(stk.back() - i*B));
                    stk.pop_back();
                }
                stk.push_back(j);
            }
            spt[0][i] = stk[0];
        }
        for(int lg=0;lg+1<lgn;lg++){
            for(int j=0;j<spt[lg].size();j++){
                if(j + (1<<lg) < spt[lg].size()){
                    spt[lg+1][j] = a[spt[lg][j]] < a[spt[lg][j+(1<<lg)]] ? spt[lg][j] : spt[lg][j+(1<<lg)];
                }
                else{
                    spt[lg+1][j] = spt[lg][j];
                }
            }
        }
    }
    int spt_query(int l, int r){
        if(l > r) return n;
        ++r;
        int len = r - l;
        int lg = 31 - __builtin_clz(len);
        return a[spt[lg][l]] < a[spt[lg][r-(1<<lg)]] ? spt[lg][l] : spt[lg][r-(1<<lg)];
    }
    int small_query(int l, int r){
        assert(l / B == r / B);
        return (l / B * B) + __builtin_ctzll(msk[r] & ~((1ll<<(l - (l / B * B))) - 1));
    }
    int query(int l, int r){
        if(l / B == r / B){
            return small_query(l, r);
        }
        int mid = spt_query(l / B + 1, r / B - 1);
        int lft = small_query(l, (l / B * B) + B - 1);
        int rht = small_query(r / B * B, r);
        if(a[mid] < a[lft] && a[mid] < a[rht]) return mid;
        if(a[lft] < a[rht]) return lft;
        else return rht;
    }
};
template<typename T, int lgn>
struct sparse_table{
    int n;
    array<vector<int>, lgn> bt;
    vector<T> a;
    sparse_table() {}
    sparse_table(vector<T> _a) : n(_a.size()), a(_a){
        build();
    }
    void set_array(vector<T> _a){
        a = _a;
        n = _a.size();
        build();
    }
    void build(){
        for(int i=0;i<lgn;i++) bt[i].assign(n, 0);
        for(int i=0;i<n;i++) bt[0][i] = i;
        for(int lg=0;lg+1<lgn;lg++){
            for(int i=0;i<n;i++){
                if(i + (1<<lg) < n){
                    bt[lg+1][i] = a[bt[lg][i]] < a[bt[lg][i + (1<<lg)]] ? bt[lg][i] : bt[lg][i + (1<<lg)];
                }
            }
        }
    }
    int query(int l,int r){
        ++r;
        int lg = 31 - __builtin_clz(r - l);
        return a[bt[lg][l]] < a[bt[lg][r - (1<<lg)]] ? bt[lg][l] : bt[lg][r - (1<<lg)];
    }
};
struct Tree{ //0 indexed
    int n;
    vector<vector<int>> adj;
    Tree(int n) : n(n){
        adj.resize(n);
    }
    void add_edge(int u,int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
};
template<typename RMQ_impl>
struct Fast_LCA : Tree{
    private:
    int t;
    vector<int> tin, iord, dep, par;
    void dfs(int u, int pr){
        tin[u] = t++;
        iord.push_back(u);
        for(auto &v : adj[u]){
            if(v == pr) continue;
            par[v] = u;
            dep[v] = dep[u] + 1;
            dfs(v, u);
        }
    }
    public:
    RMQ_impl rmq;
    Fast_LCA(int n) : Tree(n), tin(n), dep(n), par(n) {}
    void compute_LCA(int root = 0){
        t = 0;
        par[root] = root;
        dfs(root, root);
        vector<int> rmq_array(n, n + 1);
        for(int i=0;i<n;i++){
            rmq_array[i] = dep[iord[i]];
        }
        rmq.set_array(rmq_array);
    }
    int getLCA(int u, int v){
        if(u == v) return u;
        if(tin[u] > tin[v]) swap(u, v);
        return par[iord[rmq.query(tin[u]+1, tin[v])]];
    }
    int dist(int u, int v){
        return dep[u] + dep[v] - 2 * dep[getLCA(u, v)];
    }
};
void solve(){
    int n;
    cin>>n;
    vector<int> p(n);
    cin>>p;
    Fast_LCA<sparse_table<int, 20>> g(n);
    for(int i=1;i<n;i++){
        int p;
        cin>>p;
        --p;
        g.add_edge(p, i);
    }
    g.compute_LCA();
    const array<int, 2> identity = array<int, 2>({n, n});
    const array<int, 2> no_path = array<int, 2>({-1, -1});
    int _n = 1;
    while(_n < n) _n *= 2;
    segment_tree<array<int, 2>> st(_n, [&](array<int, 2> x, array<int, 2> y){
        if(x == no_path || y == no_path) return no_path;
        if(x == identity) return y;
        if(y == identity) return x;
        int max_dist = -1;
        int e_u = -1, e_v = -1;
        array<int, 4> nodes = array<int, 4>({x[0], x[1], y[0], y[1]});
        for(int i=0;i<4;i++){
            for(int j=i+1;j<4;j++){
                int u = nodes[i];
                int v = nodes[j];
                if(g.dist(u, v) > max_dist){
                    max_dist = g.dist(u, v);
                    e_u = u;
                    e_v = v;
                }
            }
        }
        for(auto e : {x[0], x[1], y[0], y[1]}){
            if(g.dist(e_u, e) + g.dist(e, e_v) > g.dist(e_u, e_v)) return no_path;
        }
        return array<int, 2>({e_u, e_v});
    }, identity);
    for(int i=0;i<n;i++){
        st.set(p[i], array<int, 2>({i, i}));
    }
    int q;
    cin>>q;
    while(q--){
        int t;
        cin>>t;
        if(t == 1){
            int i,j;
            cin>>i>>j;
            --i;--j;
            swap(p[i], p[j]);
            st.set(p[i], array<int, 2>({i, i}));
            st.set(p[j], array<int, 2>({j, j}));
        }
        else{
            cout<<st.prefix_search([&](array<int, 2> x){
                return x != no_path;
            }).first<<"\n";
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}