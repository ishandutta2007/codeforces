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

int n;
vector<PII> v;

bool check(int rate) {
	FOR(i,0,n) {
		if (v[i].nd == 1 && rate < 1900) return false;
		if (v[i].nd == 2 && rate > 1899) return false;
		rate += v[i].st;
	}
	return true;
}

int main() {
	read(n);
	int diff = 0;
	FOR(i,0,n) {
		make2(a, b);
		v.pb(mp(a,b));
		diff += a;
	}
	int jed = 0, dwa = 0;
	FOR(i,0,n) {
		if (v[i].nd == 1) jed = 1;
		if (v[i].nd == 2) dwa = 1;
	}
	if (dwa == 0) {
		printf("Infinity\n");
		return 0;
	}
	if (jed == 0) {
		int maxpick = 0;
		int act = 0;
		int dla = -1;
		FOR(i,0,n-1) {
			act += v[i].st;
			maxpick = max(maxpick, act);
			if (maxpick == act) dla = i;
		}
		int rate = 1899;
		FOR(i, dla+1, n) {
			rate += v[i].st;
		}
		printf("%d\n", rate);
		return 0;
	}
	int change = 0;
	int a1, a2;
	FOR(i,0,n) {
		if (v[i].nd != v[i+1].nd) {
			if (v[i].nd == 1 && v[i+1].nd == 2) {
				a1 = 1900  - change;
				a2 = 1900 + (-v[i].st - 1) - change;
			} else {
				a1 = 1899 - v[i].st + 1 - change;
				a2 = 1899 - change;
			}
			break;
		}
		change += v[i].st;
	}
	FORD(i,a2,a1) {
		if (check(i)) {
			printf("%d\n", i + diff);
			return 0;
		}
	}
	printf("Impossible\n");
	
}