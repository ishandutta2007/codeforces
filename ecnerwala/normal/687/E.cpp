#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;

const int MAXN = 6e3;
const int MAXM = 1e4;

int N, M;

vector<int> adj[MAXN];
int dist[MAXN][MAXN];

int main() {
	ios_base::sync_with_stdio(0);
	cin >> N >> M;
	for(int i = 0; i < M; i++) {
		int u, v; cin >> u >> v; u--, v--;
		adj[u].push_back(v);
	}

	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) dist[i][j] = 0;
		queue<int> q;
		for(int j : adj[i]) dist[i][j] = 1, q.push(j);
		while(!q.empty()) {
			int j = q.front(); q.pop();
			for(int k : adj[j]) {
				if(!dist[i][k]) dist[i][k] = dist[i][j] + 1, q.push(k);
			}
		}
	}

	int res = N;
	for(int i = 0; i < N; i++) {
		bool is_sink = dist[i][i];
		int min_cyc = dist[i][i];
		for(int j = 0; j < N; j++) {
			if(dist[i][j]) {
				if(!dist[j][i]) {
					// we're not a sink
					is_sink = false;
					break;
				}
				assert(dist[i][j] && dist[j][i]);
				if(j < i) {
					// we can reach something lower, we're not the representative
					is_sink = false;
					break;
				}
				assert(dist[i][i]);
				assert(dist[j][j]);
				min_cyc = min(min_cyc, dist[j][j]);
			}
		}
		if(is_sink) {
			res += (min_cyc * 998 + 1);
		}
	}
	cout << res << '\n';

	return 0;
}