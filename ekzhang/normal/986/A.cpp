#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 100013
#define MAXK 103
int N, M, K, S;
int A[MAXN];
vector<int> adj[MAXN];
int dist[MAXK][MAXN];

void bfs(int k) {
	queue<int> q;
	for (int i = 0; i < N; i++) {
		if (A[i] == k) {
			q.push(i);
			dist[k][i] = 0;
		}
	}
	while (q.size()) {
		int n = q.front();
		q.pop();
		for (int v : adj[n]) if (dist[k][v] == -1) {
			dist[k][v] = dist[k][n] + 1;
			q.push(v);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> M >> K >> S;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		--A[i];
	}

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	memset(dist, -1, sizeof dist);
	for (int k = 0; k < K; k++) {
		bfs(k);
	}

	for (int i = 0; i < N; i++) {
		vector<int> v;
		for (int k = 0; k < K; k++) {
			v.push_back(dist[k][i]);
		}
		sort(v.begin(), v.end());
		int ans = 0;
		for (int j = 0; j < S; j++) {
			ans += v[j];
		}
		cout << ans << ' ';
	}

	cout << endl;
	return 0;
}