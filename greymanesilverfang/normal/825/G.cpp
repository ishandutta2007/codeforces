#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int INF = 1e9, MAX_N = 1e6 + 1;

bool chk[MAX_N] = {};
int prv[MAX_N], ans[MAX_N] = {INF}, last = 0;
vector<int> adj[MAX_N];

void BuildTree(int x) {
	queue<int> Q; Q.push(x); 
	ans[x] = min(x, ans[prv[x] = 0]);
	while (!Q.empty()) {
		int cur = Q.front();
		for (int i = 0; i < adj[cur].size(); ++i) {
			int nxt = adj[cur][i];
			if (nxt != prv[cur]) {
				Q.push(nxt); 
				ans[nxt] = min(nxt, ans[prv[nxt] = cur]);
			}
		}
		Q.pop();
	}
}

int main() {
	int n, q; scanf("%d%d", &n, &q);
	for (int i = 1; i < n; ++i) {
		int u, v; scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int root; scanf("%*d%d", &root); (root %= n)++;
	BuildTree(root); chk[root] = true;
	while (--q) {
		int query, x; scanf("%d%d", &query, &x); ((x += last) %= n)++;
		if (query == 1) while (!chk[x]) {
			ans[root] = min(ans[root], x);
			chk[x] = true; x = prv[x];
		} else printf("%d\n", last = min(ans[x], ans[root]));
	}
	return 0;
}