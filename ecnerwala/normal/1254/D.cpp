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
vector<int> adj[MAXN];

int sz[MAXN];
int st[MAXN];
int en[MAXN];
int inds[MAXN];
int par[MAXN];
int heavyPar[MAXN];

const int S = 1 << 18;
num seg[2 * S];

void dfs_sz(int cur, int prv) {
	par[cur] = prv;
	sz[cur] = 1;
	for (int z = 0; z < int(adj[cur].size()); z++) {
		if (adj[cur][z] == prv) {
			adj[cur].erase(adj[cur].begin()+z);
		}
	}
	for (int nxt : adj[cur]) {
		dfs_sz(nxt, cur);
		sz[cur] += sz[nxt];
	}
	nth_element(adj[cur].begin(), adj[cur].begin(), adj[cur].end(), [&](int i, int j) { return sz[i] > sz[j]; });
}

void dfs_ord(int cur) {
	inds[st[cur]] = cur; en[cur] = st[cur]+1;
	bool isHeavy = true;
	for (int nxt : adj[cur]) {
		st[nxt] = en[cur];
		heavyPar[nxt] = isHeavy ? heavyPar[cur] : nxt;
		isHeavy = false;
		dfs_ord(nxt);
		en[cur] = en[nxt];
	}
}

num vertCnt[MAXN];

int Q;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	cin >> Q;
	for (int i = 0; i < N-1; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs_sz(1, 0);
	heavyPar[1] = 1;
	dfs_ord(1);

	num invN = num(N).inv();

	num totCnt = 0;
	for (int q = 0; q < Q; q++) {
		int t, v; cin >> t >> v;
		if (t == 1) {
			num d; cin >> d;
			totCnt += d * num(sz[v]);
			vertCnt[v] += d;
			if (!adj[v].empty()) {
				num sd = d * num(N - sz[adj[v][0]] - sz[v]);
				for (int a = S + st[v]; a; a /= 2) {
					seg[a] += sd;
				}
			}
		} else if (t == 2) {
			num res = totCnt;
			res += num(N - sz[v]) * vertCnt[v];

			for (int cur = v; cur != 1; ) {
				res += vertCnt[par[cur]] * num(N - sz[cur] - sz[par[cur]]);
				cur = par[cur];
				for (int a = S+st[heavyPar[cur]], b = S+st[cur]; a < b; a /= 2, b /= 2) {
					if (a & 1) {
						res += seg[a];
						a++;
					}
					if (b & 1) {
						--b;
						res += seg[b];
					}
				}
				cur = heavyPar[cur];
			}

			//cerr << res << '\n';
			cout << res * invN << '\n';
		} else assert(false);
	}

	return 0;
}