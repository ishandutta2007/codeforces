#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> edge;

const int MAXN = 20;
const int MAXM = 20;
const int MAXK = 1020;
const int MAXW = 1500;

int N, M, K, W;

char S[MAXK][MAXN][MAXM];

int E;
edge edges[MAXK * MAXK];

int par[MAXK];

vector<int> adj[MAXK];

int getPar(int a) { return (par[a] == a) ? a : (par[a] = getPar(par[a])); }
bool merge(int a, int b) {
	int na = getPar(a), nb = getPar(b);
	if(na == nb) return false;
	par[na] = nb;
	adj[a].push_back(b);
	adj[b].push_back(a);
	return true;
}

void dfs(int c = 0, int p = -1) {
	if(c) cout << c << ' ' << p << '\n';
	for(int i = 0; i < adj[c].size(); i++) {
		int n = adj[c][i];
		if(n == p) continue;
		dfs(n, c);
	}
}

int main() {
	cin >> N >> M >> K >> W;
	for(int k = 1; k <= K; k++) {
		for(int i = 0; i < N; i++) {
			cin >> S[k][i];
		}
	}
	E = 0;
	for(int k = 1; k <= K; k++) {
		edges[E++] = edge(N * M, pii(0, k));
		for(int l = k + 1; l <= K; l++) {
			int c = 0;
			for(int i = 0; i < N; i++) {
				for(int j = 0; j < M; j++) {
					if(S[k][i][j] != S[l][i][j]) {
						c += W;
					}
				}
			}
			//cerr << k << ' ' << l << ' ' << c << '\n';
			edges[E++] = edge(c, pii(k, l));
		}
	}
	K++;
	for(int i = 0; i < K; i++) par[i] = i;
	long long cost = 0;
	sort(edges, edges + E);
	for(int i = 0; i < E; i++) {
		if(merge(edges[i].second.first, edges[i].second.second)) {
			//cerr << edges[i].second.first << ' ' << edges[i].second.second << '\n';
			cost += edges[i].first;
		}
	}
	cout << cost << '\n';
	dfs();
	return 0;
}