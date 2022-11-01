#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
typedef long long int ll;

const int maxn = 200010;

typedef complex<double> C;
void fft(vector <C> &a) {
	int n = a.size(), L = 31 - __builtin_clz(n);
	static vector <complex <long double> > R(2, 1);
	static vector <C> rt(2, 1);  // (^ 10% faster if double)
	for(static int k = 2; k < n; k *= 2) {
		R.resize(n); rt.resize(n);
		auto x = polar(1.0L, acos(-1.0L) / k);
		for(int i = k; i < 2 * k; ++i) rt[i] = R[i] = i & 1 ? R[i/2] * x : R[i/2];
	}
	vector <int> rev(n);
	for(int i = 0; i < n; ++i) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
	for(int i = 0; i < n; ++i) if(i < rev[i]) swap(a[i], a[rev[i]]);
	for(int k = 1; k < n; k *= 2)
		for(int i = 0; i < n; i += 2 * k) for(int j = 0; j < k; ++j) {
			 //C z = rt[j+k] * a[i+j+k]; // (25% faster if hand-rolled)  /// include-line
			auto x = (double *)&rt[j+k], y = (double *)&a[i+j+k];        /// exclude-line
			C z(x[0]*y[0] - x[1]*y[1], x[0]*y[1] + x[1]*y[0]);           /// exclude-line
			a[i + j + k] = a[i + j] - z;
			a[i + j] += z;
		}
}
vector <double> mult_pol(const vector <double> &a, const vector <double> &b) {
	if (a.empty() || b.empty()) return {};
	vector <double> res(a.size() + b.size() - 1);
	int L = 32 - __builtin_clz(res.size()), n = 1 << L;
	vector<C> in(n), out(n);
	copy(begin(a), end(a), begin(in));
	for(int i = 0; i < (int)b.size(); ++i) in[i].imag(b[i]);
	fft(in);
	for(C& x : in) x *= x;
	for(int i=0;i<n;++i) out[i] = in[-i & (n - 1)] - conj(in[i]);
	fft(out);
	for(int i = 0; i < (int)res.size(); ++i) res[i] = imag(out[i]) / (4 * n);
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, x, t, kolko = 1, suma = 0;
	ll prvi = 0;
	cin >> n >> x;
	vector <double> a(2 * maxn, 0), b(2 * maxn, 0);
	REP(i, n) {
		cin >> t;
		if(t >= x) kolko++;
		else {
			a[suma] = kolko;
			b[maxn - suma] = kolko;
			prvi += (ll) kolko * (kolko - 1) / 2;
			kolko = 1;
			suma++;
		}
	}
	a[suma] = kolko;
	b[maxn - suma] = kolko;
	prvi += (ll) kolko * (kolko - 1) / 2;
	a = mult_pol(a, b);
	cout << prvi << " ";
	for(int i = maxn + 1; i <= maxn + n; i++) cout << llabs(round(a[i])) << " ";
	cout << endl;
	return 0;
}