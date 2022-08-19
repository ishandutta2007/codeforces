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

const int MAXN = 2.1e5;
int N;
num P[MAXN];
num prodP[MAXN];
num sumProdP[MAXN];
int Q;

num getRange(int l, int r) {
	// ev is x = 1 + P[l] + P[l]*P[l+1] + ... + P[l]*...*P[r-2] + (1-P[l]*...*P[r-1]) * x
	// ev is (1 + P[l] + P[l]*P[l+1] + ... + P[l]*...*P[r-2]) / (P[l]*...*P[r-1])
	// ev is (prodP[l] + prodP[l+1] + prodP[l+2] + ... + prodP[r-1]) / prodP[r]
	return (sumProdP[r] - sumProdP[l]) / prodP[r];
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N; // >> Q;
	for (int i = 0; i < N; i++) {
		cin >> P[i]; P[i] /= num(100);
	}
	prodP[0] = 1;
	for (int i = 0; i < N; i++) {
		prodP[i+1] = prodP[i] * P[i];
	}
	sumProdP[0] = 0;
	for (int i = 0; i < N; i++) {
		sumProdP[i+1] = sumProdP[i] + prodP[i];
	}
	set<int> checkpoints;
	checkpoints.insert(0);
	checkpoints.insert(N);

	num ans = getRange(0, N);
cout << ans << '\n';
exit(0);

	while (Q--) {
		int u; cin >> u; u--;
		auto it = checkpoints.find(u);
		if (it != checkpoints.end()) {
			auto nt = it; ++nt;
			auto pt = it; --pt;
			ans -= getRange(*pt, *it);
			ans -= getRange(*it, *nt);
			ans += getRange(*pt, *nt);
			checkpoints.erase(it);
		} else {
			it = checkpoints.insert(u).first;
			auto nt = it; ++nt;
			auto pt = it; --pt;
			ans += getRange(*pt, *it);
			ans += getRange(*it, *nt);
			ans -= getRange(*pt, *nt);
		}
		cout << ans << '\n';
	}

	return 0;
}