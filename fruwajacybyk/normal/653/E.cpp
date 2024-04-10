#include <bits/stdc++.h>
 
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define all(v) (v).begin(),(v).end()
 
#define VI vector<int>
#define PII pair<int,int>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define lint long long int
 
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

const int max_n = 300005;

int n, m, k;
set<int> g[max_n];
int nr[max_n];

set<int> unvisited;



void dfs1(int v) {
	VI nowe;
	FORE(j,unvisited) 
		if (g[v].find(*j)==g[v].end()) nowe.pb(*j);
	FORE(j,nowe) 
		unvisited.erase(*j);
	FORE(j,nowe) dfs1(*j);
}

bool connected() {
	FOR(i,1,n) unvisited.insert(i);
	dfs1(0);
	if (!unvisited.empty()) return false;
	return true;
}

int components() {
	FOR(i,1,n) g[i].insert(0);
	unvisited.clear();
	FOR(i,1,n) unvisited.insert(i);
	int licz = 0;
	while(!unvisited.empty()){	
		int w = *unvisited.begin();
		unvisited.erase(w);
		licz++;
		dfs1(w);
	}
	return licz;
}



int main() {
	read3(n, m, k);
	FOR(i,0,m) {
		make2(a, b);
		a--; b--;
		g[a].insert(b);
		g[b].insert(a);
	}
	bool ok = connected();
	ok = ok && (g[0].size() <= n-1-k);
	ok = ok && (components() <= k);
	if (ok) printf("possible\n");
	else printf("impossible\n");
}