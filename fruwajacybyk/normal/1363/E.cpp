#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define all(v) (v).begin(),(v).end()

#define PII pair<int,int>
#define st first
#define nd second
#define pb push_back
#define lint long long int
#define VI vector<int>

#define debug(x) {cout <<#x <<" = " <<x <<endl; }
#define debug2(x,y) {cerr <<#x <<" = " <<x << ", "<<#y<<" = "<< y <<endl; } 
#define debug3(x,y,z) {cerr <<#x <<" = " <<x << ", "<<#y<<" = "<< y << ", " << #z << " = " << z <<endl; } 
#define debugv(x) {{cout <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<endl; }}
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
#define jeb() fflush(stdout);

using namespace std;

VI g[200005];

int cost[200005];
int siup[200005];
lint ans;

int dfs(int v, int p) {
		cost[v] = min(cost[v], cost[p]);
		int uj = 0, dod = 0;
		for (int w: g[v]) {
			if (w == p) continue;
			int x = dfs(w, v);
			if (x < 0) uj+=-x;
			else dod += x;
		}
		if (siup[v] == -1) uj++;
		if (siup[v] == 1) dod++;
		int pary = min(uj, dod);
		ans += pary*2LL*cost[v];
		uj -= pary;
		dod -= pary;
		return -uj + dod; 
}

int main() {
	make(n);
	ans = 0;
	FOR(i,0,n) {
		make3(a, b, c);
		cost[i] = a;
		siup[i] = b-c;
	}
	FOR(i,0,n-1) {
		make2(a, b); a--;b--;
		g[a].pb(b); g[b].pb(a);
	}
	if (dfs(0,0) != 0) {
		printf("-1\n");
	} else {
		printf("%lld\n", ans);
	}
}