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
using num = modnum<int(1e9)+7>;

const int MAXV = 2.1e5;
num fact[MAXV+1];
num ifact[MAXV+1];
num dist(int n, int f) {
	if (n >= f) {
		return fact[n-1] * ifact[n-f] * ifact[f-1];
	} else {
		return 0;
	}
}

int mobius[MAXV+1];
vector<pair<int, int>> mobFactors[MAXV+1];
bool isPrime[MAXV+1];

void precomp() {
	fact[0] = 1;
	for (int i = 1; i <= MAXV; i++) fact[i] = fact[i-1] * num(i);
	ifact[MAXV] = inv(fact[MAXV]);
	for (int i = MAXV; i >= 1; i--) ifact[i-1] = ifact[i] * num(i);

	for (int p = 2; p <= MAXV; p++) isPrime[p] = true;
	for (int i = 1; i <= MAXV; i++) mobius[i] = 1;

	for (int p = 2; p <= MAXV; p++) {
		if (!isPrime[p]) continue;
		for (int j = p; j <= MAXV; j += p) {
			isPrime[j] = false;
			if (j / p % p == 0) mobius[j] = 0;
			mobius[j] *= -1;
		}
	}

	for (int i = 1; i <= MAXV; i++) {
		if (!mobius[i]) continue;

		for (int j = i; j <= MAXV; j += i) mobFactors[j].emplace_back(i, mobius[i]);
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	precomp();

	int Q; cin >> Q;
	while (Q--) {
		int N, F; cin >> N >> F;
		num ans = 0;
		for (auto it : mobFactors[N]) {
			ans += dist(N / it.first, F) * it.second;
		}
		cout << ans << '\n';
	}

	return 0;
}