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
using num = modnum<998244353>;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string n_str; cin >> n_str;
	vector<int> N;
	for (char c : n_str) N.push_back(c - '0');
	reverse(N.begin(), N.end());

	num tot = 0;

	for (int x = 1; x <= 9; x++) {
		for (int y = x; y <= 9; y++) {
			if (__gcd(x, y) != 1) continue;
			//cerr << "x " << x << ' ' << "y " << y << '\n';
			// carry, mask
			map<pair<bool, pair<pair<int, int>, pair<int, int>>>, num> dp;
			dp[{true, {{0,0}, {0,0}}}] = 1;
			for (int i = 0; i < int(N.size()); i++) {
				decltype(dp) ndp;
				for (auto it : dp) {
					bool isLess = it.first.first;
					auto state = it.first.second;
					num cnt = it.second;
					for (int d = 0; d <= 9; d++) {
						auto nstate = state;
						int xval = state.first.first + d * x;
						nstate.first.first = xval / 10;
						xval %= 10;
						if (xval > 0 && xval % x == 0 && (xval / x) * y <= 9) {
							nstate.first.second |= (1 << (xval / x));
						}
						int yval = state.second.first + d * y;
						nstate.second.first = yval / 10;
						yval %= 10;
						if (yval > 0 && yval % y == 0 && (yval / y) * x <= 9) {
							nstate.second.second |= (1 << (yval / y));
						}
						if (nstate.first.second & nstate.second.second) {
							nstate.first.second = nstate.second.second = 1;
						}
						//cerr << i << ' ' << d << ' ' << ((d < N[i]) || (d == N[i] && isLess)) << ' ' << nstate.first.first << ' ' << nstate.second.first << ' ' << cnt << '\n';
						ndp[{(yval < N[i]) || (yval == N[i] && isLess), nstate}] += cnt;
					}
				}
				dp = std::move(ndp);
			}
			for (auto it : dp) {
				if (it.first.first == true && it.first.second.first.first == 0 && it.first.second.second.first == 0) {
					if (it.first.second.first.second & it.first.second.second.second) {
						//cerr << x << ' ' << y << ' ' << it.second << '\n';
						tot += it.second;
						if (y > x) tot += it.second;
					}
				}
			}
		}
	}
	cout << tot << '\n';

	return 0;
}