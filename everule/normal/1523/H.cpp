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
const int MAXK = 33;
const int LGN = 20;
void solve(){
    int n,q;
    cin>>n>>q;
    vector<array<int, 2>> a(n);
    for(int i=0;i<n;i++) cin>>a[i][0], a[i][1] = i;
    for(int i=0;i<n;i++) a[i][0] += i;
    segment_tree<array<int, 2>> st(a, [&](array<int, 2> x,array<int, 2> y){
        if(x[0] < y[0]) return y;
        else return x;
    }, {0,0});
    vector<array<array<int, MAXK>, LGN>> lft(n);
    for(int i=n-1;i>=0;--i){
        for(int j=0;j<MAXK;j++){
            lft[i][0][j] = st.query(i, min(a[i][0] + j, n-1))[1];
        }
    }
    //for(int i=0;i<n;i++) cout<<lft[i][0][0]<<" ";
    //cout<<"\n";
    for(int k=1;k<LGN;k++){
        for(int i=n-1;i>=0;--i){
            fill(lft[i][k].begin(), lft[i][k].end(), i);
            for(int j1=0;j1<MAXK;j1++){
                for(int j2=0;j1+j2<MAXK;j2++){
                    if(a[lft[i][k][j1+j2]][0] < a[lft[lft[i][k-1][j1]][k-1][j2]][0]){
                        lft[i][k][j1+j2] = lft[lft[i][k-1][j1]][k-1][j2];
                    }
                }
            }
        }
    }
    //cout<<lft[0][2][0]<<"\n";
    for(int _=0;_<q;_++){
        int l,r,k;
        cin>>l>>r>>k;
        --l;--r;
        array<int, MAXK> curr;
        fill(curr.begin(), curr.end(), l);
        if(l == r){
            cout<<"0\n";
            continue;
        }
        if(a[l][0] + k>= r){
            cout<<"1\n";
            continue;
        }
        //for(auto &x : curr) cout<<x<<" ";
        //cout<<"\n";
        int ans = 2;
        for(int lg=LGN-1;lg>=0;--lg){
            array<int, MAXK> ncurr;
            fill(ncurr.begin(), ncurr.end(), l);
            for(int j1=0;j1<=k;j1++){
                for(int j2=0;j1+j2<=k;j2++){
                    if(a[ncurr[j1+j2]][0] < a[lft[curr[j1]][lg][j2]][0]){
                        ncurr[j1+j2] = lft[curr[j1]][lg][j2];
                    }
                }
            }
            bool good = 1;
            for(int j=0;j<=k;j++){
                if(a[ncurr[j]][0] + k - j >= r) good = 0;
            }
            if(good){
                ans += (1<<lg);
                curr = ncurr;
            }
        }
        cout<<ans<<"\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}