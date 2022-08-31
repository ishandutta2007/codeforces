#include<bits/stdc++.h>
using namespace std;

int N, M;
const int MAXN = 1e4;
list<int> rev[MAXN];
int V;
bool vis[MAXN];

// a presents to b
bool dfs(int a, int b) {
	if (vis[a]) return false;
	vis[a] = true;
	// insert b into rev[a]
	if (int(rev[a].size()) < V) {
		rev[a].push_back(b);
		return true;
	}
	for (list<int>::iterator it = rev[a].begin(); it != rev[a].end(); it++) {
		int nb = *it;
		if (dfs(nb, a)) {
			rev[a].erase(it);
			rev[a].push_back(b);
			return true;
		}
	}
	return false;
}

bool do_edge(int a, int b) {
	memset(vis, false, sizeof(vis));
	return dfs(a, b);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		if (do_edge(a, b) || do_edge(b, a)) {
			// we're good
		} else {
			V++;
			bool r = do_edge(a, b) || do_edge(b, a);
			assert(r);
		}
	}
	cout << V << '\n';
	for (int i = 1; i <= N; i++) {
		for (int j : rev[i]) {
			cout << i << ' ' << j << '\n';
		}
	}

	return 0;
}