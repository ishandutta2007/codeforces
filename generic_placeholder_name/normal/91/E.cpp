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

//code for dynamic convex hull
//makes zero fucking sense to me
constexpr ll is_query = -(1LL<<62);
struct Line {
    ll m, b; int id;
    mutable function<const Line*()> succ;
    bool operator<(const Line& rhs) const {
        if (rhs.b != is_query) return m < rhs.m;
        const Line* s = succ();
        if (!s) return 0;
        ll x = rhs.m;
        return 1.0L * b - s->b < 1.0L * (s->m - m) * x;
    }
};

struct HullDynamic : public multiset<Line> { // will maintain upper hull for maximum
    bool bad(const iterator& y) {
        auto z = next(y);
        if (y == begin()) {
            if (z == end()) return 0;
            return y->m == z->m && y->b <= z->b;
        }
        auto x = prev(y);
        if (z == end()) return y->m == x->m && y->b <= x->b;
        return 1.0L * (x->b - y->b)*(z->m - y->m) >= 1.0L * (y->b - z->b)*(y->m - x->m);
    }
    void insert_line(ll m, ll b, int id) {
        auto y = insert({ m, b, id});
        if (bad(y)) { erase(y); return; }
        while (next(y) != end() && bad(next(y))) erase(next(y));
        y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
        while (y != begin() && bad(prev(y))) erase(prev(y));
        if(y != begin()) prev(y)->succ = [=] { return &*y; };
    }
    pair<ll, int> eval(ll x) {
        assert (!empty());
        auto l = *lower_bound((Line) { x, is_query });
        return {l.m * x + l.b, l.id};
    }
    void merge(const HullDynamic& y) {
        for(auto& it: y) insert_line(it.m, it.b, it.id);
    }
};

constexpr int N=1e5+1;
int n, q;

ll a[N], b[N];
HullDynamic t[4*N+4];

void build(int v=1, int l=0, int r=n-1) {
    if(l==r) {
        t[v].insert_line(a[l], b[l], l+1);
    }
    else {
        int m=(l+r)/2;
        build(v*2, l, m);
        build(v*2+1, m+1, r);
        t[v]=t[v*2]; t[v].merge(t[v*2+1]);
    }
}

pair<ll, int> get(int ql, int qr, ll val, int v=1, int l=0, int r=n-1) {
    if(ql>r||qr<l) return {is_query, -1};
    if(ql<=l&&qr>=r) return t[v].eval(val);
    else {
        int m=(l+r)/2;
        return max(get(ql, qr, val, v*2, l, m), get(ql, qr, val, v*2+1, m+1, r));
    }
}

int32_t main() {
    fastio;
    cin>>n>>q; rep(i, n) cin>>b[i]>>a[i];
    build();
    rep(i, q) {
        int l, r; ll t; cin>>l>>r>>t;
        cout<<get(l-1, r-1, t).se<<endl;
    }
}