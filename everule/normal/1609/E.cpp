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
};
struct node{
    int ca, cb, cc;
    int ba, bb, eb;
    int bans;
    node join(node o){
        node ans('-');
        ans.ca = ca + o.ca;
        ans.cb = cb + o.cb;
        ans.cc = cc + o.cc;
        ans.ba = min(ba + o.cb, o.ba + ca);
        ans.bb = min(bb + o.cc - o.cb, o.bb);
        ans.bans = min({bans + o.cc, ca + o.bans, ba + o.cb + min(0, o.bb)});
        return ans;
    }
    node(char c){
        if(c == 'a'){
            ca = 1;
            cb = 0;
            cc = 0;
            ba = 0;
            bb = 2e5;
            bans = 2e5;
        }
        else if(c == 'b'){
            ca = 0;
            cb = 1;
            cc = 0;
            ba = 2e5;
            bb = -1;
            bans = 2e5;
        }
        else if(c == 'c'){
            ca = 0;
            cb = 0;
            cc = 1;
            ba = 2e5;
            bb = 2e5;
            bans = 2e5;
        }
        else{
            ca = 0;
            cb = 0;
            cc = 0;
            ba = 2e5;
            bb = 2e5;
            bans = 2e5;
        }
    }
};
void solve(){
    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    segment_tree<node> st(n, [&](node x, node y){
        return x.join(y);
    }, node('-'));
    for(int i=0;i<n;i++){
        st.set(i, node(s[i]));
    }
    for(int i=0;i<q;i++){
        int pos;
        char c;
        cin>>pos>>c;
        --pos;
        st.set(pos, node(c));
        node ans = st.query(0, n-1);
        cout<<min({ans.ca, ans.cb, ans.cc, ans.bans})<<"\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}