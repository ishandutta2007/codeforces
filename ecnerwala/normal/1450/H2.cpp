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

using num = modnum<998244353>;

template <typename T> void setmin(T& a, T b) { if (b < a) a = b; }
template <typename T> void setmax(T& a, T b) { if (b > a) a = b; }

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N, Q; cin >> N >> Q;
	assert(N % 2 == 0);

	vector<num> fact(N+1);
	fact[0] = 1;
	for (int i = 1; i <= N; i++) fact[i] = fact[i-1] * num(i);
	vector<num> ifact(N+1);
	ifact[N] = inv(fact[N]);
	for (int i = N; i >= 1; i--) ifact[i-1] = ifact[i] * num(i);
	auto choose = [&](int n, int r) -> num {
		assert(n >= -1);
		if (r < 0) return 0;
		else if (n == -1) return (r & 1) ? -1 : 1;
		else if (r > n) return 0;
		else return fact[n] * ifact[r] * ifact[n-r];
	};
	vector<num> p2(N+1);
	p2[0] = 1;
	for (int i = 1; i <= N; i++) p2[i] = p2[i-1] + p2[i-1];

	int c0 = 0;
	int c1 = 0;
	int cb = 0;

	int cur_n = 0;
	int cur_r = 0;
	num cur_sum = num(1); // sum of (n choose i) for i >= r

	string S; cin >> S;
	for (int q = 0; q <= Q; q++) {
		if (q == 0) {
			for (int i = 0; i < N; i++) {
				if ((i & 1) && S[i] != '?') S[i] ^= 'b' ^ 'w';

				if (S[i] == 'b') c0++;
				else if (S[i] == 'w') c1++;
				else if (S[i] == '?') cb++;
				else assert(false);
			}
		} else {
			int i; char c; cin >> i >> c; i--;

			if (S[i] == 'b') c0--;
			else if (S[i] == 'w') c1--;
			else if (S[i] == '?') cb--;
			else assert(false);

			S[i] = c;
			if ((i & 1) && S[i] != '?') S[i] ^= 'b' ^ 'w';

			if (S[i] == 'b') c0++;
			else if (S[i] == 'w') c1++;
			else if (S[i] == '?') cb++;
			else assert(false);
		}

		int n = cb, r = N/2 - c0;

		while (cur_n < n-2) {
			cur_sum *= 2;
			cur_sum += choose(cur_n, cur_r-1);
			cur_n ++;
		}
		while (cur_n > n-2) {
			cur_n--;
			cur_sum -= choose(cur_n, cur_r-1);
			cur_sum /= 2;
		}
		while (cur_r > r) {
			cur_r--;
			cur_sum += choose(cur_n, cur_r);
		}
		while (cur_r < r) {
			cur_sum -= choose(cur_n, cur_r);
			cur_r++;
		}

		num tot = 2 * cur_sum - (n-2 == -1 ? inv(num(2)) : p2[n-2]);
		tot *= (n-2*r);
		tot += 2 * r * choose(n-2, r);

		if (n == 1) {
			if ((r & 1) == 0) {
				tot -= inv(num(2));
			} else {
				tot += inv(num(2));
			}
		}
		tot /= 2;

		cout << tot / p2[n-1] << '\n';
	}

	return 0;
}

// Flip every other one, it's abs(# b - # w) / 4
//
// bbbwbbwb
//
// Then, you do some formula munging and write it as a function of the suffix sum