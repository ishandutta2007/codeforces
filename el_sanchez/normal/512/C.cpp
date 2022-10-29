#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for (int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for (int i = (int)(n) - 1; i >= (int)(k); i--)

#define vi vector<int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define gcd(a, b) __gcd((a), (b))

using namespace std;

typedef long long ll;
typedef long double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-8;
const int INF = 1E9;		
const int MAXN = 100500;

struct edge {
	int v, w, f, c, id, inv;
	edge() {};
	edge(int _v, int _w, int _f, int _c, int _id, int _inv): 
			v(_v), w(_w), f(_f), c(_c), id(_id), inv(_inv) {};
};

int n, BEGIN, END, tmr;
ll ans;
int used[MAXN], level[MAXN], ptr[MAXN];
vector<edge> edges;
vi g[MAXN];

void addEdge(int v, int w, int c) {
	int id = edges.size();
	edges.pb(edge(v, w, 0, c, id, id + 1));
	edges.pb(edge(w, v, 0, 0, id + 1, id));
	g[v].pb(id);
	g[w].pb(id + 1);
}

int q[MAXN], ql, qr;
         
bool bfs(int f) {
	tmr++;
	ql = qr = 0;
	used[BEGIN] = tmr;
	level[BEGIN] = 0;
	q[qr++] = BEGIN;
	
	while (qr - ql > 0) {
		int v = q[ql++];
		
		for (auto eid: g[v]) {
			int w = edges[eid].w;
			if (used[w] != tmr && edges[eid].c - edges[eid].f >= f) {
				used[w] = tmr;
				level[w] = level[v] + 1;
				q[qr++] = w;            				
			}
		}
	}
	
	return used[END] == tmr;
}

bool dfs(int v, int f) {
	if (v == BEGIN)
		tmr++;
	if (v == END)
		return 1;
	used[v] = tmr;
	
	for (; ptr[v] < (int)g[v].size(); ptr[v]++) {
		int eid = g[v][ptr[v]];
		if (level[v] + 1 == level[edges[eid].w] && edges[eid].c - edges[eid].f >= f && dfs(edges[eid].w, f)) {
			edges[eid].f += f;
			edges[edges[eid].inv].f -= f;
			return 1; 
		}
	}
	
	return 0;
}
	
bool prime(int v) {
	for (ll i = 2; i * i <= v; i++)
		if (v % i == 0)
			return 0;
	return 1;
}

int foxes, sz;
int val[MAXN], id[MAXN];
vi odd[2];
vi g2[MAXN];
vi st;
vector<vi> stacks;
int usedFox[MAXN];

void dfs(int v) {
	st.pb(v);
	usedFox[v] = 1;
	for (auto w: g2[v])
		if (!usedFox[w])
			dfs(w);
}

int main() {

	cin >> foxes;
	forn(i, foxes) {
		cin >> val[i];
		if (val[i] & 1)
			odd[0].pb(i);
		else
			odd[1].pb(i);
	}       
	
	BEGIN = 0;
	
	sz = 1;
	forn(i, 2)
		forn(j, odd[i].size())
			id[odd[i][j]] = sz++;		
	
	END = sz;
	sz++;
	n = sz;
	
	forn(i, odd[0].size())
		addEdge(BEGIN, id[odd[0][i]], 2);
	forn(i, odd[0].size())
		forn(j, odd[1].size())
			if (prime(val[odd[0][i]] + val[odd[1][j]]))
				addEdge(id[odd[0][i]], id[odd[1][j]], 1);
	forn(i, odd[1].size())
		addEdge(id[odd[1][i]], END, 2);
				
	ans = 0;
	for (int flow = (1 << 30); flow > 0; flow >>= 1) {
		while (bfs(flow)) {
			for (int i = 0; i < sz; i++)
				ptr[i] = 0;
			while (dfs(BEGIN, flow))
				ans += flow;
		}	
	}
	
	//cerr << ans << '\n';
	if ((foxes & 1) || ans != foxes) {
		cout << "Impossible";
		return 0;
	}
	
	vi ids;
	forn(i, odd[0].size()) {
		int id0 = id[odd[0][i]];
		ids.clear();
		for (auto e: g[id0]) {
			//cout << edges[e].f << '\n';
			if (edges[e].f > 0)
				ids.pb(edges[e].w);
		}
		
		//printf("VERTEX %d:\n", odd[0][i]);
		//cout << ids.size() << '\n';
		forn(j, odd[1].size())
			for (auto k: ids) {
				if (k == id[odd[1][j]]) {
					g2[odd[0][i]].pb(odd[1][j]);
					g2[odd[1][j]].pb(odd[0][i]);
				}
			}
	}
	
	forn(i, foxes)
		if (!usedFox[i]) {
			st.clear();
			dfs(i); 
			stacks.pb(st);
		}
		
	cout << stacks.size() << '\n';
	for (auto s: stacks) {
	    cout << s.size() << ' ';
	    for (auto v: s)
	    	cout << v + 1 << ' ';
		cout << '\n';	
	}
	
	return 0;
}