#include <bits/stdc++.h>

using namespace std;

#define MN 200100
#define UNVISITED -1

int num[MN], vis[MN], component[MN], n, m, low[MN], counter, root, numSCC, sz[MN];
stack<int> S;
vector<int> adj[MN];

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
			sz[numSCC]++;
			if (u == v) break;
		}
		numSCC++;
	}
}

void tarjan() {
	counter = numSCC = 0;
	memset(&num, UNVISITED, sizeof num);
	memset(&vis, 0, sizeof vis);
	memset(&low, 0, sizeof low);
	for (int i = 1; i <= n; i++) {
		if (num[i] == UNVISITED)
			dfs(i);
	}
}

struct union_find {
    vector<int> parent, rank_;

    union_find(int n) {
        init(n);
    }

    void init(int n) {
        parent.resize(n + 1); rank_.resize(n + 1);
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
            rank_[i] = 1;
        }
    }

    int find(int node) {
        if(node == parent[node]) return node;
        return parent[node] = find(parent[node]);
    }

    bool join(int a, int b) {
        a = find(a); b = find(b);
        if(a == b) return false;

        if(rank_[a] > rank_[b]) {
            parent[b] = a;
            rank_[a] += rank_[b];
        } else {
            parent[a] = b;
            rank_[b] += rank_[a];
        }
        return true;
    }
};

int cyc[MN];

int main() {
    scanf("%d %d", &n, &m);
    union_find dsu(n);

    for(int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        dsu.join(a, b);
    }

    tarjan();
    for(int i = 1; i <= n; i++) {
        if(sz[component[i]] > 1) cyc[dsu.find(i)] = 1;
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(dsu.find(i) == i) {
            ans += dsu.rank_[i] - 1 + cyc[i];
        }
    }

    printf("%d\n", ans);
    return 0;
}