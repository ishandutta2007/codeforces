

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())
#define imie(x) #x << ": " << x

using namespace std;

pair<vector<int>, vector<int>> sieve(int n) {
	vector<int> erat(n + 1);
	vector<int> primes;
	erat[1] = 1;
	for (int i = 2; i <= n; ++i) {
		if (erat[i] == 0) {
			erat[i] = i;
			primes.push_back(i);
		}
		for (int p : primes) {
			if (p > erat[i] || i * p > n) {
				break;
			}
			erat[i * p] = p;
		}
	}
	return {erat, primes};
}

vector<int> calc_phi(const vector<int>& erat) {
	const int n = erat.size();
	vector<int> phi(n);
	phi[1] = 1;
	for (int i = 2; i < n; ++i) {
		phi[i] = phi[i / erat[i]] * erat[i];
		if (erat[i] != erat[i / erat[i]]) {
			phi[i] -= phi[i / erat[i]];
		}
	}
	return phi;
}

vector<int> calc_mu(const vector<int>& erat) {
	const int n = erat.size();
	vector<int> mu(n);
	mu[1] = 1;
	for (int i = 2; i < n; ++i) {
		mu[i] = (erat[i] == erat[i / erat[i]]) ? 0 : -mu[i / erat[i]];
	}
	return mu;
}



using li = long long;
using LI = __int128_t;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;

ostream& operator <<(ostream& ostr, LI x) {
	static constexpr li BIG = 1e18;
	if (x < 0) {
		ostr << "-";
		x = -x;
	}
	if (x < BIG) {
		return ostr << (li)x;
	} else if (x / BIG >= BIG) {
		stringstream ss;
		ss << setfill('0') << setw(18) << (li)(x / BIG % BIG);
		ss << setfill('0') << setw(18) << (li)(x % BIG);
		return ostr << (li)(x / BIG / BIG) << ss.str();
	} else {
		stringstream ss;
		ss << setfill('0') << setw(18) << (li)(x % BIG);
		return ostr << (li)(x / BIG) << ss.str();
	}
}

template <typename T>
ostream& operator <<(ostream& ostr, const vector<T>& vec) {
	auto [pre, sep, post] = (&ostr == &cout) ? make_tuple("", " ", "") : make_tuple("[", ", ", "]");
	ostr << pre;
	bool fp = true;
	for (const auto& x : vec) {
		if (fp) {
			fp = false;
		} else {
			ostr << sep;
		}
		ostr << x;
	}
	return ostr << post;
}

template <typename T, size_t N>
ostream& operator <<(ostream& ostr, const array<T, N>& vec) {
	auto [pre, sep, post] = (&ostr == &cout) ? make_tuple("", " ", "") : make_tuple("[", ", ", "]");
	ostr << pre;
	bool fp = true;
	for (const auto& x : vec) {
		if (fp) {
			fp = false;
		} else {
			ostr << sep;
		}
		ostr << x;
	}
	return ostr << post;
}

template <typename T>
ostream& operator <<(ostream& ostr, const set<T>& st) {
	auto [pre, sep, post] = (&ostr == &cout) ? make_tuple("", " ", "") : make_tuple("{", ", ", "}");
	ostr << pre;
	bool fp = true;
	for (const auto& x : st) {
		if (fp) {
			fp = false;
		} else {
			ostr << sep;
		}
		ostr << x;
	}
	return ostr << post;
}

template <typename T>
ostream& operator <<(ostream& ostr, const multiset<T>& st) {
	auto [pre, sep, post] = (&ostr == &cout) ? make_tuple("", " ", "") : make_tuple("{", ", ", "}");
	ostr << pre;
	bool fp = true;
	for (const auto& x : st) {
		if (fp) {
			fp = false;
		} else {
			ostr << sep;
		}
		ostr << x;
	}
	return ostr << post;
}

template <typename T, typename U>
ostream& operator <<(ostream& ostr, const map<T, U>& mp) {
	ostr << "{";
	bool fp = true;
	for (const auto& [k, v] : mp) {
		if (fp) {
			fp = false;
		} else {
			ostr << ", ";
		}
		ostr << k << ": " << v;
	}
	return ostr << "}";
}

template <typename T, typename U>
ostream& operator <<(ostream& ostr, const pair<T, U>& p) {
	return ostr << "(" << p.first << ", " << p.second << ")";
}



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
#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())


inline int nxt() {
	int x;
	cin >> x;
	return x;
}

auto [erat, primes] = sieve(10'111'111);

void solve() {
	int n = nxt(), k = nxt() + 1;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}
	for (auto& x : a) {
		int y = 1;
		while (x > 1) {
			if (erat[x] == erat[x / erat[x]]) {
				x /= erat[x];
				x /= erat[x];
			} else {
				y *= erat[x];
				x /= erat[x];
			}
		}
		x = y;
	}

	map<int, int> M;
	vector<int> last(k);
	vector<vector<int>> dp(n + 1, vector<int>(k, 0));
	// cerr << a << "\n";
	for (int i = 0; i < n; ++i) {
		if (M.count(a[i])) {
			int x = M[a[i]] + 1;
			last.insert(lower_bound(all(last), x, greater<int>()), x);
			last.pop_back();
		}
		M[a[i]] = i;
		for (int j = 0; j < k; ++j) {
			dp[i + 1][j] = 1e9;
			for (int c = 0; c <= j; ++c) {
				remin(dp[i + 1][j], dp[last[c]][j - c] + 1);
			}
			if (j) {
				remin(dp[i + 1][j], dp[i + 1][j - 1]);
			}
		}
	}
	cout << dp[n].back() << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}