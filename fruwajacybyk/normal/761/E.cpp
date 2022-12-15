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
#define jeb fflush(stdout)

 
using namespace std;

#define max_n 500

VI g[max_n];
pair<lint, lint> ans[35];

int dx[]={0,-1,1,0};
int dy[]={1,0,0,-1};

void dfs(int v, int par, int kier, lint dist) {
	if (par == -1) {
		ans[v] = mp(0,0);
		FOR(i,0,g[v].size()) {
			int w = g[v][i];
			dfs(w, v, i, dist);
		}
	} else {
		ans[v] = mp(ans[par].st + dx[kier]*1LL*dist, ans[par].nd + dy[kier]*1LL*dist);
		set<int> zajete; zajete.insert(3-kier);
		FOR(j,0,g[v].size()) {
			int w = g[v][j];
			if (w == par) continue;
			FOR(u,0,4) {
				if (zajete.find(u) == zajete.end()) {
					dfs(w, v, u, dist/3);
					zajete.insert(u);
					break;
				} 
			}
		}
	}
}


int main() {
	make(n);
	FOR(i,0,n-1) {
		make2(a, b);
		a--; b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	FOR(i,0,n) {
		if (g[i].size() > 4) {
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	lint u = 1;
	FOR(i,0,35) u = u*3LL;
	dfs(0, -1, -1, u);
	FOR(i,0,n) {
		printf("%lld %lld\n", ans[i].st, ans[i].nd);
	}
}