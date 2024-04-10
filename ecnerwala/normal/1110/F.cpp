#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1e18;

template <typename T> void setmin(T& a, T b) { if (b < a) a = b; }

const int MAXN = 5.1e5;
const int MAXQ = 5.1e5;
int N;
int par[MAXN][21];
vector<int> ch[MAXN];
ll W[MAXN];
int depth[MAXN];
bool isLeaf[MAXN];
int en[MAXN]; // inclusive range
ll bestLeaf[MAXN]; // distance to the best leaf
ll suffBest[MAXN][21];
ll prefBest[MAXN][21];

int lca(int a, int b) {
	if (depth[a] > depth[b]) swap(a,b);
	for (int i = 0; (1 << i) <= (depth[b] - depth[a]); i++) {
		if ((1 << i) & (depth[b] - depth[a])) {
			b = par[b][i];
		}
	}
	assert(depth[a] == depth[b]);
	if (a == b) return a;
	int i = 0;
	while (par[a][i] != par[b][i]) i++;
	while (i > 0) {
		i--;
		if (par[a][i] != par[b][i]) {
			a = par[a][i];
			b = par[b][i];
		}
	}
	assert(a != b);
	assert(par[a][0] == par[b][0]);
	return par[a][0];
}

const int S = (1 << 19);
ll seg[S * 2];
ll range_min(int a, int b) {
	b++;
	ll res = INF;
	for (a += S, b += S; a < b; a /= 2, b /= 2) {
		if (a & 1) {
			setmin(res, seg[a]);
			a++;
		}
		if (b & 1) {
			b--;
			setmin(res, seg[b]);
		}
	}
	return res;
}

ll query(int v, int l, int r) {
	if (l > r) return INF;
	assert(l <= r);
	if (l <= v && v <= r) {
		if (isLeaf[v]) return 0;
		return min(query(v, l, v-1), query(v, v+1, r));
	}
	assert(v < l || v > r);
	int lv = lca(v, l);
	int rv = lca(v, r);
	assert(rv <= min(v, r));
	assert(lv <= min(v, l));
	if (lv == rv) {
		return W[v] + range_min(l, r) - 2 * W[lv];
	}
	assert(depth[lv] != depth[rv]);
	ll res = INF;
	if (v > r) {
		assert(depth[lv] < depth[rv]);
		// first go up to rv
		assert(rv > l);
		setmin(res, W[v] + range_min(rv, r) - 2 * W[rv]);
		for (int i = 0; (1 << i) <= (depth[rv] - depth[lv] - 1); i++) {
			if ((1 << i) & (depth[rv] - depth[lv] - 1)) {
				setmin(res, W[v] + prefBest[rv][i]);
				rv = par[rv][i];
			}
		}
		assert(par[rv][0] == lv);
		setmin(res, W[v] + range_min(l, rv-1) - 2 * W[lv]);
	} else if (v < l) {
		assert(depth[rv] < depth[lv]);

		assert(en[lv] < r);
		setmin(res, W[v] + range_min(l, en[lv]) - 2 * W[lv]);

		for (int i = 0; (1 << i) <= (depth[lv] - depth[rv] - 1); i++) {
			if ((1 << i) & (depth[lv] - depth[rv] - 1)) {
				setmin(res, W[v] + suffBest[lv][i]);
				lv = par[lv][i];
			}
		}

		assert(par[lv][0] == rv);
		setmin(res, W[v] + range_min(en[lv] + 1, r) - 2 * W[rv]);
	} else assert(false);
	return res;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int Q;
	cin >> N >> Q;
	for (int i = 2; i <= N; i++) {
		cin >> par[i][0] >> W[i];
	}

	for (int i = 1; i <= N; i++) {
		ch[par[i][0]].push_back(i);
	}

	par[1][0] = 0, W[1] = 0;
	for (int i = 1; i <= N; i++) {
		W[i] += W[par[i][0]]; // path to root
		depth[i] = depth[par[i][0]] + 1;
		for (int j = 0; par[i][j]; j++) {
			par[i][j+1] = par[par[i][j]][j];
		}
	}

	for (int i = 1; i <= N; i++) isLeaf[i] = ch[i].empty();

	for (int i = 1; i <= N; i++) en[i] = i;
	for (int i = N; i >= 1; i--) {
		en[par[i][0]] = max(en[par[i][0]], en[i]);
	}

	for (int i = N; i >= 1; i--) {
		seg[i+S] = bestLeaf[i] = (isLeaf[i] ? W[i] : INF);
	}
	for (int i = N; i >= 1; i--) {
		bestLeaf[par[i][0]] = min(bestLeaf[par[i][0]], bestLeaf[i]);
	}
	for (int i = S-1; i > 0; i--) {
		seg[i] = min(seg[2*i], seg[2*i+1]);
	}

	for (int i = 1; i <= N; i++) {
		ll val = INF;
		for (int z = int(ch[i].size())-1; z >= 0; z--) {
			int cur = ch[i][z];
			suffBest[cur][0] = val - 2 * W[i];
			val = min(val, bestLeaf[cur]);
		}
		val = INF;
		for (int z = 0; z < int(ch[i].size()); z++) {
			int cur = ch[i][z];
			prefBest[cur][0] = val - 2 * W[i];
			val = min(val, bestLeaf[cur]);
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 0; par[i][j]; j++) {
			suffBest[i][j+1] = min(suffBest[par[i][j]][j], suffBest[i][j]);
			prefBest[i][j+1] = min(prefBest[par[i][j]][j], prefBest[i][j]);
		}
	}

	for (int q = 0; q < Q; q++) {
		int v, l, r; cin >> v >> l >> r;
		ll res = query(v, l, r);
		assert(res < ll(1e16));
		cout << res << '\n';
	}

	return 0;
}