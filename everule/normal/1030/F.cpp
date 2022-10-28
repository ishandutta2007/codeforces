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
    T query(int l, int r){
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
    T search(T val){
        assert(__builtin_popcount(n) == 1);
        int idx = 1;
        T curr = base;
        while(idx < n){
            idx<<=1;
            if(join(curr,segtree[idx]) < val){
                curr = join(curr, segtree[idx]);
                ++idx;
            }
        }
        if(join(curr, segtree[idx]) < val){
            curr = join(curr, segtree[idx]);
            ++idx;
        }
        return idx - n;
    }
};
const int p = 1e9 + 7;
void solve(){
    int n,q;
    cin>>n>>q;
    vector<ll> a(n), w(n);
    cin>>a>>w;
    for(int i=0;i<n;i++) a[i]-=i;
    vector<ll> aw(n);
    for(int i=0;i<n;i++) aw[i]=a[i]*w[i], aw[i]%=p;
    int pn = 1;
    while(pn < n){
        pn<<=1;
    }
    w.resize(pn);
    aw.resize(pn);
    segment_tree<ll> segtree1(w, [&](ll x,ll y){
        return x+y;
    }, 0ll);
    segment_tree<ll> segtree2(aw, [&](ll x,ll y){
        ll ans = x + y;
        if(ans >= p) ans-=p;
        return ans;
    }, 0ll);
    for(int i=0;i<q;i++){
        int l,r;
        cin>>l>>r;
        if(l > 0){
            --l;--r;
            ll sum = (segtree1.query(l,r) + 1)/2;
            if(l!=0) sum+=segtree1.query(0,l-1);
            int idx = segtree1.search(sum);
            ll x = a[idx];
            ll ans = segtree2.query(idx,r) - segtree2.query(l,idx) + (((segtree1.query(l,idx) - segtree1.query(idx,r))%p) * x)%p;
            ans%=p;
            if(ans<0) ans+=p;
            cout<<ans<<"\n";
        }
        else{
            l = -l;
            --l;
            segtree1.set(l,r);
            segtree2.set(l, r*a[l]%p);
        }
    } 
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}