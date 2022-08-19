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

	const int INF = 1e9;

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<int> P(N); for (auto& p : P) { cin >> p; p--; }
		vector<int> cyc_lens; cyc_lens.reserve(N);
		for (int i = 0; i < N; i++) {
			if (P[i] == -1) continue;
			int cnt = 0;
			for (int j = i; P[j] != -1; ) {
				cnt++;

				int nj = P[j];
				P[j] = -1;
				j = nj;
			}
			cyc_lens.push_back(cnt);
		}

		using num = modnum<int(1e9)+7>;

		//for (int l : cyc_lens) { cerr << l << ' '; } cerr << '\n';

		if (N % 3 == 0) {
			int ans = 0;
			array<int, 3> c{0,0,0};
			for (int l : cyc_lens) {
				while (l > 3) l -= 3, ans++;
				if (l < 3) c[l]++;
			}
			ans += min(c[1], c[2]) + abs(c[1] - c[2]) / 3 * 2 + max(c[2] - c[1], 0) / 3;
			cout << pow(num(3), N/3) << ' ' << ans << '\n';
		} else if (N % 3 == 1) {
			assert(N >= 4);
			// 2 solutions: make 2's, or make 4
			auto solve_4 = [&]() -> int {
				int ans = 0;
				array<int, 3> c{0,0,0};
				for (int l : cyc_lens) {
					while (l > 3) l -= 3, ans++;
					if (l < 3) c[l]++;
				}

				// If the 4 stick has at least one 2, then you just don't merge that in, and you get a cheaper 2/2
				// If the 4 stick has 2 1's, ditto
				// Thus, the 4 stick must be a single stick, or a 1 + a 3
				// Or it has something >= 4
				bool has_4 = false;
				bool has_3 = false;
				for (int l : cyc_lens) {
					if (l % 3 == 1 && l >= 4) has_4 = true;
					if (l >= 3) has_3 = true;
				}
				if (has_4) {
					// undo that last break
					ans--;
					assert(c[1] >= 1);
					c[1]--;
					ans += min(c[1], c[2]) + abs(c[1] - c[2]) / 3 * 2 + max(c[2] - c[1], 0) / 3;
					return ans;
				} else if (c[1] >= 1 && has_3) {
					c[1]--;
					ans++;
					ans += min(c[1], c[2]) + abs(c[1] - c[2]) / 3 * 2 + max(c[2] - c[1], 0) / 3;
					return ans;
				}
				return INF;
			};

			auto solve_2 = [&]() -> int {
				int ans = 0;
				array<int, 3> c{0,0,0};
				for (int l : cyc_lens) {
					while (l > 3) l -= 3, ans++;
					if (l < 3) c[l]++;
				}
				int cnd = INF;

				for (int z : {0,1,2}) {
					if (c[1] >= 2*z && c[2] >= (2-z)) {
						c[1] -= 2*z;
						c[2] -= (2-z);
						cnd = min(cnd, z + min(c[1], c[2]) + abs(c[1] - c[2]) / 3 * 2 + max(c[2] - c[1], 0) / 3);
						c[1] += 2*z;
						c[2] += (2-z);
					}
				}

				ans += cnd;
				return ans;
			};
			cout << pow(num(3), (N-4)/3) * num(4) << ' ' << min(solve_2(), solve_4()) << '\n';
		} else if (N % 3 == 2) {
			int ans = 0;
			array<int, 3> c{0,0,0};
			for (int l : cyc_lens) {
				while (l > 3) l -= 3, ans++;
				if (l < 3) c[l]++;
			}

			int cnd = INF;
			if (c[1] >= 2) {
				c[1] -= 2;
				cnd = min(cnd, 1 + min(c[1], c[2]) + abs(c[1] - c[2]) / 3 * 2 + max(c[2] - c[1], 0) / 3);
				c[1] += 2;
			}
			if (c[2] >= 1) {
				c[2] -= 1;
				cnd = min(cnd, min(c[1], c[2]) + abs(c[1] - c[2]) / 3 * 2 + max(c[2] - c[1], 0) / 3);
				c[2] += 1;
			}

			ans += cnd;
			cout << pow(num(3), (N-2)/3) * num(2) << ' ' << ans << '\n';
		} else assert(false);
	}

	return 0;
}

// One exchange will either split a cycle arbitrarily, or merge 2 arbitrary cycles/

// Number of days is product of cycle sizes, optimal is attained depending on mod 3;
// If 0 mod 3, 3^k
// If 1 mod 3, then 3^k * 2 * 2 or 3^k * 4
// If 2 mod 3, 3^k * 2