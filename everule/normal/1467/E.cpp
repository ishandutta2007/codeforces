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
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    cin>>a;
    vector<vector<int>> adj(n);
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        --u;--v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> tin(n), tout(n);
    [&](){
        int t = 0;
        function<void(int,int)> dfs = [&](int u,int p){
            tin[u] = t++;
            for(int i=0;i<adj[u].size();i++){
                if(adj[u][i] == p){
                    adj[u].erase(adj[u].begin()+i);
                    break;
                }
            }
            for(const auto &v : adj[u]){
                dfs(v,u);
            }
            tout[u] = t-1;
        };
        dfs(0,0);
    }();
    RangeUpdate<int> st(n, [&](int x,int y){
        return (x|y);
    }, 0);
    map<int,vector<int>> ipos;
    for(int i=0;i<n;i++) ipos[a[i]].push_back(tin[i]);
    for(auto &[x,y] : ipos) sort(y.begin(), y.end());
    for(int i=0;i<n;i++){
        auto &ls = ipos[a[i]];
        if(ls.front() < tin[i] || ls.back() > tout[i]){
            st.update(tin[i], tout[i], 1);
        }
        auto it = upper_bound(ls.begin(), ls.end(), tin[i]);
        if(it == ls.end()) continue;
        if(*it > tout[i]) continue;
        auto it2 = upper_bound(ls.begin(), ls.end(), tout[i]);
        --it2;
        auto srch = [&](int tm){
            int l = 0, r = adj[i].size() - 1;
            while(l < r){
                int md = (l+r+1)/2;
                if(tin[adj[i][md]] <= tm){
                    l = md;
                }
                else{
                    r = md-1;
                }
            }
            return l;
        };
        int c1 = srch(*it);
        int c2 = srch(*it2);
        if(c1 != c2){
            cout<<"0\n";
            return;
        }
        int c = adj[i][c1];
        st.update(0,tin[c]-1,1);
        st.update(tout[c]+1,n-1,1);
    }
    int ans = 0;
    for(int i=0;i<n;i++) ans += (st.query(i) == 0);
    cout<<ans<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}