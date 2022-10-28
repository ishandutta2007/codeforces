#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5002;
const int inf = 1e18;
vector<vector<int>> dp(N, vector<int>(N, -inf));
vector<int> t(2 * N, -inf);
int n, k, x;

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
template<int lgn>
struct sparse_table{
    vector<array<int, lgn>> table;
    void build(vector<int> x){
        int n = x.size();
        table.resize(n);
        for(int i=0;i<n;i++){
            table[i][0] = x[i];
        }
        for(int j=0;j+1<lgn;j++){
            for(int i=0;i<n;i++){
                table[i][j+1] = table[i][j];
                if(i + (1<<j) < n) table[i][j+1] = max(table[i][j+1], table[i + (1<<j)][j]);
            }
        }
    }
    int query(int l,int r){
        int p2 = 63 - __builtin_clzll(r - l + 1);
        return max(table[l][p2], table[r-(1<<p2)+1][p2]);
    }
};
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    cin >> n >> k >> x;
    if(n / k > x)
        return cout << -1 << endl, 0;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    dp[0][0] = 0;
    sparse_table<14> rmq;
    rmq.build(dp[0]);
    for(int chosen = 1; chosen <= x; chosen++){
        for(int i = 1; i <= n; i++) {
            dp[chosen][i] = a[i] + rmq.query(max(0ll,i - k), i-1);
        } 
        rmq.build(dp[chosen]);
    }
    //for(int chosen = 1; chosen <= x; chosen++) { for(int i = 1; i <= n; i++) cout << (dp[chosen][i] <= -inf ? -1 : dp[chosen][i]) << ' '; cout << endl;}
    int ans = 0;
    for(int i = n; i > n - k; i--) ans = max(ans, dp[x][i]);
    cout << ans << endl;
    return 0;
}