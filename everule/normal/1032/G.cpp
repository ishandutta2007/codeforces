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
template<typename T, int lgn>
struct sparse_table{
    vector<array<T, lgn>> table;
    int n;
    function<T(T,T)> join;
    sparse_table(vector<T> seq, function<T(T,T)> join) : table(seq.size()), join(join), n(seq.size()){
        build(seq);
    }
    void build(vector<T> seq){
        for(int i=0;i<n;i++){
            table[i][0] = seq[i];
        }
        for(int i=0;i+1<lgn;i++){
            for(int j=0;j<n;j++){
                if(j + (1<<i) >= n){
                    table[j][i+1] = table[j][i];
                }
                else{
                    table[j][i+1] = join(table[j][i], table[j+(1<<i)][i]);
                }
            }
        }
    }
    T query(int l,int r){
        ++r;
        int lg = 31 - __builtin_clz(r - l);
        lg = 0;
        return join(table[l][lg], table[r-(1<<lg)][lg]);
    }
};
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
const int LGN = 20;
const int INF = 1e9;
void solve(){
    int n;
    cin>>n;
    if(n == 1){
        cout<<"0\n";
        return;
    }
    vector<int> r(n);
    cin>>r;
    for(int i=0;i<n;i++) r.push_back(r[i]);
    for(int i=0;i<n;i++) r.push_back(r[i]);
    vector<array<int, 2>> rr(3 * n), rl(3 * n);
    for(int i=0;i<3*n;i++) rr[i] = {min(r[i] + i, 3*n - 1), i};
    for(int i=0;i<3*n;i++) rl[i] = {max(0, i - r[i]), i};
    vector<array<array<int, 2>, LGN>> bl(3 * n);
    vector<segment_tree<int>> str(LGN, segment_tree<int>(3 * n, [&](int x,int y){
        return max(x, y);
    }, 0));
    vector<segment_tree<int>> stl(LGN, segment_tree<int>(3 * n, [&](int x,int y){
        return min(x, y);
    }, 3 * n - 1));
     for(int i=0;i<3*n;i++){
        bl[i][0][0] = rl[i][0];
        bl[i][0][1] = rr[i][0];
        stl[0].set(i, rl[i][0]);
        str[0].set(i, rr[i][0]);
    }
    for(int lg=1;lg<LGN;lg++){
        for(int i=0;i<3*n;i++){
            bl[i][lg][0] = stl[lg-1].query(bl[i][lg-1][0], bl[i][lg-1][1]);
            bl[i][lg][1] = str[lg-1].query(bl[i][lg-1][0], bl[i][lg-1][1]);
        }
        for(int i=0;i<3*n;i++){
            stl[lg].set(i, bl[i][lg][0]);
            str[lg].set(i, bl[i][lg][1]);
        }
    }
    for(int i=0;i<n;i++){
        int ans = 1;
        array<int, 2> v = bl[i+n][0];
        //cout<<i<<"\n";
        //cout<<v[0]<<" "<<v[1]<<"\n";
        //cout<<r[0]<<" "<<r[1]<<"\n";
        for(int lg=LGN-1;lg>=0;--lg){
            array<int, 2> nv;
            nv[0] = stl[lg].query(v[0], v[1]);
            nv[1] = str[lg].query(v[0], v[1]);
            if(nv[1] - nv[0] + 1 < n){
                v = nv;
                //cout<<v[0]<<" "<<v[1]<<"\n";
                ans += (1<<lg);
            }
        }
        if(v[1] - v[0] + 1< n){
            ans++;
        }
        cout<<ans<<" ";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}