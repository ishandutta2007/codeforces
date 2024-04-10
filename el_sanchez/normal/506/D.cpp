#include <iostream>
#include <fstream> 
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <complex>
#include <bitset>
#include <map>
#include <set>
#include <ctime>
#include <cfloat>

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

using namespace std;

typedef long long ll;
typedef double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-8;
const int INF = 1E9;
const int MAXN = 100500;
const int MAXK = 500;  

int n, m, q, tmr, ans;
int a, b, c;
int used[MAXN];
vector<pair<pii, int> > edges;
vi nodes[MAXN]; 
vector<vi> g[MAXN];
vi component[MAXN];
vi colors[MAXN];       
vi big;
int precalc[2111][2111];

void dfs(int color, int v) {
	component[color][v] = c;
	used[v] = tmr;
	
	for (auto w: g[color][v])
		if (used[w] != tmr) {
			dfs(color, w);	
		}
}

int main() {

	scanf("%d%d", &n, &m);
	forn(i, m) {
		scanf("%d%d%d", &a, &b, &c);
		a--, b--, c--;
		
		edges.pb({{a, b}, c});
		
		nodes[c].pb(a);
		nodes[c].pb(b);
		colors[a].pb(c);
		colors[b].pb(c);
	}

	forn(i, m) {
		sort(all(nodes[i]));
		int nn = unique(all(nodes[i])) - nodes[i].begin();
		nodes[i].resize(nn);
		
		g[i].resize(nodes[i].size());
		forn(j, nodes[i].size())
			g[i][j].clear();
		component[i].resize(nodes[i].size(), 0);
	}
	
	forn(i, m) {
		c = edges[i].Y;
		a = edges[i].X.X;
		b = edges[i].X.Y;
		int v = lower_bound(all(nodes[c]), a) - nodes[c].begin();
		int w = lower_bound(all(nodes[c]), b) - nodes[c].begin();
		g[c][v].pb(w);
		g[c][w].pb(v);			
	}
	
	forn(i, n) {
		sort(all(colors[i]));
		int nn = unique(all(colors[i])) - colors[i].begin();
		colors[i].resize(nn);    		
	}
	
	//cerr << "3!\n";
	
	tmr = 1;
	forn(i, m) {
		tmr++;
		
		c = 1;
		forn(v, nodes[i].size()) {
			if (used[v] != tmr) {
				c++;
				dfs(i, v);
			}
		}
	}

	//cerr << "4!\n";
		
	forn(i, n)
		if (colors[i].size() >= MAXK) 
			big.pb(i);

	forn(i, m)
		nodes[i].pb(INF);
		
	for (int i = 0; i < (int)big.size(); i++) {
		int v = big[i];
		for (auto c: colors[v]) {
			for (int j = 0; j < (int)big.size(); j++) {
				int w = big[j];
				
				int vv = lower_bound(all(nodes[c]), v) - nodes[c].begin();
				int ww = lower_bound(all(nodes[c]), w) - nodes[c].begin();
		    	if (nodes[c][ww] != w)
		    		continue;
		    	assert(nodes[c][vv] == v);
		    	
		    	precalc[i][j] += component[c][vv] == component[c][ww];
		    }
		}		
	}
	
	//cerr << "5!\n";
	
	scanf("%d", &q);
	forn(i, q) {
		scanf("%d%d", &a, &b);
		a--, b--;
		
		ans = 0;
		
		if (colors[a].size() > colors[b].size())
			swap(a, b);
		if (colors[a].size() >= MAXK) {
			int posa = lower_bound(all(big), a) - big.begin();
			int posb = lower_bound(all(big), b) - big.begin();
			
			assert(big[posa] == a);
		    assert(big[posb] == b);
		    	
		    ans = precalc[posa][posb];		    	
		} else {
			for (auto c: colors[a]) {
				int v = lower_bound(all(nodes[c]), a) - nodes[c].begin();
				int w = lower_bound(all(nodes[c]), b) - nodes[c].begin();
		    	if (nodes[c][w] != b)
		    		continue;
		    	assert(nodes[c][v] == a);
		    	ans += component[c][v] == component[c][w];
			}
		}
		
		printf("%d\n", ans);
	}
	
	return 0;
}