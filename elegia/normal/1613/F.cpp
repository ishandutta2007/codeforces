#include <cstdio>
#include <cstring>

#include <algorithm>
#include <chrono>
#include <random>
#include <functional>
#include <vector>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int P = 998244353, R = 3;
const int BRUTE_N2_LIMIT = 50;

int mpow(int x, int k, int p = P) {
	int ret = 1;
	while (k) {
	if (k & 1)
		ret = ret * (ll) x % p;
	x = x * (ll) x % p;
	k >>= 1;
	}
	return ret;
}

int norm(int x) { return x >= P ? x - P : x; }

void add(int& x, int y) {
	if ((x += y) >= P)
	x -= P;
}

void sub(int& x, int y) {
	if ((x -= y) < 0)
	x += P;
}

struct NumberTheory {

	typedef pair<int, int> _P2_Field;

	mt19937 rng;

	NumberTheory() : rng(chrono::steady_clock::now().time_since_epoch().count()) {}

	void _exGcd(int a, int b, int &x, int &y) {
	if (!b) {
		x = 1;
		y = 0;
		return;
	}
	_exGcd(b, a % b, y, x);
	y -= a / b * x;
	}

	int inv(int a, int p = P) {
	int x, y;
	_exGcd(a, p, x, y);
	if (x < 0)
		x += p;
	return x;
	}

	template<class Integer>
	bool quadRes(Integer a, Integer b) {
	if (a <= 1)
		return true;
	while (a % 4 == 0)
		a /= 4;
	if (a % 2 == 0)
		return (b % 8 == 1 || b % 8 == 7) == quadRes(a / 2, b);
	return ((a - 1) % 4 == 0 || (b - 1) % 4 == 0) == quadRes(b % a, a);
	}

	// assume p in prime, x in quadratic residue
	int sqrt(int x, int p = P) {
	if (p == 2 || x <= 1)
		return x;
	int w, v, k = (p + 1) / 2;
	do {
		w = rng() % p;
	} while (quadRes(v = int((w * (ll) w - x + p) % p), p));
	_P2_Field res(1, 0), a(w, 1);
	while (k) {
		if (k & 1)
		res = _P2_Field((res.first * (ll) a.first + res.second * (ll) a.second % p * v) % p,
						(res.first * (ll) a.second + res.second * (ll) a.first) % p);
		if (k >>= 1)
		a = _P2_Field((a.first * (ll) a.first + a.second * (ll) a.second % p * v) % p,
						(a.first * (ll) a.second << 1) % p);
	}
	return min(res.first, p - res.first);
	}

} nt;

struct Simple {
	int n;
	vector<int> fac, ifac, inv;

	void build(int n) {
	this->n = n;
	fac.resize(n + 1);
	ifac.resize(n + 1);
	inv.resize(n + 1);
	fac[0] = 1;
	for (int x = 1; x <= n; ++x)
		fac[x] = fac[x - 1] * (ll) x % P;
	inv[1] = 1;
	for (int x = 2; x <= n; ++x)
		inv[x] = -(P / x) * (ll) inv[P % x] % P + P;
	ifac[0] = 1;
	for (int x = 1; x <= n; ++x)
		ifac[x] = ifac[x - 1] * (ll) inv[x] % P;
	}

	Simple() {
	build(1);
	}

	void check(int k) {
	int nn = n;
	if (k > nn) {
		while (k > nn)
		nn <<= 1;
		build(nn);
	}
	}

	int gfac(int k) {
	check(k);
	return fac[k];
	}

	int gifac(int k) {
	check(k);
	return ifac[k];
	}

	int ginv(int k) {
	check(k);
	return inv[k];
	}

	int binom(int n, int m) {
	if (m < 0 || m > n)
		return 0;
	return gfac(n) * (ll) gifac(m) % P * gifac(n - m) % P;
	}
} simp;

const int L = 21;

int reduce(int x) { return x < 0 ? x + P : x; }

namespace NTT {

	const int OMEGA_2_21 = 31;

	int l, n;
	int w2[(1 << L) + 1];

	void init() {
		l = 18;
		n = 1 << l;
		*w2 = 1;
		w2[1 << l] = mpow(OMEGA_2_21, 1 << (21 - l));
		for (int i = l; i; --i) w2[1 << (i - 1)] = w2[1 << i] * (ull)w2[1 << i] % P;
		for (int i = 1; i < n; ++i) w2[i] = w2[i & (i - 1)] * (ull)w2[i & -i] % P;
	}

	void DIF(int *a) {
		int i, *j, *k, len = n >> 1, r, *o;
		for (i = 0; i < l; ++i, len >>= 1)
			for (j = a, o = w2; j != a + n; j += len << 1, ++o)
				for (k = j; k != j + len; ++k)
					r = *o * (ull)k[len] % P, k[len] = reduce(*k - r), add(*k, r);
	}

	void DIT(int *a) {
		int i, *j, *k, len = 1, r, *o;
		for (i = 0; i < l; ++i, len <<= 1)
			for (j = a, o = w2; j != a + n; j += len << 1, ++o)
				for (k = j; k != j + len; ++k)
					r = reduce(*k + k[len] - P), k[len] = ull(*k - k[len] + P) * *o % P, *k = r;
	}

	void FFT(int* a, int d = 1) {
		if (d == 1) DIF(a);
			else {
				DIT(a);
				std::reverse(a + 1, a + n);
				ull nv = P - (P - 1) / n;
				for (int i = 0; i < n; ++i) a[i] = a[i] * nv % P;
			}
	}

}

struct Poly {
	vector<int> a;

	Poly(int v = 0) : a(1) {
	if ((v %= P) < 0)
		v += P;
	a[0] = v;
	}

	Poly(const vector<int> &a) : a(a) {}

	Poly(initializer_list<int> init) : a(init) {}

	// Helps
	int operator[](int k) const { return k < a.size() ? a[k] : 0; }

	int &operator[](int k) {
	if (k >= a.size())
		a.resize(k + 1);
	return a[k];
	}

	int deg() const { return a.size() - 1; }

	void redeg(int d) { a.resize(d + 1); }

	Poly monic() const;

	Poly sunic() const;

	Poly slice(int d) const {
	if (d < a.size())
		return vector<int>(a.begin(), a.begin() + d + 1);
	vector<int> res(a);
	res.resize(d + 1);
	return res;
	}

	int *base() { return a.data(); }

	const int *base() const { return a.data(); }

	Poly println(FILE *fp) const {
	fprintf(fp, "%d", a[0]);
	for (int i = 1; i < a.size(); ++i)
		fprintf(fp, " %d", a[i]);
	fputc('\n', fp);
	return *this;
	}

	// Calculations
	Poly operator+(const Poly &rhs) const {
	vector<int> res(max(a.size(), rhs.a.size()));
	for (int i = 0; i < res.size(); ++i)
		if ((res[i] = operator[](i) + rhs[i]) >= P)
		res[i] -= P;
	return res;
	}

	Poly operator-() const {
	Poly ret(a);
	for (int i = 0; i < a.size(); ++i)
		if (ret[i])
		ret[i] = P - ret[i];
	return ret;
	}

	Poly operator-(const Poly &rhs) const { return operator+(-rhs); }

	Poly operator*(const Poly &rhs) const;
};

Poly zeroes(int deg) { return vector<int>(deg + 1); }

Poly operator "" _z(unsigned long long a) { return {0, (int) a}; }

Poly operator+(int v, const Poly &rhs) { return Poly(v) + rhs; }

Poly Poly::operator*(const Poly &rhs) const {
	int n = deg(), m = rhs.deg();
	if (n <= 10 || m <= 10 || n + m <= BRUTE_N2_LIMIT) {
	Poly ret = zeroes(n + m);
	for (int i = 0; i <= n; ++i)
		for (int j = 0; j <= m; ++j)
		ret[i + j] = (ret[i + j] + a[i] * (ll) rhs[j]) % P;
	return ret;
	}
	n += m;
	int l = 0;
	while ((1 << l) <= n) ++l;
	NTT::l = l; NTT::n = 1 << l;
	vector<int> res(1 << l), tmp(1 << l);
	memcpy(res.data(), base(), a.size() * sizeof(int));
	NTT::FFT(res.data());
	memcpy(tmp.data(), rhs.base(), rhs.a.size() * sizeof(int));
	NTT::FFT(tmp.data());
	for (int i = 0; i < (1 << l); ++i)
	res[i] = res[i] * (ll) tmp[i] % P;
	NTT::FFT(res.data(), -1);
	res.resize(n + 1);
	return res;
}

#include <cassert>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <random>
#include <bitset>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <chrono>
#include <iostream>
#include <iomanip>
#include <limits>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template <class T>
istream& operator>>(istream& is, vector<T>& v) {
	for (T& x : v)
	is >> x;
	return is;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
	if (!v.empty()) {
	os << v.front();
	for (int i = 1; i < v.size(); ++i)
		os << ' ' << v[i];
	}
	return os;
}

const int _ = 250010, B = 3;

int cnt[_], f[_][B + 1];
int deg[_];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	NTT::init();

	int N; cin >> N;
	for (int rep = 1; rep != N; ++rep) {
		int u, v; cin >> u >> v; ++deg[u]; ++deg[v];
	}
	for (int i = 1; i <= N; ++i) ++cnt[deg[i] - (i != 1)];

	int deg = accumulate(cnt, cnt + B, 0);
	for (int i = 0; i <= B; ++i) f[0][i] = 1;
	for (int i = 1; i <= deg; ++i) {
		for (int j = 0; j != B; ++j)
			f[i][B] = (f[i][B] + f[i - 1][j] * (ull)(P - cnt[j] * j)) % P;
		f[i][B] = f[i][B] * (ull)simp.ginv(i) % P;
		for (int j = 0; j != B; ++j) f[i][j] = (f[i - 1][j] * (ull)j + f[i][B]) % P;
	}
	for (int i = 0; i <= B; ++i) {
		int val = 0;
		for (int j = 0; j <= deg - (i != B); ++j) val = (val + simp.gfac(deg - (i != B) - j) * (ull)f[j][i]) % P;
		f[0][i] = val;
	}
	for (int i = 1; i <= N - deg; ++i) {
		f[i][B] = i * (ull)f[i - 1][B] % P;
		for (int j = 0; j != B; ++j) {
			f[i][j] = (f[i - 1][B] + j * (ull)f[i - 1][j]) % P;
			f[i][B] = (f[i][B] + f[i][j] * (ull)cnt[j]) % P;
		}
	}

	Poly prod = Poly(1);
	priority_queue<Poly, vector<Poly>, function<bool(const Poly&, const Poly&)>> Q([&](const Poly& lhs, const Poly& rhs) { return lhs.deg() > rhs.deg(); });

	for (int i = N; i >= B; --i) {
		if (!cnt[i]) continue;
		Poly cur = zeroes(cnt[i]);
		int p = 1, q = P - i;
		for (int j = 0; j <= cnt[i]; ++j) {
			cur[cnt[i] - j] = simp.binom(cnt[i], j) * (ull)p % P;
			p = p * (ull)q % P;
		}
		Q.push(cur);
	}
	if (!Q.empty()) {
		while (Q.size() > 1) {
			Poly x = Q.top(); Q.pop();
			Poly y = Q.top(); Q.pop();
			Q.push(x * y);
		}
		prod = Q.top(); Q.pop();
	}
	int ans = 0;
	for (int i = 0; i <= N - deg; ++i) ans = (ans + prod[i] * (ull)f[i][B]) % P;
	cout << ans << '\n';

	return 0;
}