#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

const int maxn = 100001;

vector<int> adj[maxn];
int cnt[maxn], max_ch[maxn], prt[maxn], top[maxn], dep[maxn], max_dep[maxn];
priority_queue<int> q;
int cur;

void dfs0(int u);
void dfs1(int u);
void dfs2(int u);

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int s = 0;
	for (int i = 1; i <= n; i++) {
		if (adj[i].size() == 1) {
			s = i;
			break;
		}
	}
	dfs0(s);
	dep[cur] = 0;
	prt[cur] = 0;
	dfs1(cur);
	dfs2(cur);
	int i = 2;
	int cur = 0;
	printf("1 ");
	while (!q.empty()) {
		cur += q.top();
		q.pop();
		i++;
		printf("%d ", cur);
	}
	for (; i <= n; i++) {
		printf("%d ", cur);
	}
	return 0;
}

void dfs1(int u) {
	cnt[u] = 1;
	max_dep[u] = dep[u];
	max_ch[u] = 0;
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (v == prt[u]) continue;
		prt[v] = u;
		dep[v] = dep[u] + 1;
		dfs1(v);
		if (!max_ch[u] || max_dep[v] > max_dep[u]) max_ch[u] = v, max_dep[u] = max_dep[v];
		cnt[u] += cnt[v];
	}
}

void dfs2(int u) {
	if (!prt[u] || u != max_ch[prt[u]]) {
		top[u] = u;
	}
	else {
		top[u] = top[prt[u]];
	}
	if (!max_ch[u]) {
		q.push(dep[u] - dep[top[u]] + 1);
	}
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (v == prt[u]) continue;
		dfs2(v);
	}
}

void dfs0(int u) {
	if (!cur || dep[cur] < dep[u]) cur = u;
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (v == prt[u]) continue;
		prt[v] = u;
		dep[v] = dep[u] + 1;
		dfs0(v);
	}
}