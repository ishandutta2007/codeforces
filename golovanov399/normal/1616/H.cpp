#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

template <uint32_t base>
struct Montgomery {
	using i32 = int32_t;
	using u32 = uint32_t;
	using u64 = uint64_t;

	static constexpr u32 mod() {
		return base;
	}

	static constexpr u32 np = []() {
		u32 x = base;
		for (int i = 0; i < 4; ++i) {
			x *= 2u - base * x;
		}
		return -x;
	}();
	static constexpr u32 r2 = -(u64)(base) % base;

	static_assert(base < (1u << 30));
	static_assert(base * np + 1 == 0);

	static u32 reduce(u64 x) {
		return (x + (u64)((u32)x * np) * base) >> 32;
	}

	u32 x;
	Montgomery(): x(0) {}
	constexpr Montgomery(long long y): x(y ? reduce((u64)(y % base + base) * r2) : 0) {}

	Montgomery& operator +=(const Montgomery& ot) {
		if ((i32)(x += ot.x - 2 * base) < 0) {
			x += 2 * base;
		}
		return *this;
	}

	Montgomery& operator -=(const Montgomery& ot) {
		if ((i32)(x -= ot.x) < 0) {
			x += 2 * base;
		}
		return *this;
	}

	Montgomery& operator *=(const Montgomery& ot) {
		x = reduce((u64)x * ot.x);
		return *this;
	}

	Montgomery& operator /=(const Montgomery& ot) {
		return *this *= ot.inverse();
	}

	friend Montgomery operator +(Montgomery a, const Montgomery& b) {
		a += b;
		return a;
	}

	friend Montgomery operator -(Montgomery a, const Montgomery& b) {
		a -= b;
		return a;
	}

	friend Montgomery operator *(Montgomery a, const Montgomery& b) {
		a *= b;
		return a;
	}

	friend Montgomery operator /(Montgomery a, const Montgomery& b) {
		a /= b;
		return a;
	}

	Montgomery operator -() const {
		return Montgomery() - *this;
	}

	u32 get() const {
		u32 res = reduce(x);
		return res < base ? res : res - base;
	}

	u32 operator ()() const {
		return get();
	}

	Montgomery inverse() const {
		return pow(base - 2);
	}

	Montgomery pow(int64_t p) const {
		if (p < 0) {
			return pow(-p).inverse();
		}
		Montgomery res = 1;
		Montgomery a = *this;
		while (p) {
			if (p & 1) {
				res *= a;
			}
			p >>= 1;
			a *= a;
		}
		return res;
	}

	friend istream& operator >>(istream& istr, Montgomery& m) {
		long long x;
		istr >> x;
		m = Montgomery(x);
		return istr;
	}

	friend ostream& operator <<(ostream& ostr, const Montgomery& m) {
		return ostr << m.get();
	}

	bool operator ==(const Montgomery& ot) const {
		return (x >= base ? x - base : x) == (ot.x >= base ? ot.x - base : ot.x);
	}

	bool operator !=(const Montgomery& ot) const {
		return (x >= base ? x - base : x) != (ot.x >= base ? ot.x - base : ot.x);
	}

	explicit operator int64_t() const {
		return x;
	}

	explicit operator bool() const {
		return x;
	}
};

constexpr int mod = 998'244'353;
using Mint = Montgomery<mod>;

const int L = 30;

struct Trie {
	struct Node {
		array<int, 2> to;
		int cnt;

		Node(): to({-1, -1}), cnt(0) {}
	};

	vector<Node> nodes;

	int new_node() {
		nodes.push_back({});
		return (int)nodes.size() - 1;
	}

	Trie(): nodes(1) {}

	void add(int x) {
		int v = 0;
		for (int i = L - 1; i >= 0; --i) {
			nodes[v].cnt += 1;
			int u = nodes[v].to[!!(x & (1 << i))];
			if (!~u) {
				u = nodes[v].to[!!(x & (1 << i))] = new_node();
			}
			v = u;
		}
		nodes[v].cnt += 1;
	}

	const Node& operator [](int idx) const {
		return nodes[idx];
	}

	int cnt(int idx) const {
		return idx > -1 ? nodes[idx].cnt : 0;
	}
};

const int N = 222'222;
Mint p2[N];

Mint subsolve(const Trie& t, int l, int r, int x, int bit) {
	if (l == -1 || r == -1 || !bit) {
		return p2[t.cnt(l)] * p2[t.cnt(r)];
	}
	Mint ans = 0;
	if (x & bit) {
		Mint one = subsolve(t, t[l].to[0], t[r].to[1], x, bit >> 1);
		Mint two = (l == r) ? 1 : subsolve(t, t[l].to[1], t[r].to[0], x, bit >> 1);
		ans = one * two;
	} else {
		ans = subsolve(t, t[l].to[0], t[r].to[0], x, bit >> 1) + subsolve(t, t[l].to[1], t[r].to[1], x, bit >> 1) - 1;
		ans += (p2[t.cnt(t[l].to[0])] - 1) * (p2[t.cnt(t[l].to[1])] - 1);
		ans += (p2[t.cnt(t[r].to[0])] - 1) * (p2[t.cnt(t[r].to[1])] - 1);
		// for (int i : {0, 1}) {
		// 	if (t[l].to[i] > -1 && t[r].to[i] > -1) {
		// 		ans += (p2[t[t[l].to[i]].cnt] - 1) * (p2[t[t[r].to[i]].cnt] - 1);
		// 	}
		// }
	}
	// cerr << l << " " << r << ": " << ans << "\n";
	return ans;
}

void solve() {
	p2[0] = 1;
	for (int i = 1; i < N; ++i) {
		p2[i] = p2[i - 1] * 2;
	}

	int n = nxt(), x = nxt();
	vector<int> a(n);
	generate(all(a), nxt);

	if (x == 0) {
		map<int, int> M;
		for (int y : a) {
			M[y] += 1;
		}
		Mint ans = 0;
		for (auto p : M) {
			ans += p2[p.second] - 1;
		}
		cout << ans << "\n";
		return;
	}

	Trie t;
	for (int y : a) {
		t.add(y);
	}
	// for (auto nd : t.nodes) {
	// 	cerr << nd.to[0] << " " << nd.to[1] << " " << nd.cnt << "\n";
	// }
	// cerr << "\n";

	cout << subsolve(t, 0, 0, x, 1 << (L - 1)) - 1 << "\n";
}

int main() {
	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}