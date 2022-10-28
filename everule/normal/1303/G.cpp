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
template<int MAXA, bool maxval = 1>
struct LiChaoTree{
    struct Line{
        ll m,c;
        Line(){}
        Line(ll m,ll c) : m(m), c(c) {}
        ll evaluate(ll x){
            return (m*x + c) * (maxval ? -1 : 1);
        }
    };
    struct Node{
        Line top;
        int left=-1, right=-1;
        Node() {}
        Node(ll m, ll c) : top(Line(m,c)) {}
        Node (Line curr) : top(curr) {}
        ll evaluate(ll x){
            return top.evaluate(x);
        }
    };
    vector<Node> Tree;
    const ll INF = 1e18;
    LiChaoTree(){
        Tree.emplace_back(0,INF * (maxval ? -1 : 1));
    }
    void addline(ll m,ll c){
        addline(Line(m,c),0,MAXA+1,0);
    }
    void addline(Line toadd,ll l,ll r,int idx){
        ll mid = (l+r)/2;
        Line& top = Tree[idx].top;
        if(top.evaluate(mid) > toadd.evaluate(mid)){
            swap(top, toadd);
        }
        if(r-l <= 1) return;
        if(top.evaluate(l) > toadd.evaluate(l)){
            if(Tree[idx].left == -1){
                Tree[idx].left = Tree.size();
                Tree.emplace_back(top);
            }
            addline(toadd,l,mid,Tree[idx].left);
        }
        else{
            if(Tree[idx].right == -1){
                Tree[idx].right = Tree.size();
                Tree.emplace_back(top);
            }
            addline(toadd,mid,r,Tree[idx].right);
        }
    }
    ll query(ll x){
        return min(Tree[0].evaluate(x), query(x,0,MAXA+1,0)) * (maxval ? -1 : 1);
    }
    ll query(ll x,ll l,ll r,int idx){
        if(idx==-1) return INF;
        if(x<l || x>=r) return Tree[idx].evaluate(x);
        if(r-l <= 1) return Tree[idx].evaluate(x);
        ll mid = (l+r)/2;
        return min({Tree[idx].evaluate(x), query(x,l,mid,Tree[idx].left), query(x,mid,r,Tree[idx].right)});
    }
    void clear(){
        Tree.clear();
        Tree.emplace_back(0,INF * (maxval ? -1 : 1));
    }
};
const int MAXA = 2e5;
void solve(){
    int n;
    cin>>n;
    vector<vector<int>> adj(n);
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        --u;--v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> a(n);
    cin>>a;
    vector<int> sz(n);
    vector<bool> used(n);
    auto getcentroid = [&](int u){
        function<void(int,int)> dfs = [&](int u,int p){
            sz[u] = 1;
            for(const auto &v : adj[u]){
                if(v == p || used[v]) continue;
                dfs(v,u);
                sz[u] += sz[v]; 
            }
        };
        dfs(u,u);
        int ans = -1;
        int n = sz[u];
        dfs = [&](int u,int p){
            bool ok = 1;
            for(const auto &v : adj[u]){
                if(v == p || used[v]) continue;
                if(sz[v] > n/2){
                    ok = 0;
                    sz[u]-=sz[v];
                    sz[v]+=sz[u];
                    dfs(v,u);
                }
            }
            if(ok) ans = u;
        };
        dfs(u,u);
        assert(~ans);
        return ans;
    };
    ll ans = *max_element(a.begin(), a.end());
    function<void(int)> solve = [&](int u){
        int c = getcentroid(u);
        LiChaoTree<MAXA,1> lct;
        lct.addline(a[c], a[c]);
        for(const auto &v : adj[c]){
            if(used[v]) continue;
            ll sum = 0;
            ll psum = 0;
            ll dep = 0;
            function<void(int,int)> dfs1 = [&](int u,int p){
                sum += a[u];
                psum += sum;
                dep++;
                ans = max(ans, lct.query(dep) + psum);
                for(const auto &v : adj[u]){
                    if(v==p || used[v]) continue;
                    dfs1(v,u);
                }
                --dep;
                psum -= sum;
                sum -= a[u];
            };
            dfs1(v,c);
            sum = a[c];
            psum = a[c];
            dep = 1;
            function<void(int,int)> dfs2 = [&](int u,int p){
                sum += a[u];
                ++dep;
                psum += a[u] * dep;
                lct.addline(sum, psum);
                ans = max(ans, psum);
                for(const auto &v : adj[u]){
                    if(v == p || used[v]) continue;
                    dfs2(v,u);
                }
                psum -= a[u] * dep;
                --dep;
                sum -= a[u];
            };
            dfs2(v,c);
        }
        reverse(adj[c].begin(), adj[c].end());
        lct.clear();
        lct.addline(a[c], a[c]);
        for(const auto &v : adj[c]){
            if(used[v]) continue;
            ll sum = 0;
            ll psum = 0;
            ll dep = 0;
            function<void(int,int)> dfs1 = [&](int u,int p){
                sum += a[u];
                psum += sum;
                dep++;
                ans = max(ans, lct.query(dep) + psum);
                for(const auto &v : adj[u]){
                    if(v==p || used[v]) continue;
                    dfs1(v,u);
                }
                --dep;
                psum -= sum;
                sum -= a[u];
            };
            dfs1(v,c);
            sum = a[c];
            psum = a[c];
            dep = 1;
            lct.addline(a[c], a[c]);
            function<void(int,int)> dfs2 = [&](int u,int p){
                sum += a[u];
                ++dep;
                psum += a[u] * dep;
                lct.addline(sum, psum);
                ans = max(ans, psum);
                for(const auto &v : adj[u]){
                    if(v == p || used[v]) continue;
                    dfs2(v,u);
                }
                psum -= a[u] * dep;
                --dep;
                sum -= a[u];
            };
            dfs2(v,c);
        }
        used[c] = 1;
        for(const auto &v : adj[c]){
            if(!used[v]) solve(v);
        }
    };
    solve(0);
    cout<<ans<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}