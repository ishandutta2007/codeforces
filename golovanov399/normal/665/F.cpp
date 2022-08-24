#include <bits/stdc++.h>



#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())
#define imie(x) #x << ": " << x

using namespace std;

template <typename T>
istream& operator >>(istream& istr, vector<T>& vec) {
	for (auto& x : vec) {
		istr >> x;
	}
	return istr;
}

template <typename T = int>
T nxt(istream& istr = cin) {
	T x;
	istr >> x;
	return x;
}



pair<vector<int>, vector<int>> sieve(int n) {
	vector<int> erat(n);
	vector<int> primes;
	erat[1] = 1;
	for (int i = 2; i < n; ++i) {
		if (erat[i] == 0) {
			erat[i] = i;
			primes.push_back(i);
		}
		for (int p : primes) {
			if (p > erat[i] || i * p >= n) {
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
		if (erat[i] == erat[i / erat[i]]) {
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
using ull = unsigned long long;

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

li sqr(li x) {
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


template <typename V = int>
struct Fenwick {
	int n;
	vector<V> a;

	Fenwick(int _n): n(_n), a(_n) {}

	void add(int pos, const V& x) {
		while (pos < n) {
			a[pos] += x;
			pos |= pos + 1;
		}
	}

	V get(int pos) {
		V res = 0;
		while (pos >= 0) {
			res += a[pos];
			pos = (pos & (pos + 1)) - 1;
		}
		return res;
	}

	V get(int l, int r) {
		return get(r - 1) - get(l - 1);
	}
};

template <typename T, typename Func>
class PrimeSum {
public:
	const li n;
	const li K;
	const Func func;

	static constexpr T def = 2281488;

	vector<int> erat, primes;
	vector<int> sorted_numbers;
	vector<vector<T>> dp;
	vector<T> prec;

	explicit PrimeSum(li _n, Func&& _func = Func()): n(_n), K(max({20., pow(n / max(1., log(n)), 2. / 3), sqrt(n) + 100})), func(_func) {
		tie(erat, primes) = sieve(K);
		dp.resize(n / (K - 1) + 1);
		for (int i = 1, j = (int)primes.size() - 1; n / i >= K; ++i) {
			while (j > 0 && sqr(primes[j - 1]) > n / i) {
				--j;
			}
			dp[i].assign(j + 2, def);
		}
		while (!dp.empty() && dp.back().empty()) {
			dp.pop_back();
		}
		sorted_numbers.resize(K - 1);
		iota(all(sorted_numbers), 1);
		sort(all(sorted_numbers), [&](int i, int j) {
			return erat[i] > erat[j];
		});

		prec.resize(K);
		for (int p : primes) {
			prec[p] += func(p);	// here
		}
		for (int i = 1; i < (int)prec.size(); ++i) {
			prec[i] += prec[i - 1];
		}
	}

	struct Query {
		int id;
		int n;
		int k;
		T ans;
	};

	void fill_dp() {
		if (dp.empty()) {
			return;
		}
		Fenwick<T> f(K);
		for (int i = 1; i < K; ++i) {
			f.add(i, 1);	// here
		}
		for (auto& v : dp) {
			fill(all(v), 0);
		}
		int idx = (int)sorted_numbers.size() - 2;
		for (int j = 0; j < (int)dp[1].size(); ++j) {
			for (int i = 1; i < (int)dp.size() && j < (int)dp[i].size(); ++i) {
				if (j > 0 && n / i >= K && i * primes[j - 1] >= (int)dp.size()) {
					dp[i][j] -= f.get(n / i / primes[j - 1]);
				}
			}
			while (idx >= 0 && erat[sorted_numbers[idx]] < primes[j]) {
				f.add(sorted_numbers[idx], -1);	// here
				--idx;
			}
			for (int i = 1; i < (int)dp.size() && j < (int)dp[i].size(); ++i) {
				if (j == 0) {
					dp[i][j] += n / i;	// here
				} else if (n / i < K) {
					dp[i][j] += f.get(n / i);
				} else {
					dp[i][j] += dp[i][j - 1];
					if (li ni = i * primes[j - 1]; ni < (int)dp.size()) {
						int mn = min(j - 1, (int)dp[ni].size() - 1);
						dp[i][j] -= dp[ni][mn] + mn - (j - 1);
					}
				}
			}
		}
	}

	T calc(int i) {
		if (n / i < (int)prec.size()) {
			return prec[n / i];
		}
		vector<Query> qrs;
		fill_queries(i, (int)dp[i].size(), qrs);
		if (!qrs.empty()) {
			sort(all(qrs), [&](const Query& a, const Query& b) {
				return a.k > b.k;
			});
			Fenwick<T> f(K);
			f.add(1, 1);	// here
			int idx = 0;
			for (int k : sorted_numbers) {
				if (idx >= (int)qrs.size()) {
					break;
				}
				while (idx < (int)qrs.size() && erat[k] < primes[qrs[idx].k]) {
					qrs[idx].ans = f.get(qrs[idx].n);
					++idx;
				}
				f.add(k, 1);	// here
			}
			while (idx < (int)qrs.size()) {
				qrs[idx].ans = f.get(qrs[idx].n);
				++idx;
			}
			sort(all(qrs), [&](const Query& a, const Query& b) {
				return a.id < b.id;
			});
		}
		return calc_queries(i, (int)dp[i].size(), qrs) + (int)dp[i].size() - 1;	// here
	}

private:
	void fill_queries(li i, int j, vector<Query>& qrs) {
		const li curn = n / i;
		if (j == 0) {
			return;
		} else if (curn < K) {
			int sz = qrs.size();
			qrs.push_back({sz, (int)curn, j, 0ll});
			return;
		} else if (j >= (int)dp[i].size()) {
			fill_queries(i, (int)dp[i].size() - 1, qrs);
		} else if (dp[i][j] != def) {
			return;
		} else {
			fill_queries(i * primes[j - 1], j - 1, qrs);
			fill_queries(i, j - 1, qrs);
		}
	}

	T calc_queries(li i, int j, vector<Query>& qrs) {
		const li curn = n / i;
		if (j == 0) {
			return curn;	// here
		} else if (curn < K) {
			T ans = qrs.back().ans;
			qrs.pop_back();
			return ans;
		} else if (j >= (int)dp[i].size()) {
			return calc_queries(i, (int)dp[i].size() - 1, qrs) + ((int)dp[i].size() - 1) - j;
		} else if (dp[i][j] != def) {
			return dp[i][j];
		} else {
			T ans = 0;
			ans += calc_queries(i, j - 1, qrs);
			ans -= calc_queries(i * primes[j - 1], j - 1, qrs);
			return dp[i][j] = ans;
		}
	}
};

template <typename T, size_t p>
class PowerClass {
public:
	T operator ()(T x) const {
		return pw(x, p);
	}
};

using PrimeCount = PrimeSum<li, PowerClass<li, 0>>;

#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())


inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

int main() {
	li n = nxt<li>();
	PrimeCount pc(n);
	pc.fill_dp();

	li ans = 0;
	for (li p : pc.primes) {
		if (p * p * p > n) {
			break;
		} else {
			++ans;
		}
	}
	int cur = 0;
	for (li p : pc.primes) {
		if (p * p >= n) {
			break;
		}
		++cur;
		ans += pc.calc(p) - cur;
	}
	cout << ans << "\n";

	return 0;
}