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
void solve(){
    int n;
    cin>>n;
    vector<int> p(n);
    cin>>p;
    vector<int> mn_stk, mx_stk;
    mn_stk.push_back(0);
    mx_stk.push_back(0);
    segment_tree<int> st_mn(n, [&](int x,int y){
        return min(x, y);
    }, n+1);
     segment_tree<int> st_mx(n, [&](int x,int y){
        return min(x, y);
    }, n+1);
    st_mn.set(0, 0);
    st_mx.set(0, 0);
    vector<int> prev_smaller(n, -1), prev_larger(n, -1);
    for(int i=1;i<n;i++){
        while(mn_stk.size() > 0 && p[mn_stk.back()] > p[i]){
            st_mn.set(mn_stk.back(), st_mn.base);
            mn_stk.pop_back();
        }
        while(mx_stk.size() > 0 && p[mx_stk.back()] < p[i]){
            st_mx.set(mx_stk.back(), st_mx.base);
            mx_stk.pop_back();
        }
        if(mn_stk.size() > 0) prev_smaller[i] = mn_stk.back();
        if(mx_stk.size() > 0) prev_larger[i] = mx_stk.back();
        int ans = min(st_mn.query(prev_larger[i] + 1, i), st_mx.query(prev_smaller[i] + 1, i)) + 1;
        mn_stk.push_back(i);
        mx_stk.push_back(i);
        st_mn.set(i, ans);
        st_mx.set(i, ans);
    }
    cout<<st_mn.query(n-1, n-1)<<"\n";
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