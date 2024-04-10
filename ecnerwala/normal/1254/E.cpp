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

const int MAXN = 5.1e5;
int N;
pair<int, int> E[MAXN];
vector<pair<int, int>> adj[MAXN];
int parE[MAXN];
int par[MAXN];
int depth[MAXN];

int A[MAXN];

bool used[MAXN * 2];
int Enxt[MAXN * 3];
int linkCnt[MAXN];
int goodLinkCnt[MAXN];

namespace unionFind {
	int par[MAXN * 3];
	void reset() { memset(par, -1, sizeof(par)); }
	int getPar(int a) {
		return par[a] == -1 ? a : (par[a] = getPar(par[a]));
	}
	bool merge(int a, int b) {
		a = getPar(a);
		b = getPar(b);
		if (a == b) return false;
		par[b] = a;
		return true;
	}
}

void dfs(int cur, int prv, int prvE) {
	parE[cur] = prvE;
	par[cur] = prv;
	depth[cur] = depth[prv] + 1;
	for (auto it : adj[cur]) {
		if (it.first == prvE) continue;
		int nxt = it.second;
		dfs(nxt, cur, it.first);
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	for (int e = 0; e < N-1; e++) {
		int u, v; cin >> u >> v;
		E[e] = {u,v};
		adj[u].push_back({e,v});
		adj[v].push_back({e,u});
	}
	dfs(1, 0, -1);
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}

	unionFind::reset();
	for (int i = 1; i <= N; i++) {
		if (!A[i]) continue;

		if (A[i] == i) {
			assert(N >= 2);
			cout << 0 << '\n';
			exit(0);
		}
		vector<int> xedges;
		vector<int> yedges;
		for (int x = A[i], y = i; x != y; ) {
			if (depth[x] >= depth[y]) {
				xedges.push_back(2 * parE[x]);
				x = par[x];
			} else {
				yedges.push_back(2 * parE[y] + 1);
				y = par[y];
			}
		}
		vector<int> edges = xedges;
		edges.insert(edges.end(), yedges.rbegin(), yedges.rend());
		assert(!edges.empty());
		for (auto e : edges) {
			if (used[e]) {
				cout << 0 << '\n';
				exit(0);
			}
			used[e] = true;
		}
		linkCnt[A[i]]++;
		goodLinkCnt[A[i]] += unionFind::merge(2 * (N-1) + A[i], edges.front() ^ 1);
		for (int z = 0, cur = A[i]; z+1 < int(edges.size()); z++) {
			cur = E[edges[z]/2].first ^ E[edges[z]/2].second ^ cur;
			linkCnt[cur]++;
			goodLinkCnt[cur] += unionFind::merge(edges[z], edges[z+1] ^ 1);
		}
		linkCnt[i]++;
		goodLinkCnt[i] += unionFind::merge(edges.back(), 2 * (N-1) + i);
	}

	num ans = 1;
	for (int i = 1; i <= N; i++) {
		if (goodLinkCnt[i] == min(linkCnt[i], int(adj[i].size()) + 1 - 1)) {
			int v = int(adj[i].size()) + 1 - goodLinkCnt[i];
			for (int z = 1; z <= v-1; z++) ans *= z;
		} else {
			cout << 0 << '\n';
			exit(0);
		}
	}
	cout << ans << '\n';

	return 0;
}