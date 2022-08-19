#include <bits/stdc++.h>

template <typename T> T mod_inv_in_range(T a, T m) {
	// assert(0 <= a && a < m);
	T x = a, y = m;
	T vx = 1, vy = 0;
	while (x) {
		T k = y / x;
		y %= x;
		vy -= k * vx;
		std::swap(x, y);
		std::swap(vx, vy);
	}
	assert(y == 1);
	return vy < 0 ? m + vy : vy;
}

template <typename T> T mod_inv(T a, T m) {
	a %= m;
	a = a < 0 ? a + m : a;
	return mod_inv_in_range(a, m);
}

template <int MOD_> struct modnum {
	static constexpr int MOD = MOD_;
	static_assert(MOD_ > 0, "MOD must be positive");

private:
	int v;

public:

	modnum() : v(0) {}
	modnum(int64_t v_) : v(int(v_ % MOD)) { if (v < 0) v += MOD; }
	explicit operator int() const { return v; }
	friend std::ostream& operator << (std::ostream& out, const modnum& n) { return out << int(n); }
	friend std::istream& operator >> (std::istream& in, modnum& n) { int64_t v_; in >> v_; n = modnum(v_); return in; }

	friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
	friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }

	modnum inv() const {
		modnum res;
		res.v = mod_inv_in_range(v, MOD);
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
		v -= MOD-o.v;
		v = (v < 0) ? v + MOD : v;
		return *this;
	}
	modnum& operator -= (const modnum& o) {
		v -= o.v;
		v = (v < 0) ? v + MOD : v;
		return *this;
	}
	modnum& operator *= (const modnum& o) {
		v = int(int64_t(v) * int64_t(o.v) % MOD);
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

	int T; cin >> T;
	while (T--) {
		int N, M; cin >> N >> M;

		std::vector<int> A(N);
		for (auto& a : A) cin >> a;

		std::vector<std::vector<int>> out_edges(N);
		std::vector<int> in_deg(N);
		for (int e = 0; e < M; e++) {
			int u, v; cin >> u >> v; u--, v--;
			out_edges[u].push_back(v);
			in_deg[v]++;
		}

		std::vector<int> toposort; toposort.reserve(N);
		for (int i = 0; i < N; i++) {
			if (!in_deg[i]) toposort.push_back(i);
		}
		for (int z = 0; z < int(toposort.size()); z++) {
			int i = toposort[z];
			for (int j : out_edges[i]) {
				if (!--in_deg[j]) toposort.push_back(j);
			}
		}
		assert(int(toposort.size()) == N);

		using num = modnum<998244353>;
		cout << [&]() -> num {
			int ans = 0;
			for (int iter = 0; iter < N; iter++) {
				bool did_change = false;
				for (int z = N-1; z >= 0; z--) {
					int i = toposort[z];
					if (!A[i]) continue;
					did_change = true;
					A[i]--;
					for (int j : out_edges[i]) A[j]++;
				}
				if (!did_change) {
					return ans;
				}
				ans++;
			}
			const int BASE = (1 << 30);
			std::vector<std::vector<int32_t>> vals(N);
			for (int i = 0; i < N; i++) {
				for (int v = A[i]; v; v >>= 30) {
					vals[i].push_back(v & (BASE-1));
				}
			}
			for (int z = 0; z < N; z++) {
				int i = toposort[z];
				for (int j : out_edges[i]) {
					// vals[j] += vals[i]
					vals[j].resize(std::max(vals[i].size(), vals[j].size()) + 1, 0);
					int c = 0;
					for (int k = 0; k < int(vals[i].size()) || c; k++) {
						vals[j][k] += (k < int(vals[i].size()) ? vals[i][k] : 0) + c;
						c = vals[j][k] >= BASE;
						vals[j][k] -= c * BASE;
					}
					while (!vals[j].empty() && vals[j].back() == 0) vals[j].pop_back();
				}
			}
			int max_sz = -1;
			int best_idx = -1;
			for (int i = 0; i < N; i++) {
				std::reverse(vals[i].begin(), vals[i].end());
				if (int(vals[i].size()) > max_sz) {
					best_idx = i;
					max_sz = int(vals[i].size());
				} else if (int(vals[i].size()) == max_sz) {
					if (vals[i] > vals[best_idx]) {
						best_idx = i;
					}
				}
			}
			assert(best_idx != -1);
			num res = 0;
			for (int v : vals[best_idx]) {
				res *= BASE;
				res += v;
			}
			return res + ans;
		}() << '\n';
	}

	return 0;
}