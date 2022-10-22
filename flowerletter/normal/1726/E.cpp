#include <bits/stdc++.h>
using namespace std;
const int N = 3e6 + 50;
const int mod = 998244353;
const int g = 3;

int n, m, A[N], B[N], len;
int omega[N], omegaInv[N];

inline int inc(int x, int y) { x += y - mod; return x + (x >> 31 & mod); }
inline int dec(int x, int y) { x -= y; return x + (x >> 31 & mod); }
inline int mul(int x, int y) { return 1ll * x * y % mod; }

inline void upd(int &x, int y) { x = inc(x, y); }
inline void dpu(int &x, int y) { x = dec(x, y); }
inline void pud(int &x, int y) { x = mul(x, y); }

inline int fastpow(int x, int p) {
	int r = 1;
	while (p) {
		if (p & 1) pud(r, x);
		pud(x, x);
		p >>= 1;
	}
	return r;
}

void DFTInit(int n) {
	len = 1;
	while (len <= n) len <<= 1;
	const int t = fastpow(g, (mod - 1) / len);
	omega[0] = omegaInv[0] = 1;
	for (int i = 1; i < len; ++i)
		omega[i] = omegaInv[len - i] = mul(t, omega[i - 1]);
}

inline void DFT(int *A) {
	for (int h = (len >> 1); h >= 1; h >>= 1) {
		for (int t = len / (h << 1), j = 0; j < len; j += (h << 1)) {
			const int *wn = omega;
			for (int i = j; i < j + h; ++i) {
				int _x = A[i], _y = A[i + h];
				A[i] = inc(_x, _y);
				A[i + h] = mul(_x - _y + mod, *wn);
				wn += t;
			}
		}
	}
}

inline void DIT(int *A) {
	for (int h = 1; h < len; h <<= 1)
		for (int t = len / (h << 1), j = 0; j < len; j += (h << 1)) {
			const int *wn = omegaInv;
			for (int i = j; i < j + h; ++i) {
				int _x = A[i], _y = mul(A[i + h], *wn);
				A[i] = inc(_x, _y);
				A[i + h] = dec(_x, _y);
				wn += t;
			}
		}
	const int t = mod - (mod - 1) / len;
	for (int i = 0; i < len; ++i) pud(A[i], t);
}

struct poly_t {
	vector<int> v;
	poly_t() {}
	poly_t(vector<int> v) : v(v) {}
	poly_t(initializer_list<int> v) : v(v) {}
	int& operator[](int k) {
		if (v.size() <= k) v.resize(k + 1);
		return v[k];
	}
	int operator[](int k) const {
		return k < v.size() ? v[k] : 0;
	}
	int* base() {
		return v.begin().base();
	}
	const int* base() const {
		return v.begin().base();
	}
	int deg() const {
		return (int)(v.size()) - 1;
	}
	void redeg(int k) {
		v.resize(k + 1);
	}
	poly_t slice(int k) {
		if (k < v.size())
			return vector<int>(v.begin(), v.begin() + k + 1);
		vector<int> a(v);
		a.resize(k + 1);
		return a;
	}
	poly_t clone() const { return v; }
	void clone(vector<int> &t) const {
		memcpy(t.begin().base(), base(), v.size() * sizeof(int));
	}
};

poly_t operator*(const poly_t &A, const poly_t &B) {
	DFTInit(A.deg() + B.deg());
	int t = A.deg() + B.deg();
	vector<int> a(len), b(len);
	A.clone(a), B.clone(b);
	DFT(a.begin().base()), DFT(b.begin().base());
	for (int i = 0; i < len; ++i) pud(a[i], b[i]);
	DIT(a.begin().base());
	a.resize(t + 1);
	return a;
}
int fact[1234567], inv[1234567], pw2[1234567];
int comb(int n, int m) {
	if (n < m) return 0;
	return mul(mul(fact[n], inv[m]), inv[n - m]);
}
int main() {
// 	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T, m = 3e5;;
	fact[0] = 1;
	for(int i = 1; i <= m; ++i)
		fact[i] = mul(i, fact[i - 1]);
	inv[m] = fastpow(fact[m], mod - 2);
	for (int i = m - 1; i >= 0; --i)
		inv[i] = mul(i + 1, inv[i + 1]);
	int inv2 = inv[2];
	int inv4 = mul(inv2, inv2);
	pw2[0] = 1;
	for (int i = 1; i <= m; ++i)
		pw2[i] = mul(inv2, pw2[i - 1]);
	for(cin >> T; T; T --) {
		int n;
		cin >> n;
		int ans = 0;
		poly_t A, B;
		for (int i = 0; i <= n; ++i) {
			A[i] = i % 2 ? 0 : mul(inv[i / 2], pw2[i / 2]);
			B[i] = inv[i];
		}
		poly_t C = A * B;
		for (int i = 0; i * 4 <= n; ++i) {
			int cf = mul(fact[n - 2 * i], inv[i]);
			int sum = C[n - 4 * i];
			upd(ans, mul(cf, sum));
		}
		/*for (int x = 0; x * 4 <= n; ++x) {
			int need = 2 * x;
			int ways = comb(n - need, need);
			int ways2 = fact[need];
			pud(ways2, inv[need / 2]);
		//	pud(ways2, fastpow(inv2, need / 2));
			for (int y = 0; x * 4 + y * 2 <= n; ++y) {
				int ways3 = comb(n - 4 * x, 2 * y);
				pud(ways3, fact[2 * y]);
				pud(ways3, inv[y]);
				pud(ways3, fastpow(inv2, y));
				int total = mul(mul(ways2, ways3), ways);
				upd(ans, total);
			}
		}*/
		cout << ans << '\n';
	}
	return 0;
}