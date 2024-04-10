#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return move(v); }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

#define MAXN 100013
#define MAXLG 20
int N, K;
vector<int> adj[MAXN];
int parent[MAXN];
int L[MAXLG][MAXN];
int depth[MAXN];

int dfsorder[MAXN];
int rdfsorder[MAXN];
int t = 0;

void dfs(int n, int p) {
	dfsorder[n] = t;
	rdfsorder[t] = n;
	++t;
	parent[n] = p;
	depth[n] = depth[p] + 1;
	for (int v : adj[n]) {
		if (v != p) {
			dfs(v, n);
		}
	}
}

void lcadp_init() {
	for (int i = 0; i < N; i++) {
		L[0][i] = parent[i];
	}
	for (int lg = 0; lg < MAXLG - 1; lg++) {
		for (int i = 0; i < N; i++) {
			L[lg+1][i] = L[lg][L[lg][i]];
		}
	}
}

int lca(int u, int v) {
	for (int lg = MAXLG - 1; lg >= 0; lg--) {
		if (depth[u] >= depth[v] + (1<<lg)) u = L[lg][u];
		if (depth[v] >= depth[u] + (1<<lg)) v = L[lg][v];
	}
	for (int lg = MAXLG - 1; lg >= 0; lg--) {
		if (L[lg][u] != L[lg][v]) {
			u = L[lg][u];
			v = L[lg][v];
		}
	}
	return (u == v ? u : parent[u]);
}

int dist(int u, int v) {
	return depth[u] + depth[v] - 2 * depth[lca(u, v)];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> K;
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(0, 0);
	lcadp_init();

	int ans = 0;
	int sz = 1;
	set<int> s;
	s.insert(dfsorder[0]);
	int lo = 0;
	int hi = 0;
	while (true) {
		if (sz <= K) {
			ans = max(ans, hi - lo + 1);
			++hi;
			if (hi == N) break;

			int a, b;
			auto it = s.lower_bound(dfsorder[hi]);
			if (it == s.end()) b = rdfsorder[*s.begin()];
			else b = rdfsorder[*it];
			if (it == s.begin()) a = rdfsorder[*(--s.end())];
			else a = rdfsorder[*(--it)];

			sz += (dist(hi, a) + dist(hi, b) - dist(a, b)) / 2;
			s.insert(dfsorder[hi]);
		}
		else {
			s.erase(dfsorder[lo]);

			int a, b;
			auto it = s.lower_bound(dfsorder[lo]);
			if (it == s.end()) b = rdfsorder[*s.begin()];
			else b = rdfsorder[*it];
			if (it == s.begin()) a = rdfsorder[*(--s.end())];
			else a = rdfsorder[*(--it)];

			sz -= (dist(lo, a) + dist(lo, b) - dist(a, b)) / 2;
			++lo;
		}
	}

	cout << ans << endl;
	return 0;
}