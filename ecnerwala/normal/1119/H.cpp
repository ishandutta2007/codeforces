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

template <typename T> T pow(T a, long long b) {
	T r = 1;
	while (b) {
		if (b & 1) r *= a;
		a *= a;
		b >>= 1;
	}
	return r;
}

const int MAXN = 1.1e5;
const int MAXK = 18;

int N, K;
num X[3];
int A[MAXN][3];

int dp[1<<3][1<<MAXK];

num ans[1 << MAXK];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> K;
	cin >> X[0] >> X[1] >> X[2];
	for (int i = 0; i < N; i++) {
		cin >> A[i][0] >> A[i][1] >> A[i][2];
	}

	for (int m1 = 0; m1 < (1 << 3); m1++) {
		for (int i = 0; i < N; i++) {
			int x = 0;
			for (int z = 0; z < 3; z++) {
				if (m1 & (1 << z)) x ^= A[i][z];
			}
			dp[m1][x] ++;
		}
		for (int i = 0; i < K; i++) {
			for (int m = 0; m < (1 << K); m++) {
				if (m & (1 << i)) continue;
				int o = dp[m1][m | (1 << i)];
				dp[m1][m | (1 << i)] = dp[m1][m] - o;
				dp[m1][m] += o;
			}
		}
	}
	for (int m = 0; m < (1 << K); m++) {
		for (int z = 0; z < 3; z++) {
			for (int m1 = 0; m1 < (1 << 3); m1++) {
				if (m1 & (1 << z)) continue;
				int o = dp[m1 | (1 << z)][m];
				dp[m1 | (1 << z)][m] = dp[m1][m] - o;
				dp[m1][m] += o;
			}
		}
		for (int m1 = 0; m1 < (1 << 3); m1++) {
			dp[m1][m] /= 8;
		}
		num prod = 1;
		for (int m1 = 0; m1 < (1 << 3); m1++) {
			num v = 0;
			for (int z = 0; z < 3; z++) {
				if (m1 & (1 << z)) {
					v -= X[z];
				} else {
					v += X[z];
				}
			}
			//cerr << m << ' ' << m1 << ' ' << v << ' ' << dp[m1][m] << '\n';
			prod *= pow(v, dp[m1][m]);
		}
		//cerr << m << ' ' << prod << '\n';
		ans[m] = prod;
	}
	for (int i = 0; i < K; i++) {
		for (int m = 0; m < (1 << K); m++) {
			if (m & (1 << i)) continue;
			num o = ans[m | (1 << i)];
			ans[m | (1 << i)] = ans[m] - o;
			ans[m] += o;
		}
	}
	for (int m = 0; m < (1 << K); m++) {
		ans[m] /= num(1 << K);
	}
	for (int m = 0; m < (1 << K); m++) {
		cout << ans[m] << " \n"[m+1 == (1 << K)];
	}

	return 0;
}