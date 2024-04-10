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
    T findl(T v){
        int idx = 1;
        T curr = base;
        while(idx < n){
            idx <<= 1;
            if(v >= join(curr, segtree[idx])){
                curr = join(curr, segtree[idx]);
                idx++;
            }
        }
        if(v >= join(curr, segtree[idx])){
            idx++;
        }
        return idx - n;
    }
};
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    cin>>a;
    int x;
    cin>>x;
    for(auto &v : a) v -= x;
    vector<ll> ps(n + 1);
    for(int i=1;i<=n;i++) ps[i] = ps[i-1] + a[i-1];
    //cout+a;
    //cout+ps;
    vector<int> lim(n+1, n);
    auto calc = [&](int i){
        for(int j=i+1;j<=min(i+5, n);j++){
            for(int k=i;k<j-1;k++){
                if(ps[j] < ps[k]){
                    return j - 1;
                }
            }
        }
        return lim[i+1];
    };
    for(int i=n-2;i>=0;--i){
        lim[i] = calc(i);   
    }
    //cout+lim;
    segment_tree<int> st(n + 1, [&](int x, int y){
        return min(x, y);
    }, int(1e9 + 8));
    st.set(n, 0);
    for(int i=n-1;i>=0;--i){
        st.set(i, st.query(i, lim[i+1]) + 1);
    }
   //for(int i=0;i<=n;i++) cout<<st.query(i,i)<<" ";
    //cout<<"\n\n";
    cout<<n - st.query(0, lim[0])<<"\n";
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