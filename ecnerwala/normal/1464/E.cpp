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

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N, M; cin >> N >> M;
	vector<vector<int>> outEdges(N);
	vector<vector<int>> inEdges(N);
	vector<int> outDeg(N);
	for (int e = 0; e < M; e++) {
		int u, v; cin >> u >> v; u--, v--;
		outEdges[u].push_back(v);
		inEdges[v].push_back(u);
		outDeg[u]++;
	}

	vector<int> q; q.reserve(N);
	for (int i = 0; i < N; i++) {
		if (outDeg[i] == 0) q.push_back(i);
	}

	vector<int> nimber(N);
	vector<int> mex_buf(N+1);
	for (int z = 0; z < int(q.size()); z++) {
		int cur = q[z];
		for (int nxt : outEdges[cur]) {
			mex_buf[nimber[nxt]]++;
		}
		while (mex_buf[nimber[cur]] != 0) nimber[cur]++;
		for (int nxt : outEdges[cur]) {
			mex_buf[nimber[nxt]]--;
		}

		for (int nxt : inEdges[cur]) {
			if (!--outDeg[nxt]) {
				q.push_back(nxt);
			}
		}
	}
	assert(int(q.size()) == N);

	int L = 0;
	while ((1 << L) < N) L++;
	assert(N <= (1 << L));

	using num = modnum<998244353>;
	vector<num> buf(1<<L);
	for (int i = 0; i < N; i++) {
		assert(nimber[i] < N);
		assert(nimber[i] < (1 << L));
		buf[nimber[i]] ++;
	}
	for (int l = 0; l < L; l++) {
		for (int m = 0; m < (1 << L); m++) {
			if (m & (1 << l)) continue;
			num& a = buf[m];
			num& b = buf[m | (1 << l)];
			auto nxt = make_pair(a+b, a-b);
			tie(a, b) = nxt;
		}
	}

	num ans = 0;
	for (int m = 0; m < (1 << L); m++) {
		ans += inv(N+1 - buf[m]);
	}
	ans /= num(1<<L);

	cout << 1-ans << '\n';

	return 0;
}