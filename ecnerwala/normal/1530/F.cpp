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
	using ll = long long;

	int16_t v;

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
		res.v = mod_inv_in_range(v, int16_t(MOD));
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
		static_assert(MOD * MOD <= int(1e9), "mul is okay");
		v = int32_t(v) * int32_t(o.v) % MOD;
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

using num = modnum<31607>;
num dp[1 << 23];
num ndp[1 << 23];

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N; cin >> N;
	const num BASE = inv(num(int(1e4)));

	dp[(1 << (N+2))-1] = num(1);

	for (int i = 0; i < N; i++) {
		// set the row to winning
		num prowwin = num(1);
		std::memcpy(ndp, dp, sizeof(dp[0]) * (1 << (N+2)));
		for (int j = 0; j < N; j++) {
			int msk = (1 << (j+2));
			if (i == j) msk |= 1;
			if (i + j == N-1) msk |= 2;
			num pwin; cin >> pwin; pwin *= BASE;
			num plose = 1 - pwin;
			prowwin *= pwin;
			if (msk == (1 << (j+2))) {
				for (int a = 0; a < (1 << (N+2)); a += (1 << (j+3))) {
					for (int b = (1 << (j+2)); b < (1 << (j+3)); b++) {
						int m = a+b;
						num v = dp[m] * plose;
						dp[m] -= v;
						dp[m - (1 << (j+2))] += v;
					}
				}
			} else {
				for (int m = 0; m < (1 << (N+2)); m++) {
					num v = dp[m] * plose;
					dp[m] -= v;
					dp[m & ~msk] += v;
				}
			}
		}
		for (int m = 0; m < (1 << (N+2)); m++) {
			dp[m] -= prowwin * ndp[m];
		}
	}

	cout << 1 - dp[0] << '\n';

	return 0;
}