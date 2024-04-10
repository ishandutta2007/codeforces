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
	modnum neg() const {
		modnum res;
		res.v = v ? MOD-v : 0;
		return res;
	}
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

template <typename T, typename U> struct pairnum {
	T t;
	U u;

	pairnum() : t(0), u(0) {}
	pairnum(long long v) : t(v), u(v) {}
	pairnum(const T& t_, const U& u_) : t(t_), u(u_) {}

	friend std::ostream& operator << (std::ostream& out, const pairnum& n) { return out << '(' << n.t << ',' << ' ' << n.u << ')'; }
	friend std::istream& operator >> (std::istream& in, pairnum& n) { long long v; in >> v; n = pairnum(v); return in; }

	friend bool operator == (const pairnum& a, const pairnum& b) { return a.t == b.t && a.u == b.u; }
	friend bool operator != (const pairnum& a, const pairnum& b) { return a.t != b.t || a.u != b.u; }

	pairnum inv() const {
		return pairnum(t.inv(), u.inv());
	}
	pairnum neg() const {
		return pairnum(t.neg(), u.neg());
	}
	pairnum operator- () const {
		return pairnum(-t, -u);
	}
	pairnum operator+ () const {
		return pairnum(+t, +u);
	}

	pairnum& operator += (const pairnum& o) {
		t += o.t;
		u += o.u;
		return *this;
	}
	pairnum& operator -= (const pairnum& o) {
		t -= o.t;
		u -= o.u;
		return *this;
	}
	pairnum& operator *= (const pairnum& o) {
		t *= o.t;
		u *= o.u;
		return *this;
	}
	pairnum& operator /= (const pairnum& o) {
		t /= o.t;
		u /= o.u;
		return *this;
	}

	friend pairnum operator + (const pairnum& a, const pairnum& b) { return pairnum(a) += b; }
	friend pairnum operator - (const pairnum& a, const pairnum& b) { return pairnum(a) -= b; }
	friend pairnum operator * (const pairnum& a, const pairnum& b) { return pairnum(a) *= b; }
	friend pairnum operator / (const pairnum& a, const pairnum& b) { return pairnum(a) /= b; }
};

using num = modnum<int(1e9)+7>;
using hsh = pairnum<num, num>;

const int MAXN = 1.1e5;
const int MAXM = 1.1e6;
int N, M;
char S[MAXN];
int cnt[2];
char T[MAXM];

hsh BASE;
hsh basePow[MAXM];
hsh pref[MAXM];

hsh getRange(int a, int b) {
	assert(a <= b);
	return pref[b] - pref[a] * basePow[b-a];
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	mt19937 rng((unsigned long) chrono::steady_clock::now().time_since_epoch().count());
	BASE.t = int(rng());
	BASE.u = int(rng());

	cin >> S >> T;
	N = int(strlen(S));
	M = int(strlen(T));
	for (int i = 0; i < N; i++) {
		cnt[S[i] - '0'] ++;
	}
	assert(cnt[0] + cnt[1] == N);

	pref[0] = 0;
	for (int i = 0; i < M; i++) {
		pref[i+1] = pref[i] * BASE + hsh(T[i]);
	}
	basePow[0] = 1;
	for (int i = 0; i < M; i++) {
		basePow[i+1] = basePow[i] * BASE;
	}

	int res = 0;
	for (int c0 = 1; c0 <= M / cnt[0]; c0++) {
		int c1 = M - cnt[0] * c0;
		if (c1 == 0) continue;
		if (c1 % cnt[1] != 0) continue;
		c1 /= cnt[1];
		bool seen0 = false, seen1 = false;
		hsh V0, V1;
		bool good = true;
		for (int i = 0, cur = 0; i < N; i++) {
			if (S[i] == '0') {
				hsh val = getRange(cur, cur + c0);
				cur += c0;
				if (!seen0) {
					V0 = val, seen0 = true;
				}
				if (V0 != val) {
					good = false;
					break;
				}
			} else if (S[i] == '1'){
				hsh val = getRange(cur, cur + c1);
				cur += c1;
				if (!seen1) {
					V1 = val, seen1 = true;
				}
				if (V1 != val) {
					good = false;
					break;
				}
			} else assert(false);
		}
		if (!good) continue;
		assert(seen0 && seen1);
		if (c0 == c1 && V0 == V1) continue;
		res++;
	}
	cout << res << '\n';

	return 0;
}