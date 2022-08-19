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
using num = modnum<998244353>;

const int MAXN = 1.1e6;
int N;
num fact[MAXN];
num ifact[MAXN];

string S;

int Q = 0;
num QBinPref[MAXN];
num Q1BinPref[MAXN];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> S;
	N = int(S.size());

	Q = 0;
	for (char c : S) {
		if (c == '?') Q++;
	}
	fact[0] = 1;
	for (int i = 1; i <= Q; i++) fact[i] = fact[i-1] * num(i);
	ifact[Q] = fact[Q].inv();
	for (int i = Q; i >= 1; i--) ifact[i-1] = ifact[i] * num(i);

	QBinPref[0] = 1;
	for (int i = 1; i <= Q; i++) {
		QBinPref[i] = QBinPref[i-1] + fact[Q] * ifact[i] * ifact[Q-i];
	}
	if (Q > 0) {
		Q1BinPref[0] = 1;
		for (int i = 1; i <= Q-1; i++) {
			Q1BinPref[i] = Q1BinPref[i-1] + fact[Q-1] * ifact[i] * ifact[Q-1-i];
		}
	}

	int pOpen = 0;
	int pQuestion = 0;
	int sClose = 0;
	int sQuestion = 0;

	for (char c : S) {
		if (c == '(') {
		} else if (c == ')') {
			sClose++;
		} else if (c == '?') {
			sQuestion++;
		} else assert(false);
	}
	num ans = 0;
	for (char c : S) {
		if (c == '(') {
		} else if (c == ')') {
			sClose--;
		} else if (c == '?') {
			sQuestion--;
		} else assert(false);

		if (c == '(' || c == '?') {
			pOpen++;

			assert(pQuestion + sQuestion == Q || pQuestion + sQuestion == Q-1);
			// pOpen + (opens from pQuestion) <= sClose + (closes from sQuestion)
			// (opens from pQuestion + opens from sQuestion) <= sClose + sQuestion - pOpen;
			int maxOpen = min(pQuestion + sQuestion, sClose + sQuestion - pOpen);
			if (maxOpen >= 0) {
				if (pQuestion + sQuestion == Q) ans += QBinPref[maxOpen];
				else if (pQuestion + sQuestion == Q-1) ans += Q1BinPref[maxOpen];
				else assert(false);
			}

			pOpen--;
		}

		if (c == '(') {
			pOpen++;
		} else if (c == ')') {
		} else if (c == '?') {
			pQuestion++;
		}
	}
	cout << ans << '\n';

	return 0;
}