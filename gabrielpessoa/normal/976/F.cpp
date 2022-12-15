#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;

const int ms = 5e3+5, me = 2e4+5, inf = 0x3f3f3f3f;
int copy_adj[ms], fila[ms], level[ms], deg[ms], deg2[ms], degTemp[ms];
int adj[ms], to[me], ant[me], wt[me], z, n;
ii myEdges[me];
bool used[me];

void clear() {
    memset(adj, -1, sizeof adj);
    z = 0;
}

void add(int u, int v, int k) {
    to[z] = v;
    ant[z] = adj[u];
    wt[z] = k;
    adj[u] = z++;
    swap(v, u);
    to[z] = v;
    ant[z] = adj[u];
    wt[z] = 0;
    adj[u] = z++;
}

int bfs(int source, int sink) {
	memset(level, -1, sizeof level);
	level[source] = 0;
	int front = 0, size = 0, v;
	fila[size++] = source;
	while(front < size) {
		v = fila[front++];
		for(int i = adj[v]; i != -1; i = ant[i]) {
			if(wt[i] && level[to[i]] == -1) {
				level[to[i]] = level[v] + 1;
				fila[size++] = to[i];
			}
		}
	}
	return level[sink] != -1;
}

int dfs(int v, int sink, int flow) {
	if(v == sink) return flow;
	int f;
	for(int &i = copy_adj[v]; i != -1; i = ant[i]) {
		if(wt[i] && level[to[i]] == level[v] + 1 && (f = dfs(to[i], sink, min(flow, wt[i])))) {
			wt[i] -= f;
			wt[i ^ 1] += f;
			return f;
		}
	}
	return 0;
}

int maxflow(int source, int sink) {
	int ret = 0, flow;
	while(bfs(source, sink)) {
		memcpy(copy_adj, adj, sizeof adj);
		while((flow = dfs(source, sink, 1 << 30))) {
			ret += flow;
		}
	}
	return ret;
}

int main() {
	int n1, n2, m;
	cin >> n1 >> n2 >> m;
	int source = n1 + n2 + 5, sink = n1 + n2 + 6;
	int minDegree = inf;
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		myEdges[i] = ii(u, v + n1);
		deg[u]++;
		deg2[v]++;
	}
	for(int i = 1; i <= n1; i++) {
		minDegree = min(minDegree, deg[i]);
	}
	for(int i = 1; i <= n2; i++) {
		minDegree = min(minDegree, deg2[i]);
	}
	cout << 0 << '\n';
	for(int i = 1; i <= minDegree; i++) {
		clear();
		for(int j = 0; j < m; j++) {
			add(myEdges[j].first, myEdges[j].second, 1);
		}
		for(int j = 1; j <= n1; j++) {
			add(source, j, i);
		}
		for(int j = 1; j <= n2; j++) {
			add(j + n1, sink, i);
		}
		int ans = maxflow(source, sink);
		cout << i * (n1 + n2) - ans << ' ';
		for(int j = 1; j <= n1; j++) {
			degTemp[j] = i;
		}
		for(int j = 1; j <= n2; j++) {
			degTemp[j + n1] = i;
		}
		for(int i = 0; i < m; i++) {
			used[i] = !(wt[i*2]);
			if(used[i]) {
				//cout << i << " ta no fluxo" << '\n';
				degTemp[myEdges[i].first]--;
				degTemp[myEdges[i].second]--;
			}
		}
		for(int i = 0; i < m; i++) {
			if(!used[i] && (degTemp[myEdges[i].first] > 0 || degTemp[myEdges[i].second] > 0)) {
				degTemp[myEdges[i].first]--;
				degTemp[myEdges[i].second]--;
				used[i] = true;
			}
			if(used[i]) {
				cout << i + 1 << ' ';
			}
		}
		cout << '\n';
	}
}