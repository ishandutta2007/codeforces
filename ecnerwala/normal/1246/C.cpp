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

template <typename T> T pow(T a, long long b) {
	assert(b >= 0);
	T r = 1; while (b) { if (b & 1) r *= a; b >>= 1; a *= a; } return r;
}

using num = modnum<int(1e9)+7>;

const int MAXN = 2100;
const int MAXM = 2100;
int N, M;
char G[MAXN][MAXM];

num dpRow[MAXN][MAXM];
int rowFree[MAXN][MAXM];
num dpCol[MAXN][MAXM];
int colFree[MAXN][MAXM];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> G[i];
	}

	if (N == 1 && M == 1) {
		cout << 1 << '\n';
		exit(0);
	}

	for (int i = N-1; i >= 0; i--) {
		for (int j = M-1; j >= 0; j--) {
			rowFree[i][j] = rowFree[i][j+1] + (G[i][j] == '.');
			colFree[i][j] = colFree[i+1][j] + (G[i][j] == '.');

			num rowVal = 0;
			num colVal = 0;
			if (i == N-1 && j == M-1) {
				rowVal = colVal = 1;
			} else {
				rowVal = dpRow[i][j+1] - dpRow[i][j+1 + rowFree[i][j+1]];
				colVal = dpCol[i+1][j] - dpCol[i+1 + colFree[i+1][j]][j];
			}

			dpRow[i][j] = dpRow[i][j+1] + colVal;
			dpCol[i][j] = dpCol[i+1][j] + rowVal;
		}
	}

	cout << (dpRow[0][0] - dpRow[0][1]) + (dpCol[0][0] - dpCol[1][0]) << '\n';

	return 0;
}