#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll INF = 1e18;

const int MAXN = 30;
const int MAXM = 30;

int N, M;

char grid[MAXN][MAXM];
int vert[MAXN][MAXM];

const int MAXS = 600;
int S; // number of squares
ll dist[MAXS][MAXS];

const int MAXP = MAXS;
int P[2];

int loc[2][MAXP];
ll vel[2][MAXP];

const int MAXV = MAXS * 2 + 2 * MAXP;

int V;
unordered_set<int> adj[MAXV];


int level[MAXV];
vector<int> lev[MAXV];

bool blocking_flow(int a, int en) {
	if(a == en) return true;
	while(lev[a].size()) {
		int n = lev[a].back();
		lev[a].pop_back();
		if(blocking_flow(n, en)) {
			adj[a].erase(n);
			adj[n].insert(a);
			return true;
		}
	}
	return false;
}

int max_flow(int st, int en) {
	int res = 0;
	while(true) {
		memset(level, 0, sizeof(level));
		queue<int> q;
		level[st] = 1;
		lev[st].clear();
		q.push(st);
		while(!q.empty()) {
			int v = q.front();
			if(v == en) break;

			q.pop();

			for(int n : adj[v]) {
				if(!level[n]) {
					level[n] = level[v] + 1;
					lev[n].clear();
					q.push(n);
				}
				if(level[n] == level[v] + 1) {
					lev[v].push_back(n);
				}
			}
		}

		if(q.empty()) break;

		while(blocking_flow(st, en)) {
			res++;
		}
	}

	return res;
}

bool is_good(ll time) {
	V = 2 * S;
	for(int i = 0; i < S; i++) {
		adj[2 * i].insert(2 * i + 1);
	}
	int st = V++, en = V++;
	for(int i = 0; i < P[0]; i++) {
		int v = V++;
		adj[st].insert(v);
		for(int s = 0; s < S; s++) {
			if(dist[loc[0][i]][s] <= time / vel[0][i]) {
				adj[v].insert(2 * s);
			}
		}
	}

	for(int i = 0; i < P[1]; i++) {
		int v = V++;
		adj[v].insert(en);
		for(int s = 0; s < S; s++) {
			if(dist[loc[1][i]][s] <= time / vel[1][i]) {
				adj[2 * s + 1].insert(v);
			}
		}
	}


	int flow = max_flow(st, en);
	for(int i = 0; i < V; i++) {
		adj[i].clear();
	}

	if(flow == P[0]) return true;

	return false;
}

void process_grid() {
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			if(grid[i][j] == '.') vert[i][j] = S++;
			else vert[i][j] = -1;
		}
	}

	for(int i = 0; i < S; i++) {
		for(int j = 0; j < S; j++) {
			dist[i][j] = INF;
		}
		dist[i][i] = 0;
	}

	for(int i = 0; i < N; i++) {
		for(int j = 0; j + 1 < M; j++) {
			int l = vert[i][j], r = vert[i][j + 1];
			if(l >= 0 && r >= 0) {
				dist[l][r] = dist[r][l] = 1;
			}
		}
	}
	for(int i = 0; i + 1 < N; i++) {
		for(int j = 0; j < M; j++) {
			int l = vert[i][j], r = vert[i + 1][j];
			if(l >= 0 && r >= 0) {
				dist[l][r] = dist[r][l] = 1;
			}
		}
	}

	for(int k = 0; k < S; k++) {
		for(int i = 0; i < S; i++) {
			for(int j = 0; j < S; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
}

ll go() {
	cin >> N >> M >> P[0] >> P[1];
	for(int i = 0; i < N; i++) {
		cin >> grid[i];
	}
	process_grid();
	
	if(abs(P[0] - P[1]) != 1) return -1;
	if((P[0] + P[1] + 1) / 2 > S) return -1;

	if(P[0] < P[1]) {
		int i, j, t;
		cin >> i >> j >> t;
		i--, j--;
		loc[0][P[0]] = vert[i][j];
		vel[0][P[0]] = t;
	} else {
		int i, j, t;
		cin >> i >> j >> t;
		i--, j--;
		loc[1][P[1]] = vert[i][j];
		vel[1][P[1]] = t;
	}

	for(int s = 0; s < 2; s++) {
		for(int a = 0; a < P[s]; a++) {
			int i, j, t;
			cin >> i >> j >> t;
			i--, j--;
			loc[s][a] = vert[i][j];
			vel[s][a] = t;
		}
	}

	P[0] = P[1] = (P[0] + P[1] + 1) / 2;

	/*
	cerr << "hi\n";

	for(int i = 0; i < S; i++) {
		for(int j = 0; j < S; j++) {
			cerr << dist[i][j] << ' ';
		}
		cerr << '\n';
	}
	cerr << '\n';

	for(int v = 0; v < 2; v++) {
		cerr << P[v] << '\n';
		for(int i = 0; i < P[v]; i++) {
			cerr << loc[v][i] << ' ' << vel[v][i] << '\n';
		}
		cerr << '\n';
	}
	*/

	ll mi = -1;
	ll ma = INF - 1;

	if(!is_good(ma)) return -1;

	while(ma - mi > 1) {
		ll md = (mi + ma) / 2;
		if(is_good(md)) {
			ma = md;
		} else {
			mi = md;
		}
	}

	return ma;
}

int main() {
	ios_base::sync_with_stdio(0);

	cout << go() << '\n';

	return 0;
}