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

const int MAXN = 600;

namespace perm {

num dp[MAXN][MAXN];

num solvePerm(vector<int> C) {
	int N = int(C.size());

	vector<int> vals = C;
	sort(vals.begin(), vals.end());
	assert(unique(vals.begin(), vals.end()) == vals.end());
	for (int i = 0; i < N; i++) {
		C[i] = int(lower_bound(vals.begin(), vals.end(), C[i]) - vals.begin()) + 1;
	}

	for (int i = 0; i <= N; i++) dp[i][i] = 1;

	for (int l = 1; l <= N; l++) {
		for (int i = 0, j = l; j <= N; i++, j++) {
			int m = int(min_element(C.begin()+i, C.begin()+j) - C.begin());
			num x = 0;
			for (int k = i; k <= m; k++) {
				x += dp[i][k] * dp[k][m];
			}
			num y = 0;
			for (int k = m+1; k <= j; k++) {
				y += dp[m+1][k] * dp[k][j];
			}
			dp[i][j] = x * y;
		}
	}

	return dp[0][N];
}

} // namespace perm

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N, M; cin >> N >> M;
	vector<int> C(M);
	for (int i = 0; i < M; i++) {
		cin >> C[i];
	}

	cout << perm::solvePerm(C) << '\n';

	return 0;
}