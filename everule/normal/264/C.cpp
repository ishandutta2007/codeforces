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
        if(l < 0 || r >= n || l > r) return base;
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
void solve(){
    int n,q;
    cin>>n>>q;
    vector<int> c(n), v(n);
    cin>>v>>c;
    for(auto &x : c) --x;
    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        int b1 = n, b2 = n;
        vector<ll> sc(n+1, -ll(1e18));
        for(int i=0;i<n;i++){
            sc[c[i]] = max(sc[c[i]], sc[c[i]] + ll(a) * v[i]);
            sc[c[i]] = max(sc[c[i]], max(0ll, (b1 == c[i]) ?  sc[b2] : sc[b1]) + ll(b) * v[i]);
            if(sc[c[i]] >= sc[b1] && c[i] != b1){
                b2 = b1;
                b1 = c[i];
            }
            else if(sc[c[i]] >= sc[b2] && c[i] != b1){
                b2 = c[i];
            }
        }
        cout<<max(sc[b1], 0ll)<<"\n";
    }

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}