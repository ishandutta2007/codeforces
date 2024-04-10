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

using num = modnum<998244353>;

template <typename T> T pow(T a, long long b) {
	assert(b >= 0);
	T r = 1; while (b) { if (b & 1) r *= a; b >>= 1; a *= a; } return r;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int N; cin >> N;
	int M; cin >> M;

	int numExtra = 0;

	vector<int64_t> basis; basis.reserve(M);

	for (int z = 0; z < N; z++) {
		int64_t a; cin >> a;
		for (int64_t x : basis) {
			a = min(a, a^x);
		}
		if (a) {
			for (int64_t& x : basis) {
				x = min(x, a^x);
			}
			basis.push_back(a);
		} else {
			numExtra++;
		}
	}

	auto getFrequency = [&](const vector<int64_t>& b) -> vector<num> {
		vector<int> res(M+1);
		int64_t cur = 0;
		for (int z = 0; z < (1 << int(b.size())); z++) {
			if (z) {
				cur ^= b[__builtin_ctz(z)];
			}
			res[__builtin_popcountll(cur)]++;
		}
		vector<num> numRes(M+1);
		for (int i = 0; i <= M; i++) numRes[i] = res[i];
		return numRes;
	};

	int K = int(basis.size());
	int L = M-K;

	vector<num> ans;

	if (K <= L) {
		ans = getFrequency(basis);
	} else {
		vector<int64_t> perpBasis; perpBasis.reserve(L);
		for (int i = 0; i < M; i++) {
			int64_t val = int64_t(1) << i;
			for (int64_t a : basis) {
				int d = 63 - __builtin_clzll(a);
				if (i == d) {
					val = 0;
					break;
				} else if (a & (int64_t(1) << i)) {
					val |= int64_t(1) << d;
				}
			}
			if (val) perpBasis.push_back(val);
		}

		vector<num> freq = getFrequency(perpBasis);

		vector<num> fact(M+1);
		fact[0] = 1;
		for (int i = 1; i <= M; i++) fact[i] = fact[i-1] * num(i);
		vector<num> ifact(M+1);
		ifact[M] = inv(fact[M]);
		for (int i = M; i >= 1; i--) ifact[i-1] = ifact[i] * num(i);

		auto choose = [&fact, &ifact](int n, int r) -> num { if (0 <= r && r <= n) return fact[n] * ifact[n-r] * ifact[r]; else return num(0); };

		ans.resize(M+1);
		num invPerpSz = pow(inv(num(2)), int(perpBasis.size()));
		for (int i = 0; i <= M; i++) {
			for (int j = 0; j <= M; j++) {
				// number of things with i bits orthogonal to one thing with j bits
				num numOrtho = 0;
				for (int k = 0; k <= j; k += 2) {
					numOrtho += choose(j, k) * choose(M-j, i-k);
				}
				num weight = (2 * numOrtho - choose(M, i)) * invPerpSz;
				ans[i] += weight * freq[j];
			}
		}
	}

	num extraFac = pow(num(2), numExtra);
	for (int i = 0; i <= M; i++) {
		cout << ans[i]*extraFac << " \n"[i==M];
	}

	return 0;
}