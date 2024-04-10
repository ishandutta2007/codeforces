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

#define REP(i,n) FOR(i,0,n)

using namespace std;

const int max_n = 505;

VI g[max_n];
int  ans[max_n];


int mat[505][505];

int main() {
	make2(n, m);
	FOR(i,0,n) FOR(j,0,n) mat[i][j] = 0;
	FOR(i,0,n) mat[i][i] = 1;
	FOR(i,0,m) {
		make2(a, b); a--; b--;
		g[a].pb(b);
		g[b].pb(a);
		mat[a][b] = mat[b][a] = 1;
	}
	FOR(i,0,n) ans[i] = -1;
	FOR(i,0,n) if (g[i].size()==n-1) ans[i] = 1;
	FOR(i,0,n) {
		if (ans[i]==1) 
			FOR(j,0,n) mat[i][j] = mat[j][i] = 0;
	}
	bool ok = true;
	int dupa = 0;
	FOR(i,0,n) {
		if (ans[i]==-1) {
			VI as;
			FOR(j,0,n) if(mat[i][j]==1) as.pb(j);
			FOR(u,0,as.size()) FOR(w,0,as.size()) if(mat[as[u]][as[w]]!=1) ok = false;
			FOR(u,0,as.size()) ans[as[u]] = dupa;
			FOR(u,0,as.size()) FOR(w,0,as.size()) mat[as[u]][as[w]] = 0;
			dupa += 2;
		}
	}
	if (dupa > 4) ok = false;
	FOR(i,0,n) FOR(j,0,n) if(mat[i][j]!=0) ok = false;

	if (ok) {
		printf("Yes\n");
		FOR(i,0,n) putchar('a'+ans[i]);
		printf("\n");
	} else printf("No\n");
}