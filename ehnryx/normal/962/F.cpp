#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ld> pt;
typedef vector<pt> pol;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

////////////////////////////////////////////////////////////////////////////////
// 2-vertex and 2-edge connected components (TESTED - Codeforces 521E)
// should handle multiple-edges and self-loops
// USAGE: 1) init(); 2) add edges; 3) get_bcc(num vertices);
// 4) use isCutVertex(vertex index) or isCutEdge(2* edge index)
////////////////////////////////////////////////////////////////////////////////
namespace Tarjan {
const int N = 1e5 + 1;
const int M = 1e5 + 1;
int vcompNum,ecompNum,I,m;
int first[N],low[N],vis[N],ecomp[N];
int nxt[2*M],ep[2*M],vcomp[2*M];
stack<int> edges, verts;
void init() { m = 0; memset(first, -1, sizeof(first)); }
void add_edge(int a, int b) {
    nxt[m] = first[ep[m] = a], first[ep[m]] = m, ++m;
    nxt[m] = first[ep[m] = b], first[ep[m]] = m; ++m; }
void biconnected(int u, int par){ int v,E; low[u] = vis[u] = ++I; verts.push(u);
  for (int e = first[u]; e != -1; e = nxt[e]) { v = ep[e^1];
    if (!vis[v]) { edges.push(e); biconnected(v,e);
      low[u] = min(low[u],low[v]);
      if (vis[u] <= low[v]) { // u is a cut vertex unless it's a one-child root
        do { E = edges.top(); edges.pop(); vcomp[E] = vcomp[E^1] = vcompNum; }
        while (e != E && e != (E^1)); ++vcompNum; }}
    else if (vis[v] < vis[u] && e != (par^1)) {
      low[u] = min(low[u], vis[v]); edges.push(e); }
    else if (v == u) vcomp[e] = vcomp[e^1] = vcompNum++; 
  }
  if (vis[u] <= low[u]) { // par is a cut edge unless par==-1
    do { v = verts.top(); verts.pop(); ecomp[v] = ecompNum; }
    while (v != u); ++ecompNum; }
}
void get_bcc(int n) { memset(vis,0,sizeof vis); vcompNum=ecompNum=I=0;
  for (int i = 1; i <= n; ++i) if (!vis[i]) biconnected(i, -1);
}
// tree-independent criteria for identifying articulation points and bridges
bool isCutVertex(int u) { for (int e = first[u]; e != -1; e = nxt[e])
  if (vcomp[e] != vcomp[first[u]]) return true; return false; }
bool isCutEdge(int e) { return ecomp[ep[e]] != ecomp[ep[e^1]]; }
}

namespace std {
	template<> struct hash<pii> {
		size_t operator () (const pii& v) const {
			return hash<int>()(v.first<<10) ^ hash<int>()(v.second);
		}
	};
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	Tarjan::init();

	int n, m;
	cin >> n >> m;

	unordered_map<pii,int> edge_id;
	int a, b;
	for (int i = 1; i <= m; i++) {
		cin >> a >> b;
		edge_id[pii(min(a,b),max(a,b))] = i;
		Tarjan::add_edge(a,b);
	}
	Tarjan::get_bcc(n);

	unordered_set<int> vertices[Tarjan::vcompNum];
	vector<int> edges[Tarjan::vcompNum];
	int ecnt[Tarjan::vcompNum]; memset(ecnt, 0, sizeof ecnt);
	for (int i = 0; i < 2*m; i+=2) {
		int a = Tarjan::ep[i];
		int b = Tarjan::ep[i^1];
		int id = Tarjan::vcomp[i];
		ecnt[id]++;
		edges[id].push_back(edge_id[pii(min(a,b),max(a,b))]);
		vertices[id].insert(a);
		vertices[id].insert(b);
	}

	vector<int> ans;
	for (int i = 0; i < Tarjan::vcompNum; i++) {
		if (ecnt[i] == vertices[i].size()) {
			for (int e : edges[i]) {
				ans.push_back(e);
			}
		}
	}
	sort(ans.begin(), ans.end());

	cout << ans.size() << nl;
	for (int it : ans) {
		cout << it << " ";
	}
	cout << nl;

	return 0;
}