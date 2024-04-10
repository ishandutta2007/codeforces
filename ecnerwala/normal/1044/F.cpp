#include<bits/stdc++.h>
using namespace std;

const int MAXN = 3e5;
int N;

// we're going to make a count0 seg tree

const int S = 1 << 18;
struct node {
	int val;
	int cnt;
} seg[2 * S];
void updateNode(int i) {
	assert(seg[i].val >= 0);
	if (seg[i].val) {
		seg[i].cnt = 0;
	} else if (i >= S) {
		seg[i].cnt = (i - S < N);
	} else {
		seg[i].cnt = seg[2*i].cnt + seg[2*i+1].cnt;
	}
}

void update(int a, int b, int v, int i = 1, int st = 0, int en = S) {
	assert(a <= b);
	assert(st <= a && a <= b && b <= en);
	if (a == b) return;
	assert(a < b);
	if (en - st == b - a) {
		seg[i].val += v;
		updateNode(i);
		return;
	}
	int md = (st + en) / 2;
	if (a < md) {
		update(a, min(md, b), v, 2 * i, st, md);
	}
	if (b > md) {
		update(max(md, a), b, v, 2 * i + 1, md, en);
	}
	updateNode(i);
}

int query() {
	return seg[1].cnt;
}

vector<int> adj[MAXN];

int V;
int st[MAXN];
int en[MAXN];
int depth[MAXN];
int par[MAXN][20];
void dfs(int cur, int prv = 0) {
	st[cur] = V;
	V++;

	depth[cur] = depth[prv] + 1;
	par[cur][0] = prv;
	for (int i = 0; par[cur][i]; i++) {
		par[cur][i+1] = par[par[cur][i]][i];
	}

	for (int nxt : adj[cur]) {
		if (nxt == prv) continue;
		dfs(nxt, cur);
	}
	en[cur] = V;
}

int getAnc(int a, int d) {
	for (int i = 0; (1 << i) <= d; i++) {
		if (d & (1 << i)) {
			a = par[a][i];
		}
	}
	return a;
}

void doUpdate(int a, int b, int v) {
	assert(a != b);
	if (depth[a] > depth[b]) swap(a, b);
	assert(depth[a] <= depth[b]);
	if (getAnc(b, depth[b] - depth[a]) == a) {
		int banc = getAnc(b, depth[b] - depth[a] - 1);
		assert(st[banc] <= st[b] && st[b] <= en[b] && en[b] <= en[banc]);
		update(st[banc], st[b], v);
		update(en[b], en[banc], v);
		return;
	}
	if (st[a] > st[b]) {
		swap(a, b);
	}
	assert(st[a] <= en[a] && en[a] <= st[b] && st[b] <= en[b]);
	update(0, st[a], v);
	update(en[a], st[b], v);
	update(en[b], N, v);
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int Q;
	cin >> N >> Q;
	for (int i = 2 * S - 1; i; i--) {
		updateNode(i);
	}
	for (int i = 0; i < N-1; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	V = 0;
	dfs(1);
	assert(V == N);

	set<pair<int, int>> edges;
	for (int i = 0; i < Q; i++) {
		int u, v; cin >> u >> v;
		if (u > v) swap(u, v);
		pair<int, int> edge(u, v);
		int val;
		if (edges.count(edge)) {
			edges.erase(edge);
			val = -1;
		} else {
			edges.insert(edge);
			val = +1;
		}
		doUpdate(u, v, val);
		cout << query() << '\n';
	}

	return 0;
}