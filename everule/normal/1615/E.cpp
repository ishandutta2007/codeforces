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
template<typename T, typename U>
struct lazy_segment_tree{
    int n;
    int H;
    T base;
    vector<T> segtree;
    vector<U> lazytree;
    vector<bool> isempty;
    function<T(const T&, const T&)> join;
    function<T(int, const U&, const T&)> assign;
    function<U(const U&,const U&)> lazyassign;

    lazy_segment_tree(vector<T> &seq, 
    function<T(const T&, const T&)> join, 
    function<T(int, const U&, const T&)> assign,
    function<U(const U&,const U&)> lazyassign,
    T base) : join(join), assign(assign), lazyassign(lazyassign), base(base){
        n = seq.size();
        H = 32 - __builtin_clz(n);
        segtree.resize(2*n);
        lazytree.resize(n);
        isempty.resize(n,1);
        for(int i=0;i<n;i++){
            segtree[n+i]=seq[i];
        }
        for(int i=n-1;i>=1;i--){
            segtree[i]=join(segtree[(i<<1)], segtree[(i<<1)|1]);
        }
    }
    lazy_segment_tree(int _n, 
    function<T(const T&, const T&)> join, 
    function<T(int, const U&, const T&)> assign,
    function<U(const U&,const U&)> lazyassign,
    T base) : join(join), assign(assign), lazyassign(lazyassign), base(base){
        n = _n;
        H = 32 - __builtin_clz(n);
        segtree.resize(2*n);
        lazytree.resize(n);
        isempty.resize(n,1);
        for(int i=0;i<n;i++){
            segtree[n+i]= base;
        }
        for(int i=n-1;i>=1;i--){
            segtree[i]=join(segtree[(i<<1)], segtree[(i<<1)|1]);
        }
    }
    void calc(int pos, int h){
        segtree[pos]=join(segtree[(pos<<1)],segtree[(pos<<1)|1]);
        if(!isempty[pos]){
            segtree[pos]=assign(h,lazytree[pos],segtree[pos]);
        }
    }
    void apply(int pos, U value, int h){
        segtree[pos]=assign(h, value, segtree[pos]);
        if(pos<n){
            if(!isempty[pos]){
                lazytree[pos]=lazyassign(value, lazytree[pos]);
            }
            else{
                lazytree[pos] = value;
            }
            isempty[pos]=0;
        }
    }
    void updatenode(int pos){
        int h=0;
        pos+=n;
        while(pos>1){
            h++;
            pos>>=1;
            calc(pos, h);
        }
    }
    void push(int pos){
        int h=H;
        for(pos+=n;h;--h){
            int x=(pos>>h);
            if(!isempty[x]){
                apply((x<<1), lazytree[x], h-1);
                apply((x<<1)|1, lazytree[x], h-1);
                isempty[x]=1;
            }
        }
    }
    void updaterange(int l, int r, U value){
        push(l);
        push(r);
        int k=0;
        int l0=l, r0=r;
        for(l+=n, r+=n+1;l<r;l>>=1, r>>=1, k++){
            if(l&1){
                apply(l++, value, k);
            }
            if(r&1){
                apply(--r, value,k);
            }
        }
        updatenode(l0);
        updatenode(r0);
    }
    T query(int l, int r){
        push(l);
        push(r);
        T ansl=base;
        T ansr=base;
        for(l+=n,r+=n+1;l<r;l>>=1,r>>=1){
            if(l&1){
                ansl=join(ansl, segtree[l++]);
            }        
            if(r&1){
                ansr=join(segtree[--r], ansr);
            }
        }
        return join(ansl,ansr);
    }
};
void solve(){
    int n,k;
    cin>>n>>k;
    vector<vector<int>> g(n);
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        --u;--v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> dep(n), tin(n), tout(n), par(n);
    int lv = 0;
    {
        int t = 0;
        function<void(int,int)> dfs = [&](int u,int pr){
            tin[u] = t++;
            for(auto v : g[u]){
                if(v == pr) continue;
                dep[v] = dep[u] + 1;
                par[v] = u;
                dfs(v, u);
            }
            tout[u] = t - 1;
            if(u != 0 && g[u].size() == 1) lv++;
        };
        dfs(0, 0);
    }
    if(k >= lv){
        ll ans = 0;
        for(int i=0;i<=k-lv;i++){
            ans = max(ans, 1ll * (lv + i) * (n - lv - i));
        }
        cout<<ans<<"\n";
        return;
    }
    vector<array<int, 2>> start(n);
    for(int i=0;i<n;i++){
        start[tin[i]][0] = dep[i];
        start[tin[i]][1] = i;
    }
    lazy_segment_tree<array<int, 2>, int> st(start, [&](array<int, 2> x,array<int, 2> y){
        if(x[0] > y[0]) return x;
        else return y;
    }, [&](int h, int y, array<int, 2> x){
        return array<int, 2>({x[0] + y, x[1]});
    }, [&](int x,int y){
        return x + y;
    }, array<int, 2>({-1,-1}));
    vector<bool> used(n);
    int w = 0;
    for(int l=0;l<k;l++){
        auto nxt = st.query(0, n - 1);
        assert(g[nxt[1]].size() == 1 && nxt[1] > 0);
        int gn = 0;
        while(!used[par[nxt[1]]]){
            w++;
            gn++;
            nxt[1] = par[nxt[1]];
            used[nxt[1]] = 1;
            st.updaterange(tin[nxt[1]], tout[nxt[1]], -1);
        }
        assert(gn == nxt[0]);
    }
    if(n - k - w >= n/2){
        cout<<(1ll * (n - n/2 - k)) * (k - n/2)<<"\n";
        return;
    }
    cout<<(1ll * w) * (k - (n - w - k))<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}