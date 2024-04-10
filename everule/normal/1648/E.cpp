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
struct LineTree{
    struct DSU{
        vector<int> parent;
        vector<int> sizof;
        vector<array<int, 2>> line;
        vector<int> nxt;
        vector<int> nxtw;
        int n;
        DSU(int n) : n(n){
            parent.resize(n);
            sizof.resize(n);
            line.resize(n);
            nxt.resize(n);
            nxtw.resize(n);
            for(int i=0;i<n;i++){
                parent[i]=i;
                sizof[i]=1;
                line[i] = {i,i};
                nxt[i] = i;
                nxtw[i] = 0;
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
        void join_sets(int a, int b, int w) {
            a = find_set(a);
            b = find_set(b);
            if (a != b) {
                if (sizof[a] < sizof[b]){
                    swap(a, b);
                }
                parent[b] = a;
                sizof[a] += sizof[b];
                nxt[line[b][1]] = line[a][0];
                nxtw[line[b][1]] = w;
                line[a] = {line[b][0], line[a][1]};
            }
        }
    };
    vector<array<int, 3>> edges;
    DSU dsu;
    int n;
    LineTree(int n) : dsu(n), n(n){}
    void add_edge(int u,int v,int w){
        edges.push_back({w, u, v});
    }
    tuple<vector<int>, vector<int>, vector<int>> computeLineTree(){
        sort(edges.begin(), edges.end());
        int cnt = 0;
        for(auto &[w,u,v] : edges){
            dsu.join_sets(u, v, cnt++);
        }
        int root = dsu.find_set(0);
        vector<int> ord(n);
        ord[0] = dsu.line[root][0];
        for(int i=1;i<n;i++) ord[i] = dsu.nxt[ord[i-1]];
        vector<int> id(n);
        for(int i=0;i<n;i++) id[ord[i]] = i;
        vector<int> wts(n);
        for(int i=0;i+1<n;i++) wts[i] = dsu.nxtw[ord[i]];
        wts[n-1] = -1;
        return {ord, id, wts};
    }
};
struct Tree{ //0 indexed
    int n;
    vector<vector<int>> adj;
    Tree(int n) : n(n){
        adj.resize(n);
    }
    void addedge(int u,int v){
        //cout<<u<<" "<<v<<" LCA edge\n";
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
};
struct EulerTour : Tree{
    private : 
    int t;
    void dfs(int u,int p){
        tin[u] = t++;
        eulertour.push_back(u);
        for(const auto &v : adj[u]){
            if(v!=p)
            dfs(v,u);
        }
        tout[u] = t++;
        eulertour.push_back(u);
    }
    public:
    vector<int> tin, tout, eulertour;
    void ComputeEulerTour(int root = 0){
        t = 0;
        tin.resize(n), tout.resize(n), eulertour.reserve(n<<1);
        dfs(root,root);
    }
    bool isanc(int u,int v){ //returns true if u is ancestor of v
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }
    EulerTour(int n) : Tree(n) {}
};
template<int lgn>
struct LCA : EulerTour{
    vector<array<int,lgn>> par;
    int root;
    private:
    void dfs(int u,int p){
        par[u][0] = p;
        for(int i=1;i<lgn;i++){
            par[u][i] = par[par[u][i-1]][i-1];
        }
        for(const auto &v : adj[u]){
            if(v==p) continue;
            dfs(v,u);
        }
    }
    public:
    LCA(int n) : EulerTour(n) {
        par.resize(n);
    }
    void computeLCA(int Root){
        root = Root;
        ComputeEulerTour(root);
        dfs(root,root);
    }
    int getLCA(int u,int v){
        if(isanc(u,v)) return u;
        if(isanc(v,u)) return v;
        for(int i=lgn-1;i>=0;--i){
            if(!isanc(par[u][i], v)) u = par[u][i];
        }
        return par[u][0];
    }
    int kthancestor(int u,int k){
        for(int i=0;i<lgn;i++){
            if(k&(1<<i)) u = par[u][i];
        }
        return u;
    }
};
template<int lgn>
struct DSUtree{
    struct DSU{
        vector<int> parent;
        vector<int> sizof;
        vector<int> mergenum;
        set<int> roots;
        int n;
        int curr;
        DSU(int n) : n(n){
            curr = n;
            parent.resize(n);
            sizof.resize(n);
            mergenum.resize(n);
            for(int i=0;i<n;i++){
                parent[i]=i;
                sizof[i]=1;
                roots.insert(i);
                mergenum[i] = i;
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
        int root_node(int u){
            return mergenum[find_set(u)];
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
                roots.erase(b);
                mergenum[a] = curr;
                ++curr;
            }
        }
    };
    DSU dsu;
    LCA<lgn> lca;
    int n;
    DSUtree(int n) : n(n), dsu(n), lca(2 * n - 1) {}
    void add_edge(int u, int v){
        int ru = dsu.root_node(u);
        int rv = dsu.root_node(v);
        if(ru != rv) dsu.join_sets(u, v);
        lca.addedge(ru, dsu.root_node(u));
        lca.addedge(rv, dsu.root_node(v));
    }
    int root_node(int u){
        return dsu.root_node(u);
    }
    int find_set(int u){
        return dsu.find_set(u);
    }
    int get_size(int u){
        return dsu.get_size(u);
    }
    LCA<lgn> getDSUTree(){
        return lca;
    }
};
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<array<int, 2>>> g(n);
    LineTree lt(n);
    vector<array<int, 3>> edges;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        --u;--v;
        lt.add_edge(u, v, w);
        edges.push_back({u, v, w});
    }
    auto [ord, id, wts] = lt.computeLineTree();
    segment_tree<int> st(n-1, [&](int x,int y){
        return (wts[x] > wts[y]) ? x : y;
    }, n-1);
    for(int i=0;i+1<n;i++){
        st.set(i, i);
    }
    //cout+ord+id+wts;
    vector<vector<array<int, 2>>> dncinfo(n-1); 
    for(auto &[w,u,v] : lt.edges){
        int md = st.query(min(id[u], id[v]), max(id[v], id[u]) - 1);
        dncinfo[md].push_back({u,v});
    }
    DSUtree<20> dsutree(n);
    vector<int> w(2*n - 1, 0);
    int curr = n;
    function<void(int, int)> dnc = [&](int l,int r){
        //cout<<l<<" "<<r<<" range open\n";
        if(l == r){
            //cout<<l<<" "<<r<<" range close\n";
            return;
        }
        if(l + 1 == r){
            int m = st.query(l, r - 1);
            if(dncinfo[m].size() == 0){
                dsutree.add_edge(l, r);
                w[dsutree.root_node(l)] = m;
            }
            //cout<<l<<" "<<r<<" range close\n";
            return;
        }
        int m = st.query(l, r - 1);
        dnc(l, m);
        dnc(m + 1, r);
        map<array<int, 2>, int> mp;
        set<array<int, 2>> edges;
        for(auto &[u,v] : dncinfo[m]){
            if(id[u] > id[v]) swap(u, v);
            int c1 = dsutree.find_set(id[u]);
            int c2 = dsutree.find_set(id[v]);
            mp[{c1, c2}]++;
            if(mp[{c1, c2}] == dsutree.get_size(c1) * dsutree.get_size(c2)){
                edges.insert({c1, c2});
                //cout<<c1<<" "<<c2<<" clique edge\n";
            }
        }
        vector<int> nodes;
        auto it = dsutree.dsu.roots.lower_bound(l);
        while(it != dsutree.dsu.roots.end() && *it <= r) nodes.push_back(*it), it++;
        set<int> uvis(nodes.begin(), nodes.end());
        for(auto u : nodes){
            if(uvis.count(u) == 0) continue;
            queue<int> bfs;
            bfs.push(u);
            while(!bfs.empty()){
                int u = bfs.front();
                bfs.pop();
                vector<int> toerase;
                for(int v : uvis){
                    if(min(u, v) <= m && max(u, v) > m && dsutree.find_set(u) != dsutree.find_set(v) && edges.count({min(u, v), max(u, v)}) == 0){
                        dsutree.add_edge(u, v);
                        w[curr++] = m;
                    }
                }
                for(auto &v : toerase) uvis.erase(v);
            }
        }
        //cout<<l<<" "<<r<<" range close\n";
    };
    dnc(0, n-1);
    auto &lcat = dsutree.lca;
    lcat.computeLCA(2 * n - 2);
    //cout+wts;
    for(auto &[u,v,_] : edges){
        cout<<lt.edges[wts[w[lcat.getLCA(id[u], id[v])]]][0]<<" ";
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