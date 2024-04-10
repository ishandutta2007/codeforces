#include<bits/stdc++.h>

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

template <typename T> T pow(T a, long long b) {
	assert(b >= 0);
	T r = 1; while (b) { if (b & 1) r *= a; b >>= 1; a *= a; } return r;
}

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	using num = modnum<998244353>;

	int N, M; cin >> N >> M;
	vector<num> fact(N+1);
	fact[0] = 1;
	for (int i = 1; i <= N; i++) fact[i] = fact[i-1] * num(i);
	vector<num> ifact(N+1);
	ifact[N] = inv(fact[N]);
	for (int i = N; i >= 1; i--) ifact[i-1] = ifact[i] * num(i);

	auto choose = [&](int n, int r) -> num {
		if (0 <= r && r <= n) return fact[n] * ifact[n-r] * ifact[r];
		else return 0;
	};

	vector<array<int, 2>> bounds(N);
	for (int i = 0; i < N; i++) {
		int l, r; cin >> l >> r;
		bounds[i] = {l, r};
	}

	vector<array<int, 2>> edges(M);
	vector<bool> is_special(N, false);
	for (auto& e : edges) {
		cin >> e[0] >> e[1]; e[0]--, e[1]--;
		is_special[e[0]] = true;
		is_special[e[1]] = true;
	}

	vector<int> num_extra(N+2);

	vector<int> specials; specials.reserve(2*M);
	vector<int> special_idx(N);
	int num_special = 0;

	vector<int> cutoffs; cutoffs.reserve(4*M + 2);

	for (int i = 0; i < N; i++) {
		if (is_special[i]) {
			specials.push_back(i);
			special_idx[i] = num_special++;
			cutoffs.push_back(bounds[i][0]);
			cutoffs.push_back(bounds[i][1]+1);
		} else {
			num_extra[bounds[i][0]]++;
			num_extra[bounds[i][1]+1]--;
		}
	}
	for (int i = 0; i <= N; i++) num_extra[i+1] += num_extra[i];
	assert(num_extra[N+1] == 0);

	cutoffs.push_back(1);
	cutoffs.push_back(N+1);
	sort(cutoffs.begin(), cutoffs.end());
	cutoffs.erase(unique(cutoffs.begin(), cutoffs.end()), cutoffs.end());

	vector<int> par(num_special); iota(par.begin(), par.end(), 0);
	for (auto e : edges) {
		int a = special_idx[e[0]], b = special_idx[e[1]];
		a = par[a], b = par[b];
		if (a == b) continue;
		for (int i = 0; i < num_special; i++) if (par[i] == b) par[i] = a;
	}

	vector<int> cc_ind(num_special, -1);
	vector<int> cc_sz(num_special);
	vector<vector<bool>> is_good(num_special);
	for (int rt = 0; rt < num_special; rt++) {
		if (par[rt] != rt) continue;
		cc_sz[rt] = 0;
		for (int i = 0; i < num_special; i++) {
			if (par[i] == rt) {
				assert(cc_ind[i] == -1);
				cc_ind[i] = cc_sz[rt]++;
			}
		}
		is_good[rt].assign(1 << cc_sz[rt], true);
	}
	for (auto e : edges) {
		int a = special_idx[e[0]], b = special_idx[e[1]];
		assert(par[a] == par[b]);
		int r = par[a];
		a = cc_ind[a];
		b = cc_ind[b];

		for (int m = 0; m < (1 << cc_sz[r]); m++) {
			if ((m & (1 << a)) && (m & (1 << b))) {
				is_good[r][m] = false;
			}
		}
	}

	num ans = 0;
	vector<int> right_dp(1 << 20);
	for (int z = 0; z+1 < int(cutoffs.size()); z++) {
		int l = cutoffs[z];
		int r = cutoffs[z+1];
		assert(1 <= l && l < r && r <= N+1);

		vector<int> cc_alive(num_special, 0);
		for (int i = 0; i < num_special; i++) {
			if (bounds[specials[i]][0] <= l && l <= bounds[specials[i]][1]) {
				// it's alive this whole time
				cc_alive[par[i]] |= 1 << cc_ind[i];
			}
		}

		vector<num> num_ways({num(1)});
		for (int rt = 0; rt < num_special; rt++) {
			if (par[rt] != rt) continue;
			vector<num> cur_ways(cc_sz[rt]+1);
			assert(cc_sz[rt]);
			for (int m = 0; m < (1 << cc_sz[rt]); m++) {
				if (is_good[rt][m] && ((m & cc_alive[rt]) == m)) {
					cur_ways[__builtin_popcount(m)]++;
				}
			}
			vector<num> nxt_ways(num_ways.size() + cc_sz[rt]);
			for (int i = 0; i < int(num_ways.size()); i++) {
				for (int j = 0; j < int(cur_ways.size()); j++) {
					nxt_ways[i+j] += num_ways[i] * cur_ways[j];
				}
			}
			num_ways = nxt_ways;
		}

		for (int i = l; i < r; i++) {
			for (int v = 0; v < int(num_ways.size()); v++) {
				ans += num_ways[v] * choose(num_extra[i], i - v);
			}
		}
	}

	cout << ans << '\n';

	return 0;
}