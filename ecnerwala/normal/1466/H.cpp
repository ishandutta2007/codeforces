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

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N; cin >> N;
	vector<int> A(N); for (auto& a : A) { cin >> a; a--; }

	using num = modnum<int(1e9)+7>;

	vector<num> fact(N+1);
	fact[0] = 1;
	for (int i = 1; i <= N; i++) fact[i] = fact[i-1] * num(i);
	vector<num> ifact(N+1);
	ifact[N] = inv(fact[N]);
	for (int i = N; i >= 1; i--) ifact[i-1] = ifact[i] * num(i);

	vector<num> p2(N*N+1);
	p2[0] = 1;
	for (int i = 1; i < int(p2.size()); i++) p2[i] = p2[i-1] + p2[i-1];

	using state = array<int, 41>;

	vector<map<state, num>> dp(N+1);

	array<int, 41> tgt; tgt.fill(0);
	for (int i = 0; i < N; i++) {
		if (A[i] == -1) continue;
		int sz = 0;
		for (int j = i; A[j] != -1; ) {
			sz++;
			int k = A[j];
			A[j] = -1;
			j = k;
		}
		tgt[sz]++;
	}

	vector<num> num_ways(N, num(0));
	for (int a = 0; a < N; a++) {
		for (int v = 0; v <= a; v++) {
			num_ways[a] += (fact[a] * ifact[a-v]) * fact[N-1-v];
		}
	}

	state EMPTY; EMPTY.fill(0);
	dp[0][EMPTY] = 1;

	for (int ab = 1; ab <= N; ab++) {
		if (tgt[ab]) {
			state cur; cur.fill(0);
			cur[ab] = 1;
			dp[ab][cur] = 0;
		}
		for (int a = ab-1, b = 1; a >= 0; a--, b++) {
			num weight = pow(num_ways[a], b);
			for (const auto& [sa, va] : dp[a]) {
				for (const auto& [sb, _] : dp[b]) {
					state ns; ns.fill(0);
					int num_b = 0;
					num nv = va;
					for (int i = 1; i <= N; i++) {
						if (sa[i] + sb[i] > tgt[i]) {
							goto bad;
						}
						num_b ^= sb[i];
						ns[i] = sa[i]+sb[i];
						nv *= fact[ns[i]] * ifact[sa[i]] * ifact[sb[i]];
					}
					nv *= weight;
					nv = (num_b & 1) ? nv : -nv;
					dp[ab][ns] += nv;
bad:;
				}
			}
		}
	}
	num ans = dp[N][tgt];
	cout << ans << '\n';

	return 0;
}