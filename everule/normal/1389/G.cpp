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
const int INF = 1e9;
void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<pair<int,int>>> adj(n);
    vector<int> val(n), wt(m);
    vector<bool> special(n);
    for(int i=0;i<k;i++){
        int u;
        cin>>u;
        --u;
        special[u] = 1;
    }
    cin>>val>>wt;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        --u;--v;
        adj[u].push_back({v,wt[i]});
        adj[v].push_back({u,wt[i]});
    }
    vector<int> dep(n, -1);
    struct Edge{
        int v,w,bridge;
        Edge(int v,int w,int bridge) : v(v), w(w), bridge(bridge) {}
        Edge() : v(0), w(0), bridge(0) {}
    };
    vector<vector<Edge>> tree(n);
    function<int(int)> dfs = [&](int u){
        int lowdep = INF;
        for(const auto &[v,w] : adj[u]){
            if(dep[v] != -1){
                if(dep[u] - dep[v] > 1) lowdep = min(lowdep, dep[v]);
                continue;
            }
            dep[v] = dep[u] + 1;
            int x = dfs(v);
            lowdep = min(x, lowdep);
            if(x <= dep[u]){
                tree[u].push_back(Edge(v,w,0));
            }
            else{
                tree[u].push_back(Edge(v,w,1));
            }
        }
        return lowdep;
    };
    dep[0] = 0;
    dfs(0);
    struct Dpnode{
        ll sp,val,totc;
        Dpnode(ll sp,ll val,ll totc) : sp(sp), val(val), totc(totc) {}
        Dpnode() : sp(0), val(0), totc(0) {}
        void add(const Dpnode &o, const Edge &e,int k){
            sp += o.sp;
            totc += o.totc;
            if(o.sp == 0){
                val += o.totc;
                return;
            }
            if(o.sp == k){
                val += o.val;
                return;
            }
            if(e.bridge){
                val += max(0ll,o.val-e.w);
                return;
            }
            val += o.val;
        }
        Dpnode operator+(const Dpnode &o){
            Dpnode ans = *this;
            ans.sp += o.sp;
            ans.val += o.val;
            ans.totc += o.totc;
            return ans;
        }
    };
    vector<vector<Dpnode>> prefix(n);
    vector<vector<Dpnode>> suffix(n);
    vector<Dpnode> findp(n);
    function<void(int)> dp = [&](int u){
        int d = tree[u].size();
        prefix[u].resize(d + 1);
        suffix[u].resize(d + 1);
        for(int i=1;i<=d;i++){
            dp(tree[u][i-1].v);
            prefix[u][i] = prefix[u][i-1];
            prefix[u][i].add(findp[tree[u][i-1].v], tree[u][i-1], k);
        }
        for(int i=d-1;i>=0;--i){
            suffix[u][i] = suffix[u][i+1];
            suffix[u][i].add(findp[tree[u][i].v], tree[u][i], k);
        }
        findp[u] = suffix[u][0] + Dpnode(special[u], val[u], val[u]);
    };
    dp(0);
    vector<ll> ans(n);
    function<void(int,Dpnode,Edge)> reroot = [&](int u,Dpnode pardp, Edge paredge){
        Dpnode base = Dpnode(special[u], val[u], val[u]);
        base.add(pardp, paredge, k);
        int d = tree[u].size();
        for(int i=0;i<d;i++){
            Dpnode curr = base;
            curr = curr + prefix[u][i] + suffix[u][i+1];
            reroot(tree[u][i].v, curr, tree[u][i]);
        }
        ans[u] = base.val + suffix[u][0].val;
    };
    reroot(0,Dpnode(),Edge());
    cout+ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}