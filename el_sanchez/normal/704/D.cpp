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
const int MAXN = 100500;
string shield = "br";

struct edge {
	int from, to;
	int L, R, f, pos;
	int inv;

	edge(int _from, int _to, int _L, int _R, int _pos, int _inv) {
		from = _from;
		to = _to;
		L = _L;
		R = _R;
		f = 0;
		pos = _pos;
		inv = _inv;
	}
};

int n, m, r, b, t, x, y;
int S, F, sz, S2, F2;
vector<vi> g, gg;
vi ptr;
vector<edge> lst, lst2;
map<int, int> idx, idy, rx, ry;
pii a[MAXN];
vi cx, cy;
map<int, int> qx, qy;
ll ans;
vi dist;
queue<int> q;
int color[MAXN];

bool bfs(int S, int F) {
	dist.clear();
	dist.resize(sz, INF);
	dist[S] = 0;

	while (!q.empty())
		q.pop();

	q.push(S);
	while (!q.empty()) {
		int v = q.front();
		//cerr << v << endl;
		q.pop();
		for (auto eid: g[v]) {
			int w = lst[eid].to;
			//cerr << " -> " << w << endl;
			if (lst[eid].f < lst[eid].R && dist[w] == INF) {
				dist[w] = dist[v] + 1;
				q.push(w);
			}
		}
	}
	
	return dist[F] < INF;
}

int dfs(int v, int F) {
	if (v == F)
		return 1;
		
	for (ptr[v]; ptr[v] < (int)g[v].size(); ptr[v]++) {
		int eid = g[v][ptr[v]];
		int w = lst[eid].to;
		if (dist[v] + 1 == dist[w] && lst[eid].f < lst[eid].R) {
			if (dfs(w, F)) {
				lst[eid].f++;
				lst[lst[eid].inv].f--;
				return 1;	
			}
		}
	}
	
	return 0;
}

int lastEdge;

int dinic(int S, int F) {
	int res = 0;
//	cerr << "go" << endl;
	while (bfs(S, F)) {
		ptr.clear();
		ptr.resize(sz, 0);
		
		while (dfs(S, F)) {
			res++;
		}
	}
	return res;
}

int addEdge(int u, int v, int R, int pos) {
	gg[u].pb(lst2.size());
	gg[v].pb(lst2.size() + 1);		
	lst2.pb(edge(u, v, 0, R, pos, lst2.size() + 1));
	lst2.pb(edge(v, u, 0, 0, -1, lst2.size() - 1));
	return (int)lst2.size() - 2;
}

void rebuildNet() {
	S2 = sz++;
	F2 = sz++;
	gg.resize(sz);

	for (auto e: lst) {
		if (e.L > e.R) {
			cout << -1 << '\n';
			exit(0);
		}
		
		//assert(e.L <= e.R);
		
		int u = e.from;
		int v = e.to;
		addEdge(S2, v, e.L, -1);
		addEdge(u, F2, e.L, -1);
		addEdge(u, v, e.R - e.L, e.pos);
	}
	
	lastEdge = addEdge(F, S, INF, -1);
	
	g = gg;
	lst = lst2;
}

int main() {

	cin >> n >> m >> r >> b;
	if (r > b) {
		swap(r, b);
		swap(shield[0], shield[1]);
	}
	
	forn(i, n) {
		scanf("%d%d", &a[i].X, &a[i].Y);
		cx.pb(a[i].X);
		cy.pb(a[i].Y);
		rx[a[i].X]++;
		ry[a[i].Y]++;
	}
	
	sort(all(cx));
	cx.resize(unique(all(cx)) - cx.begin());
	for (auto x: cx)
		qx[x] = INF;

	sort(all(cy));
	cy.resize(unique(all(cy)) - cy.begin());
	for (auto y: cy)
		qy[y] = INF;
	
	forn(i, m) {
		scanf("%d%d%d", &t, &x, &y);
		if (t == 1) {
			qx[x] = min(qx[x], y);
		} else {
			qy[x] = min(qy[x], y);
		}
	}	
	
	//build net
	S = 0;
	F = 1;
	sz = 2;
	for (auto x: cx)
		idx[x] = sz++;
	for (auto y: cy)
		idy[y] = sz++;	

	g.clear();
	g.resize(sz);
	
	//S -> X
	for (auto x: cx) {
		g[S].pb(lst.size());
		lst.pb(edge(S, idx[x], 
		            max(0, (rx[x] - qx[x] + 1) / 2), min(rx[x], (rx[x] + qx[x]) / 2), -1, -1));	
	}
	
	//X -> Y
	forn(i, n) {
		g[idx[a[i].X]].pb(lst.size());
		lst.pb(edge(idx[a[i].X], idy[a[i].Y], 0, 1, i, -1));
	}

	//Y -> F
	for (auto y: cy) {
		g[idy[y]].pb(lst.size());
		lst.pb(edge(idy[y], F, 
		            max(0, (ry[y] - qy[y] + 1) / 2), min(ry[y], (ry[y] + qy[y]) / 2), -1, -1));	
	}
	
	rebuildNet();

	int needFlow = 0;
	for (auto eid: g[S2])	
		needFlow += lst[eid].R;
		
	int flow = dinic(S2, F2);	
	if (flow < needFlow) {
		cout << -1 << '\n';
		return 0;
	}
	
	assert(flow == needFlow);

	flow = dinic(S, F);
	
	ll ans = 1ll * flow * r + 1ll * (n - flow) * b;

	forn(eid, lst.size())
		if (lst[eid].pos != -1) {
			int i = lst[eid].pos;
			color[i] = lst[eid].f;
		}
		
	cout << ans << '\n';
	string s = "";
	forn(i, n)
		s += shield[color[i]];
	cout << s << '\n';	
	return 0;
}