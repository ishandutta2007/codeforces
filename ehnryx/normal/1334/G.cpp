#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

//#define FILENAME sadcactus

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef complex<ld> pt;

constexpr char nl = '\n';
constexpr ll INF = 0x3f3f3f3f;
constexpr ll INFLL = 0x3f3f3f3f3f3f3f3f;
constexpr ll MOD = 998244353;
constexpr ld EPS = 1e-9L;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

constexpr ld PI = acosl((ld)-1);

typedef complex<ld> C;
typedef vector<ld> vd;
void fft(vector<C>& a) {
	int n = a.size(), L = 31 - __builtin_clz(n);
	static vector<complex<ld>> R(2, 1);
	static vector<C> rt(2, 1);  // (^ 10% faster if double)
	for (static int k = 2; k < n; k *= 2) {
		R.resize(n); rt.resize(n);
		auto x = polar(1.0L, PI / k);
    for (int i=k; i<2*k; i++) rt[i] = R[i] = i&1 ? R[i/2] * x : R[i/2];
	}
	vector<int> rev(n);
  for (int i = 0; i < n; i++) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
  for (int i = 0; i < n; i++) if (i < rev[i]) swap(a[i], a[rev[i]]);
	for (int k = 1; k < n; k *= 2)
		for (int i = 0; i < n; i += 2 * k) for (int j = 0; j < k; j++) {
			// C z = rt[j+k] * a[i+j+k]; // (25% faster if hand-rolled)  /// include-line
			auto x = (ld *)&rt[j+k], y = (ld *)&a[i+j+k];        /// exclude-line
			C z(x[0]*y[0] - x[1]*y[1], x[0]*y[1] + x[1]*y[0]);           /// exclude-line
			a[i + j + k] = a[i + j] - z;
			a[i + j] += z;
		}
}
vd conv(const vd& a, const vd& b) {
	if (a.empty() || b.empty()) return {};
	vd res(a.size() + b.size() - 1);
	int L = 32 - __builtin_clz(res.size()), n = 1 << L;
	vector<C> in(n), out(n);
	copy(a.begin(), a.end(), in.begin());
  for (int i = 0; i < b.size(); i++) in[i].imag(b[i]);
	fft(in);
  for (auto& x : in) x *= x;
  for (int i = 0; i < n; i++) out[i] = in[-i & (n - 1)] - conj(in[i]);
	fft(out);
  for (int i = 0; i < res.size(); i++) res[i] = imag(out[i]) / (4 * n);
	return res;
}

// double-check correctness
// read limits carefully
// characterize valid solutions
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cout << fixed << setprecision(10);
#if defined(ONLINE_JUDGE) && defined(FILENAME)
  freopen(FILENAME ".in", "r", stdin);
  freopen(FILENAME ".out", "w", stdout);
#endif

	static const int M = 26;
	vector<int> p(M);
  vector<int> remap(M);
  iota(remap.begin(), remap.end(), 0);
	for(int i=0; i<M; i++) {
		cin >> p[i];
		p[i] = remap[p[i] - 1];
	}


	string S, T;
	cin >> S >> T;
	int n = S.size();
	int m = T.size();
	vector<int> s(n), t(m);
	for(int i=0; i<n; i++) s[i] = remap[S[i] - 'a'];
	for(int i=0; i<m; i++) t[i] = remap[T[i] - 'a'];
	reverse(s.begin(), s.end());

	vector<ll> res(n+m-1);
	vd a(n), b(m), c;
	ll sum = 0;

	// (s^2 * p^2) * t^0
	for(int i=0; i<n; i++) {
		sum += s[i]*s[i] * p[s[i]]*p[s[i]];
	}

	// -2 * (s^2 * p + s * p^2) * t^1
	for(int i=0; i<n; i++) {
		a[i] = s[i]*s[i] * p[s[i]] + s[i] * p[s[i]]*p[s[i]];
	}
	for(int i=0; i<m; i++) {
		b[i] = t[i];
	}
	c = conv(a, b);
	for(int i=0; i<n+m-1; i++) {
		res[i] += -2 * llround(c[i]);
	}

	// (4*s*p + s^2 + p^2) * t^2
	for(int i=0; i<n; i++) {
		a[i] = 4*s[i]*p[s[i]] + s[i]*s[i] + p[s[i]]*p[s[i]];
	}
	for(int i=0; i<m; i++) {
		b[i] = t[i]*t[i];
	}
	c = conv(a, b);
	for(int i=0; i<n+m-1; i++) {
		res[i] += llround(c[i]);
	}

	// -2 * (s + p) * t^3
	for(int i=0; i<n; i++) {
		a[i] = s[i] + p[s[i]];
	}
	for(int i=0; i<m; i++) {
		b[i] = t[i]*t[i]*t[i];
	}
	c = conv(a, b);
	for(int i=0; i<n+m-1; i++) {
		res[i] += -2 * llround(c[i]);
	}

	// 1 * t^4
	vector<ll> pref(m+1);
	for(int i=0; i<m; i++) {
		pref[i+1] = pref[i] + t[i]*t[i]*t[i]*t[i];
	}

	// output
	for(int i=n-1; i<m; i++) {
		ll val = res[i] + sum + pref[i+1] - pref[i-n+1];
		cout << !val;
	}
	cout << nl;

  return 0;
}