#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return move(v); }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

#define MAXN 200013
#define MAXM 200013
#define INF 1123456789
int N, M;
map<pair<int, int>, int> eidx;
pair<int, pair<int, int> > edges[MAXM];
int ufd[MAXN];
vector<int> adj[MAXN];
int parent[MAXN];
int depth[MAXN];
int sz[MAXN];
int in[MAXN], nxt[MAXN], t = 0;
int ans[MAXM];

int f(int n) {
	if (ufd[n] == n) return n;
	return ufd[n] = f(ufd[n]);
}

void dfs_sz(int n, int p) {
	if (~p) {
		depth[n] = depth[p] + 1;
		adj[n].erase(find(adj[n].begin(), adj[n].end(), p));
	}
	parent[n] = p;
	sz[n] = 1;
	for (int& v : adj[n]) {
		dfs_sz(v, n);
		sz[n] += sz[v];
		if (sz[v] > sz[adj[n][0]]) swap(v, adj[n][0]);
	}
}

void dfs_hld(int n) {
	in[n] = t++;
	for (int v : adj[n]) {
		nxt[v] = (v == adj[n][0] ? nxt[n] : v);
		dfs_hld(v);
	}
}

#define MAXSEG (1<<19)
int st[MAXSEG];
int lazy[MAXSEG];

void push(int node, int lo, int hi) {
	if (lazy[node] != INF) {
		st[node] = min(st[node], lazy[node]);
		if (lo != hi) {
			lazy[2 * node + 1] = min(lazy[2 * node + 1], lazy[node]);
			lazy[2 * node + 2] = min(lazy[2 * node + 1], lazy[node]);
		}
		lazy[node] = INF;
	}
}

void update_range(int s, int e, int x, int lo=0, int hi=-1, int node=0) {
	if (hi == -1) hi = N - 1;
	push(node, lo, hi);
	if (lo > e || hi < s) return;
	if (s <= lo && hi <= e) { lazy[node] = x; push(node, lo, hi); return; }
	int mid = (lo + hi) / 2;
	update_range(s, e, x, lo, mid, 2 * node + 1);
	update_range(s, e, x, mid + 1, hi, 2 * node + 2);
	st[node] = min(st[2 * node + 1], st[2 * node + 2]);
}

int query(int s, int e, int lo=0, int hi=-1, int node=0) {
	if (hi == -1) hi = N - 1;
	if (lo > e || hi < s) return INF;
	push(node, lo, hi);
	if (s <= lo && hi <= e) return st[node];
	int mid = (lo + hi) / 2;
	return min(query(s, e, lo, mid, 2 * node + 1),
			query(s, e, mid + 1, hi, 2 * node + 2));
}

void update_path(int a, int b, int c) {
	while (nxt[a] != nxt[b]) {
		if (depth[nxt[a]] < depth[nxt[b]]) swap(a, b);
		update_range(in[nxt[a]], in[a], c);
		a = parent[nxt[a]];
	}
	if (depth[a] < depth[b]) swap(a, b);
	update_range(in[b] + 1, in[a], c);
}

int query_path(int a, int b) {
	int ret = INF;
	while (nxt[a] != nxt[b]) {
		if (depth[nxt[a]] < depth[nxt[b]]) swap(a, b);
		ret = min(ret, query(in[nxt[a]], in[a]));
		a = parent[nxt[a]];
	}
	if (depth[a] < depth[b]) swap(a, b);
	ret = min(ret, query(in[b] + 1, in[a]));
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		--u; --v;
		edges[i] = {c, {u, v}};
		eidx[{u, v}] = eidx[{v, u}] = i;
	}

	sort(edges, edges + M);
	for (int i = 0; i < N; i++) ufd[i] = i;
	for (int i = 0; i < M; i++) {
		int u = edges[i].second.first, v = edges[i].second.second;
		int a = f(u), b = f(v);
		if (a != b) {
			ufd[b] = a;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
	}

	dfs_sz(0, -1);
	dfs_hld(0);

	for (int i = 0; i < MAXSEG; i++) {
		st[i] = lazy[i] = INF;
	}

	for (int i = 0; i < M; i++) {
		int c = edges[i].first;
		int u = edges[i].second.first, v = edges[i].second.second;
		if (parent[u] != v && parent[v] != u) {
			update_path(u, v, c);
		}
	}

	for (int i = 1; i < N; i++) {
		ans[eidx[{i, parent[i]}]] = query(in[i], in[i]);
	}

	for (int i = 0; i < M; i++) {
		int c = edges[i].first;
		int u = edges[i].second.first, v = edges[i].second.second;
		if (parent[v] == u) swap(u, v);
		if (parent[u] == v) {
			update_range(in[u], in[u], -c);
		}
	}

	for (int i = 0; i < M; i++) {
		int u = edges[i].second.first, v = edges[i].second.second;
		if (parent[u] != v && parent[v] != u) {
			ans[eidx[{u, v}]] = -query_path(u, v);
		}
	}

	for (int i = 0; i < M; i++) {
		cout << (ans[i] == INF ? -1 : ans[i] - 1) << ' ';
	}
	cout << endl;
	return 0;
}