#include <bits/stdc++.h>

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

static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();

using mnum = modnum<int(1e9)+7>;
using hsh = modnum<998244353>;
hsh BASE(FIXED_RANDOM);

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int NT, Q; cin >> NT >> Q;
	string S0, T; cin >> S0 >> T;
	int NS0 = int(S0.size());
	assert(int(T.size()) == NT);

	vector<hsh> base_pow(NS0+1);
	base_pow[0] = 1;
	for (int i = 1; i < int(base_pow.size()); i++) base_pow[i] = base_pow[i-1] * BASE;

	vector<hsh> pref(NS0 + 1);
	for (int i = 0; i < NS0; i++) {
		pref[i+1] = pref[i] * BASE + hsh(S0[i]);
	}

	vector<array<mnum, 26>> T_cnt(NT+1);
	T_cnt[0].fill(0);
	for (int k = 0; k < NT; k++) {
		for (int i = 0; i < 26; i++) T_cnt[k+1][i] = T_cnt[k][i] + T_cnt[k][i];
		T_cnt[k+1][T[k]-'a']++;
	}

	while (Q--) {
		int K; string W; cin >> K >> W;
		int NW = int(W.size());
		vector<hsh> wpref(NW+1);
		for (int i = 0; i < NW; i++) {
			wpref[i+1] = wpref[i] * BASE + hsh(W[i]);
		}

		mnum ans = 0;
		for (int off = NW; off <= NS0; off++) {
			hsh sval = pref[NS0-off+NW] - pref[NS0-off] * base_pow[NW];
			hsh wval = wpref[NW];
			if (sval == wval) {
				ans++;
			}
		}

		ans *= pow(mnum(2), K);

		for (int off = 0; off <= NS0 && off < NW; off++) {
			{
				bool is_good = true;
				for (int i = off - NS0; i < NW; i += NS0 + 1) {
					int lo = i, hi = i + NS0;
					lo = max(lo, 0);
					hi = min(hi, NW);
					assert(lo <= hi);
					hsh sval = pref[hi-i] - pref[lo-i] * base_pow[hi-lo];
					hsh wval = wpref[hi] - wpref[lo] * base_pow[hi-lo];
					if (sval != wval) {
						is_good = false;
						break;
					}
				}
				if (!is_good) continue;
			}
			std::y_combinator([&](auto self, int st, int stride, int k) -> void {
				if (k >= K) return;
				if (st + stride >= NW) {
					// just a single character
					ans += T_cnt[K][W[st]-'a'] - T_cnt[k][W[st]-'a'] * pow(mnum(2), K - k);
					return;
				}
				for (int z = 0; z < 2; z++) {
					bool is_good = true;
					for (int i = st + stride * z; i < NW; i += stride * 2) {
						if (W[i] != T[k]) {
							is_good = false;
							break;
						}
					}
					if (!is_good) continue;
					self(st + stride * !z, stride * 2, k+1);
				}
			})(off, NS0 + 1, 0);
		}
		cout << ans << '\n';
	}

	return 0;
}