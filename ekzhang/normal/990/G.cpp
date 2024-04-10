#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> pii;
const double PI = 4 * atan(1);

#define MAXN 200013
#define MAX 200013
int N;
int A[MAXN];
vector<int> adj[MAXN];
bool vis[MAXN];
vector<int> divisors[MAX];
vector<int> verts[MAX];
LL func[MAX];

inline int dfs(int n) {
	vis[n] = true;
	register int ret = 1;
	for (int v : adj[n])
		if (!vis[v])
			ret += dfs(v);
	return ret;
}

LL solve(int val) {
	LL total = 0;
	for (int v : verts[val])
		vis[v] = false;
	for (int v : verts[val]) if (!vis[v]) {
		LL sz = dfs(v);
		total += sz * (sz + 1) / 2;
	}
	return total;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for (int d = 1; d < MAX; d++) {
		for (int n = d; n < MAX; n += d) {
			divisors[n].push_back(d);
		}
	}

	// freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		for (int d : divisors[A[i]]) {
			verts[d].push_back(i);
		}
	}

	for (int i = 1; i < N; i++) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	memset(vis, 1, sizeof vis);
	for (int val = 1; val < MAX; val++) {
		func[val] = solve(val);
	}

	for (int x = MAX - 1; x; x--) {
		LL cur = func[x];
		for (int y = 2 * x; y < MAX; y += x) {
			cur -= func[y];
		}
		func[x] = cur;
	}

	for (int x = 1; x < MAX; x++) {
		if (func[x])
			cout << x << ' ' << func[x] << '\n';
	}

	cout.flush();
	return 0;
}