#include<bits/stdc++.h>

namespace std {

template<class Fun>
class y_combinator_result {
	Fun fun_;
public:
	template<class T>
	explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

	template<class ...Args>
	decltype(auto) operator()(Args &&...args) {
		return fun_(std::ref(*this), std::forward<Args>(args)...);
	}
};

template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
	return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

} // namespace std

template <int MOD_> struct modnum {
	static constexpr int MOD = MOD_;
	static_assert(MOD_ > 0, "MOD must be positive");

private:
	using ll = long long;

	int v;

	static int minv(int a, int m) {
		a %= m;
		assert(a);
		return a == 1 ? 1 : int(m - ll(minv(m, a)) * ll(m) / a);
	}

public:

	modnum() : v(0) {}
	modnum(ll v_) : v(int(v_ % MOD)) { if (v < 0) v += MOD; }
	explicit operator int() const { return v; }
	friend std::ostream& operator << (std::ostream& out, const modnum& n) { return out << int(n); }
	friend std::istream& operator >> (std::istream& in, modnum& n) { ll v_; in >> v_; n = modnum(v_); return in; }

	friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
	friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }

	modnum inv() const {
		modnum res;
		res.v = minv(v, MOD);
		return res;
	}
	friend modnum inv(const modnum& m) { return m.inv(); }
	modnum neg() const {
		modnum res;
		res.v = v ? MOD-v : 0;
		return res;
	}
	friend modnum neg(const modnum& m) { return m.neg(); }

	modnum operator- () const {
		return neg();
	}
	modnum operator+ () const {
		return modnum(*this);
	}

	modnum& operator ++ () {
		v ++;
		if (v == MOD) v = 0;
		return *this;
	}
	modnum& operator -- () {
		if (v == 0) v = MOD;
		v --;
		return *this;
	}
	modnum& operator += (const modnum& o) {
		v += o.v;
		if (v >= MOD) v -= MOD;
		return *this;
	}
	modnum& operator -= (const modnum& o) {
		v -= o.v;
		if (v < 0) v += MOD;
		return *this;
	}
	modnum& operator *= (const modnum& o) {
		v = int(ll(v) * ll(o.v) % MOD);
		return *this;
	}
	modnum& operator /= (const modnum& o) {
		return *this *= o.inv();
	}

	friend modnum operator ++ (modnum& a, int) { modnum r = a; ++a; return r; }
	friend modnum operator -- (modnum& a, int) { modnum r = a; --a; return r; }
	friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
	friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
	friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }
	friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= b; }
};

template <typename T> T pow(T a, long long b) {
	assert(b >= 0);
	T r = 1; while (b) { if (b & 1) r *= a; b >>= 1; a *= a; } return r;
}

using num = modnum<998244353>;

namespace book {
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define FFT 0
namespace fft {
// NTT
const int mod = 998244353, g = 3;

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
		num z = pow(num(g), (mod-1)/(2*k)); // NTT
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

// Complex/NTT
vn multiply(vn a, vn b) { /// start-hash
	int s = sz(a) + sz(b) - 1;
	if (s <= 0) return {};
	int L = s > 1 ? 32 - __builtin_clz(s-1) : 0, n = 1 << L;
	a.resize(n), b.resize(n);
	fft(a, n);
	fft(b, n);
	num d = inv(num(n));
	rep(i,0,n) a[i] = a[i] * b[i] * d;
	reverse(a.begin()+1, a.end());
	fft(a, n);
	a.resize(s);
	return a;
} /// end-hash

// Complex/NTT power-series inverse
// Doubles b as b[:n] = (2 - a[:n] * b[:n/2]) * b[:n/2]
vn inverse(const vn& a) { /// start-hash
	if (a.empty()) return {};
	vn b({inv(a[0])});
	b.reserve(2*a.size());
	while (sz(b) < sz(a)) {
		int n = 2*sz(b);
		b.resize(2*n, 0);
		if (sz(fa) < 2*n) fa.resize(2*n);
		fill(fa.begin(), fa.begin()+2*n, 0);
		copy(a.begin(), a.begin()+min(n,sz(a)), fa.begin());
		fft(b, 2*n);
		fft(fa, 2*n);
		num d = inv(num(2*n));
		rep(i, 0, 2*n) b[i] = b[i] * (2 - fa[i] * b[i]) * d;
		reverse(b.begin()+1, b.end());
		fft(b, 2*n);
		b.resize(n);
	}
	b.resize(a.size());
	return b;
} /// end-hash

#if FFT
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

// Integer multiply mod m (num = complex) /// start-hash
vi multiply_mod(const vi& a, const vi& b, int m) {
	int s = sz(a) + sz(b) - 1;
	if (s <= 0) return {};
	int L = s > 1 ? 32 - __builtin_clz(s-1) : 0, n = 1 << L;
	if (sz(fa) < n) fa.resize(n);
	if (sz(fb) < n) fb.resize(n);

	rep(i,0,sz(a)) fa[i] = num(a[i] & ((1<<15)-1), a[i] >> 15);
	fill(fa.begin()+sz(a), fa.begin() + n, 0);
	rep(i,0,sz(b)) fb[i] = num(b[i] & ((1<<15)-1), b[i] >> 15);
	fill(fb.begin()+sz(b), fb.begin() + n, 0);

	fft(fa, n);
	fft(fb, n);
	double r0 = 0.5 / n; // 1/2n
	rep(i,0,n/2+1) {
		int j = (n-i)&(n-1);
		num g0 = (fb[i] + conj(fb[j])) * r0;
		num g1 = (fb[i] - conj(fb[j])) * r0;
		swap(g1.x, g1.y); g1.y *= -1;
		if (j != i) {
			swap(fa[j], fa[i]);
			fb[j] = fa[j] * g1;
			fa[j] = fa[j] * g0;
		}
		fb[i] = fa[i] * conj(g1);
		fa[i] = fa[i] * conj(g0);
	}
	fft(fa, n);
	fft(fb, n);
	vi r(s);
	rep(i,0,s) r[i] = int((ll(fa[i].x+0.5)
				+ (ll(fa[i].y+0.5) % m << 15)
				+ (ll(fb[i].x+0.5) % m << 15)
				+ (ll(fb[i].y+0.5) % m << 30)) % m);
	return r;
} /// end-hash
#endif

} // namespace fft

// For multiply_mod, use num = modnum, poly = vector<num>
using poly = fft::vn;
using fft::multiply;
using fft::inverse;
/// start-hash
poly& operator+=(poly& a, const poly& b) {
	if (sz(a) < sz(b)) a.resize(b.size());
	rep(i,0,sz(b)) a[i]=a[i]+b[i];
	return a;
}
poly operator+(const poly& a, const poly& b) { poly r=a; r+=b; return r; }
poly& operator-=(poly& a, const poly& b) {
	if (sz(a) < sz(b)) a.resize(b.size());
	rep(i,0,sz(b)) a[i]=a[i]-b[i];
	return a;
}
poly operator-(const poly& a, const poly& b) { poly r=a; r-=b; return r; }
poly operator*(const poly& a, const poly& b) {
	// TODO: small-case?
	return multiply(a, b);
}
poly& operator*=(poly& a, const poly& b) {return a = a*b;}
/// end-hash
poly& operator*=(poly& a, const num& b) { // Optional
	trav(x, a) x = x * b;
	return a;
}
poly operator*(const poly& a, const num& b) { poly r=a; r*=b; return r; }
}

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int N; cin >> N;
	vector<int> a(N);
	for (int i = 0; i < N; i++) cin >> a[i];
	int A = accumulate(a.begin(), a.end(), 0);

	vector<num> fact(A+1);
	fact[0] = 1;
	for (int i = 1; i <= A; i++) fact[i] = fact[i-1] * num(i);
	vector<num> ifact(A+1);
	ifact[A] = inv(fact[A]);
	for (int i = A; i >= 1; i--) ifact[i-1] = ifact[i] * num(i);
	auto choose = [&](int n, int r) -> num { if(0 <= r && r <= n) return fact[n] * ifact[r] * ifact[n-r]; else return 0; };

	num invN = inv(num(N));
	vector<num> pInvN(A+1);
	pInvN[0] = 1;
	for (int i = 1; i <= A; i++) pInvN[i] = pInvN[i-1] * invN;

	vector<num> p1N(A+1);
	p1N[0] = 1;
	for (int i = 1; i <= A; i++) p1N[i] = p1N[i-1] * num(1-N);

	// do the multiplication
	vector<num> cntS(A+1);
	for (int i = 0; i < N; i++) {
		for (int v = 0; v <= a[i]; v++) {
			cntS[v] += choose(a[i], v);
		}
	}

	// let z = (-e^(-x/(n-1))) and y = e^x
	// we have sum cntS[v] * (-z)^(v) (1/n y + 1/n z)^(A-v)
	for (int v = 0; v <= A; v++) {
		if (v & 1) cntS[v] *= -1;
		cntS[v] *= pInvN[A-v];
	}

	// now we have sum cntS[v] z^(v) (y + z)^(A-v)
	reverse(cntS.begin(), cntS.end());
	// now we have sum cntS[v] (y + z)^v z^(A-v)
	// = sum_u (y)^u z^(A-u) / u! * cntS[v] * v! / (v-u)!

	vector<num> numerByY(A+1);
	{
		using namespace book;
		poly lhs(A+1);
		for (int v = 0; v <= A; v++) lhs[v] = cntS[v] * fact[v];
		poly rhs(A+1);
		for (int v = 0; v <= A; v++) rhs[v] = ifact[A-v];

		poly res = lhs * rhs;
		for (int v = 0; v <= A; v++) {
			numerByY[v] = res[A+v] * ifact[v];
		}
	}

	//for (int v = 0; v <= A; v++) { cerr << numerByY[v] << '\n'; }

	vector<num> denomByY(A+1);
	for (int v = 0; v <= A; v++) {
		denomByY[v] = choose(A, v) * pInvN[A] * (num(N-1) + p1N[A-v]);
	}
	//for (int v = 0; v <= A; v++) { cerr << denomByY[v] << '\n'; }

	for (int v = 0; v <= A; v++) {
		if (v & 1) {
			numerByY[v] *= -1;
			denomByY[v] *= -1;
		}
	}

	vector<num> bases(A+1);
	for (int v = 0; v <= A; v++) {
		// the term is (v - (A-v)/(n-1))x
		bases[v] = v - num(A-v) / num(N-1);
		bases[v] /= num(A);
	}

	//for (int v = 0; v <= A; v++) { cerr << bases[v] << '\n'; }
	assert(bases[A] == 1);
	auto eval = [&](const vector<num>& coeff) {
		return coeff[A];
	};
	auto deriv = [&](const vector<num>& coeff) {
		num ans = 0;
		for (int v = 0; v < A; v++) {
			// derivative of coeff[v] (1-x) / (1-bases[v]x)
			ans -= coeff[v] / (1 - bases[v]);
		}
		return ans;
	};

	num ans = deriv(numerByY) * eval(denomByY) - eval(numerByY) * deriv(denomByY);
	ans /= eval(denomByY);
	ans /= eval(denomByY);

	cout << ans << '\n';

	return 0;
}

// probability that a biscuit starts at a and ends at b after k moves is / (n-1)^k
//
// Let d_k = prob to get to b != a in k moves

// d_0 = 0
// d_1 = 1/(n-1)
// d_2 = (n-2) / (n-1)^2

// d_k = (n-2) / (n-1) * d_(k-1) + (1 - (n-1) * d_(k-1)) / (n-1)
// d_k = 1/(n-1) - d_(k-1) / (n-1)

// d_k = (1 - (-1/(n-1))^k) / n

// DE(x) = 1/n e^x - 1/n e^(-x/(n-1))
// SE(x) = 1/n e^x + (n-1)/n e^(-x/(n-1))
// SE(x) = DE(x) + e^(-x/(n-1))
//
// EE(x) = (n-1) * DE(x)^A + SE(x)^A
//
// P(x) = (sum un_exp(DE(x)^A-a_i SE(x)^a_i)) / E(x)

// v_t = sum_{sum k_i = t} prod w_k