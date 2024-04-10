#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

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
template<typename T, typename cmp = less<T>>
using ordered_set=tree<T, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

constexpr int MOD=1e9+7;
constexpr int INV2=500000004;
int add(int a, int b) {return (a+=b)>=MOD?a-MOD:a;}
int mul(int a, int b) {return (a*1LL*b)%MOD;}

template<typename T>
void ckmax(T& x, const T& y) {x=x<y?y:x;}

struct Line {
	mutable ll k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
	int eval(ll l, ll r) { return add(mul(m, r-l+1), mul(mul(k, INV2), mul(r-l+1, add(r, l)))); }
};

struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	static const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) return x->p = inf, 0;
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	Line query(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l;
	}
};

constexpr int N=2005;
int dp[N][N];
vector<pii> adj[N];

int32_t main() {
    fastio;
    int n, m, q; cin>>n>>m>>q;
    rep(i, m) {
        int u, v, w; cin>>u>>v>>w; --u, --v;
        adj[u].eb(v, w);
        adj[v].eb(u, w);
    }
    memset(dp, -1, sizeof(dp));
    dp[0][0]=0;
    rep(i, m) {
        rep(u, n) if(~dp[u][i]) {
            for(auto& [v, w]: adj[u]) ckmax(dp[v][i+1], dp[u][i]+w);
        }
    }
    ll ans=0;
    rep1(i, m) {
        int x=0;
        rep(j, n) ckmax(x, dp[j][i]);
        ans+=x;
    }
    LineContainer s;
    rep(i, n) {
        int mx=0;
        for(auto& [v, w]: adj[i]) ckmax(mx, w);
        s.add(mx, dp[i][m]);
    }
    int p=1;
    while(p<=q-m) {
        Line line=s.query(p);
        if(line.p>=q-m) ans+=line.eval(p, q-m), p=q-m+1;
        else ans+=line.eval(p, line.p), p=line.p+1;
    }
    cout<<ans%MOD<<endl;
}