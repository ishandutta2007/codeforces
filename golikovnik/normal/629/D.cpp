#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define szof(x) int32_t((x).size())
#define str(x) to_string(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;

const int MOD = 1e9 + 7;
const int MOD998 = 998244353;
const int INF = 1e9;
const ll LLINF = 1e18;

mt19937_64 rng((uint) chrono::steady_clock::now().time_since_epoch().count());

template <class T>
T rnd(T l, T r) {
	return uniform_int_distribution<T>(l, r)(rng);
}

struct Node {
	ll mx;
};

const Node NEUTRAL = {0};

struct SegTree {
	int n;
	vector<Node> tree;

	SegTree(int _n) : n(_n) {
		tree.assign(n << 2, NEUTRAL);
	}

	Node combine(Node x, Node y) {
		return {max(x.mx, y.mx)};
	}

	Node query(int v, int l, int r, int ql, int qr) {
		if (l > qr || ql > r) {
			return NEUTRAL;
		}
		if (ql <= l && r <= qr) {
			return tree[v];
		}
		int m = (l + r) / 2;
		return combine(query(v << 1, l, m, ql, qr), query((v << 1) | 1, m + 1, r, ql, qr));
	}

	Node query(int ql, int qr) {
		return query(1, 0, n - 1, ql, qr);
	}

	void upd(int v, int l, int r, int at, Node x) {
		if (l == r) {
			tree[v] = combine(tree[v], x);
			return;
		}
		int m = (l + r) / 2;
		if (at <= m) {
			upd(v << 1, l, m, at, x);
		} else {
			upd((v << 1) | 1, m + 1, r, at, x);
		}
		tree[v] = combine(tree[v << 1], tree[(v << 1) | 1]);
	}

	void upd(int at, Node x) {
		upd(1, 0, n - 1, at, x);
	}
};

void run() {
	int n;
	cin >> n;
	vector<pair<ll, int>> a(n);
	for (int i = 0; i < n; i++) {
		int r, h;
		cin >> r >> h;
		a[i] = {1LL * r * r * h, i};
	}
	auto sorted_a = a;
	sort(all(sorted_a));
	int ptr = 0;
	for (int i = 0; i < n; ) {
		int j = i;
		do {
			a[sorted_a[j].second].second = ptr;
			j++;
		} while (j < n && sorted_a[j].first == sorted_a[j - 1].first);
		ptr++;
		i = j;
	}
	SegTree tree(n);
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		auto [val, pos] = a[i];
		ll res = tree.query(0, pos - 1).mx + val;
		ans = max(ans, res);
		tree.upd(pos, {res});
	}
	cout << ans * acosl(-1.0) << "\n";
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout.precision(15); cout << fixed;
	int tests = 1;
	// cin >> tests;
	while (tests--) {
		run();
	}
	cerr << "Time elapsed: " << (double) clock() / CLOCKS_PER_SEC << "s.\n";
	return 0;
}