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
const int MAXN = 11111;
const ll LINF = 1E18;

struct edge {
	int to;
	ll w;
	int id;	
};

int n, m, L, s, t;
vector<edge> g[MAXN], tg[MAXN];
vector<pair<pii, int>> edges;
int vv[2][MAXN];
ll res[MAXN];

set<pair<ll, int>> q;
ll dist[MAXN];
    
ll getPath(int pos) {
	forn(i, n)
		g[i].clear();
	forn(i, n)
		for (auto e: tg[i])
			g[i].pb(e);
			
	for (int i = 0; i <= pos; i++) {
		int a = edges[i].X.X;
		int b = edges[i].X.Y;
		g[a].pb({b, 1, i});
		g[b].pb({a, 1, i});
	}
	
	q.clear();
	forn(i, n)  	
		dist[i] = LINF;
	dist[s] = 0;
	
	forn(i, n)
		q.insert({dist[i], i});
		
	while (!q.empty()) {
		pair<ll, int> tt = *q.begin();
		q.erase(tt);

		int v = tt.Y;
				
		//cerr << v << ' ' << dist[v] << '\n';
		//cerr << q.size() << '\n';
				
		for (auto e: g[v]) {
			//cerr << v << " -> " << e.to << ' ' << e.w << '\n';
			if (dist[e.to] > dist[v] + e.w) {
				q.erase({dist[e.to], e.to});
				dist[e.to] = dist[v] + e.w;
				q.insert({dist[e.to], e.to});				
			}
		}
	}
	
	return dist[t];
}

int main() {
	
	cin >> n >> m >> L >> s >> t;
	forn(i, m) {
		int a, b, w;
		scanf("%d%d%d", &a, &b, &w);
		vv[0][i] = a;
		vv[1][i] = b;
		res[i] = w;
		
		if (w > 0) {
			tg[a].pb({b, w, i});
			tg[b].pb({a, w, i});
		} else {
			edges.pb({{a, b}, i});	
		}
	}

	if ((getPath(-1) < L) || getPath((int)edges.size() - 1) > L) {
		cout << "NO\n";
		return 0;
	}
	
	int lf = -1, rg = (int)edges.size() - 1, mid = 0;
	while (rg - lf > 1) {
		//cerr << lf << ' ' << rg << endl;
		mid = (lf + rg) >> 1;
		ll len = getPath(mid);
		if (len <= L) {
			rg = mid;	
		} else {
			lf = mid;
		}
	}
	
	ll len = getPath(rg);
	assert(len <= L);
	
	if (rg >= 0) {
		for (int i = 0; i < rg; i++)
			res[edges[i].Y] = 1;
		res[edges[rg].Y] = 1 + L - len;
		for (int i = rg + 1; i < (int)edges.size(); i++)
			res[edges[i].Y] = LINF;
	}
	
	cout << "YES\n";
	forn(i, m)
		cout << vv[0][i] << ' ' << vv[1][i] << ' ' << res[i] << '\n';
	return 0;
}