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

int n, a, b, c, q;
vector<pii> g[MAXN];
int sz[MAXN], h[MAXN], used[MAXN];
pii vedge[MAXN];
int cost[MAXN], delta;
ld ans, nans, prnt;      

void dfs(int v) {
	used[v] = 1;
	sz[v] = 1;
	for (auto w: g[v]) {
		if (!used[w.X]) {
			h[w.X] = h[v] + 1;
			dfs(w.X);
			sz[v] += sz[w.X];
		}	
	}
}

int main() {
                      
	scanf("%d", &n);
	forn(i, n - 1) {
		scanf("%d%d%d", &a, &b, &c);
		a--, b--;
		g[a].pb(mp(b, c));
		g[b].pb(mp(a, c));
		
		vedge[i] = mp(a, b);
		cost[i] = c;	
	}	
	
	h[0] = 0;
	dfs(0);
	
	ans = 0;
	forn(i, n - 1) {
		if (h[vedge[i].X] < h[vedge[i].Y])
			swap(vedge[i].X, vedge[i].Y);
			
		ans += 1.0 * sz[vedge[i].X] * (n - sz[vedge[i].X]) * cost[i];	
	}
		
	scanf("%d", &q);
	cout.precision(30);
	forn(i, q) {
		scanf("%d%d", &a, &b);
		a--;
		delta = cost[a] - b;
		cost[a] = b;
			
		ans -= 1.0 * sz[vedge[a].X] * (n - sz[vedge[a].X]) * delta;
		
		prnt = ans * 6.0 / n / (n - 1);
		cout << prnt << '\n';
	}
	
   	return 0;
}