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

const int MAXN = 4000;
int N;
num permEx[MAXN][MAXN]; // permutations excluding a value
int A[MAXN][MAXN];

struct bit {
	int vals[MAXN];
	void update(int a, int v) {
		for (a++; a <= N; a += (a & -a)) {
			vals[a] += v;
		}
	}
	int query(int a) {
		int res = 0;
		for (; a > 0; a -= (a & -a)) {
			res += vals[a];
		}
		return res;
	}
	int query(int a, int b) { return query(b) - query(a); }
	void reset() { for (int i = 1; i <= N; i++) vals[i] = 0; }
};

bit allBit, excBit;

// let's try filling in A[i][j] with some smaller value v
// then, we have some (N-j-1) spaces left to fill in, some with an excluded value
// there are a few choices of v: excluded here, excluded later, not excluded

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];
			A[i][j] --;
		}
	}

	permEx[0][0] = 1;
	for (int i = 1; i <= N; i++) {
		permEx[i][0] = permEx[i-1][0] * i;
		for (int j = 1; j <= i; j++) {
			permEx[i][j] = 0;
			// there are j-1 values which are other excluded things, in which case that exclusion becomes trivial
			if (j >= 2) {
				permEx[i][j] += (j-1) * permEx[i-1][j-2];
			}
			permEx[i][j] += (i-j) * permEx[i-1][j-1];
		}
	}

	num ans = 0;
	for (int i = 0; i < N; i++) {
		// previous answers can be anything
		ans *= permEx[N][N];

		allBit.reset();
		excBit.reset();
		for (int j = 0; j < N; j++) {
			allBit.update(j, 1);
			if (i) {
				excBit.update(j, 1);
			}
		}
		for (int j = 0; j < N; j++) {
			int ind = allBit.query(A[i][j]); // 0-based index = number of choices of smaller things
			// permutation of N-j items
			// number of non-trivial excludes
			int exc = excBit.query(N);
			// number of remaining excludes less than ind
			int excLow = excBit.query(A[i][j]);
			bool excCur = false;
			if (i && excBit.query(A[i-1][j], A[i-1][j]+1)) {
				// it's still a relevant exclude
				assert(A[i-1][j] != A[i][j]);
				if (A[i-1][j] < A[i][j]) {
					excCur = true;
					excLow--;
				}
				exc--;
			}
			//cerr << ind << ' ' << exc << ' ' << excLow << ' ' << excCur << '\n';

			assert(excLow + excCur <= ind);
			assert(exc <= N-j-1);
			ans += permEx[N-j-1][exc] * (ind-excLow-excCur);
			if (excLow) {
				assert(exc >= 1);
				ans += permEx[N-j-1][exc-1] * excLow;
			}

			allBit.update(A[i][j], -1);
			if (i) {
				// both of these are no longer excluded things
				if (excBit.query(A[i][j], A[i][j]+1)) {
					excBit.update(A[i][j], -1);
				}
				if (excBit.query(A[i-1][j], A[i-1][j]+1)) {
					excBit.update(A[i-1][j], -1);
				}
			}
		}
	}
	cout << ans << '\n';

	return 0;
}