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
	friend modnum inv(const modnum& m) { return m.inv(); }
	modnum neg() const {
		modnum res;
		res.v = v ? MOD-v : 0;
		return res;
	}
	friend modnum neg(const modnum& m) { return m.neg(); }

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

const int MAXS = 400;
int S;
unordered_map<uint32_t, int> msk_id;
uint32_t msks[MAXS];
int trans[MAXS][MAXS];

uint32_t mergeMsks(uint32_t a, uint32_t b) {
	// assume a and b are both closed
	if (a & b) return ~uint32_t(0);
	uint32_t ans = a | b;
	for (int i = 0; i < 32; i++) {
		for (int j = 0; j < 32; j++) {
			if ((a & (uint32_t(1) << i)) && (b & (uint32_t(1) << j))) {
				ans |= uint32_t(1) << (i^j);
			}
		}
	}
	assert(__builtin_popcount(ans|1) == __builtin_popcount(a|1) * __builtin_popcount(b|1));
	return ans;
}

void precomp() {
	S = 0;
	auto getId = [&] (uint32_t v) {
		if (msk_id.count(v)) return msk_id[v];
		msks[S] = v;
		return msk_id[v] = S++;
	};
	getId(~uint32_t(0)); // 0 is the bad one
	for (int i = 1; i < 32; i++) {
		getId(uint32_t(1) << i);
	}
	getId(0); // 32 is empty one

	for (int a = 0; a < S; a++) {
		for (int b = 0; b <= a; b++) {
			trans[a][b] = trans[b][a] = getId(mergeMsks(msks[a], msks[b]));
		}
	}
	cerr << S << '\n';
}

const int MAXN = 1.1e5;
const int MAXM = 1.1e5;
int N, M;
pair<pair<int, int>, int> edges[MAXM];
int adj0[MAXN];
vector<pair<int, int>> adj[MAXN];

pair<int, int> par[MAXN];
int basis[MAXN];
void reset() {
	for (int i = 1; i < N; i++) {
		par[i] = {-1, 0};
		basis[i] = 32;
	}
}
pair<int, int> getPar(int a) {
	if (par[a].first < 0) return {a, par[a].second};
	int v = par[a].second;
	par[a] = getPar(par[a].first);
	par[a].second ^= v;
	return par[a];
}

void merge(int a, int b, int v) {
	{ auto pa = getPar(a); a = pa.first, v ^= pa.second; }
	{ auto pb = getPar(b); b = pb.first, v ^= pb.second; }
	if (a == b) {
		basis[a] = trans[basis[a]][v];
		return;
	}
	if (par[a].first > par[b].first) swap(a,b);
	par[a].first += par[b].first;
	par[b] = {a, v};
	basis[a] = trans[basis[a]][basis[b]];
}

num dp[MAXS];
num ndp[MAXS];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	precomp();

	cin >> N >> M;
	reset();
	memset(adj0, -1, sizeof(adj0));
	for (int e = 0; e < M; e++) {
		int a, b, w; cin >> a >> b >> w;
		a--, b--;
		if (a > b) swap(a, b);
		edges[e] = {{a,b}, w};
		if (a == 0) {
			adj0[b] = w;
		} else {
			adj[a].emplace_back(b, w);
			adj[b].emplace_back(a, w);
			merge(a, b, w);
		}
	}

	dp[32] = 1;
	for (int e = 0; e < M; e++) {
		int a = edges[e].first.first, b = edges[e].first.second;
		if (adj0[a] != -1 && adj0[b] != -1) {
			int p = getPar(a).first;
			assert(p == getPar(b).first);
			if (basis[p] == 0) {
				// there's a simple cycle, can't use either
			} else {
				for (int i = 0; i < S; i++) ndp[i] = dp[i];

				for (int i = 0; i < S; i++) {
					ndp[trans[basis[p]][i]] += dp[i] * 2;
				}

				merge(a, b, adj0[a] ^ adj0[b]);
				assert(p == getPar(a).first);
				assert(p == getPar(b).first);
				for (int i = 0; i < S; i++) {
					ndp[trans[basis[p]][i]] += dp[i];
				}

				for (int i = 0; i < S; i++) dp[i] = ndp[i];
			}
			// cut it off
			adj0[a] = adj0[b] = -1;
		}
	}

	for (int a = 1; a < N; a++) {
		if (adj0[a] != -1) {
			int p = getPar(a).first;
			for (int i = 0; i < S; i++) ndp[i] = dp[i];

			for (int i = 0; i < S; i++) {
				ndp[trans[basis[p]][i]] += dp[i];
			}
			for (int i = 0; i < S; i++) dp[i] = ndp[i];
			// cut it off
			adj0[a] = -1;
		}
	}
	num ans = 0;
	for (int i = 1; i < S; i++) ans += dp[i];
	cout << ans << '\n';

	return 0;
}