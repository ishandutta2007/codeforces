#include<bits/stdc++.h>
using namespace std;


struct val {
	typedef long long ll;
	static const int MOD = 998244353;

	int v;

	val (int a=0) : v(a) {}

	val operator + (const val &o) const {
		int a = v + o.v;
		return val{a >= MOD ? a-MOD : a};
	}
	val& operator += (const val &o) {
		int a = v + o.v;
		v = (a >= MOD ? a-MOD : a);
		return *this;
	}
	val operator - (const val &o) const {
		int a = v - o.v;
		return val{a < 0 ? a+MOD : a};
	}
	val& operator -= (const val &o) {
		int a = v - o.v;
		v = (a < 0 ? a+MOD : a);
		return *this;
	}

	val operator * (const val &o) const {
		return val{int(ll(v) * ll(o.v) % ll(MOD))};
	}

	val& operator *= (const val &o) {
		v = int(ll(v) * ll(o.v) % ll(MOD));
		return *this;
	}

	bool operator == (const val &o) const {
		return v == o.v;
	}
};

const int MAXN = 5000;
int N;
vector<int> adj[MAXN];
int par[MAXN];

const int MAXK = 40;
using arr = val[MAXK];
int K;
arr dp_down[MAXN];

arr dp_node[MAXN]; // sum of dps going out of this node, i.e. number of nontrivial simple cycles coming out of this node

arr tmp;
void powk(const arr &a) {
	assert(a[0] == 0);
	memset(tmp, 0, sizeof(tmp));
	tmp[0] = 1;

	for (int i = 1; i <= K; i++) {
		val v = 0;
		for (int j = 1; j <= i; j++) {
			v += a[j] * tmp[i-j];
		}
		tmp[i] = v;
	}
}

void dfs_down(int cur, int prv = -1) {
	par[cur] = prv;

	memset(dp_node[cur], 0, sizeof(dp_node[cur]));
	memset(dp_down[cur], 0, sizeof(dp_down[cur]));

	for (int nxt : adj[cur]) {
		if (nxt == prv) continue;

		dfs_down(nxt, cur);

		for (int i = 0; i <= K; i++) {
			dp_node[cur][i] += dp_down[nxt][i];
		}
	}
	powk(dp_node[cur]);
	for (int i = 1; i <= K; i++) {
		dp_down[cur][i] += tmp[i-1];
	}
}

arr dp_tot;

void dfs_up(int cur, int prv = -1) {
	for (int nxt : adj[cur]) {
		if (nxt == prv) continue;

		for (int i = 0; i <= K; i++) {
			dp_node[cur][i] -= dp_down[nxt][i];
		}

		// add in the dp_up
		powk(dp_node[cur]);
		for (int i = 1; i <= K; i++) {
			dp_node[nxt][i] += tmp[i-1];
		}

		for (int i = 0; i <= K; i++) {
			dp_node[cur][i] += dp_down[nxt][i];
		}

		dfs_up(nxt, cur);
	}

	powk(dp_node[cur]);
	for (int i = 0; i <= K; i++) {
		dp_tot[i] += tmp[i];
	}
}

void go() {
	for (int i = 0; i < N-1; i++) {
		int u, v; cin >> u >> v;
		u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	memset(dp_tot, 0, sizeof(dp_tot));

	dfs_down(0);
	dfs_up(0);

	for (int i = 0; i < N; i++) {
		adj[i].clear();
	}
	//for (int i = 0; i < N; i++) { cerr << dp_tot[i].v << ' '; } cerr << '\n';
}

arr dp_final[2];

val binom[MAXK * 2][MAXK * 2];

int main() {
	ios_base::sync_with_stdio(0);
	int n1, n2; cin >> n1 >> n2 >> K;
	if (K % 2 == 1) {
		cout << 0 << '\n';
		return 0;
	}
	K /= 2;

	N = n1;
	go();
	for (int i = 0; i <= K; i++) dp_final[0][i] = dp_tot[i];

	N = n2;
	go();
	for (int i = 0; i <= K; i++) dp_final[1][i] = dp_tot[i];

	val res = 0;

	for (int i = 0; i <= K * 2; i++) {
		binom[i][0] = binom[i][i] = 1;
		for (int j = 1; j < i; j++) {
			binom[i][j] = binom[i-1][j-1] + binom[i-1][j];
		}
	}

	for (int i = 0; i <= K; i++) {
		res += dp_final[0][i] * dp_final[1][K-i] * binom[K*2][i*2];
	}

	cout << res.v << '\n';

	return 0;
}