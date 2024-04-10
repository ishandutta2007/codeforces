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
const int BLK = 500;
template<int BLK>
struct query{
    int u,v;
    int l,r;
    int id;
    int ql,qr;
    int lc = -1;
    query(){}
    bool operator<(const query<BLK> &o){
        if(ql/BLK != o.ql/BLK) return ql < o.ql;
        if(ql/BLK % 2) return qr > o.qr;
        else return qr < o.qr;
    }
};
const int MAXA = 3e5;
void solve(){
    int n,q;
    cin>>n>>q;
    vector<int> A(n);
    cin>>A;
    for(auto &x : A) --x;
    LCA<20> tree(n);
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        --u;--v;
        tree.addedge(u,v);
    }
    tree.computeLCA(0);
    vector<query<BLK>> qry(q);
    for(int i=0;i<q;i++){
        cin>>qry[i].u>>qry[i].v>>qry[i].l>>qry[i].r;
        --qry[i].u;--qry[i].v;--qry[i].l;--qry[i].r;
        qry[i].id = i;
        if(tree.tin[qry[i].u] > tree.tin[qry[i].v]) swap(qry[i].u, qry[i].v); 
        qry[i].lc = tree.getLCA(qry[i].u,qry[i].v);
        if(qry[i].lc == qry[i].u || qry[i].lc == qry[i].v){
            qry[i].ql = tree.tin[qry[i].u];
            qry[i].qr = tree.tin[qry[i].v];
            qry[i].lc = -1;
        }
        else{
            qry[i].ql = tree.tout[qry[i].u];
            qry[i].qr = tree.tin[qry[i].v];
        }
    }
    sort(qry.begin(), qry.end());
    vector<int> blksum(n);
    vector<int> parity(n);
    vector<int> fin(q);
    [&](){
        auto flip = [&](int c){
            blksum[c/BLK] -= parity[c];
            parity[c] ^= 1;
            blksum[c/BLK] += parity[c];
        };
        int cl = 0, cr = -1;
        for(const auto &[u,v,l,r,id,ql,qr,lc] : qry){
            while(cl < ql) flip(A[tree.eulertour[cl++]]);
            while(cl > ql) flip(A[tree.eulertour[--cl]]);
            while(cr < qr) flip(A[tree.eulertour[++cr]]);
            while(cr > qr) flip(A[tree.eulertour[cr--]]);
            if(lc != -1) flip(A[lc]);
            int i = l;
            int ans = -2;
            for(;i<=r;i++){
                if(i % BLK == 0) break;
                if(parity[i] == 1) ans = i;
            }
            for(;i+BLK-1<=r;i+=BLK){
                if(blksum[i/BLK] == 0) continue;
                for(int j=i;j<i+BLK;j++){
                    if(parity[j]) ans = j;
                }
                break;
            }
            if(ans == -2){
                for(;i<=r;i++){
                    if(parity[i] == 1) ans = i;
                }
            }
            fin[id] = ans + 1;
            if(lc != -1) flip(A[lc]);
        }
    }();
    for(auto &x : fin) cout<<x<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}