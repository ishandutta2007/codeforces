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

const int MAXV = 4000;
num p2[MAXV+1];
num invp2[MAXV+1];
num p2min1[MAXV+1];
num invp2min1[MAXV+1];

void precomp() {
	p2[0] = 1;
	for (int i = 1; i <= MAXV; i++) {
		p2[i] = p2[i-1] + p2[i-1];
	}
	invp2[MAXV] = p2[MAXV].inv();
	for (int i = MAXV-1; i >= 0; i--) {
		invp2[i] = invp2[i+1] + invp2[i+1];
	}

	for (int i = 0; i <= MAXV; i++) {
		p2min1[i] = p2[i] - 1;
	}
	for (int i = 1; i <= MAXV; i++) {
		invp2min1[i] = p2min1[i].inv();
	}
}

const int MAXN = 4000;
int N;
int A[MAXN];

int C;

#pragma GCC diagnostic ignored "-Wsign-conversion"

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	precomp();

	cin >> N >> C;
	for (int i = 0; i < N; i++) { cin >> A[i], A[i] --; }

	vector<vector<num>> dp(N+1);
	dp[0] = vector<num>({num(1)});
	if (C > 10) {
		// c large
		for (int i = 0; i < N; i++) {
			vector<int> cnt(C);
			num ways = 1;
			int numBad = C-1;
			for (int j = i; j >= 0; j--) {
				if (A[j] != A[i]) {
					if (cnt[A[j]] == 0) {
						numBad --;
					} else {
						ways *= invp2min1[cnt[A[j]]];
					}
					++cnt[A[j]];
					ways *= p2min1[cnt[A[j]]];
				}

				if (numBad == 0) {
					if (dp[i+1].size() < dp[j].size() + 1) {
						dp[i+1].resize(dp[j].size() + 1, num(0));
					}
					for (int l = 0; l < int(dp[j].size()); l++) {
						dp[i+1][l+1] += ways * dp[j][l];
					}
				}

			}
		}
	} else {
		vector<vector<num>> dp2(1 << C);
		dp2[0] = vector<num>({num(1)});
		for (int i = 0; i < N; i++) {
			for (int m = (1 << C) - 1; m >= 0; m--) {
				if (dp2[m | (1 << A[i])].size() < dp2[m].size()) {
					dp2[m | (1 << A[i])].resize(dp2[m].size(), num(0));
				}
				for (int l = 0; l < int(dp2[m].size()); l++) {
					dp2[m | (1 << A[i])][l] += dp2[m][l];
				}
			}

			swap(dp[i+1], dp2[(1 << C) - 1]);
			dp[i+1].insert(dp[i+1].begin(), num(0));

			if (dp2[0].size() < dp[i+1].size()) {
				dp2[0].resize(dp[i+1].size(), num(0));
			}
			for (int l = 0; l < int(dp[i+1].size()); l++) {
				dp2[0][l] += dp[i+1][l];
			}
		}
	}

	vector<num> ans(N+1);
	for (int i = 0; i <= N; i++) {
		for (int l = 0; l < int(dp[i].size()); l++) {
			ans[l] += dp[i][l] * p2[N-i];
		}
	}
	ans[0] --;
	for (int i = 0; i < N; i++) {
		ans[i] -= ans[i+1];
	}
	for (int i = 0; i <= N; i++) {
		cout << ans[i] << " \n"[i==N];
	}

	return 0;
}