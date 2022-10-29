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

struct edge {
	int to, c, f, cost, inv;

	edge(int _to = 0, int _c = 0, int _cost = 0, int _inv = 0) {
		to = _to;
		c =	_c;
		f = 0;
		cost = _cost;
		inv = _inv;
	}
};

int n, m, x;
int BEGIN, END, sz;
vector<edge> edges;
vi g[MAXN];

void addEdge(int u, int v, int c, int cost) {
	int id = edges.size();
	edges.pb(edge(v, c, cost, id + 1));
	edges.pb(edge(u, 0, -cost, id));
	g[u].pb(id);
	g[v].pb(id + 1);		
}

ll totalCost;
int curFlow;
queue<int> q;
int used[MAXN], d[MAXN], parEdge[MAXN], parV[MAXN];

bool findPath(int S) {
	while (!q.empty())
		q.pop();
	forn(i, sz) {
		parV[i] = -1;
		parEdge[i] = -1;
		used[i] = 0;
		d[i] = INF;
	}
		
	used[S] = 1;
	d[S] = 0;
	q.push(S);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		used[v] = 0;
		
		for (auto eid: g[v]) {
			edge e = edges[eid];
			int w = e.to;
			if (e.c - e.f > 0 && d[w] > d[v] + e.cost) {
				d[w] = d[v] + e.cost;
				parV[w] = v;
				parEdge[w] = eid;
				if (!used[w])
					q.push(w);
			}
		}
	}
	
	return d[END] < INF;
}

void push(int v) {
	if (v == BEGIN) 
		return;

	int eid = parEdge[v];
	assert(eid != -1);
	curFlow = min(curFlow, edges[eid].c - edges[eid].f);
	
	push(parV[v]);
	
	edges[eid].f += curFlow;
	edges[edges[eid].inv].f -= curFlow;
	totalCost += 1ll * curFlow * edges[eid].cost;
}

string s;
string t[MAXN];
int p[MAXN];

int main() {

	cin >> n;
	cin >> s;
	cin >> m;
	forn(i, m) {
		cin >> t[i] >> p[i];	
	}
	cin >> x;
	
	sz = n;
	END = sz++;
	BEGIN = sz++;
	
	addEdge(BEGIN, 0, x, 0);
	forn(i, n - 1)
		addEdge(i, i + 1, INF, 0);
	addEdge(n - 1, END, INF, 0);
	
	forn(i, m) {
		for (int pos = 0; pos + (int)t[i].size() <= n; pos++)
			if (s.substr(pos, t[i].size()) == t[i])
				addEdge(pos, pos + (int)t[i].size(), 1, -p[i]);	
	}
	
	totalCost = 0;
	while (findPath(BEGIN)) {
		curFlow = INF;
		push(END);	
	}
	cout << -totalCost << '\n';
	
	return 0;
}