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
    pair<int, T> search(function<bool(T)> cmp){ 
        //first x such that query(0, x) satisfies cmp
        assert(__builtin_popcount(n) == 1);
        int curr = 1;
        int r = n;
        T currv = base;
        int ans = 0;
        while(curr < n){
            r >>= 1;
            curr *= 2;
            if(!cmp(join(currv, segtree[curr]))){
                currv = join(currv, segtree[curr]);
                ++curr;
                ans += r;
            }
        }
        currv = join(currv, segtree[curr]);
        if(!cmp(currv)) ans++;
        return {ans, currv};
    }
};
void solve(){
    int n;
    cin>>n;
    vector<int> p(n);
    cin>>p;
    for(auto &x : p) --x;
    vector<int> pos(n);
    for(int i=0;i<n;i++) pos[p[i]] = i;
    int _n = 1;
    while(_n < n) _n *= 2;
    segment_tree<int> st(_n, [&](int x,int y){
        return x + y;
    }, 0);
    segment_tree<ll> stt(_n, [&](ll x,ll y){
        return x + y;
    }, 0ll);
    ll inv = 0;
    for(int i=0;i<n;i++){
        inv += st.query(pos[i], n-1);
        st.set(pos[i], 1);
        stt.set(pos[i], pos[i]);
        int mid = st.search([&](int x){
            return x >= i / 2 + 1;
        }).first;
        //first pos x such that [0, x] has at least ceil(i / 2) elements = median
        //x elements on right sum idx right - x * mid - x * (x + 1) / 2
        //x elements on left  x * mid - sum idx left - x * (x + 1) / 2
        //trust
        //i = 0 1st ele
        //i = 1 2nd ele
        //i = 3 2nd ele
        //works now ig
        //.fuck bugged bs
        //cout<<mid<<" "<<inv<<" "; //thonk
        ll sumidxright = stt.query(mid, n - 1) - mid;
        ll sumidxleft = stt.query(0, mid) - mid;
        ll xl = st.query(0, mid) - 1;
        ll xr = st.query(mid, n - 1) - 1;
        //cout<<sumidxleft<<" "<<sumidxright<<" "<<xl<<" "<<xr<<"\n";
        cout<<inv + sumidxright - sumidxleft - xr * mid + xl * mid - xl * (xl + 1) / 2 - xr * (xr + 1) / 2<<"\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}