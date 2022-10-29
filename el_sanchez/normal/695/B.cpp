#include "bits/stdc++.h"

#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define ford(i, n) for (int i = (int)n - 1; i >= 0; i--)
#define forab(i, a, b) for (int i = (int)a; i < (int)b; i++)
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

template<typename T> inline T sqr(T x)
{
    return x*x; 
}                    

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

//const ld pi = acos((ld)-1.0);
const ld eps = 1e-9;
const int INF = 2 * (int)1E9 + 3;
const int MAXN = 33333;

struct edge {
	int to, w, id;

	edge(int _to = 0, int _w = 0, int _id = 0) {
		to = _to;
		w = _w;
		id = _id;
	}
};

int n, m, s, t;
vector<edge> g[MAXN];
int ans, used[MAXN], inUse[MAXN], isBridge[MAXN], curAns;
int tmr, tin[MAXN], fup[MAXN];
vector<edge> edges;
vector<edge> path, path3;

bool dfs(int v) {
	if (v == t)
		return 1;

	used[v] = 1;
	for (auto e: g[v]) {
		if (!used[e.to]) {
			path.pb(e);
			if (dfs(e.to))
				return 1;
			path.pop_back();
		}
	}

	return 0;
}

bool dfs3(int v) {
	if (v == t)
		return 1;

	used[v] = 1;
	for (auto e: g[v]) {
		if (inUse[e.id] && !used[e.to]) {
			path3.pb(e);
			if (dfs3(e.to))
				return 1;
			path3.pop_back();
		}
	}

	return 0;
}
        
//INUSE!!!
void dfs2(int v, int lastId = -1) {
	used[v] = 1;
	tin[v] = tmr++;
	fup[v] = tin[v];

	for (auto e: g[v])
		if (e.id != lastId && inUse[e.id]) {
			if (!used[e.to]) {
				dfs2(e.to, e.id);
				if (fup[e.to] >= tin[e.to]) {
					isBridge[e.id] = 1;
				}
				fup[v] = min(fup[v], fup[e.to]);
            } else {
				fup[v] = min(fup[v], tin[e.to]);
			}
		}
}
       
int main() {

	cin >> n >> m;
	cin >> s >> t;
	s--, t--;
	forn(i, m) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		u--, v--;
		g[u].pb(edge(v, w, i));
		g[v].pb(edge(u, w, i));
	}

	ans = INF;
	path.clear();
	if (!dfs(s)) {
		cout << 0 << '\n';
		cout << 0 << '\n';
		return 0;
	}

	forn(i, m)
		inUse[i] = 1;

	for (auto e: path) {
		inUse[e.id] = 0;
		curAns = e.w;

		forn(i, n)
			used[i] = 0;
		forn(i, m)
			isBridge[i] = 0;

		tmr = 0;
		dfs2(s);

		if (!used[t]) {
			if (curAns < ans) {
				ans = curAns;
				edges.clear();
				edges.pb(e);
			}
			
		} else {

    		forn(i, n)
    			used[i] = 0;
    		path3.clear();
    		
    		assert(dfs3(s));

    		for (auto e2: path3)
    			if (isBridge[e2.id]) {
    				curAns += e2.w;
    				if (curAns < ans) {
        				ans = curAns;
        				edges.clear();
        				edges.pb(e);
        				edges.pb(e2);
        			}
    				curAns -= e2.w;
    			}
    	}

		inUse[e.id] = 1;
	}

	if (ans == INF) {
		cout << -1 << '\n';
		return 0;
	}	

	cout << ans << '\n';
	cout << edges.size() << '\n';
	for (auto e: edges)
		cout << e.id + 1 << ' ';
	cout << '\n';	
			   
	return 0;
}