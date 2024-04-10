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
struct Tree{ //0 indexed
    int n;
    vector<vector<int>> adj;
    Tree(int n) : n(n){
        adj.resize(n);
    }
    void addedge(int u,int v){
        adj[u].pb(v);
        adj[v].pb(u);
    }
};
struct EulerTour : Tree{
    private : 
    int t;
    void dfs(int u,int p){
        tin[u] = t++;
        eulertour.push_back(u);
        for(const auto &v : adj[u]){
            if(v==p) continue;
            dep[v] = dep[u] + 1;
            dfs(v,u);
        }
        tout[u] = t - 1;
    }
    public:
    vector<int> dep;
    vector<int> tin, tout, eulertour;
    void ComputeEulerTour(int root = 0){
        t = 0;
        tin.resize(n), tout.resize(n), eulertour.reserve(n);
        dep.resize(n);
        dep[root] = 0;
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
template<typename T, int lgn>
struct PathQueries : LCA<lgn>, private RangeUpdate<T>{
    function<T(const T&, const T&)> remove;
    PathQueries(int n, function<T(const T&, const T&)> join, function<T(const T&,const T&)> remove, T base)
    : LCA<lgn>(n), RangeUpdate<T>(n, join, base), remove(remove) {}
    void init(int root = 0){
        LCA<lgn>::computeLCA(root);
    }
    vector<T> seq;
    void init(vector<T> val,int root = 0){
        seq = vector<T>(val.begin(), val.end());
        LCA<lgn>::computeLCA(root);
        for(int i=0;i<Tree::n;i++){
            RangeUpdate<T>::update(EulerTour::tin[i], EulerTour::tout[i], seq[i]);
        }
    }
    void updatenode(int u, T val){
        RangeUpdate<T>::update(EulerTour::tin[u], EulerTour::tout[u], remove(val,seq[u]));
        seq[u] = val;
    }
    T query(int u,int v){
        T ans = RangeUpdate<T>::base;
        int w = LCA<lgn>::getLCA(u,v);
        ans = RangeUpdate<T>::join(ans, RangeUpdate<T>::query(EulerTour::tin[u]));
        ans = RangeUpdate<T>::join(ans, RangeUpdate<T>::query(EulerTour::tin[v]));
        T lcq = RangeUpdate<T>::query(w);
        ans = remove(ans, RangeUpdate<T>::join(lcq, lcq));
        ans = RangeUpdate<T>::join(ans, seq[w]);
        return ans;
    }
};
const int INF = 1e9;
void solve(){
    int n;
    cin>>n;
    LCA<20> tree(n);
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        --u;--v;
        tree.addedge(u,v);
    }
    tree.computeLCA(0);
    int q;
    cin>>q;
    vector<int> vir(n, -1);
    vector<int> imp(n, -1);
    vector<vector<pair<int,int>>> vadj(n);
    vector<array<int, 3>> dp(n, {INF,INF,INF});
    auto cmp = [&](array<int, 3> x,array<int, 3> y){
        if(x[0] != y[0]) return x[0] < y[0];
        if(x[1] != y[1]) return x[1] < y[1];
        return false;
    };
    for(int i=0;i<q;i++){
        int k,m;
        cin>>k>>m;
        vector<int> nodes;
        vector<int> spd(k);
        nodes.reserve(2 * (k + m));
        for(int i=0;i<k;i++){
            int u,s;
            cin>>u>>s;
            --u;
            nodes.push_back(u);
            vir[u] = i;
            spd[i] = s;
            dp[u] = {0,i,0};
        }
        for(int i=0;i<m;i++){
            int u;
            cin>>u;
            --u;
            imp[u] = i;
            nodes.push_back(u);
        }
        sort(nodes.begin(), nodes.end(), [&](int x,int y){
            return tree.tin[x] < tree.tin[y];
        });
        for(int i=1;i<k+m;i++){
            nodes.push_back(tree.getLCA(nodes[i], nodes[i-1]));
        }
        nodes.push_back(0);
        sort(nodes.begin(), nodes.end(), [&](int x,int y){
            return tree.tin[x] < tree.tin[y];
        });
        nodes.resize(unique(nodes.begin(), nodes.end()) - nodes.begin());
        stack<int> curr;
        curr.push(nodes[0]);
        for(int i=1;i<nodes.size();i++){
            while(tree.tout[curr.top()] < tree.tin[nodes[i]]){
                curr.pop();
            }
            vadj[curr.top()].emplace_back(nodes[i], tree.dep[nodes[i]] - tree.dep[curr.top()]);
            curr.push(nodes[i]);
        }
        function<void(int)> dfs = [&](int u){
            for(const auto &[v,w] : vadj[u]){
                dfs(v);
                auto dpv = dp[v];
                if(dpv[1] == INF) continue;
                dpv[2] += w;
                dpv[0] = (dpv[2] + spd[dpv[1]] - 1)/spd[dpv[1]];
                dp[u] = min(dp[u], dpv, cmp);
            }
        };
        dfs(0);
        dfs = [&](int u){
            for(const auto &[v,w] : vadj[u]){
                auto dpu = dp[u];
                dpu[2] += w;
                dpu[0] = (dpu[2] + spd[dpu[1]] - 1)/spd[dpu[1]];
                dp[v] = min(dp[v], dpu, cmp);
                dfs(v);
            }
        };
        dfs(0);
        vector<int> ans(m);
        for(int i=0;i<nodes.size();i++) if(imp[nodes[i]] != -1) ans[imp[nodes[i]]] = dp[nodes[i]][1] + 1;
        cout+ans;
        for(int i=0;i<nodes.size();i++){
            vadj[nodes[i]].clear();
            imp[nodes[i]] = -1;
            vir[nodes[i]] = -1;
            dp[nodes[i]] = {INF,INF,INF};
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}