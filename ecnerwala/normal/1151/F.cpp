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
using num = modnum<int(1e9)+7>;

const int MAXN = 110;
int N;
int A[MAXN];
int cnt[2];

const int MAXS = 60;
int S;

void mul(num a[MAXS][MAXS], const num b[MAXS][MAXS]) {
	num tmp[MAXS][MAXS];
	for (int i = 0; i <= S; i++) {
		for (int j = 0; j <= S; j++) {
			tmp[i][j] = 0;
			for (int k = 0; k <= S; k++) {
				tmp[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	for (int i = 0; i <= S; i++) {
		for (int j = 0; j <= S; j++) {
			a[i][j] = tmp[i][j];
		}
	}
}

num trans[MAXS][MAXS];
num prod[MAXS][MAXS];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int K;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		cnt[A[i]] ++;
	}
	S = min(cnt[0], cnt[1]); // anything from 0 to S
	int S0 = 0;
	for (int i = 0; i < cnt[0]; i++) {
		if (A[i] == 1) S0++;
	}

	memset(trans, 0, sizeof(trans));
	for (int i = 0; i <= S; i++) {
		// i that are switched
		num poss = num(N) * num(N-1) / num(2);

		num pminus = num(i) * num(i) / poss;
		num pplus = num(cnt[0] - i) * num(cnt[1] - i) / poss;
		num psame = num(1) - pplus - pminus;
		if (i > 0) trans[i][i-1] = pminus;
		trans[i][i] = psame;
		if (i < S) trans[i][i+1] = pplus;
	}

	for (int i = 0; i <= S; i++) {
		for (int j = 0; j <= S; j++) {
			prod[i][j] = num(i==j);
		}
	}
	while (K) {
		if (K & 1) mul(prod, trans);
		mul(trans, trans);
		K >>= 1;
	}
	cout << prod[S0][0] << '\n';

	return 0;
}