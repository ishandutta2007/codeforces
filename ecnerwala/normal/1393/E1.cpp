#include<bits/stdc++.h>

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

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	using num = modnum<int(1e9)+7>;

	int Q; cin >> Q;
	string A; cin >> A;
	vector<num> dp(int(A.size())+1, num(1));
	Q--;
	while (Q--) {
		string B; cin >> B;
		vector<num> ndp(int(B.size())+1, num(0));

		int Asize = int(A.size());
		int Bsize = int(B.size());
		int L = max(Asize + 1, Bsize + 1);
		A.resize(L+1, '$');
		B.resize(L+1, '%');
		dp.resize(L+1, num(0)); // extend it to L+1 for convenience
		ndp.resize(L, num(0));

		// our state is nxt-B-index, A-used, == vs <
		vector<array<array<num, 2>, 2>> pref_dp(L);
		pref_dp[0][0][0]++;
		for (int i = 0; i < L; i++) {
			// first, we can skip A
			for (int z : {0, 1}) {
				pref_dp[i][1][z] += dp[i] * pref_dp[i][0][z];
			}

			if (i+1 == L) break;

			for (int z : {0, 1}) {
				// if it's already <, we don't need to check
				pref_dp[i+1][z][1] += pref_dp[i][z][1];

				if (A[i+z] == B[i]) {
					pref_dp[i+1][z][0] += pref_dp[i][z][0];
				} else if (A[i+z] < B[i]) {
					pref_dp[i+1][z][1] += pref_dp[i][z][0];
				}
			}
		}

		bool suff_less = true;
		// These are for A-unused
		num ways_suff = num(0);
		num ways_suff_less = num(0);
		for (int i = L-1; i >= 0; i--) {
			// update ways_suff with skipping i+1
			ways_suff += dp[i+1];

			// update ways_suff_less with skipping i+1
			if (suff_less) {
				ways_suff_less += dp[i+1];
			}

			// update ways_suff_less with i,i+1
			if (A[i] < B[i+1]) {
				ways_suff_less = ways_suff;
			} else if (A[i] > B[i+1]) {
				ways_suff_less = 0;
			}

			// update suff_less with i+1,i+1
			if (A[i+1] != B[i+1]) {
				suff_less = A[i+1] < B[i+1];
			}

			// A-unused and ==
			ndp[i] += ways_suff_less * pref_dp[i][0][0];

			// A-used and ==
			ndp[i] += suff_less * pref_dp[i][1][0];

			// A-unused and <
			ndp[i] += ways_suff * pref_dp[i][0][1];

			// A-used and <
			ndp[i] += pref_dp[i][1][1];
		}

		A.resize(Asize);
		B.resize(Bsize);
		dp.resize(Asize+1);
		ndp.resize(Bsize+1);

		A = std::move(B);
		dp = std::move(ndp);
	}

	num ans = accumulate(dp.begin(), dp.end(), num(0));
	cout << ans << '\n';

	return 0;
}