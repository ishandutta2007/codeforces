#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#ifdef ONLINE_JUDGE
	inline int pidorand() {
		return ((rand() & 32767) << 15) | (rand() & 32767);
	}
	#define rand pidorand
#endif	// ONLINE_JUDGE

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
const int L = 21;	// can be 23 for 998244353
const int N = 1 << L;

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

int getRoot() {
	int root = 1;
	while (pw(root, 1 << L) != 1 || pw(root, 1 << (L - 1)) == 1) {
		++root;
	}
	return root;
}

const int root = getRoot();

long long angles[N + 1];
int bitrev[N];

void init() {
	angles[0] = 1;
	for (int i = 1; i <= N; ++i) {
		angles[i] = angles[i - 1] * root % mod;
	}

	for (int i = 0; i < N; ++i) {
		int x = i;
		for (int j = 0; j < L; ++j) {
			bitrev[i] = (bitrev[i] << 1) | (x & 1);
			x >>= 1;
		}
	}
}

inline int revBit(int x, int len) {
	return bitrev[x] >> (L - len);
}

void fft(vector<long long>& a, bool inverse = false) {
	int n = a.size();
	assert(!(n & (n - 1)));	// work only with powers of two
	int l = __builtin_ctz(n);

	for (int i = 0; i < n; ++i) {
		int j = revBit(i, l);
		if (i < j) {
			swap(a[i], a[j]);
		}
	}

	for (int len = 1; len < n; len *= 2) {
		for (int start = 0; start < n; start += 2 * len) {
			for (int i = 0; i < len; ++i) {
				long long x = a[start + i], y = a[start + len + i];
				int idx = N / 2 / len * i;
				long long w = angles[inverse ? N - idx : idx];
				w = w * y % mod;
				a[start + i] = x + w;
				if (a[start + i] >= mod) {
					a[start + i] -= mod;
				}
				a[start + len + i] = x - w;
				if (a[start + len + i] < 0) {
					a[start + len + i] += mod;
				}
			}
		}
	}

	if (inverse) {
		int rev_deg = 1;
		for (int i = 0; i < l; ++i) {
			rev_deg = (rev_deg % 2) ? (rev_deg + mod) / 2 : rev_deg / 2;
		}
		for (auto& x : a) {
			x = x * rev_deg % mod;
		}
	}
}

vector<long long> multiply(vector<long long> a, vector<long long> b) {
	int n = 1;
	while (n < (int)a.size() || n < (int)b.size()) {
		n *= 2;
	}
	a.resize(n + n);
	b.resize(n + n);
	fft(a);
	fft(b);
	for (int i = 0; i < n + n; ++i) {
		a[i] = a[i] * b[i] % mod;
	}
	fft(a, true);
	while (!a.empty() && a.back() == 0) {
		a.pop_back();
	}
	return a;
}

ostream& operator <<(ostream& ostr, const vector<long long>& a) {
	ostr << "{";
	for (int i = 0; i < (int)a.size(); ++i) {
		if (i) {
			ostr << ", ";
		}
		ostr << a[i];
	}
	ostr << "}";
	return ostr;
}

vector<long long> derivative(vector<long long> a) {
	if (a.empty()) {
		return a;
	}
	for (int i = 0; i < (int)a.size(); ++i) {
		a[i] = a[i] * i % mod;
	}
	a.erase(a.begin());
	return a;
}

vector<long long> add(vector<long long> a, const vector<long long>& b) {
	a.resize(max(a.size(), b.size()));
	for (int i = 0; i < (int)b.size(); ++i) {
		a[i] = (a[i] + b[i]) % mod;
	}
	return a;
}

vector<long long> sub(vector<long long> a, const vector<long long>& b) {
	a.resize(max(a.size(), b.size()));
	for (int i = 0; i < (int)b.size(); ++i) {
		a[i] = (a[i] + mod - b[i]) % mod;
	}
	return a;
}

vector<long long> getInversed(vector<long long> a, int n) {
	// cerr << a << "^(-1) = ";
	long long c = a[0];
	assert(c);
	c = pw(c, mod - 2);
	for (auto& x : a) {
		x = x * c % mod;
	}

	vector<long long> res = {1};
	int k = 1;
	while (k < n) {
		k *= 2;
		vector<long long> tmp = multiply(res, {a.begin(), a.begin() + min(k, (int)a.size())});
		for (auto& x : tmp) {
			x = x ? mod - x : 0;
		}
		tmp[0] = (tmp[0] + 2) % mod;

		res = multiply(tmp, res);
		res.resize(k);
	}
	res.resize(n);
	for (auto& x : res) {
		x = x * c % mod;
	}
	// cerr << res << " mod x^" << n << "\n";
	return res;
}

pair<vector<long long>, vector<long long>> divmod(vector<long long> a, vector<long long> b) {
	int n = a.size();
	int m = b.size();
	if (n < m) {
		return {{0}, a};
	}
	reverse(all(a));
	reverse(all(b));
	auto quotient = multiply(a, getInversed(b, n - m + 1));
	quotient.resize(n - m + 1);
	reverse(all(a));
	reverse(all(b));
	reverse(all(quotient));
	auto remainder = sub(a, multiply(b, quotient));
	while (!remainder.empty() && remainder.back() == 0) {
		remainder.pop_back();
	}
	return {quotient, remainder};
}

// this is for multipoint and interpolate functions
vector<vector<long long>> getSegmentProducts(const vector<long long>& pts) {
	vector<vector<long long>> segment_polys;
	function<int(int, int)> fill_polys = [&](int l, int r) {
		if (l + 1 == r) {
			segment_polys.push_back({(mod - pts[l]) % mod, 1});
			return (int)segment_polys.size() - 1;
		}
		int m = (l + r) / 2;
		int i = fill_polys(l, m);
		int j = fill_polys(m, r);
		auto new_poly = multiply(segment_polys[i], segment_polys[j]);
		segment_polys.push_back(new_poly);
		return (int)segment_polys.size() - 1;
	};
	fill_polys(0, pts.size());

	return segment_polys;
}

vector<long long> multipoint(const vector<long long>& poly, const vector<long long>& pts) {
	if (pts.empty()) {
		return {};
	}

	vector<vector<long long>> segment_polys = getSegmentProducts(pts);
	vector<long long> ans;
	function<void(const vector<long long>&)> fill_ans = [&](const vector<long long>& p) {
		if ((int)segment_polys.back().size() <= 2) {
			ans.push_back(p.empty() ? 0 : p[0]);
			segment_polys.pop_back();
			return;
		}
		segment_polys.pop_back();
		fill_ans(divmod(p, segment_polys.back()).second);
		fill_ans(divmod(p, segment_polys.back()).second);
	};
	fill_ans(poly);
	reverse(all(ans));

	return ans;
}

vector<long long> interpolate(const vector<long long>& xs, const vector<long long>& ys) {
	assert(xs.size() == ys.size());
	if (xs.empty()) {
		return {0};
	}

	auto segment_polys = getSegmentProducts(xs);
	auto der = derivative(segment_polys.back());
	auto coeffs = multipoint(der, xs);
	for (auto& c : coeffs) {
		c = pw(c, mod - 2);
	}
	for (int i = 0; i < (int)ys.size(); ++i) {
		coeffs[i] = coeffs[i] * ys[i] % mod;
	}

	function<vector<long long>()> get_ans = [&]() {
		vector<long long> res;
		if (segment_polys.back().size() <= 2) {
			segment_polys.pop_back();
			res = {coeffs.back()};
			coeffs.pop_back();
		} else {
			segment_polys.pop_back();

			auto p1 = segment_polys.back();
			auto q1 = get_ans();

			auto p2 = segment_polys.back();
			auto q2 = get_ans();

			res = add(multiply(p1, q2), multiply(p2, q1));
		}
		return res;
	};
	return get_ans();
}

const int max_n = 111111;
long long inv[max_n];
long long fact[max_n];
long long invfact[max_n];

int main() {
	init();
	fact[0] = invfact[0] = 1;
	for (int i = 1; i < max_n; ++i) {
		inv[i] = (i == 1) ? 1 : mod - 1ll * mod / i * inv[mod % i] % mod;
		fact[i] = fact[i - 1] * i % mod;
		invfact[i] = invfact[i - 1] * inv[i] % mod;
	}

	int n;
	long long m;
	scanf("%d%lld", &n, &m);
	// n = 20000;
	// m = 12345678901234567ll;
	vector<long long> p(n + 1);
	for (int i = 0; i <= n; ++i) {
		p[i] = nxt();
		// p[i] = rand() % mod;
	}
	// p[n] = (p[n] + mod + 1 - accumulate(all(p), 0ll) % mod) % mod;

	// vector<long long> xs(n + 1);
	// iota(all(xs), 0ll);
	// auto ys = multipoint(p, xs);
	// for (auto& x : xs) {
	// 	--x;
	// }
	// p = interpolate(xs, ys);
	// p.resize(n + 1);
	// reverse(all(p));

	{
		vector<long long> tmp(n + 1);
		for (int i = 0; i <= n; ++i) {
			tmp[i] = invfact[i];
			p[i] = p[i] * fact[i] % mod;
		}
		reverse(all(p));
		p = multiply(p, tmp);
		p.resize(n + 1);
		reverse(all(p));
		for (int i = 0; i <= n; ++i) {
			p[i] = p[i] * invfact[i] % mod;
		}
	}

	for (int i = 0; i <= n; ++i) {
		p[i] = p[i] * pw(inv[i + 1], m) % mod;
	}

	{
		vector<long long> tmp(n + 1);
		for (int i = 0; i <= n; ++i) {
			tmp[i] = invfact[i];
			p[i] = p[i] * fact[i] % mod;
			if (i % 2) {
				p[i] = (mod - p[i]) % mod;
			}
		}
		reverse(all(p));
		p = multiply(p, tmp);
		p.resize(n + 1);
		reverse(all(p));
		for (int i = 0; i <= n; ++i) {
			p[i] = p[i] * invfact[i] % mod;
			if (i % 2) {
				p[i] = (mod - p[i]) % mod;
			}
		}
	}

	// reverse(all(p));
	// iota(all(xs), 0ll);
	// ys = multipoint(p, xs);
	// for (auto& x : xs) {
	// 	++x;
	// }
	// p = interpolate(xs, ys);
	// p.resize(n + 1);

	for (long long& x : p) {
		printf("%lld ", x);
		// cout << hr(x) << " ";
	}
	printf("\n");

	return 0;
}