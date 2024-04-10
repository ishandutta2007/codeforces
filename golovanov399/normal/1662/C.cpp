#include <bits/stdc++.h>

#include <cstdint>
#include <istream>
#include <ostream>

using std::istream, std::ostream;

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

	Montgomery inv() const {
		return inverse();
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


#include <vector>

using std::vector;

template <typename T>
vector<T> find_linear_recurrence(const vector<T>& a) {
	vector<T> p;
	auto get = [&](int idx) -> T {
		T res = 0;
		for (int i = 0; i < (int)p.size(); ++i) {
			res += a[idx - 1 - i] * p[i];
		}
		return res;
	};
	vector<T> last_incorrect;
	int last_idx = -1;
	for (int i = 0; i < (int)a.size(); ++i) {
		auto cur = get(i);
		if (cur == a[i]) {
			continue;
		}
		auto new_p = p;
		bool need_to_upd = true;
		if (new_p.empty()) {
			new_p.assign(i + 1, 0);
		} else {
			const int sz = (i - last_idx - 1) + (int)last_incorrect.size();
			if (sz > (int)new_p.size()) {
				new_p.resize(sz);
			} else {
				need_to_upd = false;
			}
			for (int j = 0; j < (int)last_incorrect.size(); ++j) {
				new_p[i - last_idx - 1 + j] += last_incorrect[j] * (a[i] - cur);
			}
		}
		if (need_to_upd) {
			last_incorrect = p;
			last_incorrect.insert(last_incorrect.begin(), -1);
			auto inv = 1 / (cur - a[i]);
			for (auto& x : last_incorrect) {
				x *= inv;
			}
			last_idx = i;
		}
		p.swap(new_p);
	}
	return p;
}

template <typename T>
T get_nth_term_of_recurrence(const vector<T>& rec, const vector<T>& initial, long long n) {
	if (n < (int)initial.size()) {
		return initial[n];
	}
	const int sz = (int)rec.size();
	auto mult = [&](const vector<T>& a, const vector<T>& b) {
		vector<T> res(sz * 2);
		for (int i = 0; i < sz; ++i) {
			for (int j = 0; j < sz; ++j) {
				res[i + j] += a[i] * b[j];
			}
		}
		for (int i = 2 * sz - 1; i >= sz; --i) {
			if (!res[i]) {
				continue;
			}
			for (int j = 0; j < sz; ++j) {
				res[i - 1 - j] += res[i] * rec[j];
			}
		}
		res.resize(sz);
		return res;
	};

	if (sz == 1) {
		T answer = initial[0];
		T cur = rec[0];
		while (n) {
			if (n & 1ll) {
				answer *= cur;
			}
			n >>= 1;
			cur *= cur;
		}
		return answer;
	}

	vector<T> res(sz);
	res[0] = 1;
	vector<T> a(sz);
	a[1] = 1;
	while (n) {
		if (n & 1ll) {
			res = mult(res, a);
		}
		n >>= 1;
		a = mult(a, a);
	}
	T answer = 0;
	for (int i = 0; i < sz; ++i) {
		answer += res[i] * initial[i];
	}
	return answer;
}

template <typename T>
T guess_nth_term(const vector<T>& a, long long n) {
	auto rec = find_linear_recurrence(a);
	return get_nth_term_of_recurrence(rec, a, n);
}

#define all(x) (x).begin(), (x).end()
// #define make_unique(x) sort(all(x)); x.resize(unique(all(x)) - x.begin())

using namespace std;

inline int nxt() {
	int x;
	// scanf("%d", &x);
	cin >> x;
	return x;
}

constexpr int mod = 998'244'353;
using Mint = Montgomery<mod>;

// Matrix<Mint> pw(Matrix<Mint> m0, Matrix<Mint> m1, Matrix<Mint> a, Matrix<Mint> b, int k) {
// 	const int n = m0.n;
// 	pair cur = {Matrix<Mint>(n), Matrix<Mint>::id(n)};
// 	pair res = {Matrix<Mint>::id(n), Matrix<Mint>(n)};
// 	auto mult = [&](const Matrix<Mint>& x, const Matrix<Mint>& y) {
// 		return {};
// 	};
// 	while (k) {
// 		if (k & 1) {
// 			res = mult(res, cur);
// 		}
// 		k >>= 1;
// 		cur = mult(cur, cur);
// 	}
// 	return res[0] * m0 + res[1] * m1;
// }

void solve() {
	int n = nxt(), m = nxt();
	int k = nxt();

	vector<pair<int, int>> edges;
	vector<int> deg(n);
	for (int i = 0; i < m; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		edges.push_back({u, v});
		deg[u] += 1;
		deg[v] += 1;
	}

	auto sumd = [](const vector<vector<Mint>>& a) {
		Mint ans = 0;
		for (int i = 0; i < (int)a.size(); ++i) {
			ans += a[i][i];
		}
		return ans;
	};

	if (k == 1) {
		cout << "0\n";
		return;
	}

	vector<vector<Mint>> f0(n, vector<Mint>(n));
	auto f1 = f0;
	for (int i = 0; i < n; ++i) {
		f0[i][i] = 1;
	}
	for (auto [u, v] : edges) {
		f1[u][v] = 1;
		f1[v][u] = 1;
	}
	vector<Mint> ss = {sumd(f0), sumd(f1)};
	for (int it = 2; it < 4 * n + 10; ++it) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				f0[i][j] *= (1 - deg[j]);
			}
		}
		for (auto [u, v] : edges) {
			for (int i = 0; i < n; ++i) {
				f0[i][v] += f1[i][u];
				f0[i][u] += f1[i][v];
			}
		}
		ss.push_back(sumd(f0));
		f0.swap(f1);
	}

	cout << guess_nth_term(ss, k) - guess_nth_term(ss, k - 2) << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}