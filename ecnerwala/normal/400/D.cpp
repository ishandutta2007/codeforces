#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MAXN = 2e5;
const int MAXK = 1000;

const int INF = 1e9;

int N, M, K;
int C[MAXK];
int T[MAXN];
vector<int> adj[MAXN];
int D[MAXK][MAXK];

int vis[MAXN];

void dfs(int cur) {
	vis[cur] = true;
	for(__typeof(adj[cur].begin()) it = adj[cur].begin(); it != adj[cur].end(); it++) {
		int nxt = *it;
		if(vis[nxt]) continue;
		//cerr << cur << ' ' << nxt << '\n';
		dfs(nxt);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin >> N >> M >> K;
	int v = 0;
	for(int i = 0; i < K; i++) {
		cin >> C[i];
		for(int j = 0; j < C[i]; j++) {
			T[v++] = i;
		}
	}
	for(int i = 0; i < K; i++) {
		for(int j = 0; j < K; j++) {
			D[i][j] = (i == j) ? 0 : INF;
		}
	}
	for(int i = 0; i < M; i++) {
		int u, v, x; cin >> u >> v >> x; u--, v--;
			if(x == 0) {
				adj[u].push_back(v);
				adj[v].push_back(u);
			}
		if(T[u] == T[v]) {

		} else {
			if(x < D[T[u]][T[v]]) {
				D[T[u]][T[v]] = D[T[v]][T[u]] = x;
			}
		}
	}
	cerr << "input read\n";
bool good = true;
	for(int i = 0; i < N && good; i++) {
		if(!vis[i]) {
if(i > 0 && T[i] == T[i - 1]) good = false;
else dfs(i);
}
	}
	if(good) {
		cout << "Yes" << '\n';
		for(int k = 0; k < K; k++) {
			for(int i = 0; i < K; i++) {
				for(int j = 0; j < K; j++) {
					int v = D[i][k] + D[k][j];
					if(v < D[i][j]) D[i][j] = v;
				}
			}
		}
		for(int i = 0; i < K; i++) {
			for(int j = 0; j < K; j++) {
				if(D[i][j] == INF) D[i][j] = -1;
				cout << D[i][j] << ' ';
			}
			cout << '\n';
		}
	} else  {
		cout << "No" << '\n';
	}
	return 0;
}