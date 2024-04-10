//#pragma GCC optimize("O3")
//#pragma GCC target("sse4,avx2,abm,fma,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef complex<ld> pt;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-9;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

namespace kactl {
	struct Line {
		mutable ll m, b, p;
		bool operator<(const Line& o) const { return m < o.m; }
		bool operator<(ll x) const { return p < x; }
	};

	struct LineContainer : multiset<Line, less<>> {
		// (for doubles, use inf = 1/.0, div(a,b) = a/b)
		const ll inf = LLONG_MAX;
		ll div(ll a, ll b) { // floored division
			return a / b - ((a ^ b) < 0 && a % b); }
		bool isect(iterator x, iterator y) {
			if (y == end()) { x->p = inf; return false; }
			if (x->m == y->m) x->p = x->b > y->b ? inf : -inf;
			else x->p = div(y->b - x->b, x->m - y->m);
			return x->p >= y->p;
		}
		void add(ll m, ll b) {
			auto z = insert({m, b, 0}), y = z++, x = y;
			while (isect(y, z)) z = erase(z);
			if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
			while ((y = x) != begin() && (--x)->p >= y->p)
				isect(x, erase(y));
		}
		ll query(ll x) const {
			auto l = *lower_bound(x);
			return l.m * x + l.b;
		}
	};
}

namespace ubc {
	// WARNING: could overflow for values ~1e9, use __int128 instead
	// WARNING: tested only with integer and rational types
	const ll is_query = -(1LL<<62);
	struct Line {
		ll m, b;
		mutable function<const Line*()> succ;
		bool operator<(const Line& rhs) const {
			if (rhs.b != is_query) return m < rhs.m;
			const Line* s = succ();
			if (!s) return 0;
			ll x = rhs.m;
			return b - s->b < (s->m - m) * x;
		}
	};
	// will maintain upper hull for maximum
	struct HullDynamic : public multiset<Line> {
		bool bad(iterator y) {
			auto z = next(y);
			if (y == begin()) {
				if (z == end()) return 0;
				return y->m == z->m && y->b <= z->b;
			}
			auto x = prev(y);
			if (z == end()) return y->m == x->m && y->b <= x->b;
			// could overflow
			return (x->b - y->b)*(z->m - y->m) >= (y->b - z->b)*(y->m - x->m);
		}
		void add(ll m, ll b) { // m = -m; b = -b; // for lower hull
			auto y = insert({ m, b });
			y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
			if (bad(y)) { erase(y); return; }
			while (next(y) != end() && bad(next(y))) erase(next(y));
			while (y != begin() && bad(prev(y))) erase(prev(y));
		}
		ll query(ll x) const {
			auto l = *lower_bound((Line) { x, is_query });
			return l.m * x + l.b; // return -(l.m * x + l.b); // for lower hull
		}
	};
}

const int N = 2e5 + 1;
ll val[N];

vector<int> adj[N];
bool vis[N];
int sz[N];

typedef ubc::HullDynamic Magic;

ll get_ups(int u, int p, int d, ll s, ll r, const Magic& dat, vector<pair<ll,ll>>& out) {
	s += val[u];
	r += val[u] * d;
	out.push_back(make_pair(s, r));
	ll res = dat.query(s) + r;
	for(int v : adj[u]) {
		if(v == p || vis[v]) continue;
		res = max(res, get_ups(v, u, d+1, s, r, dat, out));
	}
	return res;
}

ll get_downs(int u, int p, int d, ll s, ll r, const Magic& dat, Magic& upd) {
	s += val[u];
	r += s;
	ll res = dat.query(d) + r;
	upd.add(d, r);
	for(int v : adj[u]) {
		if(v == p || vis[v]) continue;
		res = max(res, get_downs(v, u, d+1, s, r, dat, upd));
	}
	return res;
}

ll calc(int s) {
	Magic up, down;
	up.add(val[s], val[s]);
	down.add(0, 0);

	ll res = val[s];
	for(int v : adj[s]) {
		if(vis[v]) continue;
		vector<pair<ll,ll>> ups;
		res = max(res, get_ups(v, s, 2, val[s], val[s], down, ups));
		res = max(res, get_downs(v, s, 1, 0, 0, up, down));
		for(auto [a, b] : ups) {
			up.add(a, b);
		}
	}

	return res;
}

int dfs(int u, int p, vector<int>& seen) {
	seen.push_back(u);
	sz[u] = 1;
	for(int v : adj[u]) {
		if(v == p || vis[v]) continue;
		sz[u] += dfs(v, u, seen);
	}
	return sz[u];
}

pair<int,ll> centroid(int u) {
	vector<int> seen;
	int s = dfs(u, 0, seen);
	for(int v : seen) {
		if(2*sz[v] < s) continue;
		bool ok = true;
		for(int w : adj[v]) {
			if(vis[w]) continue;
			if(2*sz[w] > s && sz[w] < sz[v]) {
				ok = false;
				break;
			}
		}
		if(ok) {
			return make_pair(v, calc(v));
		}
	}
	assert(false);
}

ll decompose(int u) {
	auto [c, res] = centroid(u);
	vis[c] = true;
	for(int v : adj[c]) {
		if(vis[v]) continue;
		res = max(res, decompose(v));
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;
	for(int i=1; i<n; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for(int i=1; i<=n; i++) {
		cin >> val[i];
	}
	cout << decompose(1) << nl;

	return 0;
}