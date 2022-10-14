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

constexpr ll INF=1e18;
struct Node {
    ll max_odd, max_even, min_odd, min_even;

    Node() {}
    Node(ll n): max_odd(n), min_odd(n), max_even(-INF), min_even(INF) {}

    friend Node operator + (const Node& a, const Node& b) {
        Node c;
        c.max_odd=max(max(a.max_odd, b.max_odd), max(a.max_odd-b.min_even, a.max_even+b.max_odd));
        c.max_even=max(max(a.max_even, b.max_even), max(a.max_odd-b.min_odd, a.max_even+b.max_even));
        c.min_odd=min(min(a.min_odd, b.min_odd), min(a.min_odd-b.max_even, a.min_even+b.min_odd));
        c.min_even=min(min(a.min_even, b.min_even), min(a.min_odd-b.max_odd, a.min_even+b.min_even));
        return c;
    }

    const ll get_max() const {
        return max(max_odd, max_even);
    }
};

struct SegTree {
    vector<Node> t;
    int n;

    void bld(vi& a, int v, int l, int r) {
        if(l==r) t[v]=Node(a[l]);
        else {
            int m=(l+r)/2;
            bld(a, v*2, l, m);
            bld(a, v*2+1, m+1, r);
            t[v]=t[v*2]+t[v*2+1];
        }
    }

    SegTree(vi& a): n(a.size()), t(4*a.size()+4) {
        bld(a, 1, 0, n-1);
    }

    void upd(int pos, int val, int v, int l, int r) {
        if(l==r) t[v]=Node(val);
        else {
            int m=(l+r)/2;
            if(pos<=m) upd(pos, val, v*2, l, m);
            else upd(pos, val, v*2+1, m+1, r);
            t[v]=t[v*2]+t[v*2+1];
        }
    }
    inline void upd(int pos, int val) {upd(pos, val, 1, 0, n-1);}

    Node get(int ql, int qr, int v, int l, int r) {
        if(ql<=l&&qr>=r) return t[v];
        else {
            int m=(l+r)/2;
            if(ql>m) return get(ql, qr, v*2+1, m+1, r);
            else if(qr<=m) return get(ql, qr, v*2, l, m);
            else return get(ql, qr, v*2, l, m)+get(ql, qr, v*2+1, m+1, r);
        }
    }
    inline Node get(int l, int r) {return get(l, r, 1, 0, n-1);}
    inline ll query() {return get(0, n-1, 1, 0, n-1).get_max();}
};

int32_t main() {
    fastio;
    int t; cin>>t; while(t--) {
        int n, q; cin>>n>>q;
        vi a(n); rep(i, n) cin>>a[i];
        SegTree t(a);
        cout<<t.query()<<endl;
        rep(i, q) {
            int l, r; cin>>l>>r; --l, --r;
            swap(a[l], a[r]);
            t.upd(l, a[l]);
            t.upd(r, a[r]);
            cout<<t.query()<<endl;
        }
    }
}