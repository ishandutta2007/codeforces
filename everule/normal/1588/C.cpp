#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template<typename T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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
    segment_tree(int _n, function<T(const T&,const T&)> join, T base = T()) : n(_n), join(join), base(base){
        n = 32 - __builtin_clz(n-1);
        n = (1<<n);
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
    int find(T val){
        if(segtree[1] > val) return n;
        int idx = 1;
        T sum = base;
        while(idx < n){
            if(join(sum, segtree[idx<<1]) <= val){
                idx = (idx<<1);
            }
            else{
                sum = join(sum, segtree[(idx<<1)]);
                idx = ((idx<<1)|1);
            }
        }
        return idx - n;
    }
};
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    cin>>a;
    vector<ll> p(n+1);
    for(int i=0;i<n;i++){
        p[i+1] = a[i] - p[i];
    }
    segment_tree<ll> sto(n+1, [&](ll x, ll y){
        return min(x, y);
    }, 1e18);
    segment_tree<ll> ste(n+1, [&](ll x, ll y){
        return min(x, y);
    }, 1e18);
    map<int, vector<int>> mpe, mpo;
    ll ans = 0;
    //cout+p;
    for(int i=n;i>=0;--i){
        if(i % 2 == 1){
            int r1 = sto.find(p[i] - 1);
            int r2 = ste.find(-p[i] - 1);
            int r = min(r1, r2);
            //cout<<i<<" "<<r<<"\n";
            //cout<<mpo[p[i]].size()<<"\n";
            ans += lower_bound(mpo[p[i]].rbegin(), mpo[p[i]].rend(), r) - mpo[p[i]].rbegin();
            sto.set(i, p[i]);
            mpo[p[i]].push_back(i);
            mpe[-p[i]].push_back(i);
        }
        else{
            int r1 = ste.find(p[i] - 1);
            int r2 = sto.find(-p[i] - 1);
            int r = min(r1, r2);
            //cout<<i<<" "<<r<<"\n";
            //cout<<mpe[p[i]].size()<<"\n";
            ans += lower_bound(mpe[p[i]].rbegin(), mpe[p[i]].rend(), r) - mpe[p[i]].rbegin();
            ste.set(i, p[i]);
            mpe[p[i]].push_back(i);
            mpo[-p[i]].push_back(i);
        }
    }
    cout<<ans<<"\n";
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