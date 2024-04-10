#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int MAXN = 4e5;

int N, M, Q;
vector<int> adj[MAXN];

int par[MAXN];
int dia[MAXN];

inline int c2(int a) { return (a + 1) / 2; }

int getPar(int a) {
	return (par[a] == -1) ? a : (par[a] = getPar(par[a]));
}

void merge(int a, int b) {
	a = getPar(a), b = getPar(b);
	if(a == b) return;
	par[b] = a;
	dia[a] = max(max(dia[a], dia[b]), c2(dia[a]) + c2(dia[b]) + 1);
}

// pair of distance, vertex
pii farthest(int cur, int prv = -1) {
	//cerr << cur << '\n';
	par[cur] = prv; // weee, doing extra
	pii res = pii(0, cur);
	for(int nxt : adj[cur]) {
		if(nxt == prv) continue;
		pii val = farthest(nxt, cur);
		val.first ++;
		if(val > res) res = val;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin >> N >> M >> Q;
	for(int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for(int i = 0; i < N; i++) {
		par[i] = -2;
	}

	for(int i = 0; i < N; i++) {
		if(par[i] == -2) {
			int v = farthest(i).second;
			dia[v] = farthest(v).first;
		}
	}

	for(int i = 0; i < Q; i++) {
		int t; cin >> t;
		if(t == 1) {
			int x; cin >> x;
			x--;
			cout << dia[getPar(x)] << '\n';
		} else {
			int x, y; cin >> x >> y;
			x--, y--;
			merge(x, y);
		}
	}
	return 0;
}