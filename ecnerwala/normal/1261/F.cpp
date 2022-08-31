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
using ll = long long;

const int MAXNODES = 1.1e7;
int NNODES;
struct node_t{
	int c[2] = {0,0};
	bool mark = false;
} nodes[MAXNODES];

void dfs(int lg, int& node, ll l1, ll r1, ll l2, ll r2) {
	//cerr << lg << ' ' << node << ' ' << l1 << ' ' << r1 << ' ' << l2 << ' ' << r2 << '\n';
	assert(lg >= 0);
	ll m = (1ll << lg);
	l1 = max(l1, 0ll);
	r1 = min(r1, m-1);
	l2 = max(l2, 0ll);
	r2 = min(r2, m-1);
	if (l1 > r1 || l2 > r2) return;

	if (!node) {
		node = ++NNODES;
	}
	if ((l1 == 0 && r1 == m-1) || (l2 == 0 && r2 == m-1)) {
		//cerr << "mark " << node << '\n';
		nodes[node].mark = true;
		return;
	}
	assert(lg >= 1);
	for (ll a = 0; a < 2; a++) {
		for (ll b = 0; b < 2; b++) {
			dfs(lg-1, nodes[node].c[a^b], l1 - a*(m/2), r1 - a*(m/2), l2 - b*(m/2), r2 - b*(m/2));
		}
	}
}

num dfs2(int lg, int node, ll v) {
	if (!node) return 0;
	assert(lg >= 0);
	//cerr << lg << ' ' << node << ' ' << '\n';
	if (nodes[node].mark) {
		num res = v * (1ll << lg);
		num cnt = (1ll << lg);
		return res * cnt + cnt * (cnt-1) / 2;
	}
	return dfs2(lg-1, nodes[node].c[0], v*2 + 0) + dfs2(lg-1, nodes[node].c[1], v*2 + 1);
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int NA; cin >> NA;
	vector<pair<ll, ll>> A(NA);
	for (int i = 0; i < NA; i++) {
		cin >> A[i].first >> A[i].second;
	}

	int NB; cin >> NB;
	vector<pair<ll, ll>> B(NB);
	for (int i = 0; i < NB; i++) {
		cin >> B[i].first >> B[i].second;
	}

	NNODES = 1;
	int ROOT = 1;

	for (auto it : A) {
		for (auto jt : B) {
			dfs(61, ROOT, it.first, it.second, jt.first, jt.second);
		}
	}

	cout << dfs2(61, ROOT, 0) << '\n';

	return 0;
}