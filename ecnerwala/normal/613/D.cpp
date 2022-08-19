#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define A first
#define B second

const int MAXN = 2e5;

int N;
vector<int> adj[MAXN];
int V;
int loc[MAXN]; // location in the pre-order traversal

int depth[MAXN];
int par[MAXN][20];
int en[MAXN]; // end of subtree, not inclusive

void dfs(int cur, int prv) {
	for(int nxt : adj[cur]) {
		if(nxt == prv) continue;
		loc[nxt] = V ++;
		depth[loc[nxt]] = depth[loc[cur]] + 1;
		par[loc[nxt]][0] = loc[cur];
		for(int i = 0; par[loc[nxt]][i]; i++) {
			par[loc[nxt]][i + 1] = par[par[loc[nxt]][i]][i];
		}
		dfs(nxt, cur);
	}
	en[loc[cur]] = V;
}

int lca(int a, int b) {
	if(depth[a] < depth[b]) swap(a, b);
	assert(depth[a] >= depth[b]);
	for(int i = 19; i >= 0; i--) {
		if((depth[a] - depth[b]) & (1 << i)) {
			if(par[a][i] == b) {
				for(int j = i - 1; j >= 0; j--) {
					a = par[a][j];
				}
				return a;
			}
			a = par[a][i];
		}
	}
	assert(a != b);
	assert(depth[a] == depth[b]);
	for(int i = 19; i >= 0; i--) {
		if(par[a][i] != par[b][i]) {
			a = par[a][i], b = par[b][i];
		}
	}
	assert(a != b);
	assert(depth[a] == depth[b]);
	assert(par[a][0] == par[b][0]);
	return par[a][0];
}

const int MAXK = MAXN;
int K;
int plan[MAXK];
int prv[MAXK];
int nxt[MAXK];

int query() {
	cin >> K;
	for(int i = 0; i < K; i++) {
		int v; cin >> v; plan[i] = loc[v];
	}
	sort(plan, plan + K);
	for(int i = 1; i < K; i++) {
		if(binary_search(plan, plan + K, par[plan[i]][0])) return -1;
	}

	for(int i = 0; i < K; i++) {
		prv[i] = i - 1; nxt[i] = i + 1;
	}

	priority_queue<pair<pii, pii>> merge;
	for(int i = 0; i + 1 < K; i++) {
		int l = lca(plan[i], plan[i + 1]);
		assert(l != plan[i + 1]);
		assert(l != plan[i]);
		assert(l < plan[i + 1]);
		merge.emplace(pii(depth[l], l), pii(i, i + 1));
	}

	int res = 0;
	while(!merge.empty()) {
		int l = merge.top().A.B;
		pii a = merge.top().B;
		merge.pop();
		if(prv[a.A] == a.A || prv[a.B] == a.B) continue;

		res++;

		// remove v until the en[l];
		assert(l != plan[a.A]);
		assert(l != plan[a.B]);
		assert(l < plan[a.B]);
		int v = (l < plan[a.A]) ? a.A : a.B;
		int p = prv[v];
		while(p >= 0 && plan[p] > l) {
			int tmp = prv[p];
			prv[p] = p;
			p = tmp;
		}
		while(v < K && plan[v] < en[l]) {
			prv[v] = v;
			v = nxt[v];
		}
		if(p != -1) nxt[p] = v;
		if(v != K) prv[v] = p;
		if(p != -1 && v != K) {
			l = lca(plan[p], plan[v]);
			assert(l != plan[v]);
			assert(l != plan[p]);
			assert(l < plan[v]);
			merge.emplace(pii(depth[l], l), pii(p, v));
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin >> N;
	for(int i = 0; i < N - 1; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	loc[1] = 0;
	depth[0] = 0;
	par[0][0] = 0;
	V = 1;

	dfs(1, 0);
	assert(V == N);

	int Q;
	cin >> Q;
	for(int q = 0; q < Q; q++) {
		cout << query() << '\n';
	}

	return 0;
}