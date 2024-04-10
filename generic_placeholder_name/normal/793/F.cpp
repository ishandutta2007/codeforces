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
template<typename T, typename comp = less<T>>
using ordered_set = tree<T, null_type, comp, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

constexpr int N=1e5;
int lf[N+1];
vector<pii> Q[N+1];
int ans[N];
int n;

struct Node {
    int f, s;

    Node(): f(0), s(-1) {}
    Node(int f): f(f), s(-1) {}
    Node(int f, int s): f(f), s(s) {}

    friend Node operator + (const Node& a, const Node& b) {
        Node c;
        if(a.f==b.f) c.f=a.f, c.s=max(a.s, b.s);
        else {
            if(a.f>b.f) c.f=a.f, c.s=max(a.s, b.f);
            else c.f=b.f, c.s=max(b.s, a.f);
        }
        return c;
    }
};

struct SegTree {
    Node t[4*N+4];
    void push(int v) {
        int lc=v*2, rc=v*2+1;
        if(t[lc].f>t[v].s) t[lc].f=t[v].f;
        if(t[rc].f>t[v].s) t[rc].f=t[v].f;
    }
    void bld(int a[], int v=1, int l=1, int r=n) {
        if(l==r) t[v]=Node(a[l]);
        else {
            int m=(l+r)/2;
            bld(a, v*2, l, m);
            bld(a, v*2+1, m+1, r);
            t[v]=t[v*2]+t[v*2+1];
        }
    }
    void upd(int ql, int qr, int req, int val, int v=1, int l=1, int r=n) {
        if(ql>r||qr<l||t[v].f<req) return;
        if(ql<=l&&qr>=r&&t[v].s<req) t[v].f=val;
        else {
            push(v);
            int m=(l+r)/2;
            upd(ql, qr, req, val, v*2, l, m);
            upd(ql, qr, req, val, v*2+1, m+1, r);
            t[v]=t[v*2]+t[v*2+1];
        }
    }
    int get(int pos, int v=1, int l=1, int r=n) {
        if(l==r) return t[v].f;
        else {
            push(v);
            int m=(l+r)/2;
            if(pos<=m) return get(pos, v*2, l, m);
            else return get(pos, v*2+1, m+1, r);
        }
    }
} t;

int32_t main() {
    fastio;
    int m; cin>>n>>m;
    rep1(i, n) lf[i]=i;
    t.bld(lf);
    rep1(i, m) {
        int x, y; cin>>x>>y;
        lf[y]=x;
    }
    int q; cin>>q;
    rep(i, q) {
        int l, r; cin>>l>>r;
        Q[r].eb(l, i);
    }
    rep1(i, n) {
        t.upd(1, lf[i], lf[i], i);
        for(auto& [v, id]: Q[i]) ans[id]=t.get(v);
    }
    rep(i, q) cout<<ans[i]<<endl;
}