#include<bits/stdc++.h>
#define FOR(i, n, m) for(long long i = n; i < (int)m; i++)
#define REP(i, n) FOR(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define pb push_back
using namespace std;
using ll = std::int_fast64_t;
using ld = long double;
using P = pair<ll, ll>;
constexpr ll inf = 1000000000;
constexpr ll mod = 1000000007;
constexpr long double eps = 1e-15;
template<typename T1, typename T2>
ostream& operator<<(ostream& os, pair<T1, T2> p) {
	os << to_string(p.first) << " " << to_string(p.second);
	return os;
}
template<typename T>
ostream& operator<<(ostream& os, vector<T>& v) {
	REP(i, v.size()) {
		if(i) os << " ";
		os << to_string(v[i]);
	}
	return os;
}

/*
template<typename T>
struct Treap {
	double drand() { // random number in [0, 1]
		static random_device rd;
		static mt19937 mt(rd());
		return (unsigned)mt() / (double)numeric_limits<unsigned>::max();
	}
	T v;
	double p;
	int cnt;
	Treap* lch;
	Treap* rch;
	Treap(T v) : v(v), p(drand()), cnt(1), lch(NULL), rch(NULL) { }
	Treap* update() {
		this->size = size(this->lch) + size(this->rch) + 1;
		return this;
	}
	static int size(Treap* t) {
		if(!t) return 0;
		else return t->cnt;
	}
	static Treap* merge(Treap* l, Treap* r) {
		if(!l || !r) {
			if(!l) return r;
			else return l;
		}
		if(l->p >= r->p) {
			l->rch = merge(l->rch, r);
			return l->update();
		} else {
			r->lch = merge(r->lch, l);
			return r->update();
		}
	}
	static pair<Treap*, Treap*> split(Treap* t, int k) {
		// split [0, k) and [k, n)
		if(k == 0) return {NULL, t};
		if(!(t->l)) {
			auto tmp = split(t->r, k - 1);
			t->r = tmp.first;
			return {t->update(), tmp.second};
		} else if(!(t->r)) {
			auto tmp = split(t->r, k - 1);
			t->r = tmp.first;
			return {t->update(), tmp.second};
		} else {

		}
	}
	Treap* insert() {
	}
	Treap* erase() {
	}
	T operator[](int k) {
	}
};
*/

struct modint {
	ll n;
public:
	modint(const ll n = 0) : n((n % mod + mod) % mod) {}
	static modint pow(modint a, int m) {
		modint r = 1;
		while(m > 0) {
			if(m & 1) { r *= a; }
			a = (a * a); m /= 2;
		}
		return r;
	}
	modint &operator++() { *this += 1; return *this; }
	modint &operator--() { *this -= 1; return *this; }
	modint operator++(int) { modint ret = *this; *this += 1; return ret; }
	modint operator--(int) { modint ret = *this; *this -= 1; return ret; }
	modint operator~() const { return (this -> pow(n, mod - 2)); } // inverse
	friend bool operator==(const modint& lhs, const modint& rhs) {
		return lhs.n == rhs.n;
	}
	friend bool operator<(const modint& lhs, const modint& rhs) {
		return lhs.n < rhs.n;
	}
	friend bool operator>(const modint& lhs, const modint& rhs) {
		return lhs.n > rhs.n;
	}
	friend modint &operator+=(modint& lhs, const modint& rhs) {
		lhs.n += rhs.n;
		if (lhs.n >= mod) lhs.n -= mod;
		return lhs;
	}
	friend modint &operator-=(modint& lhs, const modint& rhs) {
		lhs.n -= rhs.n;
		if (lhs.n < 0) lhs.n += mod;
		return lhs;
	}
	friend modint &operator*=(modint& lhs, const modint& rhs) {
		lhs.n = (lhs.n * rhs.n) % mod;
		return lhs;
	}
	friend modint &operator/=(modint& lhs, const modint& rhs) {
		lhs.n = (lhs.n * (~rhs).n) % mod;
		return lhs;
	}
	friend modint operator+(const modint& lhs, const modint& rhs) {
		return modint(lhs.n + rhs.n);
	}
	friend modint operator-(const modint& lhs, const modint& rhs) {
		return modint(lhs.n - rhs.n);
	}
	friend modint operator*(const modint& lhs, const modint& rhs) {
		return modint(lhs.n * rhs.n);
	}
	friend modint operator/(const modint& lhs, const modint& rhs) {
		return modint(lhs.n * (~rhs).n);
	}
};
istream& operator>>(istream& is, modint m) { is >> m.n; return is; }
ostream& operator<<(ostream& os, modint m) { os << m.n; return os; }

using mi = modint;

mi calc(ll l1, ll r1, ll l2, ll r2, ll l3, ll r3) {
	mi c = (r1 - l1 + 1);
	c *= (r2 - l2 + 1);
	c *= (r3 - l3 + 1);
	mi d = 0;
	mi c1 = max(0ll, min(r2, r1) - max(l2, l1) + 1); c1 *= (r3 - l3 + 1);
	mi c2 = max(0ll, min(r3, r2) - max(l3, l2) + 1); c2 *= (r1 - l1 + 1);
	mi c3 = max(0ll, min({r3, r2, r1}) - max({l3, l2, l1}) + 1);
	d = c1 + c2 - c3;
	return (c - d) / c;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> l(n);
	vector<int> r(n);
	REP(i, n) cin >> l[i];
	REP(i, n) cin >> r[i];
	mi ans = 1;
	vector<mi> v(n - 1);
	REP(i, n - 1) {
		ll vl = max(l[i], l[i + 1]);
		ll vr = min(r[i], r[i + 1]);
		mi c = (r[i] - l[i] + 1); c *= (r[i + 1] - l[i + 1] + 1);
		v[i] = (c - max(0LL, vr - vl + 1)) / c;
		ans += 3 * v[i];
	}
	mi sum = 0;
	REP(i, n - 1) sum += v[i];
	REP(i, n - 1) {
		mi nsum = sum - v[i];
		if(i) nsum -= v[i - 1];
		if(i != n - 2) nsum -= v[i + 1];
		ans += v[i] * nsum;
		if(i) ans += calc(l[i - 1], r[i - 1], l[i], r[i], l[i + 1], r[i + 1]);
		if(i != n - 2) ans += calc(l[i], r[i], l[i + 1], r[i + 1], l[i + 2], r[i + 2]);
	}
	cout << ans << endl;
	return 0;
}
// ---------------------------------------