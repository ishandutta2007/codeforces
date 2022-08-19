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
using num = modnum<int(1e9)+7>;

using ll = long long;

ll N;
int K;
vector<pair<ll, int>> exps;
const int MAXE = 200;
num choose[MAXE]; // K + i choose i

num dp[MAXE];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> K;

	choose[0] = 1;
	for (int i = 1; i < MAXE; i++) {
		choose[i] = choose[i-1] * num(K+i) / num(i);
	}

	for (ll p = 2; p*p <= N; p++) {
		if (N % p == 0) {
			int e = 0;
			while (N % p == 0) {
				N /= p;
				e ++;
			}
			exps.emplace_back(p, e);
		}
	}
	if (N > 1) {
		ll p = N;
		exps.emplace_back(p, 1);
		N /= p;
		assert(N == 1);
	}

	num res = 1;
	for (auto it : exps) {
		ll p = it.first;
		int e = it.second;
		dp[0] = 1;
		for (int i = 1; i <= e; i++) dp[i] = dp[i-1] * num(p);

		for (int z = 0; z < K; z++) {
			for (int i = e; i >= 0; i--) {
				num val = 0;
				for (int j = 0; j <= i; j++) {
					val += dp[j];
				}
				dp[i] = val / num(i+1);
			}
		}

		res *= dp[e];
	}
	cout << res << '\n';

	return 0;
}