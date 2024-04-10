#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1.1e5;
const int MAXM = 5.1e5;
const int MAXV = MAXN * 2;
const int MAXQ = 2.1e5;

int N;
int M;
vector<int> adj[MAXN];
int depth[MAXN];
stack<pair<int, int>> stk;

int V;
vector<int> ch[MAXV];

int bcc(int cur, int prv = 0) {
	depth[cur] = depth[prv] + 1;
	if (prv) stk.emplace(prv, cur);
	int lv = depth[cur];
	for (int nxt : adj[cur]) {
		if (nxt == prv) continue;
		if (depth[nxt]) {
			if (depth[nxt] < depth[cur]) {
				lv = min(lv, depth[nxt]);
			}
			continue;
		}
		int nlv = bcc(nxt, cur);
		if (nlv < depth[cur]) {
			lv = min(lv, nlv);
			continue;
		}
		assert(nlv == depth[cur] || nlv == depth[nxt]);
		int vert = V++;
		while (true) {
			int a = stk.top().first, b = stk.top().second;
			stk.pop();
			ch[vert].push_back(b);
			if (a == cur) break;
		}
		ch[cur].push_back(vert);
	}
	return lv;
}

int d2[MAXV];
int par[MAXV][20];
void dfs(int cur, int prv = 0) {
	d2[cur] = d2[prv] + 1;
	par[cur][0] = prv;
	for (int i = 0; par[cur][i]; i++) {
		par[cur][i+1] = par[par[cur][i]][i];
	}
	for (int nxt : ch[cur]) {
		dfs(nxt, cur);
	}
}

int lca(int a, int b) {
	if (d2[a] < d2[b]) swap(a,b);
	for (int i = 0; d2[a] > d2[b]; i++) {
		if ((d2[a] - d2[b]) & (1 << i)) {
			a = par[a][i];
		}
	}
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
	return par[a][0];
}

int dist(int a, int b) {
	int c = lca(a,b);
	int r = (d2[a] - d2[c]) + (d2[b] - d2[c]);
	assert(r % 2 == 0);
	return r / 2;
}

int Q;

int main() {
	ios_base::sync_with_stdio(0);
	cin >> N >> M >> Q;
	for (int i = 0; i < M; i++) {
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	V = N+1;
	bcc(1);
	dfs(1);

	for (int i = 0; i < Q; i++) {
		int x, y; cin >> x >> y;
		cout << dist(x, y) << '\n';
	}

	return 0;
}