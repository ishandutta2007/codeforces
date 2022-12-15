#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define all(v) (v).begin(),(v).end()

#define PII pair<int,int>
#define mp make_pair
#define st first
#define nd second
#define pb push_back
#define lint long long int
#define VI vector<int>

#define debug(x) {cerr <<#x <<" = " <<x <<endl; }
#define debug2(x,y) {cerr <<#x <<" = " <<x << ", "<<#y<<" = "<< y <<endl; } 
#define debug3(x,y,z) {cerr <<#x <<" = " <<x << ", "<<#y<<" = "<< y << ", " << #z << " = " << z <<endl; } 
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<endl; }}
#define debugt(t,n) {{cerr <<#t <<" = "; FOR(it,0,(n)) cerr <<t[it] <<", "; cerr <<endl; }}

#define make( x) int (x); scanf("%d",&(x));
#define make2( x, y) int (x), (y); scanf("%d%d",&(x),&(y));
#define make3(x, y, z) int (x), (y), (z); scanf("%d%d%d",&(x),&(y),&(z));
#define make4(x, y, z, t) int (x), (y), (z), (t); scanf("%d%d%d%d",&(x),&(y),&(z),&(t));
#define makev(v,n) VI (v); FOR(i,0,(n)) { make(a); (v).pb(a);} 
#define IOS ios_base::sync_with_stdio(0)
#define HEAP priority_queue

#define read( x) scanf("%d",&(x));
#define read2( x, y) scanf("%d%d",&(x),&(y));
#define read3(x, y, z) scanf("%d%d%d",&(x),&(y),&(z));
#define read4(x, y, z, t) scanf("%d%d%d%d",&(x),&(y),&(z),&(t));
#define readv(v,n) FOR(i,0,(n)) { make(a); (v).pb(a);}
#define jeb() fflush(0);

using namespace std;

const int max_n = 1e5 + 5;
int n, k;

VI g[max_n];
int dist[max_n];
int par[max_n];

void dfs(int v, int p, int d) {
	par[v] = p;
	FORE(i, g[v]) {
		int w = *i;
		if (w == p) continue;
		dist[w] = d+1;
		dfs(w, v, d+1);
	}
}

bool check2(int v, int p, int u) {
	if (u == 0 && g[v].size() != 1) return false;
	if (u == 0 && g[v].size() == 1) return true;
	if (g[v].size() < 4) return false;
	FORE(i, g[v]) {
		int w = *i; 
		if (w == p) continue;
		if (!check2(w, v, u - 1)) return false;
	}
	return true;
}

bool check(int v) {
	if (g[v].size() < 3) return false;
	FORE(i, g[v]) {
		int w = *i;
		if (!check2(w, v, k-1)) return false;
	}
	return true;
}

int main() {
	read2(n, k);
	FOR(i,0,n-1) {
		make2(a,b); a--; b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	dist[0] = 0;
	dfs(0,0,0);
	int w = 0;
	FOR(i,0,n) {
		if (dist[i] > dist[w]) w = i;
	}
	dist[w] = 0;
	dfs(w,w,0);
	int md = 0;
	FOR(i,0,n) {
		if (dist[i] > dist[md]) md = i;
	}
	if (dist[md] != 2*k) {
		printf("No\n");
		return 0;
	}
	FOR(i,0,k) md = par[md];
	if (check(md)) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
}