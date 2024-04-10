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

	int v;

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

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	using num = modnum<998244353>;

	int M, K; cin >> M >> K;
	vector<array<num, 2>> vals(K);
	for (int k = 0; k < K; k++) {
		num sum = 0;
		num sum_sq = 0;
		for (int m = 0; m < M; m++) {
			num v; cin >> v;
			sum += v;
			sum_sq += v * v;
		}
		vals[k] = {sum, sum_sq};
	}

	int a = 0;
	while (vals[a][0] + vals[a+2][0] == 2 * vals[a+1][0]) a++;

	if (a == 0) {
		int b = a;
		while (vals[b][0] + vals[b+2][0] != 2 * vals[b+1][0]) b++;
		a = b-1;
	} else {
		a = a+2;
	}

	array<num, 2> new_val = vals[a];
	array<num, 2> old_val;
	for (int z = 0; z < 2; z++) {
		vector<pair<int, num>> v; v.reserve(3);
		for (int i = 0; v.size() < 3; i++) {
			if (i == a) continue;
			v.push_back({i, vals[i][z]});
		}
		num res = 0;
		for (int i = 0; i < 3; i++) {
			num cur = v[i].second;
			for (int j = 0; j < 3; j++) {
				if (j == i) continue;
				cur *= num(a - v[j].first) / num(v[i].first - v[j].first);
			}
			res += cur;
		}
		old_val[z] = res;
	}

	num diff = new_val[0] - old_val[0];
	num diff2 = new_val[1] - old_val[1];
	num sum = diff2 / diff;

	num ans = (sum - diff) / 2;

	cout << a << ' ' << ans << '\n';

	return 0;
}