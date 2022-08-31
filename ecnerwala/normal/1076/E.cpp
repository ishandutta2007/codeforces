#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 4e5;
int N;
vector<int> adj[MAXN];

vector<pair<int, ll>> ops[MAXN];

ll bit[MAXN];
void update(int a, ll v) {
	// update upwards
	for (int i = a; i <= N; i += (i & (-i))) {
		bit[i] += v;
	}
}
ll query(int a) {
	ll res = 0;
	for (int i = a; i > 0; i -= (i & (-i))) {
		res += bit[i];
	}
	return res;
}

ll ans[MAXN];
void dfs(int cur = 1, int prv = 0, int depth = 1) {
	for (auto it : ops[cur]) {
		int d = min(N, depth + it.first);
		ll v = it.second;
		update(depth, v);
		update(d+1, -v);
	}
	ans[cur] = query(depth);
	for (int nxt : adj[cur]) {
		if (nxt == prv) continue;
		dfs(nxt, cur, depth+1);
	}
	for (auto it : ops[cur]) {
		int d = min(N, depth + it.first);
		ll v = it.second;
		update(depth, -v);
		update(d+1, v);
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	for (int i = 0; i < N-1; i++) {
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	int M; cin >> M;
	for (int i = 0; i < M; i++) {
		int v; int d; ll x; cin >> v >> d >> x;
		ops[v].emplace_back(d, x);
	}
	dfs();
	for (int i = 1; i <= N; i++) {
		cout << ans[i] << " \n"[i==N];
	}

	return 0;
}