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
bitset<1000000> bts;
inline bool is_equal(int i,int j,int k){
    return bts[10000 * i + 100 * j + k];
} 
inline void set_bts(int i,int j,int k, int v){
    bts[10000 * i + 100 * j + k] = bts[10000 * i + 100 * k + j] = v;
}
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
        return l - l % B + __builtin_ctzll(msk[r] & ~((1ll<<(l % B)) - 1));
    }
    int query(int l, int r){
        if(l / B == r / B) return small_query(l, r);
        int mid = spt_query(l / B + 1, r / B - 1);
        int lft = small_query(l, (l / B * B) + B - 1);
        int rht = small_query(r / B * B, r);
        if(a[mid] < a[lft] && a[mid] < a[rht]) return mid;
        if(a[lft] < a[rht]) return lft;
        else return rht;
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
template<int lgn>
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
    static_RMQ<int, lgn> rmq;
    Fast_LCA(int n) : Tree(n), tin(n), dep(n), par(n) {}
    void compute_LCA(int root = 0){
        t = 0;
        par[root] = root;
        dfs(root, root);
        vector<int> rmq_array(n, n + 1);
        for(int i=0;i<n;i++){
            rmq_array[i] = dep[iord[i]];
        }
        rmq = static_RMQ<int, lgn>(rmq_array);
    }
    int getLCA(int u, int v){
        if(u == v) return u;
        if(tin[u] > tin[v]) swap(u, v);
        return par[iord[rmq.query(tin[u]+1, tin[v])]];
    }
    int dist(int u,int v){
        return dep[u] + dep[v] - 2 * dep[getLCA(u, v)];
    }
};
void solve(){
    int n;
    cin>>n;
    for(int i=1;i<n;i++){
        for(int j=1;j<=n-i;j++){
            string s;
            cin>>s;
            for(int k=0;k<n;k++){
                set_bts(k, i-1, i+j-1, s[k] - '0');
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            set_bts(i, j, j, 1);
        }
    }
    auto find_from = [&](int x){
        vector<int> vis(n);
        bool is_tree = 1;
        Fast_LCA<7> tree(n);
        function<void(int, int)> dfs = [&](int u,int par){
            if(!is_tree) return;
            if(vis[u]){
                is_tree = 0;
                return;
            }
            vis[u] = 1;
            for(int c=0;c<n;c++){
                if(is_equal(u, par, c)){
                    if(u != 0 && c == par) continue;
                    tree.add_edge(c, u);
                    dfs(c, u);
                }
            }
        };
        dfs(0, x);
        if(!is_tree || find(vis.begin(), vis.end(), 0) != vis.end()) return false;
        tree.compute_LCA();
        vector<vector<int>> d(n, vector<int>(n));
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) d[i][j] = tree.dist(i, j);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(is_equal(i, j, k) && d[i][j] != d[i][k]) return false;
                    if(!is_equal(i, j, k) && d[i][j] == d[i][k]) return false; 
                }
            }
        }
        cout<<"Yes\n";
        auto g = tree.adj;
        for(int i=0;i<n;i++){
            for(int j : g[i]){
                if(j > i) continue;
                cout<<i+1<<" "<<j+1<<"\n";
            }
        }
        return true;
    };
    for(int i=1;i<n;i++){
        if(find_from(i)) return;
    }
    cout<<"No\n";
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