#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#ifdef iq
  mt19937 rnd(228);
#else
  mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

const int N = (int) (1e5) + 7;

vector <int> gr[N];
vector <int> ingr[N];

vector <pair <int, int> > guys[N];
vector <int> pref[N];

const int MAXN = 1e5; //  
const int INF = 1000000007; // -
 
struct edge {
	int a, b, cap, flow;
};
 
int n, s, t, d[MAXN], ptr[MAXN], q[MAXN];
vector<edge> e;
vector<int> g[MAXN];
 
void add_edge (int a, int b, int cap) {
	edge e1 = { a, b, cap, 0 };
	edge e2 = { b, a, 0, 0 };
	g[a].push_back ((int) e.size());
	e.push_back (e1);
	g[b].push_back ((int) e.size());
	e.push_back (e2);
}
 
bool bfs() {
	int qh=0, qt=0;
	q[qt++] = s;
	memset (d, -1, n * sizeof d[0]);
	d[s] = 0;
	while (qh < qt && d[t] == -1) {
		int v = q[qh++];
		for (size_t i=0; i<g[v].size(); ++i) {
			int id = g[v][i],
				to = e[id].b;
			if (d[to] == -1 && e[id].flow < e[id].cap) {
				q[qt++] = to;
				d[to] = d[v] + 1;
			}
		}
	}
	return d[t] != -1;
}
 
int dfs (int v, int flow) {
	if (!flow)  return 0;
	if (v == t)  return flow;
	for (; ptr[v]<(int)g[v].size(); ++ptr[v]) {
		int id = g[v][ptr[v]],
			to = e[id].b;
		if (d[to] != d[v] + 1)  continue;
		int pushed = dfs (to, min (flow, e[id].cap - e[id].flow));
		if (pushed) {
			e[id].flow += pushed;
			e[id^1].flow -= pushed;
			return pushed;
		}
	}
	return 0;
}
 
ll dinic() {
	ll flow = 0;
	for (;;) {
		if (!bfs())  break;
		memset (ptr, 0, n * sizeof ptr[0]);
		while (int pushed = dfs (s, INF))
			flow += pushed;
	}
	return flow;
}

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll ans = 0;
  vector <int> id;
  vector <int> cost;
  vector <pair <int, int> > go;
  {
    int n, m;
    cin >> n >> m;
    int inf = (int) (1e9) + 7;
    vector <vector <int> > g(n, vector <int> (n, inf));
    for (int i = 0; i < n; i++) g[i][i] = 0;
    for (int i = 0; i < m; i++) {
      int a, b;
      cin >> a >> b;
      a--, b--;
      g[a][b] = g[b][a] = 1;
    }
    for (int k = 0; k < n; k++) {
      for (int i= 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
        }
      }
    }
    int s, b, k;
    cin >> s >> b >> k;
    vector <int> x(s), a(s), f(s), p(s);
    for (int i = 0; i < s; i++) {
      cin >> x[i] >> a[i] >> f[i] >> p[i];
      x[i]--;
    }
    vector <int> y(b), d(b), gold(b);
    for (int i = 0; i < b; i++) {
      cin >> y[i] >> d[i] >> gold[i];
      y[i]--;
      guys[y[i]].push_back({d[i], gold[i]});
    }
    for (int i = 0; i < n; i++) {
      sort(guys[i].begin(), guys[i].end());
      pref[i].resize(guys[i].size());
      for (int j = 0; j < (int) pref[i].size(); j++) {
        pref[i][j] = guys[i][j].second;
        if (j) pref[i][j] = max(pref[i][j], pref[i][j - 1]);
      }
    }
    vector <bool> alive(s);
    vector <int> score(s);
    for (int i = 0; i < s; i++) {
      vector <int> ok;
      for (int j = 0; j < n; j++) {
        if (g[x[i]][j] <= f[i]) {
          int ind = upper_bound(guys[j].begin(), guys[j].end(), make_pair(a[i], inf)) - guys[j].begin() - 1;
          if (ind >= 0) {
            ok.push_back(pref[j][ind]);
          }
        }
      }
      if (!ok.empty()) {
        score[i] = *max_element(ok.begin(), ok.end()) - p[i];
        alive[i] = true;
      }
    }
    vector <bool> in_edge(s);
    vector <pair <int, int> > edges;
    for (int i = 0; i < k; i++) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      in_edge[u] = in_edge[v] = true;
      edges.push_back({u, v});
    }
    bool ch = true;
    while (ch) {
      ch = false;
      for (auto c : edges) {
        if (!alive[c.second] && alive[c.first]) {
          ch = true;
          alive[c.first] = false;
        }
      }
    }
    for (int i = 0; i < s; i++) {
      if (!in_edge[i]) {
        ans += max(0, score[i]);
      }
    }
    for (int i = 0; i < s; i++) {
      if (in_edge[i] && alive[i]) {
        id.push_back(i);
        cost.push_back(score[i]);
      }
    }
    for (auto c : edges) {
      if (!alive[c.first] || !alive[c.second]) {
        continue;
      }
      int u = lower_bound(id.begin(), id.end(), c.first) - id.begin();
      int v = lower_bound(id.begin(), id.end(), c.second) - id.begin();
      go.push_back({u, v});
    }
  }
  n = 2 + id.size();
  s = id.size();
  t = id.size() + 1;
  for (auto c : go) {
    add_edge(c.first, c.second, INF);
  }
  for (int i= 0; i < (int) id.size(); i++) {
    if (cost[i] >= 0) {
      ans += cost[i];
      add_edge(s, i, cost[i]);
    } else {
      add_edge(i, t, -cost[i]);
    }
  }
  cout << ans - dinic() << '\n';
}