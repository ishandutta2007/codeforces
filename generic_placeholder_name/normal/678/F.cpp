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

struct Line {
	mutable ll k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
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
	ll query(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};

constexpr ll INF = 2e18;
constexpr pii NO = {INT_MIN, INT_MIN};

struct SegTree {
    int n;
    vector<LineContainer> ct;

    SegTree(int _n): n(_n), ct(_n << 2) {}

    void insert_line(int a, int b, int ql, int qr, int v, int l, int r) {
        if(ql > r || qr < l) return;
        if(ql <= l && qr >= r) ct[v].add(a, b);
        else {
            int m = (l + r) / 2;
            insert_line(a, b, ql, qr, v * 2, l, m);
            insert_line(a, b, ql, qr, v * 2 + 1, m + 1, r);
        }
    }

    ll answer_query(int q, int p, int v, int l, int r) {
        ll ans = ct[v].empty() ? -INF : ct[v].query(q);
        if(l != r) {
            int m = (l + r) / 2;
            if(p <= m) ans = max(ans, answer_query(q, p, v * 2, l, m));
            else ans = max(ans, answer_query(q, p, v * 2 + 1, m + 1, r));
        }
        return ans;
    }

    void insert_line(int a, int b, int ql, int qr) {insert_line(a, b, ql, qr, 1, 0, n - 1);}
    ll answer_query(int q, int p) {return answer_query(q, p, 1, 0, n - 1);}
};

int32_t main() {
    fastio;
    int n; cin >> n;
    SegTree t(n);
    vector<pii> st(n, NO);
    vector<pii> queries;
    rep(i, n) {
        int T; cin >> T;
        if(T == 1) {
            int a, b; cin >> a >> b;
            st[i] = {a, b};
        }
        else if(T == 2) {
            int p; cin >> p; --p;
            t.insert_line(st[p].fi, st[p].se, p, i);
            st[p] = NO;
        }
        else {
            int q; cin >> q;
            queries.eb(q, i);
        }
    }
    rep(i, n) if(st[i] != NO) t.insert_line(st[i].fi, st[i].se, i, n - 1);
    for(auto& [q, i]: queries) {
        auto x = t.answer_query(q, i);
        if(x == -INF) cout << "EMPTY SET\n";
        else cout << x << endl;
    }
}