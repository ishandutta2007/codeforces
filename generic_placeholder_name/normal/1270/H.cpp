#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define gcd __gcd
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define rep(i, n) for (int i=0; i<(n); i++)
#define rep1(i, n) for (int i=1; i<=(n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned uint;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
template<typename _def> using ordered_set=tree<_def, null_type, less<_def>, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

struct Node {
    int mn=0, lz=0, cnt=0;
    Node() {}
    Node(int x): mn(x), lz(0), cnt(1) {}
    friend Node operator + (const Node& a, const Node& b) {
        Node c;
        if(a.mn<b.mn) c.mn=a.mn, c.cnt=a.cnt;
        else if(b.mn<a.mn) c.mn=b.mn, c.cnt=b.cnt;
        else c.mn=a.mn, c.cnt=a.cnt+b.cnt;
        return c;
    }
    void push(Node& l, Node& r) {
        if(!lz) return;
        l.mn+=lz; l.lz+=lz;
        r.mn+=lz; r.lz+=lz;
        lz=0;
    }
};

template<int N>
struct SegTree {
    Node t[4*N+4];
    void upd_cnt(int pos, int val, int v=1, int l=1, int r=N) {
        if(l==r) {
            t[v].cnt+=val;
            return;
        }
        else {
            t[v].push(t[v*2], t[v*2+1]);
            int m=(l+r)/2;
            if(pos<=m) upd_cnt(pos, val, v*2, l, m);
            else upd_cnt(pos, val, v*2+1, m+1, r);
            t[v]=t[v*2]+t[v*2+1];
        }
    }
    void upd(int ql, int qr, int val, int v=1, int l=1, int r=N) {
        if(ql>r||qr<l) return;
        if(ql<=l&&qr>=r) {
            t[v].mn+=val;
            t[v].lz+=val;
            return;
        }
        else {
            t[v].push(t[v*2], t[v*2+1]);
            int m=(l+r)/2;
            upd(ql, qr, val, v*2, l, m);
            upd(ql, qr, val, v*2+1, m+1, r);
            t[v]=t[v*2]+t[v*2+1];
        }
    }
    int get_top() {return t[1].cnt;}
};

constexpr int N=1e6+2;
int a[N];
SegTree<N> t;

int32_t main() {
    fastio;
    int n, q; cin>>n>>q;
    a[0]=N, a[n+1]=0; rep1(i, n) cin>>a[i];
    rep(i, n+1) {
        if(a[i]>a[i+1]) t.upd(a[i+1]+1, a[i], 1);
		if(i) t.upd_cnt(a[i], 1);
    }
    while(q--) {
        int x, v; cin>>x>>v;
        t.upd_cnt(a[x], -1);
        if(a[x]>a[x+1]) t.upd(a[x+1]+1, a[x], -1);
        if(a[x-1]>a[x]) t.upd(a[x]+1, a[x-1], -1);
        a[x]=v;
        t.upd_cnt(a[x], 1);
        if(a[x]>a[x+1]) t.upd(a[x+1]+1, a[x], 1);
        if(a[x-1]>a[x]) t.upd(a[x]+1, a[x-1], 1);
        cout<<t.get_top()<<endl;
    }
}