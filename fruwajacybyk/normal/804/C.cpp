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

const int max_n = 3e5+5;

int n, m;
VI g[max_n];
VI types[max_n];
int kolor[max_n];

void dfs(int v, int par) {
	VI uzyte;
	FORE(i, types[v]) {
		int lod = *i; 
		if (kolor[lod] != -1) uzyte.pb(kolor[lod]);
	}
	sort(all(uzyte));
	int pos = 0;
	int myc = 0;
	FORE(i, types[v]) {
		int lod = *i;
		if (kolor[lod] == -1) {
			while (pos < uzyte.size() && uzyte[pos]==myc) {
				myc++;
				pos++;
			}
			if (pos == uzyte.size()) {
				kolor[lod] = myc;
				myc++;
			} else {
				kolor[lod] = myc;
				myc++;
			}
		}
	}
	FORE(i, g[v]) {
		int w = *i;
		if (w == par) continue;
		dfs(w, v);
	}
}

int main() {
	read2(n, m);
	int ans = 0;
	FOR(i,0,n) {
		make(x);
			ans = max(ans, x);
		FOR(j,0,x) {
			make(b); 
			b--;
			types[i].pb(b);
		}
	}
	FOR(i,0,n-1) {
		make2(u, v);
		u--; v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	FOR(i,0,m) kolor[i] = -1;
	dfs(0, 0);
	ans = max(ans, 1);
	printf("%d\n", ans);
	FOR(i,0,m) {
		if (kolor[i] == -1) printf("1 ");
		else printf("%d ", kolor[i] + 1);
	}
	printf("\n");
}