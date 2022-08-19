#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1.1e5;
const int MAXM = 1.1e5;
int N, M;
vector<int> adj[MAXN];

int inDeg[MAXN];
bool inStack[MAXN];
bool vis[MAXN];

void dfs(int cur) {
	if (vis[cur]) return;
	vis[cur] = true;
	inStack[cur] = true;
	int s = 0;
	for (int i = 0; i < int(adj[cur].size()); i++) {
		int nxt = adj[cur][i];
		if (inStack[nxt]) {
			// ancestor edge, so delete it
			continue;
		} else {
			adj[cur][s++] = nxt;
			inDeg[nxt]++;
		}

		dfs(nxt);
	}
	adj[cur].resize(s);
	inStack[cur] = false;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
	}

	for (int i = 1; i <= N; i++) {
		dfs(i);
	}

	stack<int> cnds;
	for (int i = 1; i <= N; i++) {
		if (inDeg[i] == 0) {
			cnds.push(i);
		}
	}
	while (cnds.size() >= 2) {
		int a = cnds.top(); cnds.pop();
		int b = cnds.top(); cnds.pop();
		cout << "?" << ' ' << a << ' ' << b << '\n' << flush;
		int r; cin >> r;
		if (r == 1) {
			// take a
		} else {
			// take b
			swap(a,b);
		}
		// take a, kill b
		for (int nxt : adj[b]) {
			if (--inDeg[nxt] == 0) {
				cnds.push(nxt);
			}
		}
		cnds.push(a);
	}
	cout << "!" << ' ' << cnds.top() << '\n' << flush;
}