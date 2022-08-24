#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

const int mod = 998244353;

long long pw(long long a, long long b) {
	long long res = 1;
	while (b) {
		if (b & 1ll) {
			res = res * a % mod;
		}
		b >>= 1;
		a = a * a % mod;
	}
	return res;
}

long long inv(long long x) {
	return pw(x % mod, mod - 2);
}

struct Node {
	long long sum, prod;
};

Node merge(const Node& a, const Node& b) {
	return {(a.sum + b.sum * a.prod) % mod, a.prod * b.prod % mod};
}

struct SegTree {
	int n;
	vector<Node> a;

	SegTree(const vector<long long>& p) {
		n = 1;
		while (n < (int)p.size()) {
			n *= 2;
		}
		a.resize(n + n, {0ll, 1ll});
		for (int i = 0; i < (int)p.size(); ++i) {
			a[n + i].sum = 1;
			a[n + i].prod = p[i];
		}
		for (int i = n - 1; i > 0; --i) {
			a[i] = merge(a[i + i], a[i + i + 1]);
		}
		// for (int i = 1; i < 2 * n; ++i) {
		// 	if (!(i & (i - 1))) {
		// 		cerr << "\n";
		// 	}
		// 	cerr << "(" << a[i].sum << ", " << a[i].prod << ") ";
		// }
		// cerr << "\n";
	}

	Node get(int v, int l1, int r1, int l, int r) {
		if (l >= r1 || l1 >= r) {
			return {0ll, 1ll};
		}
		if (l <= l1 && r >= r1) {
			return a[v];
		}
		int m = (l1 + r1) / 2;
		return merge(get(v + v, l1, m, l, r), get(v + v + 1, m, r1, l, r));
	}

	long long get(int l, int r) {
		auto nd = get(1, 0, n, l, r);
		return nd.sum * inv(nd.prod) % mod;
	}
};

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	long long hundredth = 1;
	while (hundredth % 100) {
		hundredth += mod;
	}
	hundredth /= 100;

	int n = nxt(), q = nxt();
	vector<long long> p(n);
	for (int i = 0; i < n; ++i) {
		p[i] = nxt() * hundredth % mod;
	}

	SegTree tree(p);
	set<int> S;
	S.insert(0);
	S.insert(n);
	long long ans = tree.get(0, n);
	while (q--) {
		int u = nxt() - 1;
		auto it = S.lower_bound(u);
		if (it != S.end() && *it == u) {
			ans = ans - tree.get(*prev(it), u) - tree.get(u, *next(it)) + tree.get(*prev(it), *next(it));
			S.erase(it);
		} else {
			ans = ans + tree.get(*prev(it), u) + tree.get(u, *it) - tree.get(*prev(it), *it);
			S.insert(u);
		}
		ans %= mod;
		if (ans < 0) {
			ans += mod;
		}
		printf("%lld\n", ans);
	}

	return 0;
}