#include<cstdio>
#include<vector>
const int mod = 998244353;
const int prt = 3;
long long int mpow(long long int x, long long int y) {
	if (y == 0)return 1;
	long long int r = mpow(x, y / 2);
	r *= r;
	r %= mod;
	if (y % 2 == 1) {
		r *= x;
		r %= mod;
	}
	return r;
}
long long int minv(long long int x) {
	return mpow(x, mod - 2);
}
std::vector<long long int> fft(std::vector<long long int> &x, int sz, long long int w) {
	if (sz == 0)return x;
	int hsz = 1 << (sz - 1);
	std::vector<long long int> xl(hsz), xr(hsz);
	for (int i = 0; i < hsz; i++) {
		xl[i] = x[2 * i];
		xr[i] = x[2 * i + 1];
	}
	std::vector<long long int> yl = fft(xl, sz - 1, w*w%mod);
	std::vector<long long int> yr = fft(xr, sz - 1, w*w%mod);
	std::vector<long long int> y(2 * hsz);
	int mask = hsz - 1;
	long long int wpow = 1;
	for (int i = 0; i < (1 << sz); i++) {
		y[i] = (yl[i&mask] + wpow*yr[i&mask]) % mod;
		wpow *= w;
		wpow %= mod;
	}
	return y;
}
std::vector<long long int> pmult(std::vector<long long int> x, std::vector<long long int> y, int sz, long long int w, long long int winv) {
	std::vector<long long int> xf = fft(x, sz, w);
	std::vector<long long int> yf = fft(y, sz, w);
	std::vector<long long int> resf;
	for (int i = 0; i < (1 << sz); i++) {
		resf.push_back(xf[i] * yf[i] % mod);
	}
	std::vector<long long int> res = fft(resf, sz, winv);
	long long int dsz = mpow((mod + 1) / 2, sz);
	for (int i = 0; i < (1 << sz); i++) {
		res[i] *= dsz;
		res[i] %= mod;
	}
	return res;
}
std::vector<long long int> solve(int n) {
	std::vector<std::vector<long long int>> r;
	for (int i = 0; i < n; i++) {
		std::vector<long long int> t;
		t.push_back(i);
		t.push_back(1);
		r.push_back(t);
	}
	for (int sz = 1; sz <= 17; sz++) {
		std::vector<std::vector<long long int>> nr;
		long long int w = mpow(prt, (mod - 1) / (1 << sz));
		long long int winv = minv(w);
		for (int i = 0; i < r.size(); i += 2) {
			std::vector<long long int> tl = r[i];
			if (i + 1 == r.size()) {
				tl.resize(1 << (sz + 1));
				nr.push_back(tl);
			}
			else {
				std::vector<long long int> tr = r[i + 1];
				std::vector<long long int> t = pmult(tl, tr, sz, w, winv);
				long long int c = tl[0] * tr[0] % mod;
				t.push_back((t[0] + mod - c) % mod);
				t[0] = c;
				t.resize(1 << (sz + 1));
				nr.push_back(t);
			}
		}
		r = nr;
	}
	return r[0];
}
long long int fct(int x) {
	long long int res = 1;
	for (int i = 1; i <= x; i++) {
		res *= i;
		res %= mod;
	}
	return res;
}
long long int comb(int a, int b) {
	return fct(a)*minv(fct(b)) % mod*minv(fct(a - b)) % mod;
}
int main() {
	int n, a, b;
	scanf("%d%d%d", &n, &a, &b);
	if (a == 0 || b == 0 || a + b > n + 1) {
		printf("0");
		return 0;
	}
	if (n == 1) {
		printf("1");
		return 0;
	}
	long long int ans = solve(n - 1)[a + b - 2];
	ans *= comb(a + b - 2, b - 1);
	ans %= mod;
	printf("%lld", ans);
	return 0;
}