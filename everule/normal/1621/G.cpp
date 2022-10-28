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
const int p = 1e9 + 7;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    cin>>a;
    {
        auto sa = a;
        sort(sa.begin(), sa.end());
        sa.resize(unique(sa.begin(), sa.end()) - sa.begin());
        for(auto &x : a) x = lower_bound(sa.begin(), sa.end(), x) - sa.begin();
    }
    vector<int> is_left(n), is_right(n);
    {
        segment_tree<int> st(n+1, [&](int x,int y){
            return (x + y) % p;
        }, 0);
        st.set(0, 1);
        for(int i=0;i<n;i++){
            is_left[i] = st.query(0, a[i]);
            st.increment(a[i] + 1, is_left[i]);
        }
    }
    {
        segment_tree<int> st(n+1, [&](int x,int y){
            return (x + y) % p;
        }, 0);
        st.set(n, 1);
        for(int i=n-1;i>=0;--i){
            is_right[i] = st.query(a[i]+1, n);
            st.increment(a[i], is_right[i]);
        }
    }
    ll ans = 0;
    for(int i=0;i<n;i++) ans += 1ll * is_left[i] * is_right[i] % p;
    ans %= p;
    vector<int> suffix_max;
    suffix_max.push_back(n-1);
    for(int i=n-2;i>=0;--i){
        if(a[i] > a[suffix_max.back()]){
            suffix_max.push_back(i);
        }
    }
    int num_vec = suffix_max.size();
    vector<vector<int>> split(num_vec);
    for(int i=0;i<n;i++){
        int vec_id = upper_bound(suffix_max.begin(), suffix_max.end(), i, [&](int x, int y){
            return a[x] < a[y];
        }) - suffix_max.begin();
        if(vec_id >= num_vec || suffix_max[vec_id] <= i){
            ans -= 1ll * is_left[i] * is_right[i] % p;
            continue;
        }
        split[vec_id].push_back(i);
    }
    ans %= p;
    if(ans < 0) ans += p;
    for(int i=0;i<num_vec;i++) split[i].push_back(suffix_max[i]);
    for(auto &v : split){
        if(v.size() < 2) continue;
        auto ov = v;
        for(auto &x : v) x = a[x];
        {
            auto sa = v;
            sort(sa.begin(), sa.end());
            sa.resize(unique(sa.begin(), sa.end()) - sa.begin());
            for(auto &x : v) x = lower_bound(sa.begin(), sa.end(), x) - sa.begin();
        }
        segment_tree<int> st(v.size() + 1, [&](int x,int y){
            return (x + y) % p;
        }, 0);
        st.set(v.back(), 1);
        for(int i=v.size()-2;i>=0;--i){
            int num_is = st.query(v[i]+1, v.size());
            ans -= 1ll * is_left[ov[i]] * num_is % p; 
            st.increment(v[i], num_is);
        }
    }
    ans %= p;
    if(ans < 0) ans += p;
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