#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 200013
int N, M, K;
vector<pair<int, int> > adj[MAXN];
int dist[MAXN];
vector<int> par[MAXN];
vector<string> ans;

void bfs(int start) {
	memset(dist, -1, sizeof dist);
	dist[start] = 0;
	queue<int> q;
	q.push(start);
	while (q.size()) {
		int n = q.front();
		q.pop();
		for (auto p : adj[n]) {
			int v = p.first;
			if (dist[v] == -1) {
				dist[v] = dist[n] + 1;
				q.push(v);
			}
			if (dist[v] == dist[n] + 1) {
				par[v].push_back(p.second);
			}
		}
	}
}

string state;

void go(int n) {
	if (n == N) {
		ans.push_back(state);
		return;
	}
	for (int e : par[n]) {
		state[e] = '1';
		go(n + 1);
		state[e] = '0';
		if (ans.size() >= K)
			return;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		int u, v; cin >> u >> v; --u; --v;
		adj[u].emplace_back(v, i);
		adj[v].emplace_back(u, i);
	}

	bfs(0);

	state = string(M, '0');
	go(1);

	cout << ans.size() << '\n';
	for (string s : ans)
		cout << s << '\n';
	cout.flush();
	return 0;
}