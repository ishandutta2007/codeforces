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
const int AL = 26;
void solve(){
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    {
        string ss = s;
        sort(ss.begin(), ss.end());
        if(ss >= t){
            cout<<"-1\n";
            return;
        }
    }
    vector<vector<int>> cp(AL);
    for(int i=n-1;i>=0;--i){
        cp[s[i] - 'a'].push_back(i);
    }
    ll ans = 1e18;
    ll curr = 0;
    segment_tree<int> st(n, [&](int x,int y){
        return x + y;
    }, 0);
    for(int i=0;i<n;i++){
        int ch = t[i] - 'a';
        for(int j=0;j<ch;j++){
            if(cp[j].size() == 0) continue;
            int pos = cp[j].back();
            pos += st.query(pos, n - 1);
            ans = min(ans, curr + abs(pos - i));
        }
        if(cp[ch].size() == 0) break;
        int pos = cp[ch].back();
        pos += st.query(pos, n - 1);
        curr += abs(pos - i);
        st.increment(cp[ch].back(), 1);
        cp[ch].pop_back();
    }
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