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
struct LineTree{
    struct DSU{
        vector<int> parent;
        vector<int> sizof;
        vector<array<int, 2>> line;
        vector<int> nxt;
        vector<T> nxtw;
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
        void join_sets(int a, int b, T w) {
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
    vector<tuple<T,int,int>> edges;
    DSU dsu;
    int n;
    function<bool(T, T)> cmp;
    LineTree(int n, function<bool(T, T)> cmp) : dsu(n), n(n), cmp(cmp) {}
    void add_edge(int u, int v, T w){
        edges.emplace_back(w, u, v);
    }
    tuple<vector<int>, vector<int>, vector<T>> computeLineTree(){
        sort(edges.begin(), edges.end(), [&](tuple<T, int, int> x, tuple<T, int, int> y){
            return cmp(get<0>(y), get<0>(x));
        });
        for(auto &[w,u,v] : edges){
            dsu.join_sets(u, v, w);
        }
        int root = dsu.find_set(0);
        vector<int> ord(n);
        ord[0] = dsu.line[root][0];
        for(int i=1;i<n;i++) ord[i] = dsu.nxt[ord[i-1]];
        vector<int> id(n);
        for(int i=0;i<n;i++) id[ord[i]] = i;
        vector<int> wts(n - 1);
        for(int i=0;i+1<n;i++) wts[i] = dsu.nxtw[ord[i]];
        return {ord, id, wts};
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
    lazy_segment_tree(int n, 
    function<T(const T&, const T&)> join, 
    function<T(int, const U&, const T&)> assign,
    function<U(const U&,const U&)> lazyassign,
    T base) : join(join), assign(assign), lazyassign(lazyassign), base(base){
        H = 32 - __builtin_clz(n);
        segtree.resize(2*n);
        lazytree.resize(n);
        isempty.resize(n,1);
        for(int i=0;i<n;i++){
            segtree[n+i] = base;
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
    int n,q;
    cin>>n>>q;
    LineTree<int> lt(n, [&](int x,int y){
        return x > y;
    });
    for(int i=1;i<n;i++){
        int u,v,w;
        cin>>u>>v>>w;
        --u;--v;
        lt.add_edge(u, v, w);
    }
    auto [ord, id, wts] = lt.computeLineTree();
    segment_tree<int> st(wts, [&](int x,int y){
        return max(x, y);
    });
    vector<array<int, 4>> lst_val(n);
    for(int i=0;i<n;i++) lst_val[i] = {id[i], 0, id[i], n+1};
    lazy_segment_tree<array<int, 4>, int> lst(lst_val,
        [&](array<int, 4> x, array<int, 4> y){
            array<int, 4> z;
            for(int i=0;i<4;i++) if(i < 2) z[i] = max(x[i], y[i]); else z[i] = min(x[i], y[i]);
            return z;
        }, 
        [&](int h, int u, array<int, 4> x){
            if(u == 0){
                x[1] = -1;
                x[3] = n+1;
            }
            else{
                x[1] = x[0];
                x[3] = x[2];
            }
            return x;
        },
        [&](int x, int y){
            return x;
    }, array<int, 4>({-1, -1, n+1, n+1}));
    for(int i=0;i<q;i++){
        int t;
        cin>>t;
        if(t == 1){
            int l,r;
            cin>>l>>r;
            --l;--r;
            lst.updaterange(l, r, 1);
        }
        if(t == 2){
            int l,r;
            cin>>l>>r;
            --l;--r;
            lst.updaterange(l, r, 0);
        }
        if(t == 3){
            int x;
            cin>>x;
            --x;
            auto [_, mx, __, mn] = lst.query(0, n-1);
            mx = max(mx, id[x]);
            mn = min(mn, id[x]);
            if(mn == mx) cout<<"-1\n";
            else cout<<st.query(mn, mx-1)<<"\n";
        }
    }

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}