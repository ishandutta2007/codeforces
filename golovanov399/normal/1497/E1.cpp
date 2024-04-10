

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


#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())


inline int nxt() {
	int x;
	cin >> x;
	return x;
}

auto [erat, primes] = sieve(10'111'111);

// const int inf = 1e9;
// struct Segtree {
// 	int n;
// 	vector<int> a;

// 	Segtree(int _n) {
// 		n = 1;
// 		while (n < _n) {
// 			n *= 2;
// 		}
// 		a.resize(n + n, inf);
// 	}

// 	void upd(int v, int x) {
// 		v += n;
// 		a[v] = x;
// 		while (v > 1) {
// 			v /= 2;
// 			a[v] = min(a[v + v], a[v + v + 1]);
// 		}
// 	}

// 	int get(int v, int l1, int r1, int l, int r) {
// 		if (l >= r1 || l1 >= r) {
// 			return inf;
// 		}
// 		if (l <= l1 && r >= r1) {
// 			return a[v];
// 		}
// 		int m = (l1 + r1) / 2;
// 		return min(get(v + v, l1, m, l, r), get(v + v + 1, m, r1, l, r));
// 	}

// 	int get(int l, int r) {
// 		return get(1, 0, n, l, r);
// 	}
// };

void solve() {
	[[maybe_unused]] int n = nxt(), k = nxt();
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
	int last = 0;
	vector<int> dp(n + 1, 0);
	// cerr << a << "\n";
	for (int i = 0; i < n; ++i) {
		if (M.count(a[i])) {
			last = max(last, M[a[i]] + 1);
		}
		M[a[i]] = i;
		dp[i + 1] = dp[last] + 1;
	}
	cout << dp[n] << "\n";
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