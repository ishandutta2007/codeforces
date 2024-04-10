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
const int INF = 1e9;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1), b(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int j=1;j<=n;j++) cin>>b[j];
    vector<vector<int>> binv(n+1);
    for(int i=1;i<=n;i++){
        binv[i + b[i]].push_back(i);
    }
    segment_tree<array<int,2>> st(n+1, [&](const array<int, 2>& x, const array<int, 2>& y){
        return min(x, y);
    }, array<int,2>({INF,INF}));
    for(int i=1;i<=n;i++){
        st.set(i, array<int, 2>({i-a[i], i}));
    }
    queue<int> bfs;
    vector<int> par(n+1, -1);
    vector<int> dist(n+1, INF);
    dist[0] = 0;
    bfs.push(0);
    while(!bfs.empty()){
        int h = bfs.front();
        bfs.pop();
        while(true){
            auto ch = st.query(h, n);
            if(ch[0] <= h){
                for(auto &c : binv[ch[1]]){
                    bfs.push(c);
                    par[c] = h;
                    dist[c] = dist[h] + 1;
                }
                st.set(ch[1], st.base);
            }
            else{
                break;
            }
        }
    }
    array<int, 2> ans = st.base;
    for(int i=n;i>=n-a[n];i--){
        ans = min(ans, array<int, 2>({dist[i], i}));
    }
    if(ans[0] > n){
        cout<<"-1\n";
        return;
    }
    vector<int> d;
    int curr = ans[1];
    while(curr > 0){
        d.push_back(curr);
        curr = par[curr];
    }
    d.push_back(0);
    cout<<d.size()<<"\n";
    cout+d;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}