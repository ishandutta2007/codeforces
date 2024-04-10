#include<bits/stdc++.h>
using namespace std;
constexpr int maxn = 24000;
//https://cp-algorithms.com/graph/dinic.html
struct FlowEdge {
    int v, u;
    long long cap, flow = 0;
    FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
};

struct Dinic {
    const long long flow_inf = 1e18;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    vector<bool> vis; 
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;

    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void add_edge(int v, int u, long long cap) {
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u, v, 0);
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
        m += 2;
    }

    bool bfs() {
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int id : adj[v]) {
                if (edges[id].cap - edges[id].flow < 1)
                    continue;
                if (level[edges[id].u] != -1)
                    continue;
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    long long dfs(int v, long long pushed) {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
                continue;
            long long tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    long long flow() {
        long long f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
    void DFS(int u){
    	vis[u] = true;
    	for(int x : adj[u])
    		if(edges[x].flow < edges[x].cap){
    			int v = edges[x].u;
    			if(vis[v]) continue;
    			DFS(v);
			}
	}
};
struct edge{
	int u, v;
}e[maxn];
vector<int> G[maxn];
int pa[maxn][16], pe[maxn], depth[maxn];
void DFS(int u){
	depth[u] = depth[pa[u][0]] + 1;
	for(int i = 1; i <= 15; i += 1) pa[u][i] = pa[pa[u][i - 1]][i - 1];
	for(int x : G[u]) if(x != pe[u]){
		int v = u ^ e[x].u ^ e[x].v;
		pa[v][0] = u;
		pe[v] = x;
		DFS(v);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m;
	cin >> n >> m;
	int s = 0, t = n + m + n * 16 + 1;
	Dinic dinic(t + 1, s, t);
	for(int i = 1; i < n; i += 1){
		dinic.add_edge(m + i, t, 1);
		cin >> e[i].u >> e[i].v;
		G[e[i].u].push_back(i);
		G[e[i].v].push_back(i);
	}
	DFS(1);
	for(int i = 1; i <= n; i += 1) if(pe[i]) dinic.add_edge(n + m + i, m + pe[i], maxn);
	for(int i = 1; i <= n; i += 1)
		for(int j = 1; j <= 15; j += 1)
			if(pa[i][j]){
				dinic.add_edge(n + m + j * n + i, n + m + (j - 1) * n + i, maxn);
				dinic.add_edge(n + m + j * n + i, n + m + (j - 1) * n + pa[i][j - 1], maxn);
			}
	for(int i = 1; i <= m; i += 1){
		dinic.add_edge(s, i, 1);
		int u, v;
		cin >> u >> v;
		if(depth[u] < depth[v]) swap(u, v);
		for(int j = 15; depth[u] > depth[v]; j -= 1)
			if(depth[u] - (1 << j) >= depth[v]){
				dinic.add_edge(i, n + m + j * n + u, maxn);
				u = pa[u][j];
			}
		if(u == v) continue;
		for(int j = 15; ~j; j -= 1)
			if(pa[u][j] != pa[v][j]){
				dinic.add_edge(i, n + m + j * n + u, maxn);
				u = pa[u][j];
				dinic.add_edge(i, n + m + j * n + v, maxn);
				v = pa[v][j];
			}
		dinic.add_edge(i, n + m + u, maxn);
		dinic.add_edge(i, n + m + v, maxn);
	}
	cout << dinic.flow() << endl;
	dinic.vis.resize(dinic.n, false);
	dinic.DFS(s);
	vector<int> q, ee;
	for(int i = 1; i <= m; i += 1) if(not dinic.vis[i]) q.push_back(i);
	for(int i = 1; i < n; i += 1) if(dinic.vis[m + i]) ee.push_back(i);
	cout << q.size() << " ";
	for(int x : q) cout << x << " ";
	cout << endl;
	cout << ee.size() << " ";
	for(int x : ee) cout << x << " ";
	cout << endl;
	return 0; 
}