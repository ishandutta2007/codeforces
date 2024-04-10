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
    ll m, b;
    mutable function<const Line*()> succ;
    bool operator<(const Line& rhs) const {
        if (rhs.b != is_query) return m < rhs.m;
        const Line* s = succ();
        if (!s) return 0;
        ll x = rhs.m;
        return b - s->b < 1.0L * (s->m - m) * x;
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
    void insert_line(ll m, ll b) {
        auto y = insert({ m, b });
        if (bad(y)) { erase(y); return; }
        while (next(y) != end() && bad(next(y))) erase(next(y));
        y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
        while (y != begin() && bad(prev(y))) erase(prev(y));
        if(y != begin()) prev(y)->succ = [=] { return &*y; };
    }
    ll eval(ll x) {
        if (empty()) return 0;
        auto l = *lower_bound((Line) { x, is_query });
        return l.m * x + l.b;
    }
};

constexpr int N=100001;
ll a[N], b[N];
ll dp[N];
HullDynamic conv[N];
vi adj[N];
int n;

HullDynamic* dfs(int x, int p=-1) {
	HullDynamic *res=new HullDynamic();
	for (int u: adj[x]) if (u!=p) {
		auto* tmp=dfs(u, x);
		if (tmp->size()>res->size()) swap(tmp, res);
		for (const Line& y: *tmp) res->insert_line(y.m, y.b);
	}
	dp[x]=-res->eval(a[x]);
	res->insert_line(-b[x], -dp[x]);
	return res;
}
//this leaves the question:
//why do we need the fucking long doubles?
//i don't fucking know
//fuck

int32_t main() {
    fastio;
    cin>>n; rep(i, n) cin>>a[i]; rep(i, n) cin>>b[i];
    rep(i, n-1) {
        int u, v; cin>>u>>v;
        adj[--u].pb(--v); adj[v].pb(u);
    }
    dfs(0);
    rep(i, n) cout<<dp[i]<<' '; cout<<endl;
}