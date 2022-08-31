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

const int MAXL = 4000;
int L[2];
bool used[2][MAXL];
int N;
int F[2];

num numWays[2][MAXL];

num dp[MAXL][2]; // last one is used or free

num fact[MAXL];
num ifact[MAXL];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	fact[0] = 1;
	for (int i = 1; i < MAXL; i++) {
		fact[i] = fact[i-1] * num(i);
	}
	ifact[MAXL-1] = fact[MAXL-1].inv();
	for (int i = MAXL - 1; i > 0; i--) {
		ifact[i-1] = ifact[i] * num(i);
	}

	cin >> L[0] >> L[1] >> N;
	used[0][0] = used[1][0] = used[0][L[0]+1] = used[1][L[1]+1] = true;
	for (int i = 0; i < N; i++) {
		int r1, c1, r2, c2;
		cin >> r1 >> c1 >> r2 >> c2;
		used[0][r1] = used[1][c1] = used[0][r2] = used[1][c2] = true;
	}

	for (int z = 0; z < 2; z++) {
		F[z] = 0;
		for (int i = 1; i <= L[z]; i++) {
			F[z] += !used[z][i];
		}

		memset(dp, 0, sizeof(dp));

		dp[0][1] = 1;

		for (int i = 1; i <= L[z]; i++) {
			if (used[z][i]) {
				for (int c = 0; c <= F[z]; c++) {
					dp[c][1] = dp[c][1] + dp[c][0];
					dp[c][0] = 0;
				}
			} else {
				for (int c = F[z]; c >= 0; c--) {
					dp[c][0] = dp[c][1] + dp[c][0];
					dp[c][1] = c > 0 ? dp[c-1][0] : 0;
				}
			}
		}
		for (int c = 0; c <= F[z]; c++) {
			numWays[z][c] = dp[c][0] + dp[c][1];
		}
	}

	num ans = 0;
	for (int a = 0; a <= F[0]; a++) {
		for (int b = 0; b <= F[1]; b++) {
			if (2 * a + b <= F[0] && 2 * b + a <= F[1]) {
				ans += numWays[0][a] * numWays[1][b] * fact[F[1] - 2 * b] * ifact[F[1] - 2 * b - a] * fact[F[0] - 2 * a] * ifact[F[0] - 2 * a - b];
			}
		}
	}
	cout << ans << '\n';

	return 0;
}