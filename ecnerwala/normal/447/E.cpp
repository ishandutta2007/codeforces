#include<bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
template <typename T> int sz(const T& t) { return int(t.size()); }
template <typename T> void setmax(T& a, T b) { if (b > a) a = b; }
template <typename T> void setmin(T& a, T b) { if (b < a) a = b; }

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

template <typename U, typename V> struct pairnum {
	U u;
	V v;

	pairnum() : u(0), v(0) {}
	pairnum(long long val) : u(val), v(val) {}
	pairnum(const U& u_, const V& v_) : u(u_), v(v_) {}

	friend std::ostream& operator << (std::ostream& out, const pairnum& n) { return out << '(' << n.u << ',' << ' ' << n.v << ')'; }
	friend std::istream& operator >> (std::istream& in, pairnum& n) { long long val; in >> val; n = pairnum(val); return in; }

	friend bool operator == (const pairnum& a, const pairnum& b) { return a.u == b.u && a.v == b.v; }
	friend bool operator != (const pairnum& a, const pairnum& b) { return a.u != b.u || a.v != b.v; }

	pairnum inv() const {
		return pairnum(u.inv(), v.inv());
	}
	pairnum neg() const {
		return pairnum(u.neg(), v.neg());
	}
	pairnum operator- () const {
		return pairnum(-u, -v);
	}
	pairnum operator+ () const {
		return pairnum(+u, +v);
	}

	pairnum& operator ++ () {
		++u, ++v;
		return *this;
	}
	pairnum& operator -- () {
		--u, --v;
		return *this;
	}

	pairnum& operator += (const pairnum& o) {
		u += o.u;
		v += o.v;
		return *this;
	}
	pairnum& operator -= (const pairnum& o) {
		u -= o.u;
		v -= o.v;
		return *this;
	}
	pairnum& operator *= (const pairnum& o) {
		u *= o.u;
		v *= o.v;
		return *this;
	}
	pairnum& operator /= (const pairnum& o) {
		u /= o.u;
		v /= o.v;
		return *this;
	}

	friend pairnum operator ++ (pairnum& a, int) { pairnum r = a; ++a; return r; }
	friend pairnum operator -- (pairnum& a, int) { pairnum r = a; --a; return r; }
	friend pairnum operator + (const pairnum& a, const pairnum& b) { return pairnum(a) += b; }
	friend pairnum operator - (const pairnum& a, const pairnum& b) { return pairnum(a) -= b; }
	friend pairnum operator * (const pairnum& a, const pairnum& b) { return pairnum(a) *= b; }
	friend pairnum operator / (const pairnum& a, const pairnum& b) { return pairnum(a) /= b; }
};

using num = modnum<int(1e9)+9>;
using pnum = pairnum<num, num>;
num psum(pnum v) { return v.u + v.v; }

const pnum BASE = {308495997, 691504013};
const pnum FIBO = {861699207, 138300803};

using ll = long long;

const int MAXN = 3.1e5;

const int S = 1 << 19;
pnum pows[20];
pnum sumPows[20];

void precomp() {
	pows[0] = BASE;
	sumPows[0] = 1;
	for (int i = 1; i <= 19; i++) {
		pows[i] = pows[i-1] * pows[i-1];
		sumPows[i] = sumPows[i-1] * (pows[i-1] + 1);
	}
}

pnum lazy[2*S];
pnum seg[2*S];
void updateNode(int i) {
	seg[i] = lazy[i] * sumPows[__builtin_clz(i) - __builtin_clz(S)];
	if (i < S) seg[i] += seg[2*i] + seg[2*i+1];
}
void updateAll(int i) {
	for (int a = i; a; a /= 2) updateNode(a);
}

void propogateNode(int i) {
	if (i < S) {
		lazy[2*i+0] += lazy[i];
		lazy[2*i+1] += lazy[i] * pows[__builtin_clz(2*i) - __builtin_clz(S)];
		updateNode(2*i+0);
		updateNode(2*i+1);
		lazy[i] = 0;
	}
}
void propogateAll(int i) {
	if (!i) return;
	propogateAll(i/2);
	propogateNode(i);
}

void updateSuff(int l, pnum v) {
	propogateAll(S+l);
	for (int a = S+l, b = S+S; a < b; a /= 2, b /= 2) {
		if (a & 1) {
			lazy[a] += v;
			updateNode(a);
			v *= pows[__builtin_clz(a) - __builtin_clz(S)];
			a++;
		}
	}
	updateAll(S+l);
}

void updateRange(int l, int r) {
	updateSuff(l, FIBO);
	updateSuff(r, -FIBO * pow(BASE, r-l));
}

num query(int l, int r){
	propogateAll(S+l);
	propogateAll(S+r-1);

	pnum ans;
	for (int a = S+l, b = S+r; a < b; a /= 2, b /= 2) {
		if (a & 1) { ans += seg[a++]; }
		if (b & 1) { ans += seg[--b]; }
	}
	return psum(ans);
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	precomp();
	int N; cin >> N;
	int Q; cin >> Q;
	for (int i = 0; i < N; i++) {
		int a; cin >> a;
		lazy[S+i] += pnum(a, 0);
	}
	for (int a = 2*S-1; a; a--) updateNode(a);

	while (Q--) {
		int t, l, r; cin >> t >> l >> r; l--;
		if (t == 1) {
			updateRange(l, r);
		} else if (t == 2) {
			cout << query(l, r) << '\n';
		} else assert(false);
	}

	return 0;
}