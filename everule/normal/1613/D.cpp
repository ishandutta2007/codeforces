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
const int p = 998244353;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    cin>>a;
    vector<ll> dp1(n+1), dp2(n+1), dp3(n+1);
    for(int i=0;i<n;i++){
        int olddp1 = dp1[a[i]];
        int olddp2 = dp2[a[i]];
        int olddp3 = dp3[a[i]];
        if(a[i] > 0) dp1[a[i]] += dp1[a[i] - 1];
        if(a[i] - 2 >= 0) dp2[a[i]] += dp1[a[i] - 2];
        if(a[i] - 2 >= 0) dp2[a[i]] += dp3[a[i] - 2];
        if(a[i] + 2 <= n) dp3[a[i]] += dp2[a[i] + 2];
        if(a[i] == 0) dp1[0]++;
        if(a[i] == 1) dp2[1]++;
        dp1[a[i]] += olddp1;
        dp2[a[i]] += olddp2;
        dp3[a[i]] += olddp3;
        dp1[a[i]] %= p;
        dp2[a[i]] %= p;
        dp3[a[i]] %= p;
    }
    //cout+dp1+dp2;
    cout<< (accumulate(dp1.begin(), dp1.end(), 0ll) + accumulate(dp2.begin(), dp2.end(), 0ll) + accumulate(dp3.begin(), dp3.end(), 0ll)) % p <<"\n";
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