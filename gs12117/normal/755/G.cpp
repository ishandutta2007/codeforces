#include<cstdio>
#include<vector>
using namespace std;
const int max_m = 1 << 15;
const int sz = 1 << 16;
const int mod = 998244353;
const int prt = 929671676;//1<<16-th root of 1
const int iprt = 196959475;
const int isz = 998229121;
int _a[sz];
int _b[sz];
int m;
void recfft(int *x, int *y, int n, int root) {
	if (n == 2) {
		y[0] = (x[0] + x[1]) % mod;
		y[1] = (x[0] + ((long long int)x[1]) * root) % mod;
		x[0] = y[0];
		x[1] = y[1];
		return;
	}
	int hn = n / 2;
	int j = 0;
	int *z = y + hn;
	for (int i = 0; i < hn; i++) {
		y[i] = x[j++];
		z[i] = x[j++];
	}
	recfft(y, x, hn, ((long long int)root)*root%mod);
	recfft(z, x, hn, ((long long int)root)*root%mod);
	int *ra = y;
	int *rb = y + hn;
	z = x + hn;
	long long int p = 1;
	for (int i = 0; i < hn; i++) {
		x[i] = (ra[i] + rb[i] * p) % mod;
		z[i] = (ra[i] + rb[i] * (mod - p)) % mod;
		p *= root;
		p %= mod;
	}
}
vector<long long int> fft(vector<long long int>x) {
	for (int i = 0; i < sz; i++)_a[i] = x[i];
	recfft(_a, _b, sz, prt);
	vector<long long int>res;
	res.resize(sz);
	for (int i = 0; i < sz; i++)res[i] = _a[i];
	return res;
}
vector<long long int> ifft(vector<long long int>x) {
	for (int i = 0; i < sz; i++)_a[i] = x[i];
	recfft(_a, _b, sz, iprt);
	vector<long long int>res;
	res.resize(sz);
	for (int i = 0; i < sz; i++)res[i] = _a[i];
	for (int i = 0; i < sz; i++) {
		res[i] *= isz;
		res[i] %= mod;
	}
	return res;
}
vector<long long int> mult(vector<long long int>a, vector<long long int>b) {
	for (int i = m + 1; i < sz; i++) {
		a[i] = 0;
		b[i] = 0;
	}
	vector<long long int> fa = fft(a);
	vector<long long int> fb = fft(b);
	vector<long long int> res;
	res.resize(sz);
	for (int i = 0; i < sz; i++) {
		res[i] = fa[i] * fb[i] % mod;
	}
	return ifft(res);
}
struct pvll {
	vector<long long int>a, b;
};
pvll fstep() {
	pvll res;
	res.a.resize(sz);
	res.b.resize(sz);
	for (int i = 0; i < sz; i++) {
		res.a[i] = 0;
		res.b[i] = 0;
	}
	res.a[0] = 1;
	res.a[1] = 1;
	res.b[0] = 1;
	return res;
}
pvll step(pvll x) {
	pvll res;
	res.b = x.a;
	res.a.resize(sz);
	res.a[0] = x.a[0];
	for (int i = 1; i <= m; i++) {
		res.a[i] = x.a[i] + x.a[i - 1] + x.b[i - 1];
		res.a[i] %= mod;
	}
	return res;
}
pvll dstep(pvll x) {
	pvll res;
	res.a.resize(sz);
	res.b.resize(sz);
	vector<long long int> asq = mult(x.a, x.a);
	vector<long long int> bsq = mult(x.b, x.b);
	vector<long long int> xab = mult(x.a, x.b);
	pvll y = step(x);
	vector<long long int> yab = mult(y.a, y.b);
	res.a[0] = yab[0];
	res.b[0] = asq[0];
	for (int i = 1; i <= m; i++) {
		res.a[i] = yab[i] + xab[i - 1];
		res.a[i] %= mod;
		res.b[i] = asq[i] + bsq[i - 1];
		res.b[i] %= mod;
	}
	return res;
}
pvll pn(int x) {
	if (x == 1)return fstep();
	if (x % 2 == 1)return dstep(pn(x / 2));
	return step(pn(x - 1));
}
int main() {
	int n;
	scanf("%d%d", &n, &m);
	vector<long long int> p = pn(n).a;
	for (int i = 1; i <= m; i++)printf("%d ", (int)p[i]);
	return 0;
}