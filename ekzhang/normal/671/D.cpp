#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return v; }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

typedef long long LL;

#define MAXN 300015
#define MAXM 300015
#define MAXSEG 1048576
#define INF (1LL<<58)
int N, M;
vector<int> adj[MAXN], add[MAXN], del[MAXN];
LL C[MAXN];
LL st[MAXSEG];
LL lazy[MAXSEG];
int order[MAXM];
int o = 0;
int start[MAXN], finish[MAXN];
LL dp[MAXN];

void push(int node, int lo, int hi) {
	// Usage: push(node, lo, hi);
	if (lazy[node] == 0) return;
	st[node] += lazy[node];
	st[node] = min(st[node], INF);
	if (lo != hi) {
		lazy[2 * node + 1] += lazy[node];
		lazy[2 * node + 2] += lazy[node];
	}
	lazy[node] = 0;
}

void update_range(int s, int e, LL x, int lo=0, int hi=-1, int node=0) {
	if (hi == -1) hi = M - 1;
	push(node, lo, hi);
	if (hi < s || lo > e) return;
	if (lo >= s && hi <= e) {
		lazy[node] = x;
		push(node, lo, hi);
		return;
	}
	int mid = (lo + hi) / 2;
	update_range(s, e, x, lo, mid, 2 * node + 1);
	update_range(s, e, x, mid + 1, hi, 2 * node + 2);
	st[node] = min(st[2 * node + 1], st[2 * node + 2]);
}

void update(int i, LL x) {
	update_range(i, i, x);
}

LL query(int s, int e, int lo=0, int hi=-1, int node=0) {
	if (hi == -1) hi = M - 1;
	push(node, lo, hi);
	if (hi < s || lo > e) return INF;
	if (lo >= s && hi <= e) return st[node];
	int mid = (lo + hi) / 2;
	return min(query(s, e, lo, mid, 2 * node + 1),
			query(s, e, mid + 1, hi, 2 * node + 2));
}

void dfs(int n, int p) {
	start[n] = o;
	for (int x : add[n]) {
		order[x] = o++;
	}
	for (int x : adj[n]) {
		if (x != p) {
			dfs(x, n);
		}
	}
	finish[n] = o - 1;
}

LL solve(int n, int p) {
	// this is really also just a different kind of dfs()
	LL all = 0;
	for (int x : adj[n]) {
		if (x != p) {
			all += solve(x, n);
			all = min(all, INF);
		}
	}
	if (n == 0) return dp[n] = all;
	for (int i : add[n]) update(order[i], C[i] + all);
	for (int i : del[n]) update(order[i], INF);
	for (int x : adj[n]) {
		if (x != p) {
			update_range(start[x], finish[x], all - dp[x]);
		}
	}
	dp[n] = query(start[n], finish[n]);
	// error(n, start[n], finish[n], dp[n]);
	return dp[n];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> M;

	for (int i = 0; i < N - 1; i++) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	for (int i = 0; i < M; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		u--; v--;
		add[u].push_back(i);
		del[v].push_back(i);
		C[i] = c;
	}

	dfs(0, -1);
	assert(o == M);

	LL ans = solve(0, -1);
	cout << (ans >= INF ? -1 : ans) << endl;
	return 0;
}