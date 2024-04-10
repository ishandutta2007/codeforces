#include<bits/stdc++.h>
using namespace std;

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

using mnum = modnum<998245353>;
using hsh = pairnum<mnum, mnum>;
const hsh BASE = hsh(mnum(29), mnum(163));

struct range_data {
	int len = 0;
	hsh hashVal = 0;
	bool start1 = 0;
	bool end1 = 0;
	friend bool operator == (const range_data& a, const range_data& b) {
		return a.len == b.len && a.hashVal == b.hashVal && a.start1 == b.start1 && a.end1 == b.end1;
	}
	friend ostream& operator << (ostream& o, const range_data& r) {
		return o << '(' << r.len << ',' << r.hashVal << ',' << r.start1 << ',' << r.end1 << ')';
	}
};

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N; cin >> N;
	string T; cin >> T;
	assert(int(T.size()) == N);

	vector<hsh> basePows(N+1);
	basePows[0] = 1;
	for (int i = 0; i < N; i++) {
		basePows[i+1] = basePows[i] * BASE;
	}
	hsh baseInv = BASE.inv();

	auto merge = [&basePows, &baseInv](range_data a, range_data b) -> range_data {
		//cerr << "merge " << a << ' ' << b << '\n';
		range_data r;
		if (a.len && a.end1 && b.len && b.start1) {
			a.end1 = false;
			b.start1 = false;
			a.len--, b.len--;
			a.hashVal -= basePows[a.len];
			b.hashVal --;
			b.hashVal *= baseInv;
		}
		r.len = a.len + b.len;
		r.hashVal = a.hashVal + b.hashVal * basePows[a.len];
		r.start1 = a.len ? a.start1 : b.start1;
		r.end1 = b.len ? b.end1 : a.end1;
		//cerr << r << '\n';
		return r;
	};

	const int S = 1 << 18;
	vector<range_data> seg(2*S);

	for (int i = 0; i < N; i++) {
		bool v = T[i] - '0';
		seg[S+i] = range_data{1, hsh(v), v, v};
	}
	for (int i = S-1; i; i--) seg[i] = merge(seg[2*i+0], seg[2*i+1]);

	auto queryRange = [&](int l, int r) -> range_data {
		range_data lDat, rDat;
		for (int a = S+l, b = S+r; a < b; a /= 2, b /= 2) {
			if (a & 1) lDat = merge(lDat, seg[a++]);
			if (b & 1) rDat = merge(seg[--b], rDat);
		}
		range_data ans = merge(lDat, rDat);
		//cerr << l  << '-' << r << ' ' << ans << '\n';
		return ans;
	};

	int Q; cin >> Q;
	while (Q--) {
		int a, b, l; cin >> a >> b >> l;
		a--, b--;
		cout << (queryRange(a,a+l) == queryRange(b,b+l) ? "Yes" : "No") << '\n';
	}

	return 0;
}