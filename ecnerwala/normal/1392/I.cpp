#include<bits/stdc++.h>

namespace fft {
using namespace std;
const double PI = std::atan2(0, -1);
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

// FFT
using dbl = double;
struct num { /// start-hash
	dbl x, y;
	num(dbl x_ = 0, dbl y_ = 0) : x(x_), y(y_) { }
};
inline num operator+(num a, num b) { return num(a.x + b.x, a.y + b.y); }
inline num operator-(num a, num b) { return num(a.x - b.x, a.y - b.y); }
inline num operator*(num a, num b) { return num(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x); }
inline num conj(num a) { return num(a.x, -a.y); }
inline num inv(num a) { dbl n = (a.x*a.x+a.y*a.y); return num(a.x/n,-a.y/n); }
/// end-hash

using vn = vector<num>;
vi rev({0, 1});
vn rt(2, num(1)), fa, fb;

inline void init(int n) { /// start-hash
	if (n <= sz(rt)) return;
	rev.resize(n);
	rep(i,0,n) rev[i] = (rev[i>>1] | ((i&1)*n)) >> 1;
	rt.reserve(n);
	for (int k = sz(rt); k < n; k *= 2) {
		rt.resize(2*k);
		double a=PI/k; num z(cos(a),sin(a)); // FFT
		rep(i,k/2,k) rt[2*i] = rt[i], rt[2*i+1] = rt[i]*z;
	}
} /// end-hash

inline void fft(vector<num> &a, int n) { /// start-hash
	init(n);
	int s = __builtin_ctz(sz(rev)/n);
	rep(i,0,n) if (i < rev[i]>>s) swap(a[i], a[rev[i]>>s]);
	for (int k = 1; k < n; k *= 2)
		for (int i = 0; i < n; i += 2 * k) rep(j,0,k) {
			num t = rt[j+k] * a[i+j+k];
			a[i+j+k] = a[i+j] - t;
			a[i+j] = a[i+j] + t;
		}
} /// end-hash

// Double multiply (num = complex)
using vd = vector<double>;
vd multiply(const vd& a, const vd& b) { /// start-hash
	int s = sz(a) + sz(b) - 1;
	if (s <= 0) return {};
	int L = s > 1 ? 32 - __builtin_clz(s-1) : 0, n = 1 << L;
	if (sz(fa) < n) fa.resize(n);
	if (sz(fb) < n) fb.resize(n);

	fill(fa.begin(), fa.begin() + n, 0);
	rep(i,0,sz(a)) fa[i].x = a[i];
	rep(i,0,sz(b)) fa[i].y = b[i];
	fft(fa, n);
	trav(x, fa) x = x * x;
	rep(i,0,n) fb[i] = fa[(n-i)&(n-1)] - conj(fa[i]);
	fft(fb, n);
	vd r(s);
	rep(i,0,s) r[i] = fb[i].y / (4*n);
	return r;
} /// end-hash

} // namespace fft

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	array<int, 2> N; int Q; cin >> N[0] >> N[1] >> Q;
	array<vector<int>, 2> A;
	for (int z = 0; z < 2; z++) {
		A[z].resize(N[z]);
		for (int& v : A[z]) cin >> v;
	}
	vector<int> queries(Q); for (auto& q : queries) cin >> q;

	const int X = int(1e5) + 100;

	array<vector<double>, 2> mults;
	for (int z = 0; z < 2; z++) {
		mults[z].assign(X, 0);

		for (int i = 0; i+1 < N[z]; i++) {
			mults[z][min(A[z][i], A[z][i+1])]--;
			mults[z][max(A[z][i], A[z][i+1])]++;
		}
	}

	vector<long long> ans(2 * X - 1);
	vector<double> ans_double = fft::multiply(mults[0], mults[1]);
	for (int i = 0; i < 2 * X - 1; i++) {
		ans[i] = ((ans_double[i] > 0) - (ans_double[i] < 0)) * (long long)(abs(ans_double[i]) + 0.5);
	}
	for (int a : {A[0].front(), A[0].back()}) {
		for (int b : {A[1].front(), A[1].back()}) {
			ans[a+b]++;
		}
	}

	for (int i = 2 * X - 3; i >= 0; i--) {
		ans[i] += ans[i+1];
	}
	long long tot = ans[0];
	for (auto& a : ans) {
		a = 2 * a - tot;
		a /= 4;
	}

	for (int q : queries) {
		cout << ans[q] << '\n';
	}

	return 0;
}