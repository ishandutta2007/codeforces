//Author: Heltion
//Date: 07-31-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr LL maxm = 120;
constexpr LL maxn = 120000;
LL d[maxm][maxm];
LL sx[maxn], a[maxn], f[maxn], p[maxn], bx[maxn], dd[maxn], g[maxn];
struct FlowEdge {
    int v, u;
    long long cap, flow = 0;
    FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
};

struct Dinic {
    const long long flow_inf = 1e18;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
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
};
vector<pair<LL, LL>> v[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	LL n, m;
	cin >> n >> m;
	for(LL i = 1; i <= n; i += 1)
		for(LL j = 1; j <= n; j += 1) if(i != j) d[i][j] = 1e10;
	for(LL i = 1; i <= m; i += 1){
		LL u, v;
		cin >> u >> v;
		if(u != v) d[u][v] = d[v][u] = 1;
	}
	for(LL k = 1; k <= n; k += 1)
		for(LL i = 1; i <= n; i += 1)
			for(LL j = 1; j <= n; j += 1)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
	LL s, b, k;
	cin >> s >> b >> k;
	LL ans = 0;
	for(LL i = 1; i <= s; i += 1)
		cin >> sx[i] >> a[i] >> f[i] >> p[i];
	for(LL i = 1; i <= b; i += 1)
		cin >> bx[i] >> dd[i] >> g[i];
	
	Dinic dinic(s + 2, 0, s + 1);
	for(LL i = 1; i <= k; i += 1){
		int u, v;
		cin >> u >> v;
		dinic.add_edge(u, v, 1e17);
	}
	for(LL j = 1; j <= b; j += 1)
		v[bx[j]].push_back(make_pair(dd[j], g[j]));
	for(LL j = 1; j <= n; j += 1){
		sort(v[j].begin(), v[j].end());
		for(LL i = 1; i < (LL)v[j].size(); i += 1)
			v[j][i].second = max(v[j][i].second, v[j][i - 1].second);
	}
	for(LL i = 1; i <= s; i += 1){
		LL x = -1e15;
		for(LL j = 1; j <= n; j += 1)
			if(d[sx[i]][j] <= f[i] and v[j].size()) {
				auto p = upper_bound(v[j].begin(), v[j].end(), make_pair(a[i], (LL)1e17));
				if(p == v[j].begin()) continue;
				p --;
				x = max(x, p->second);
			}
		LL y = x - p[i];
		if(y > 0){
			ans += y;
			dinic.add_edge(0, i, y);
		}
		else dinic.add_edge(i, s + 1, -y);
	}
	cout << ans - dinic.flow();
	return 0;
}