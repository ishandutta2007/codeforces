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

using ll = long long;

const int MAXN = 2.1e5;
int N;
ll T;
ll V[MAXN];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> T;
	for (int i = 0; i < N; i++) {
		cin >> V[i];
	}

	vector<num> fact(N+1);
	fact[0] = 1;
	for (int i = 1; i <= N; i++) fact[i] = fact[i-1] * i;
	vector<num> ifact(N+1);
	ifact[N] = fact[N].inv();
	for (int i = N; i >= 1; i--) ifact[i-1] = ifact[i] * i;
	vector<num> p2(N+2);
	p2[0] = 1;
	for (int i = 1; i <= N+1; i++) {
		p2[i] = p2[i-1] * 2;
	}

	V[N] = T+1; // can never solve all of them

	num ans = 0;

	ll pref = 0;
	for (int i = 0; i <= N; pref += V[i], i++) {
		for (int z = 0; z < 2; z++) {
			// pref + a <= T < pref + a + V[i] + z
			// also 0 <= a <= i
			// T - pref - V[i] - z < a <= T - pref
			for (ll a = max(T - pref - V[i] - z + 1, 0ll); a <= min(ll(i), T - pref); a++) {
				// prefix has exactly a
				num prob = fact[i] * ifact[a] * ifact[i-a] / p2[i] / 2;
				//cerr << i << ' ' << z << ' ' << a << ' ' << prob << '\n';
				ans += prob * num(i);
			}
		}
	}
	cout << ans << '\n';
	return 0;
}