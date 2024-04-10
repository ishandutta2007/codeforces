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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// copy-paste begin

template <typename T>
struct TypeModular {
	using Type = typename decay<decltype(T::value)>::type;
	Type val;

	static constexpr Type mod() {
		return T::value;
	}

	TypeModular(long long _val = 0) {
		if (_val < 0 || _val >= mod()) {
			val = _val % mod();
			if (val < 0) {
				val += mod();
			}
		} else {
			val = _val;
		}
	}

	friend TypeModular operator -(const TypeModular& a) {
		return {-a.val};
	}

	friend TypeModular operator +(const TypeModular& a, const TypeModular& b) {
		Type res = a.val + b.val;
		if (res >= mod()) {
			res -= mod();
		}
		return {res};
	}

	friend TypeModular operator -(const TypeModular& a, const TypeModular& b) {
		Type res = a.val - b.val;
		if (res < 0) {
			res += mod();
		}
		return {res};
	}

	friend TypeModular operator *(const TypeModular& a, const TypeModular& b) {
		return {1ll * a.val * b.val};
	}

	friend TypeModular operator /(const TypeModular& a, const TypeModular& b) {
		return a * b.inv();
	}

	TypeModular& operator +=(const TypeModular& b) {
		val += b.val;
		if (val >= mod()) {
			val -= mod();
		}
		return *this;
	}

	TypeModular& operator -=(const TypeModular& b) {
		val -= b.val;
		if (val < 0) {
			val += mod();
		}
		return *this;
	}

	TypeModular& operator *=(const TypeModular& b) {
		val = 1ll * val * b.val % mod();
		return *this;
	}

	TypeModular& operator /=(const TypeModular& b) {
		*this *= b.inv();
		return *this;
	}

	TypeModular& operator ++() {
		val += 1;
		if (val == mod()) {
			val = 0;
		}
		return *this;
	}

	TypeModular operator ++(int) {
		TypeModular tmp(*this);
		operator ++();
		return tmp;
	}

	friend bool operator ==(const TypeModular& a, const TypeModular& b) {
		return a.val == b.val;
	}

	friend bool operator !=(const TypeModular& a, const TypeModular& b) {
		return a.val != b.val;
	}

	TypeModular pow(long long b) const {
		TypeModular res{1}, a{*this};
		while (b) {
			if (b & 1ll) {
				res *= a;
			}
			b >>= 1;
			a *= a;
		}
		return res;
	}

	TypeModular inv() const {
		assert(val);
		return _inv(val, mod());
	}

	int _inv(int a, int b) const {
		return a == 1 ? a : b - 1ll * _inv(b % a, a) * b / a % b;
	}

	explicit operator bool() const {
		return val;
	}
};

template <typename T = int>
struct integral_variable {
	T value;
};

template <typename T>
ostream& operator <<(ostream& ostr, const TypeModular<T>& x) {
	return ostr << x.val;
}

template <int mod>
using Modular = TypeModular<integral_constant<int, mod>>;
template <int mod, int N = (1 << __builtin_ctz(mod - 1))>
struct NTT {
	static constexpr int L = 31 - __builtin_clz(N);
	using Mint = Modular<mod>;
	vector<Mint> angles;
	vector<int> bitrev;

	NTT() {
		static_assert(!(N & (N - 1)));
		vector<int> primes;
		for (int x = mod - 1, p = 2; x > 1; ++p) {
			if (p * p > x) {
				primes.push_back(x);
				break;
			}
			if (x % p == 0) {
				primes.push_back(p);
				while (x % p == 0) {
					x /= p;
				}
			}
		}
		auto isPrimitiveRoot = [&](Mint g) {
			for (int p : primes) {
				if (g.pow(mod / p) == 1) {
					return false;
				}
			}
			return true;
		};
		int g = 2;
		while (!isPrimitiveRoot(g)) {
			++g;
		}
		g = Mint(g).pow(mod / N).val;

		angles.assign(N, 1);
		for (int i = 1; i < N; ++i) {
			angles[i] = angles[i - 1] * g;
		}
		assert(angles.back() * g == 1);

		bitrev.assign(N, 0);
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < L; ++j) {
				bitrev[i] = (bitrev[i] << 1) | !!(i & (1 << j));
			}
		}
	}

	int revbit(int num, int len) const {
		return bitrev[num] >> (L - len);
	}

	void fft(vector<Mint>& a) const {
		const int n = a.size();
		assert(!(n & (n - 1)));
		const int l = __builtin_ctz(n);

		for (int i = 0; i < n; ++i) {
			int j = revbit(i, l);
			if (j > i) {
				swap(a[i], a[j]);
			}
		}

		for (int len = 1; len < n; len *= 2) {
			for (int start = 0; start < n; start += 2 * len) {
				for (int i = 0; i < len; ++i) {
					const auto w = angles[N / 2 / len * i];
					const auto x = a[start + i], y = a[start + len + i] * w;
					a[start + i] = x + y;
					a[start + len + i] = x - y;
				}
			}
		}
	}

	void ntt(vector<Mint>& a) const {
		fft(a);
	}

	vector<Mint> multiply(vector<Mint> a, vector<Mint> b, bool shorten = false) {
		const size_t size = max((size_t)1, a.size() + b.size()) - 1;
		int n = 1;
		while (n < (int)a.size() || n < (int)b.size()) {
			n *= 2;
		}
		a.resize(n + n);
		b.resize(n + n);
		fft(a);
		fft(b);
		for (int i = 0; i < n + n; ++i) {
			a[i] *= b[i];
		}
		fft(a);
		Mint inv = Mint(n + n).inv();
		for (auto& x : a) {
			x *= inv;
		}
		reverse(1 + all(a));
		a.resize(size);
		if (shorten) {
			while ((int)a.size() > 1 && !a.back()) {
				a.pop_back();
			}
		}
		return a;
	}
};


constexpr int mod = 998'244'353;
using Mint = Modular<mod>;

// copy-paste end

const int N = 3333;
vector<int> tree[N];
int cur = 0;
char is_good[N];

struct Dsu {
	int n;
	vector<int> p, rk, node, sz, eds;

	Dsu(int _n): n(_n), p(_n), rk(_n), node(_n), sz(_n, 1), eds(_n, 0) {
		iota(all(p), 0);
		iota(all(node), 0);
	}

	int get(int v) {
		return v == p[v] ? v : p[v] = get(p[v]);
	}

	bool merge(int u, int v) {
		u = get(u), v = get(v);
		if (u == v) {
			eds[u] += 1;
			return false;
		}
		if (rk[u] < rk[v]) {
			swap(u, v);
		}
		p[v] = u;
		sz[u] += sz[v];
		eds[u] += eds[v] + 1;
		tree[cur].push_back(node[u]);
		tree[cur].push_back(node[v]);
		node[u] = cur++;
		if (rk[u] == rk[v]) {
			++rk[u];
		}
	}

	bool check_clique(int v) {
		v = get(v);
		return sz[v] * (sz[v] - 1) / 2 == eds[v];
	}
};

vector<Mint> dp[N];
pair<int, int> order[N * N / 2];

int main() {
	int n = nxt();
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int x = nxt();
			if (i >= j) {
				continue;
			}
			order[x] = {i, j};
		}
	}

	for (int i = 0; i < n; ++i) {
		is_good[i] = true;
	}
	cur = n;
	Dsu dsu(n);
	for (int i = 1; i <= n * (n - 1) / 2; ++i) {
		auto [x, y] = order[i];
		dsu.merge(x, y);
		if (dsu.check_clique(x)) {
			is_good[dsu.node[dsu.get(x)]] = true;
		}
	}

	NTT<mod, 4096> ntt;
	for (int i = 0; i < cur; ++i) {
		dp[i] = {1};
		for (int x : tree[i]) {
			// cerr << i << " -> " << x << "\n";
			dp[i] = ntt.multiply(dp[i], dp[x]);
		}
		if (is_good[i]) {
			if ((int)dp[i].size() < 2) {
				dp[i].resize(2);
			}
			dp[i][1] += 1;
		}
		dp[i][0] = 0;
		// for (auto x : dp[i]) {
		// 	cerr << x << " ";
		// }
		// cerr << "\n";
	}

	for (int i = 1; i <= n; ++i) {
		cout << dp[cur - 1][i] << " ";
	}
	cout << "\n";

	return 0;
}