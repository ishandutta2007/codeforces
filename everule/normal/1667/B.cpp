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
        if(l < 0 || r >= n || r < l) return base;
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
const int INF = 1e9;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    cin>>a;
    vector<ll> p(n+1);
    for(int i=1;i<=n;i++) p[i] = p[i-1] + a[i-1];
    //cout+a+p;
    vector<ll> _p_val = p;
    sort(_p_val.begin(), _p_val.end());
    _p_val.resize(unique(_p_val.begin(), _p_val.end()) - _p_val.begin());
    for(int i=0;i<=n;i++){
        p[i] = lower_bound(_p_val.begin(), _p_val.end(), p[i]) - _p_val.begin();
    }
    //cout+p;
    segment_tree<int> st_small(n+1, [&](int x,int y){
        return max(x, y);
    }, -INF);
    segment_tree<int> st_big(n+1, [&](int x,int y){
        return max(x, y);
    }, -INF);
    vector<int> fixed_sum(n + 1, -INF);
    st_small.set(p[0], 0);
    st_big.set(p[0], 0);
    fixed_sum[p[0]] = 0;
    vector<int> dp(n+1);
    for(int i=1;i<=n;i++){
        dp[i] = max(st_small.query(0, p[i] - 1) + i, st_big.query(p[i] + 1, n) - i);
        dp[i] = max(dp[i], fixed_sum[p[i]]);
        st_small.increment(p[i], dp[i] - i);
        st_big.increment(p[i], dp[i] + i);
        fixed_sum[p[i]] = dp[i];
    }
    cout<<dp[n]<<"\n";
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