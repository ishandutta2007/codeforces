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

VI votes[3005];

int main() {
	make2(n, m);
	FOR(i,0,n) {
		make2(p, c);
		votes[p].pb(-c);
	}
	FOR(j,1,m+1) sort(all(votes[j]));
	int mam = votes[1].size();
	lint best = 3000LL*1e9;
	FOR(j,max(mam,1), n+1) {
		lint cost = 0;
		int wziac = j - mam;
		VI reszta;
		FOR(i,2,m+1) {
			VI v = votes[i];
			while (v.size() >= j) {
				wziac--;
				cost -= v.back();
				v.pop_back();
			} 
			FORE(u, v) reszta.pb(*u);
		}
		if (wziac < 0) continue;
		sort(all(reszta));
		while (wziac > 0 && !reszta.empty()) {
			cost -= reszta.back();
			reszta.pop_back();
			wziac--;
		}
		if (wziac != 0) continue;
		best = min(best, cost);
	}
	printf("%lld\n", best);
}