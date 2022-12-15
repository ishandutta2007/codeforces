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


using namespace std;

const int max_n = 200005;

int n, k;
VI g[max_n];
int jest[max_n];
int sz[max_n];
lint ans = 0;

int dfs(int v, int p) {
	sz[v] = jest[v];
	FORE(i, g[v]) {
		int w = *i;
		if (w == p) continue;
		sz[v] += dfs(w, v);
	}
	return sz[v];
}

void dfs2(int v, int p) {
	FORE(i, g[v]) {
		int w = *i;
		if (w==p) continue;
		dfs2(w, v);
	}
	ans += min(sz[v], 2*k-sz[v]);
}

int main() {
	read2(n, k);
	FOR(i,0,n) jest[i] = 0;
	FOR(i,0,2*k) {
		make(a); a--;
		jest[a] = 1;
	}
	FOR(i,0,n-1) {
		make2(a, b); a--; b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs(0,0);
	dfs2(0,0);
	printf("%I64d\n", ans);
}