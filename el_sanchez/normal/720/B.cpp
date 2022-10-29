#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for (int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for (int i = (int)(n) - 1; i >= (int)(k); i--)

#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define db(x) cout << #x << " = " << x << endl

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-9;
const int INF = 1E9; 
const int MAXN = 1005000;

struct edge {
	int to, c, f, inv;

	edge(int _to = 0, int _c = 0, int _inv = 0) {
		to = _to;
		c = _c;
		f = 0;
		inv = _inv;
	}
};

int BEGIN, END, SZ;
vector<edge> edges;
vi gf[MAXN];

void addEdge(int u, int v, int c) {
	int id = edges.size();
	edges.pb(edge(v, c, id + 1));
	edges.pb(edge(u, c, id));
	gf[u].pb(id);
	gf[v].pb(id + 1);			
}

int n, m, tmr = 1;
int used[MAXN], tin[MAXN], marked[MAXN], cid[MAXN];
int color[MAXN];
vector<pair<pii, int>> g[MAXN];
vector<pii> st;
int lsz = 0;
vi lists[MAXN];

void dfs(int v, int p = -1) {
	tin[v] = tmr++;
	used[v] = 1;
	
	for (auto ee: g[v]) {
		pii e = ee.X;
		int w = e.X;
		if (ee.Y == p)
			continue;
		
		if (used[w]) {
			if (tin[w] > tin[v])
				continue;
				
			for (int i = (int)st.size() - 1; i >= 0; i--) {
				lists[lsz].pb(color[st[i].Y]);
				marked[st[i].Y] = 1;
				if (st[i].X == w)
					break;
			}
			lists[lsz].pb(color[ee.Y]);
			marked[ee.Y] = 1;
			lsz++;
		} else {
			st.pb({v, ee.Y});
			dfs(w, ee.Y);
			st.pop_back();	
		}
	}
}

bool get(int v, int F) {
	if (v == END)
		return 1;

	used[v] = tmr;
	for (auto eid: gf[v]) {
		if (used[edges[eid].to] == tmr)
			continue;

		if (edges[eid].c - edges[eid].f >= F && get(edges[eid].to, F)) {
			edges[eid].f += F;
			edges[edges[eid].inv].f -= F;
			return 1;			
		}
	}
	
	return 0;
}

int main() {

	cin >> n >> m;
	forn(i, m) {
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--, c--;
		g[a].pb({{b, c}, i});
		g[b].pb({{a, c}, i});
		color[i] = c;
	}
	
	dfs(0);
	
	SZ = 0;
	BEGIN = SZ++;
	END = SZ++;
	
	forn(i, m)
		cid[i] = SZ++;
	
	forn(i, lsz) {
		int V = SZ++;
		addEdge(BEGIN, V, (int)lists[i].size() - 1);
		for (auto c: lists[i])
			addEdge(V, cid[c], 1);
	}
	
	forn(i, m) {
		if (!marked[i]) {
			//lists[lsz].pb(color[i]);
			//lsz++;	
			//cout << color[i] << '\n';
			addEdge(BEGIN, cid[color[i]], 1);
		}
	}
	
	forn(i, m)
		addEdge(cid[i], END, 1);
		
	int ans = 0;
	tmr = 1;
	memset(used, 0, sizeof(used));
	for (int F = (1 << 29); F > 0; F >>= 1) {
		tmr++;
		while (get(BEGIN, F)) {
			tmr++;
			ans += F;	
		}
	}
	
	cout << ans << '\n';
	
/*
	forn(i, lsz) {
		for (auto c: lists[i])
			cout << c << ' ';
		cout << '\n';	
	}
*/	
	return 0;
}