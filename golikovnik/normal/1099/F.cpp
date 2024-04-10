#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define szof(x) int32_t((x).size())
#define str(x) to_string(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;

const ll MOD = 1e9 + 7;
const ll MOD998 = 998244353;
const int INF = 1e9;
const ll LLINF = 1e18;

mt19937_64 rng((uint) chrono::steady_clock::now().time_since_epoch().count());

template <class T>
T rnd(T l, T r) {
	return uniform_int_distribution<T>(l, r)(rng);
}

struct edge {
	int to, cost;

	edge() {}
	edge(int to, int cost) : to(to), cost(cost) {}
};

#define time asdas8d

vector<vector<edge>> graph;

vector<int> cookies;
vector<int> time;

const int MAXTIME = 1e6 + 20;
const int N = MAXTIME * 4;

struct SegTree {
	ll tree[N];

	void inc(int at, ll delta) {
		int l = 0, r = MAXTIME - 1, v = 1;
		while (true) {
			tree[v] += delta;
			if (l == r) {
				break;
			}
			int m = (l + r) / 2;
			v <<= 1;
			if (at <= m) {
				r = m;
			} else {
				l = m + 1;
				v++;
			}
		}
	}

	ll query(int v, int l, int r, int ql, int qr) {
		if (l > qr || ql > r) {
			return 0;
		}
		if (ql <= l && r <= qr) {
			return tree[v];
		}
		int m = (l + r) / 2;
		return query(2 * v, l, m, ql, qr) + query(2 * v + 1, m + 1, r, ql, qr);
 	}

 	ll pref(int r) {
 		return query(1, 0, MAXTIME - 1, 0, r);
 	}

 	int lower_bound(ll x) {
 		int l = 0, r = MAXTIME - 1, v = 1;
 		while (l < r) {
 			int m = (l + r) / 2;
 			ll cur = tree[2 * v];
 			if (cur < x) {
 				x -= cur;
 				l = m + 1;
 				v = 2 * v + 1;
 			} else {
 				r = m;
 				v *= 2;
 			}
 		}
 		if (tree[v] > x) {
 			l--;
 		}
 		return l;
 	}

} overall, ccs;

ll T;

int dfs(int u = 0, ll up = 0) {
	overall.inc(time[u], 1LL * time[u] * cookies[u]);
	ccs.inc(time[u], cookies[u]);
	ll left = T - up - up;
	int i = overall.lower_bound(left);
	ll took = overall.pref(i);
	int ans = ccs.pref(i);
	if (0 < i + 1 && i + 1 < MAXTIME) {
		ans += (left - took) / (i + 1);
	}
	int mx = 0, mx2 = 0;
	for (auto[v, cost] : graph[u]) {
		int res = dfs(v, up + cost);
		if (res >= mx) {
			mx2 = mx;
			mx = res;
		} else if (res > mx2) {
			mx2 = res;
		}
	}
	overall.inc(time[u], -1LL * time[u] * cookies[u]);
	ccs.inc(time[u], -cookies[u]);
	return max(ans, u == 0 ? mx : mx2);
}

void run() {
	int n;
	cin >> n >> T;
	cookies.resize(n);
	for (int &x : cookies) {
		cin >> x;
	}
	time.resize(n);
	for (int &x : time) {
		cin >> x;
	}
	graph.resize(n);
	for (int i = 1; i < n; i++) {
		int p, cost;
		cin >> p >> cost;
		graph[p - 1].emplace_back(i, cost);
	}
	cout << dfs() << "\n";
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout.precision(10); cout << fixed;
	int tests = 1;
	// cin >> tests;
	while (tests--) {
		run();
	}
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.\n";
	return 0;
}