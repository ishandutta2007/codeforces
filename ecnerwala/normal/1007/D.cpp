#include<bits/stdc++.h>
using namespace std;

struct two_sat {
	static const int MAXV = 3.1e6;
	int V;
	vector<int> implies[MAXV*2];

	int new_var() {
		assert(V < MAXV);
		return ((V++) * 2 + 1);
	}

	inline int n(int a) {
		return a ^ 1;
	}

	// a implies b
	void constrain(int a, int b) {
		if (a < 0 || b < 0) return;
		implies[a].push_back(b);
		implies[n(b)].push_back(n(a));
	}

	int make_and(int a, int b) {
		if (a < 0) return b;
		if (b < 0) return a;
		int v = new_var();
		constrain(v, a);
		constrain(v, b);
		return v;
	}

	int make_or(int a, int b) {
		if (a < 0) return b;
		if (b < 0) return a;
		int v = new_var();
		constrain(a, v);
		constrain(b, v);
		return v;
	}

	int make_at_most_one(int a, int b) {
		if (a < 0) return b;
		if (b < 0) return a;
		constrain(a, n(b)); // contrapositive is automatic
		return make_or(a, b);
	}

	bool solution[MAXV*2];
	bool vis[2][MAXV*2];
	int q[2][MAXV*2];

	bool solve() {
		for (int i = 0; i < 2*V; i++) {
			solution[i] = false;
			vis[0][i] = vis[1][i] = false;
		}
		for (int i = 0; i < V; i++) {
			if (!solution[2*i+0] && !solution[2*i+1]) {
				// we have to do the search
				bool bad[2] = {false, false};
				int qs[2] = {0, 0};
				int qi[2] = {0, 0};
				int qt[2] = {0, 0};
				for (int z = 0; z < 2; z++) {
					vis[z][2*i+z] = true;
					q[z][qt[z]++] = 2*i+z;
				}
				while (true) {
					if (bad[0] && bad[1]) {
						return false;
					}
					for (int z = 0; z < 2; z++) {
						if (bad[z]) continue;
						if (qs[z] >= qt[z]) {
							// we're done, so we should finalize it
							for (int ind = 0; ind < qt[z]; ind++) {
								solution[q[z][ind]] = true;
							}
							bad[!z] = true;
							goto done;
						}
						int v = q[z][qs[z]];
						if (qi[z] == int(implies[v].size())) {
							qs[z] ++;
							qi[z] = 0;
							continue;
						}

						int u = implies[v][qi[z]];
						assert(!solution[n(u)]);
						if (vis[z][n(u)]) {
							bad[z] = true;
						} else if (!solution[u] && !vis[z][u]) {
							vis[z][u] = true;
							q[z][qt[z]++] = u;
						}

						qi[z] ++;
					}
				}
done:
				assert(bad[0] + bad[1] == 1);
				// reset vis
				for (int z = 0; z < 2; z++) {
					for (int ind = 0; ind < qt[z]; ind++) {
						vis[z][q[z][ind]] = false;
					}
				}
			}
			assert(solution[2*i+0] + solution[2*i+1] == 1);
		}
		return true;
	}

} ts;

const int MAXN = int(1e5) + 20;
int N;
vector<int> adj[MAXN];
int depth[MAXN];
int par[MAXN][20];
int var[MAXN][20];

int lca(int a, int b, int v) {
	if (depth[a] != depth[b]) {
		if (depth[a] > depth[b]) swap(a,b);
		assert(depth[b] > depth[a]);
		int d = depth[b] - depth[a];
		assert(d > 0);
		for (int i = 0; (1 << i) <= d; i++) {
			if (d & (1 << i)) {
				var[b][i] = ts.make_at_most_one(var[b][i], v);
				b = par[b][i];
			}
		}
	}
	if (a == b) return a;
	int i = 0;
	while (par[a][i] != par[b][i]) i++;
	assert(par[a][i] == par[b][i]);
	for (; i > 0; i--) {
		assert(par[a][i] == par[b][i]);
		if (par[a][i-1] != par[b][i-1]) {
			var[a][i-1] = ts.make_at_most_one(var[a][i-1], v);
			a = par[a][i-1];
			var[b][i-1] = ts.make_at_most_one(var[b][i-1], v);
			b = par[b][i-1];
		}
		assert(par[a][i-1] == par[b][i-1]);
	}
	assert(par[a][0] == par[b][0]);

	var[a][0] = ts.make_at_most_one(var[a][0], v);
	a = par[a][0];

	var[b][0] = ts.make_at_most_one(var[b][0], v);
	b = par[b][0];

	assert(a == b);

	return a;
}

void dfs_lca(int cur, int prv = 0) {
	depth[cur] = depth[prv]+1;
	par[cur][0] = prv;
	for (int i = 0; par[cur][i] != 0; i++) {
		par[cur][i+1] = par[par[cur][i]][i];
	}
	for (int nxt : adj[cur]) {
		if (nxt == prv) continue;
		dfs_lca(nxt, cur);
	}
}

const int MAXM = 1.1e4;
int M;
int ant_vars[MAXM];

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N-1; i++) {
		int u,v; scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	depth[0] = 0;
	dfs_lca(1);
	memset(var, -1, sizeof(var));

	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		int v = ts.new_var();
		ant_vars[i] = v;
		for (int z = 0; z < 2; z++, v = ts.n(v)) {
			int a[2]; scanf("%d %d", &a[0], &a[1]);
			lca(a[0], a[1], v);
		}
	}

	for (int i = 19; i > 0; i--) {
		for (int cur = 1; cur <= N; cur++) {
			if (!par[cur][i]) continue;
			int prv = par[cur][i-1];
			var[prv][i-1] = ts.make_at_most_one(var[prv][i-1], var[cur][i]);
			var[cur][i-1] = ts.make_at_most_one(var[cur][i-1], var[cur][i]);
		}
	}

	if (ts.solve()) {
		printf("YES\n");
		for (int i = 0; i < M; i++) {
			printf("%c\n", ts.solution[ant_vars[i]] ? '1' : '2');
		}
	} else {
		printf("NO\n");
	}

	return 0;
}