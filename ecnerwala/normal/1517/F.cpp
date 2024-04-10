#include <bits/stdc++.h>

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

namespace std {

template<class Fun>
class y_combinator_result {
	Fun fun_;
public:
	template<class T>
	explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

	template<class ...Args>
	decltype(auto) operator()(Args &&...args) {
		return fun_(std::ref(*this), std::forward<Args>(args)...);
	}
};

template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
	return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

} // namespace std

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N; cin >> N;
	vector<vector<int>> adj(N);
	for (int e = 0; e < N-1; e++) {
		int u, v; cin >> u >> v; u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	using num = modnum<998244353>;

	num ans = 0;

	for (int R = 1; R <= N; R++) {
		auto dfs = std::y_combinator([&](auto self, int cur, int prv) -> std::tuple<num, vector<num>, vector<num>> {
			num win = 0;
			vector<num> has({num(1)});
			vector<num> need({num(1)});
			for (int nxt : adj[cur]) {
				if (nxt == prv) continue;
				auto [ch_win, ch_has, ch_need] = self(nxt, cur);
				assert(int(ch_has.size()) == int(ch_need.size()));
				assert(int(ch_has.size()) <= R+1);

				ch_has.insert(ch_has.begin(), num(0));
				ch_need.insert(ch_need.begin(), num(0));

				if (int(ch_has.size()) == R+2) {
					ch_win += ch_need.back();
					ch_need.pop_back();
					ch_need[0] += ch_has.back();
					ch_has.pop_back();
				}

				num nwin = 0;
				vector<num> nhas(max(has.size(), ch_has.size()), num(0));
				vector<num> nneed(max(need.size(), ch_need.size()), num(0));

				nwin += win * ch_win;
				for (num v : has) nwin += v * ch_win;
				for (num v : need) nwin += v * ch_win;
				for (num v : ch_has) nwin += win * v;
				for (num v : ch_need) nwin += win * v;

				for (int a = 0; a < int(has.size()); a++) {
					for (int b = 0; b < int(ch_has.size()); b++) {
						nhas[min(a, b)] += has[a] * ch_has[b];
					}
				}
				for (int a = 0; a < int(has.size()); a++) {
					for (int b = 0; b < int(ch_need.size()); b++) {
						if (a + b <= R) {
							nhas[a] += has[a] * ch_need[b];
						} else {
							nneed[b] += has[a] * ch_need[b];
						}
					}
				}
				for (int a = 0; a < int(need.size()); a++) {
					for (int b = 0; b < int(ch_has.size()); b++) {
						if (a + b <= R) {
							nhas[b] += need[a] * ch_has[b];
						} else {
							nneed[a] += need[a] * ch_has[b];
						}
					}
				}
				for (int a = 0; a < int(need.size()); a++) {
					for (int b = 0; b < int(ch_need.size()); b++) {
						nneed[max(a, b)] += need[a] * ch_need[b];
					}
				}

				win = nwin;
				has = std::move(nhas);
				need = std::move(nneed);
			}
			return {win, has, need};
		});

		auto res = dfs(0, -1);
		num cur = 0;
		cur += get<0>(res);
		for (num v : get<2>(res)) cur += v;
		//cerr << "tot " << R << ' ' << cur << '\n';
		ans += cur;
	}
	ans--;

	ans *= pow(inv(num(2)), N);
	cout << ans << '\n';

	return 0;
}