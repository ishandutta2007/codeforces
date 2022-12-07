#include <algorithm>
#include <cstdio>
#include <cstring>
#include <functional>
#include <map>
#include <vector>

typedef unsigned long long L;
const int N = 5.3e5 + 535, P = 998244353, G = 3;

int pw(int x, int y) {
	int r = 1;
	for (; y; y >>= 1, x = (L)x * x % P)
		if (y & 1) r = (L)r * x % P;
	return r;
}

int lim, rev[N], w[N];
void init(int n) {
	int l = 32 - __builtin_clz(n - 1);
	lim = 1 << l;
	for (int i = 0, ri = 0; i < lim; ++i) {
		rev[i] = ri;
		for (int k = lim >> 1; (ri ^= k) < k;) k >>= 1;
	}
	int wn = pw(G, (P - 1) >> l);
	w[lim >> 1] = 1;
	for (int i = (lim >> 1) + 1; i < lim; ++i) w[i] = (L)w[i - 1] * wn % P;
	for (int i = (lim >> 1) - 1; i; --i) w[i] = w[i << 1];
	lim = l;
}

int _inv[N];
struct ___init {
	___init() {
		_inv[1] = 1;
		for (int i = 2; i < N; i++) _inv[i] = L(P - P / i) * _inv[P % i] % P;
	}
} __init;
void md(int &x) { x += x >> 31 & P; }

struct poly {
	std::vector<int> v;

	inline poly() {}
	inline poly(int n) : v(n) {}
	inline poly(const poly &rhs) : v(rhs.v) {}
	inline poly(const std::vector<int> &rhs) : v(rhs) {}

	inline size_t size() { return v.size(); }
	inline bool empty() { return v.empty(); }
	inline void resize(int n) { v.resize(n); }
	inline void clear() { v.clear(); }
	inline void shl() { v.insert(v.begin(), 0); }
	void shrink() {
		while (!v.empty() && !v.back()) v.pop_back();
	}

	inline static int len(int n) { return 1 << (32 - __builtin_clz(n - 1)); }

	inline int &operator[](int i) { return v[i]; }

	void deriv() {
		for (int i = 1; i < v.size(); i++) v[i - 1] = (L)i * v[i] % P;
		v.pop_back();
	}
	void intg() {
		shl();
		for (int i = 1; i < v.size(); i++) v[i] = (L)v[i] * _inv[i] % P;
	}

	void dft(int n) {
		static L tmp[N];
		int ofs = lim - __builtin_ctz(n);
		resize(n);
		if (n <= 1) return;
		for (int i = 0; i < n; ++i) tmp[rev[i] >> ofs] = v[i];
		for (int i = 0; i < n; i += 2) {
			int x = tmp[i], y = tmp[i + 1];
			tmp[i] = x + y, tmp[i + 1] = x + P - y;
		}
		for (int i = 2; i < n; i <<= 1)
			for (int j = 0; j < n; j += i << 1)
				for (int k = 0; k < i; ++k) {
					int y = (L)tmp[j + i + k] * w[i + k] % P;
					tmp[j + i + k] = tmp[j + k] + P - y, tmp[j + k] += y;
				}
		for (int i = 0; i < n; ++i) v[i] = tmp[i] % P;
	}
	void idft(int n) {
		dft(n);
		if (n <= 1) return;
		std::reverse(v.begin() + 1, v.end());
		int tmp = P - (P - 1) / n;
		for (int i = 0; i < n; i++) v[i] = (L)v[i] * tmp % P;
	}
	void mul(poly rhs) {
		int n = len(size() + rhs.size() - 1);
		dft(n), rhs.dft(n);
		for (int i = 0; i < n; i++) v[i] = (L)v[i] * rhs[i] % P;
		idft(n), shrink();
	}
	void inv() {
		std::vector<int> va(1);
		va[0] = pw(v[0], P - 2);
		poly a;
		int n = size(), m = len(n);
		v.resize(m), v.swap(va);
		for (int i = 2; i <= m; i <<= 1) {
			a.resize(i);
			for (int j = 0; j < i; j++) a[j] = va[j];
			a.dft(i << 1), dft(i << 1);
			for (int j = 0; j < (i << 1); j++)
				v[j] = v[j] * (2 + P - (L)v[j] * a[j] % P) % P;
			idft(i << 1);
			resize(i);
		}
		resize(n);
	}
	void ln() {
		poly f0 = *this;
		int n = size();
		deriv(), f0.inv(), mul(f0), resize(n), intg(), resize(n);
	}
	void exp() {
		std::vector<int> va(1);
		va[0] = 1;
		poly a;
		int n = size(), m = len(n);
		v.resize(m), v.swap(va);
		for (int i = 2; i <= m; i *= 2) {
			a = *this, a.resize(i), a.ln();
			for (int j = 0; j < i; j++) a[j] = (va[j] + !j + P - a[j]) % P;
			mul(a);
			resize(i);
		}
		resize(n);
	}
} a;

std::map<int, int> mp, mp2;
int n, m, ans;
int main() {
	scanf("%d", &n);
	for (int i = 1, x; i <= n; i++) scanf("%d", &x), mp2[x]++;
	init((n + 1) * 2);
	a.resize(n + 1);
	m = mp2.size();
	for (auto [_, y] : mp2) mp[y]++;
	for (auto [x, y] : mp)
		for (int i = x + 1, j = 1; i <= n; i += x + 1, j++)
			a[i] = (a[i] + P - (L)y * _inv[j] % P) % P;
	for (int i = 1; i <= n; i++) a[i] = (a[i] + (L)m * _inv[i]) % P;
	a.exp();
	printf("%d\n", a[n / 2]);
}