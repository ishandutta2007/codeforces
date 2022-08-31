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

const int MAXN = 1.1e5;
const int MAXK = 220;

int N, K;
vector<int> adj[MAXN];

num fact[MAXK];
num ipow2[MAXN];

// size in vertices
int sz[MAXN];
num dp[MAXN][MAXK];

num tots[MAXK];

void dfs(int cur, int prv = 0) {
	sz[cur] = 1;
	dp[cur][0] = 1;

	for (int nxt : adj[cur]) {
		if (nxt == prv) continue;
		dfs(nxt, cur);

		// loop one: add in using this edge
		for (int k = min(sz[nxt]-1, K-1); k >= 0; k--) {
			num val = dp[nxt][k];
			if (k == 0) {
				val *= (1 - ipow2[sz[nxt]]);
			}

			// special case: if this is the root, we can call it a day
			tots[k+1] += val * (1 - ipow2[N-sz[nxt]]);

			dp[nxt][k+1] += val;
		}
		assert(dp[nxt][0] == 1);
		// loop 2: use something from this subtree and something from another subtree
		for (int j = min(sz[cur]-1, K); j >= 0; j--) {
			for (int k = 1; j+k <= K && k <= sz[nxt]; k++) {
				num val = dp[nxt][k] * dp[cur][j];
				// two subtrees
				if (j) {
					tots[j+k] += val;
				}
				dp[cur][j+k] += val;
			}
		}

		sz[cur] += sz[nxt];
	}
}

num dpcnt[MAXK][MAXK];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N-1; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	fact[0] = 1;
	for (int i = 1; i <= K; i++) {
		fact[i] = fact[i-1] * num(i);
	}
	ipow2[0] = 1;
	for (int i = 1; i <= N; i++) {
		ipow2[i] = ipow2[i-1] / num(2);
	}

	dfs(1);

	for (int i = 1; i <= K; i++) {
		// i distinct edges
		tots[i] /= ipow2[N];
	}

	dpcnt[0][0] = 1;
	for (int i = 1; i <= K; i++) {
		for (int j = i-1; j >= 0; j--) {
			dpcnt[i][j] += dpcnt[i-1][j] * j;
			dpcnt[i][j+1] += dpcnt[i-1][j];
		}
	}
	num ans = 0;
	for (int i = 1; i <= K; i++) {
		tots[i] *= fact[i] * dpcnt[K][i];
		ans += tots[i];
	}
	cout << ans << '\n';

	return 0;
}