#include <bits/stdc++.h>

using namespace std;

#define MN 200100
#define UNVISITED -1

int num[MN], vis[MN], component[MN], N, M, low[MN], counter, root, numSCC;
stack<int> S;
vector<int> adj[MN], adj2[MN];

void dfs(int u) {
	low[u] = num[u] = counter++;
	S.push(u);
	vis[u] = 1;
	int v;
	for(int v : adj[u]) {
		if (num[v] == UNVISITED) dfs(v);
		if (vis[v]) low[u] = min(low[u], low[v]);
	}
	if (low[u] == num[u]) {
		while (true) {
			v = S.top(); S.pop(); vis[v] = 0;
			component[v] = numSCC;
			if (u == v) break;
		}
		numSCC++;
	}
}

void tarjan(int N) {
	counter = numSCC = 0;
	memset(&num, UNVISITED, sizeof num);
	memset(&vis, 0, sizeof vis);
	memset(&low, 0, sizeof low);
	for (int i = 1; i <= N; i++) {
		if (num[i] == UNVISITED)
			dfs(i);
	}
}

int n, m, k, ans, deg[MN];

int main() {
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
    }
    tarjan(n);
    for(int i = 1; i <= n; i++) {
        for(int v : adj[i]) {
            if(component[i] == component[v]) continue;
            adj2[component[i]].push_back(component[v]);
            deg[component[v]]++;
        }
    }

    for(int i = 0; i < numSCC; i++)
        if(deg[i] == 0 && component[k] != i)
            ans++;

    printf("%d\n", ans);
    return 0;
}