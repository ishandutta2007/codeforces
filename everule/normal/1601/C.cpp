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
void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n), b(m);
    cin>>a>>b;
    sort(b.begin(), b.end());
    b.push_back(1e9 + 7);
    m++;
    ll ansb = 0;
    vector<array<int,2>> sa(n);
    for(int i=0;i<n;i++) sa[i] = {a[i], i};
    sort(sa.begin(), sa.end());
    segment_tree<array<int,2>> st(vector<array<int, 2>>(n, {0,1}), [&](const array<int, 2>& x, const array<int, 2> &y){
        return array<int, 2>({min(x[0], x[1] + y[0]), x[1] + y[1]});
    }, array<int, 2>({0,0}));
    ll ans = 0;
    for(int i=0,j=0,prv=0;i<m;i++){
        if(i > 0 && b[i] == b[i-1]){
            ans += prv;
            continue;
        }
        while(j < n && sa[j][0] < b[i]){
            st.set(sa[j][1], {-1, -1});
            if(sa[j][1] != 0) ans += (st.query(0, sa[j][1] - 1)[1] + sa[j][1]) / 2;
            j++;
        }
        int kj = j;
        while(kj < n && sa[kj][0] == b[i]){
            st.set(sa[kj][1], {0,0});
            kj++;
        }
        prv = j + st.query(0, n-1)[0];
        ans += prv;
    }
    cout<<ans<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) solve();
}