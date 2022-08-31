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
const int N = 7;
num P[N][N];

vector<int> msks[N+1];
int ind[1<<N];

uint64_t trans[1<<N][1<<N];

num pnext[1 << N];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	{ // process input, pad up to N
		int n; cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> P[i][j];
				P[i][j] /= num(100);
			}
		}
		// pad with guaranteed edges
		for (int i = n; i < N; i++) {
			P[i][i] = 1;
		}
	}

	for (int m = 0; m < (1 << N); m++) {
		int l = __builtin_popcount(m);
		ind[m] = int(msks[l].size());
		msks[l].push_back(m);
	}
	for (int nxt = 0; nxt < (1 << N); nxt++) {
		for (int m = 0; m < (1 << N); m++) {
			for (int i = 0; i < N; i++) {
				if ((nxt & (1 << i)) && !(m & (1 << i))) {
					trans[nxt][m] |= (1ull << ind[m | (1 << i)]);
				}
			}
		}
	}

	unordered_map<uint64_t, num> dp;
	dp[1] ++;
	for (int l = 0; l < N; l++) {
		for (int nxt = 0; nxt < (1 << N); nxt++) {
			pnext[nxt] = 1;
			for (int i = 0; i < N; i++) {
				if (nxt & (1 << i)) {
					pnext[nxt] *= P[l][i];
				} else {
					pnext[nxt] *= 1-P[l][i];
				}
			}
		}
		unordered_map<uint64_t, num> ndp;
		for (int nxt = 0; nxt < (1 << N); nxt++) {
			for (auto it : dp) {
				uint64_t pos = it.first;
				uint64_t npos = 0;
				for (int i = 0; i < int(msks[l].size()); i++) {
					if (pos & (1ull << i)) {
						npos |= trans[nxt][msks[l][i]];
					}
				}
				ndp[npos] += it.second * pnext[nxt];
			}
		}
		dp = std::move(ndp);
	}
	cout << dp[1] << '\n';

	return 0;
}