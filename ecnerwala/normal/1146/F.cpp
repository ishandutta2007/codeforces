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

const int MAXN = 3e5;
int N;
int P[MAXN];
vector<int> ch[MAXN];
num dp[MAXN][2];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	P[1] = 0;
	for (int i = 2; i <= N; i++) {
		cin >> P[i];
	}

	for (int i = 1; i <= N; i++) {
		ch[P[i]].push_back(i);
	}

	for (int i = N; i >= 1; i--) {
		if (ch[i].empty()) {
			dp[i][0] = dp[i][1] = num(1);
		} else {
			num tot = 1;
			for (int j : ch[i]) {
				tot *= dp[j][0] + dp[j][1];
			}
			int numZero = 0;
			num useNone = 1;
			for (int j : ch[i]) {
				if (dp[j][0] == 0) {
					numZero++;
				} else {
					useNone *= dp[j][0];
				}
			}
			// use is take at least 1
			dp[i][1] = tot - useNone * (numZero ? num(0) : num(1));

			num useOne = 0;
			for (int j : ch[i]) {
				if (dp[j][0] == 0) {
					useOne += dp[j][1] * ((numZero - 1) ? num(0) : num(1)) * useNone;
				} else {
					useOne += dp[j][1] * (numZero ? num(0) : num(1)) * (useNone / dp[j][0]);
				}
			}

			// don't use is take none or >= 2
			dp[i][0] = tot - useOne;
		}
	}
	cout << dp[1][0] << '\n';

	return 0;
}