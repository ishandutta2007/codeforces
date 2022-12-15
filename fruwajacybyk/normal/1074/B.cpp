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
#define jeb() fflush(stdout)

using namespace std;

const int max_n = 1e3+5;

int n;
VI g[max_n];
int par[max_n];
int ins[max_n];
int ins2[max_n];

void dfs(int a, int p) {
	FORE(i, g[a]) {
		int w = *i;
		if (w == p) continue;
		par[w] = a;
		dfs(w, a);
	}
}


void solve() {
	read(n);
	FOR(i,1,n+1) g[i].clear();
	FOR(i,0,n-1) {
		make2(a, b);
		g[a].pb(b);
		g[b].pb(a);
	}
	FOR(i,1,n+1) ins[i] = ins2[i] = 0;
	make(k1);
	makev(v, k1);
	FORE(i, v) ins[*i] = 1;

	par[v[0]] = -1;
	dfs(v[0], v[0]);

	make(k2);
	makev(w, k2);
	FORE(i, w) ins2[*i] = 1;


	printf("B %d\n",w[0]); jeb();
	make(q);
	if (ins[q]) {
		printf("C %d\n", q); jeb();
		return;
	}
	int qq = q;
	while (ins[qq] == 0) qq = par[qq];
	printf("A %d\n", qq); jeb();
	make(typ);
	if (ins2[typ]) {
		printf("C %d\n", qq); jeb();
		return;
	}
	else {
		printf("C -1\n");
		jeb();
		return;
	}
}

int main() {
	make(z);
	while (z--) {
		solve();
	}
}