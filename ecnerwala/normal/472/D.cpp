#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define A first
#define B second

const int MAXN = 3000;

int N;
int D[MAXN][MAXN];

int par[MAXN];
vector<pii> adj[MAXN];

int getpar(int a) {
	return (par[a] == a) ? a : (par[a] = getpar(par[a]));
}

bool merge(int a, int b, int d) {
	int pa = getpar(a), pb = getpar(b);
	if(pa == pb) return false;
	par[pa] = pb;
	adj[a].push_back(pii(b, d));
	adj[b].push_back(pii(a, d));
	//cerr << a << ' ' << b << ' ' << d << '\n';
	return true;
}

bool dfs(int root, int cur, int prv = -1) {
	for(pii edg : adj[cur]) {
		int nxt = edg.A;
		if(nxt == prv) continue;
		int dist = D[root][cur] + edg.B;
		if(dist != D[root][nxt]) return false;
		if(!dfs(root, nxt, cur)) return false;
	}
	return true;
}

bool go() {
	vector<pair<int, pii>> edges;
	for(int i = 0; i < N; i++) {
		if(D[i][i] != 0) return false;
		for(int j = i + 1; j < N; j++) {
			if(D[i][j] != D[j][i]) return false;
			if(D[i][j] == 0) return false;
			edges.push_back(make_pair(D[i][j], pii(i, j)));
		}
	}

	sort(edges.begin(), edges.end());

	for(int i = 0; i < N; i++) par[i] = i;
	for(auto it : edges) {
		merge(it.B.A, it.B.B, it.A);
	}

	for(int i = 0; i < N; i++) {
		if(!dfs(i, i)) return false;
	}
	return true;
}

int main() {
ios_base::sync_with_stdio(0);
	cin >> N;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			cin >> D[i][j];
		}
	}
	cout << (go() ?  "YES" : "NO") << '\n';
	return 0;
}