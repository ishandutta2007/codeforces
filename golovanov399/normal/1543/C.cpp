

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())
#define imie(x) #x << ": " << x

using namespace std;



using li = long long;
using LI = __int128_t;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;

#define _repeat_cat(a, b) a##b
#define _repeat_helper(ctr, n) for (int _repeat_cat(_mx_, ctr) = n, _repeat_cat(_i_, ctr) = 0; _repeat_cat(_i_, ctr) < _repeat_cat(_mx_, ctr); ++_repeat_cat(_i_, ctr))
#define repeat(n) _repeat_helper(__COUNTER__, n)

LI gcd(LI x, LI y) {
	while (y) {
		x %= y;
		swap(x, y);
	}
	return x;
}

LI lcm(LI x, LI y) {
	return x / gcd(x, y) * y;
}

LI abs(LI x) {
	return max(x, -x);
}

template <typename T>
T pw(T a, li b) {
	T res = 1;
	while (b) {
		if (b & 1ll) {
			res *= a;
		}
		b >>= 1;
		a *= a;
	}
	return res;
}

li pw(li a, li b, int mod) {
	li res = 1;
	while (b) {
		if (b & 1ll) {
			res = res * a % mod;
		}
		b >>= 1;
		a = a * a % mod;
	}
	return res;
}

li mult_big(li x, li y, li mod) {
	li res = x * y - (li)((ld)x * (ld)y / (ld)mod) * mod;
	while (res < 0) {
		res += mod;
	}
	while (res >= mod) {
		res -= mod;
	}
	return res;
}

li pw_big(li a, li b, li mod) {
	li res = 1;
	while (b) {
		if (b & 1ll) {
			res = mult_big(res, a, mod);
		}
		b >>= 1;
		a = mult_big(a, a, mod);
	}
	return res;
}

template <typename T>
conditional_t<is_same_v<T, int>, long long, T> sqr(T x) {
	if constexpr (is_same_v<T, int>) {
		return 1ll * x * x;
	}
	return x * x;
}

template <typename T>
bool remin(T& x, T y) {
	if (x > y) {
		x = y;
		return true;
	} else {
		return false;
	}
}

template <typename T>
bool remax(T& x, T y) {
	if (x < y) {
		x = y;
		return true;
	} else {
		return false;
	}
}

ld eps = 1e-8;
void set_eps(ld new_eps) {
	eps = new_eps;
}

template <typename T>
enable_if_t<is_integral_v<T>, int> sign(T x) {
	return x < 0 ? -1 : x > 0;
}

template <typename T>
enable_if_t<is_floating_point_v<T>, int> sign(T x) {
	return x < -eps ? -1 : x > eps;
}

int isqrt(long long n) {
	int x = sqrtl(n);
	while (sqr(x + 1) <= n) {
		++x;
	}
	return x;
}

int icbrt(long long n) {
	int x = pow(n, 1./3);
	while (sqr(x + 1) * (x + 1) <= n) {
		++x;
	}
	return x;
}

int mex(vector<int> a) {
	make_unique(a);
	int res = 0;
	while (res < (int)a.size() && a[res] == res) {
		++res;
	}
	return res;
}

template <typename T, typename Iter>
int find_position(Iter b, Iter e, const T& x) {
	auto it = lower_bound(b, e, x);
	if (it != e && *it == x) {
		return it - b;
	} else {
		return -1;
	}
}
template <typename T>
struct RectMatrix {
	int n, m;
	vector<vector<T>> a;

	RectMatrix(int _n, int _m): n(_n), m(_m), a(_n, vector<T>(_m)) {}

	struct GaussResult {
		bool success;
		vector<vector<T>> lhs;
		vector<T> rhs;
		vector<int> main_coords;
	};

	static constexpr GaussResult gauss(vector<vector<T>> a, vector<T> b) {
		int n = a.size();
		int m = a[0].size();
		vector<int> main_coords;
		int i = 0;
		for (int col = 0; i < n && col < m; ++col) {
			if constexpr (is_floating_point_v<T>) {
				int mx = i;
				for (int j = i + 1; j < n; ++j) {
					if (abs(a[j][col]) > abs(a[mx][col])) {
						mx = j;
					}
				}
				if (sign(a[mx][col]) == 0) {
					continue;
				}
				if (mx > i) {
					a[mx].swap(a[i]);
					swap(b[mx], b[i]);
				}
			} else {
				if (a[i][col] == 0) {
					int j = i + 1;
					while (j < n && a[j][col] == 0) {
						++j;
					}
					if (j == n) {
						continue;
					}
					a[j].swap(a[i]);
					swap(b[j], b[i]);
				}
			}

			{
				T k = a[i][col];
				for (int j = col; j < m; ++j) {
					a[i][j] /= k;
				}
				b[i] /= k;
			}
			for (int j = i + 1; j < n; ++j) {
				T k = a[j][col];
				if (k != 0) {
					for (int l = col; l < m; ++l) {
						a[j][l] -= a[i][l] * k;
					}
					b[j] -= b[i] * k;
				}
			}
			main_coords.push_back(col);
			++i;
		}

		for (int row = i; row < n; ++row) {
			if constexpr (is_floating_point_v<T>) {
				if (sign(b[row])) {
					return {false, a, b, main_coords};
				}
			} else {
				if (b[row] != 0) {
					return {false, a, b, main_coords};
				}
			}
		}
		n = i;
		a.resize(n);
		b.resize(n);

		for (int i = n - 1; i >= 0; --i) {
			for (int j = i - 1; j >= 0; --j) {
				const int col = main_coords[i];
				T k = a[j][col];
				if (k != 0) {
					for (int l = 0; l < m; ++l) {
						a[j][l] -= a[i][l] * k;
					}
					b[j] -= b[i] * k;
				}
			}
		}

		return {true, a, b, main_coords};
	}

	const vector<T>& operator [](int idx) const {
		return a[idx];
	}

	vector<T>& operator [](int idx) {
		return a[idx];
	}

	void operator +=(const RectMatrix<T>& ot) {
		assert(n == ot.n);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				a[i][j] += ot[i][j];
			}
		}
	}

	void operator -=(const RectMatrix<T>& ot) {
		assert(n == ot.n);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				a[i][j] -= ot[i][j];
			}
		}
	}

	void operator *=(const T& k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				a[i][j] *= k;
			}
		}
	}

	void operator /=(const T& k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				a[i][j] /= k;
			}
		}
	}

	RectMatrix<T> operator +(const RectMatrix<T>& ot) const {
		auto res = *this;
		res += ot;
		return res;
	}

	RectMatrix<T> operator -(const RectMatrix<T>& ot) const {
		auto res = *this;
		res -= ot;
		return res;
	}

	RectMatrix<T> operator *(const T& k) const {
		auto res = *this;
		res *= k;
		return res;
	}

	RectMatrix<T> operator /(const T& k) const {
		auto res = *this;
		res /= k;
		return res;
	}

	RectMatrix<T> operator *(const RectMatrix<T>& ot) const {
		assert(m == ot.n);
		RectMatrix<T> res(n, ot.m);
		for (int i = 0; i < n; ++i) {
			for (int k = 0; k < ot.m; ++k) {
				for (int j = 0; j < m; ++j) {
					res[i][k] += a[i][j] * ot[j][k];
				}
			}
		}
		return res;
	}

	void operator *=(const RectMatrix<T>& ot) {
		*this = *this * ot;
	}

	optional<vector<vector<T>>> row_basis() const {
		if (auto res = gauss(a, vector<T>(n, 0)); res.success) {
			vector<vector<T>> ans;
			int i = 0;
			for (int c = 0; c < m; ++c) {
				if (i < (int)res.main_coords.size() && res.main_coords[i] == c) {
					++i;
					continue;
				} else {
					ans.emplace_back(m);
					ans.back()[c] = -1;
					for (int j = 0; j < (int)res.main_coords.size(); ++j) {
						ans.back()[res.main_coords[j]] = res.lhs[j][c];
					}
				}
			}
			return ans;
		} else {
			return {nullopt};
		}
	}

	optional<vector<T>> solve_linear_system(const vector<T>& rhs) const {
		assert((int)rhs.size() == n);
		if (auto res = gauss(a, rhs); res.success) {
			vector<T> ans(m);
			for (int i = 0; i < (int)res.main_coords.size(); ++i) {
				ans[res.main_coords[i]] = res.rhs[i];
			}
			return ans;
		} else {
			return nullopt;
		}
	}

	struct SolutionSpace {
		vector<T> solution;
		vector<vector<T>> basis;
	};

	optional<SolutionSpace> solve_linear_system_completely(const vector<T>& rhs) const {
		assert((int)rhs.size() == n);
		if (auto res = gauss(a, rhs); res.success) {
			vector<T> sol(m);
			for (int i = 0; i < (int)res.main_coords.size(); ++i) {
				sol[res.main_coords[i]] = res.rhs[i];
			}

			vector<vector<T>> basis;
			int i = 0;
			for (int c = 0; c < m; ++c) {
				if (i < (int)res.main_coords.size() && res.main_coords[i] == c) {
					++i;
					continue;
				} else {
					basis.emplace_back(m);
					basis.back()[c] = -1;
					for (int j = 0; j < (int)res.main_coords.size(); ++j) {
						basis.back()[res.main_coords[j]] = res.lhs[j][c];
					}
				}
			}

			return SolutionSpace{sol, basis};
		} else {
			return nullopt;
		}
	}
};

template <typename T>
ostream& operator <<(ostream& ostr, const RectMatrix<T>& m) {
	for (int i = 0; i < m.n; ++i) {
		if (i) {
			ostr << "\n";
		}
		for (int j = 0; j < m.m; ++j) {
			if (j) {
				ostr << " ";
			}
			ostr << m[i][j];
		}
	}
	return ostr;
}

template <typename T>
istream& operator >>(istream& istr, RectMatrix<T>& m) {
	for (int i = 0; i < m.n; ++i) {
		for (int j = 0; j < m.m; ++j) {
			istr >> m[i][j];
		}
	}
	return istr;
}

#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())


inline int nxt() {
	int x;
	cin >> x;
	return x;
}

#define less problemsetter_pidoras

bool less(double x, double y) {
	return sign(y - x) > 0;
}

bool leq(double x, double y) {
	return sign(y - x) >= 0;
}

bool eq(double x, double y) {
	return sign(x - y) == 0;
}

struct State {
	double p[3];

	bool operator <(const State& ot) const {
		for (int i = 0; i < 3; ++i) {
			if (less(p[i], ot.p[i])) {
				return true;
			}
			if (!leq(p[i], ot.p[i])) {
				return false;
			}
		}
		return false;
	}

	bool operator ==(const State& ot) const {
		for (int i = 0; i < 3; ++i) {
			if (!eq(p[i], ot.p[i])) {
				return false;
			}
		}
		return true;
	}
};

void solve() {
	double c, m, p, v;
	cin >> c >> m >> p >> v;
	vector<State> vec = {{{c, m, p}}};
	set<State> S(all(vec));
	map<State, vector<pair<double, State>>> edges;
	for (int i = 0; i < (int)vec.size(); ++i) {
		auto s = vec[i];
		for (int i = 0; i < 2; ++i) {
			if (eq(s.p[i], 0)) {
				continue;
			}
			double tmp = min(s.p[i], v);
			State t = s;
			t.p[i] -= tmp;
			int cnt = count_if(s.p, s.p + 3, [](double x) { return sign(x) > 0; }) - 1;
			for (int j = 0; j < 3; ++j) {
				if (j != i && !eq(t.p[j], 0)) {
					t.p[j] += tmp / cnt;
				}
			}

			if (!S.count(t)) {
				S.insert(t);
				vec.push_back(t);
			}

			edges[s].push_back({s.p[i], t});
		}
	}
	sort(all(vec));

	const int sz = vec.size();
	RectMatrix<double> mat(sz, sz);
	auto& a = mat.a;
	for (int i = 0; i < sz; ++i) {
		a[i][i] += 1;
		for (const auto& [p, to] : edges[vec[i]]) {
			a[i][lower_bound(all(vec), to) - vec.begin()] -= p;
		}
	}
	// for (auto& s : vec) {
	// 	for (int i = 0; i < 3; ++i) {
	// 		cerr << s.p[i] << " ";
	// 	}
	// 	cerr << "--\n";
	// }
	// cerr << mat << "\n";
	cout << setprecision(10) << fixed;
	cout << (*mat.solve_linear_system(vector<double>(sz, 1)))[lower_bound(all(vec), State{c, m, p}) - vec.begin()] << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}