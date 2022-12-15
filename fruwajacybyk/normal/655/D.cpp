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

VI g[100005];
int indeg[100005];

map<PII,int> dupa;

int main() {
	make2(n, m);
	FOR(i,0,n) indeg[i] = 0;
	FOR(i,0,m) {
		make2(a, b);
		a--; b--;
		dupa[mp(a,b)] = i;
		g[a].pb(b);
		indeg[b]++;
	}
	VI kolejnosc;
	FOR(i,0,n) {
		if(indeg[i]==0) kolejnosc.pb(i);	
	}
	if(kolejnosc.size() != 1) {
		printf("-1\n");
		return 0;
	}
	bool ok = true;
	FOR(i,0,n-1) {
		int act = kolejnosc[i];
		int nowy = -1;
		FORE(j,g[act]) {
			indeg[*j]--;
			if (indeg[*j]==0 && nowy==-1) nowy = *j;
			else if (indeg[*j]==0 && nowy!=-1) ok = false;
		}
		if(!ok) {
			printf("-1\n");
			return 0;
		} 
		kolejnosc.pb(nowy);
	}
	int best = 0;
	FOR(i,0,n-1) {
		best = max(best, dupa[mp(kolejnosc[i], kolejnosc[i+1])]+1);
	}
	printf("%d\n", best);
}